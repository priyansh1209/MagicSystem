@echo off
title Magic System Automator
setlocal enabledelayedexpansion

echo [1/4] Scanning for Microsoft C++ Compiler Tools...

set "VS_PATH="
for /f "usebackq tokens=*" %%i in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do (
    set "VS_PATH=%%i"
)

if "%VS_PATH%"=="" (
    echo [ERROR] Could not detect a valid Visual Studio installation.
    echo Please make sure C++ Desktop Development tools are installed.
    pause
    exit /b 1
)

set "DEV_CMD=!VS_PATH!\Common7\Tools\VsDevCmd.bat"
if not exist "!DEV_CMD!" (
    echo [ERROR] Developer command core missing at: !DEV_CMD!
    pause
    exit /b 1
)

echo [2/4] Initializing Developer Environment flags...
call "!DEV_CMD!" -no_logo >nul

echo [3/4] Checking workspace file directories...
if not exist "build" mkdir build
if not exist "build\Save" mkdir build\Save

echo [4/4] Compiling Magic System project...
cl.exe /Z7 /EHsc /nologo /Fe:build\Game.exe /Fo:build\ /Fd:build\ src\Main.cpp src\Attributes\Type.cpp src\Attributes\Form.cpp src\Spells\basicSpell.cpp


if %errorlevel% neq 0 (
    echo.
    echo [ERROR] Compilation failed! Review the syntax messages above.
    echo.
    pause
    exit /b %errorlevel%
)

echo.
echo ===================================================
echo SUCCESS: build/Game.exe has been compiled!
echo You can now double-click Game.exe inside the build folder to play.
echo ===================================================
echo.
pause
