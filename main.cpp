#include "tiny.h"
#include "flowers.h"
#include "background.h"

#ifdef _WIN32
#include <Windows.h>
#include <ScrnSave.h>
#endif

rkLink(tinySFMLsys)
rkLink(tinySFMLgfx)
rkLink(tiny_core)
rkLink(daisies)

#ifndef DAISY_SCRNSVR

#ifdef _WIN32
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#else
int main(void)
#endif
{
  tiny::engine::get().initialize();
  tiny::engine::get().run();
  tiny::engine::get().close();

  return 0;
}
#endif

#ifdef DAISY_SCRNSVR
//define a Windows timer 
#define TIMER 1 

extern int Width;
extern int Height;

// Screen Saver Procedure
LRESULT WINAPI ScreenSaverProc(HWND hWnd, UINT message,
  WPARAM wParam, LPARAM lParam)
{
  static HDC hDC;
  static HGLRC hRC;
  static RECT rect;

  switch (message) {

  case WM_CREATE:
    // get window dimensions
    GetClientRect(hWnd, &rect);
    Width = rect.right;
    Height = rect.bottom;

    //get configuration from registry if applicable

    //set up OpenGL
    //InitGL(hWnd, hDC, hRC);
    //Initialize perspective, viewpoint, and
    //any objects you wish to animate
    tiny::engine::get().initialize();

    //create a timer that ticks every 10 milliseconds
    SetTimer(hWnd, TIMER, 10, NULL);
    return 0;

  case WM_KEYUP:
    return 0;

  case WM_DESTROY:
    KillTimer(hWnd, TIMER);

    //delete any objects created during animation
    //and close down OpenGL nicely

    //CloseGL(hWnd, hDC, hRC);
    tiny::engine::get().stop();
    tiny::engine::get().close();

    PostQuitMessage(0);
    return 0;

  case WM_TIMER:
    //call some function to advance your animation        
    using namespace tiny;

    frc* FRC = systems::get<frc>();
    FRC->begin_frame();

    while (FRC->time_left())
    {
      float dt = FRC->dt();

      engine::get().update(dt);
    }

    engine::get().render();

    return 0;
  }

  //let the screensaver library take care of any
  //other messages
  return DefScreenSaverProc(
    hWnd, message, wParam, lParam);
}

BOOL WINAPI
ScreenSaverConfigureDialog(HWND hDlg, UINT message,
  WPARAM wParam, LPARAM lParam)
{
  switch (message)
  {
  case WM_INITDIALOG:

    //get configuration from the registry
    return TRUE;

  case WM_COMMAND:
    switch (LOWORD(wParam))
    {

      //handle various cases sent when controls
      //are checked, unchecked, etc

      //when OK is pressed, write the configuration
      //to the registry and end the dialog box

    case IDOK:
      //write configuration

      EndDialog(hDlg, LOWORD(wParam) == IDOK);
      return TRUE;

    case IDCANCEL:
      EndDialog(hDlg, LOWORD(wParam) == IDOK);
      return TRUE;
    }

  }     //end command switch

  return FALSE;
}

// needed for SCRNSAVE.LIB
BOOL WINAPI RegisterDialogClasses(HANDLE hInst)
{
  return TRUE;
}

#endif
