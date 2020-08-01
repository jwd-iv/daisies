; -- Example1.iss --
; Demonstrates copying 3 files and creating an icon.

; SEE THE DOCUMENTATION FOR DETAILS ON CREATING .ISS SCRIPT FILES!

[Setup]
AppName=daisies
AppVersion=1.0
WizardStyle=modern
DefaultDirName={sys}
;DefaultGroupName=daisies
UninstallDisplayIcon={sys}\daisies.scr
Compression=lzma2
SolidCompression=yes
OutputDir=.
OutputBaseFilename=daisies_setup
SetupIconFile=daisy.ico

[Files]
Source: "game\*"; DestDir: {sys}; Flags: recursesubdirs 64bit

;[Icons]
;Name: "{group}\My Program"; Filename: "{app}\MyProg.exe"
