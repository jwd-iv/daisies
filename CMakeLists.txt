cmake_minimum_required(VERSION 3.8)
enable_testing()

project(daisies)

option(DAISY_SCRNSVR "Builds daisies as a WinAPI screensaver" ON)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS_DEBUG} /MTd")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set(CMAKE_C_FLAGS_RELEASE   "${CMAKE_C_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
endif()

set(TINY_SFML_SFX OFF CACHE BOOL " " FORCE)
add_definitions(-DTW_STATIC)
add_subdirectory("${daisies_SOURCE_DIR}/../tinysfml" "${CMAKE_CURRENT_BINARY_DIR}/tinysfml_build")
message(STATUS "tinysfml found and added to build!")

include_directories(.
                    ../ext/SFML/include
                    ../tinysfml/include
                    ../tinyeng/include
                    ../RIKU/include
                    ${tiny_SOURCE_DIR}/../ext/glm)

file(GLOB_RECURSE DAISIES_src *.cpp)
file(GLOB_RECURSE DAISIES_hdr *.h)

add_executable(daisies WIN32 ${DAISIES_src} ${DAISIES_hdr})

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set_target_properties(daisies PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS") #:CONSOLE for console application, will still make sfml window
  set_target_properties(daisies PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/game")
  set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT daisies)

endif()


target_link_libraries(daisies tiny_core)
target_link_libraries(daisies tiny-editor)
target_link_libraries(daisies tinysfml-gfx)
target_link_libraries(daisies tinysfml-sys)

if(DAISY_SCRNSVR)
  if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_sources(daisies PRIVATE resource.h daisies.rc screensaver.h screensaver.cpp)

    set_target_properties(daisies PROPERTIES
      SUFFIX ".scr")

    target_link_libraries(daisies scrnsave)
    target_link_libraries(daisies Comctl32)

    add_definitions(-DDAISY_SCRNSVR)

    find_program(INNO_COMPILER iscc
      HINTS "C:/Program Files (x86)/Inno Setup 6")

    if(NOT(INNO_COMPILER-NOTFOUND))
      message("Found Inno Setup Script Compiler")
      add_custom_command(TARGET daisies
                         POST_BUILD
                         COMMAND ${INNO_COMPILER} "${daisies_SOURCE_DIR}/installer.iss")
    else()
      message("Couldn't find Inno Setup Script Compiler!")
    endif()
  endif()
endif()

set_target_properties(daisies PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY_DEBUG          "${daisies_SOURCE_DIR}/game/"
                      RUNTIME_OUTPUT_DIRECTORY_RELEASE        "${daisies_SOURCE_DIR}/game/"
                      RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL     "${daisies_SOURCE_DIR}/game/"
                      RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${daisies_SOURCE_DIR}/game/"
)
