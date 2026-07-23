@echo off
title Magic System Automator
setlocal enabledelayedexpansion

:: Change to the folder this batch file is located in
cd /d "%~dp0"

echo ===================================================
echo Magic System Build Tool
echo ===================================================
echo.
echo Current Directory:
echo %CD%
echo.

echo [1/4] Scanning for Microsoft C++ Compiler Tools...

set "VS_PATH="
for /f "usebackq tokens=*" %%i in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do (
    set "VS_PATH=%%i"
)

if "!VS_PATH!"=="" (
    echo [ERROR] Could not detect a valid Visual Studio installation.
    echo Please make sure Desktop Development with C++ is installed.
    pause
    exit /b 1
)

set "DEV_CMD=!VS_PATH!\Common7\Tools\VsDevCmd.bat"

if not exist "!DEV_CMD!" (
    echo [ERROR] Could not find:
    echo !DEV_CMD!
    pause
    exit /b 1
)

echo [2/4] Initializing Developer Environment...
call "!DEV_CMD!" -no_logo >nul

echo [3/4] Checking project structure...

if not exist "src" (
    echo [ERROR] Could not find the "src" folder.
    echo Current directory is:
    echo %CD%
    pause
    exit /b 1
)

if not exist "src\Main.cpp" (
    echo [ERROR] Missing file:
    echo src\Main.cpp
    pause
    exit /b 1
)

if not exist "src\Attributes\Type.cpp" (
    echo [ERROR] Missing file:
    echo src\Attributes\Type.cpp
    pause
    exit /b 1
)

if not exist "src\Attributes\Form.cpp" (
    echo [ERROR] Missing file:
    echo src\Attributes\Form.cpp
    pause
    exit /b 1
)

if not exist "src\Spells\basicSpell.cpp" (
    echo [ERROR] Missing file:
    echo src\Spells\basicSpell.cpp
    pause
    exit /b 1
)

if not exist "build" mkdir build
if not exist "build\Save" mkdir build\Save

echo.
echo [4/4] Compiling...

cl.exe ^
/Z7 ^
/EHsc ^
/nologo ^
/Fe:build\Game.exe ^
/Fo:build\ ^
/Fd:build\ ^
src\Main.cpp ^
src\Attributes\Type.cpp ^
src\Attributes\Form.cpp ^
src\Spells\basicSpell.cpp

if errorlevel 1 (
    echo.
    echo ===================================================
    echo BUILD FAILED
    echo ===================================================
    pause
    exit /b %errorlevel%
)

echo.
echo ===================================================
echo BUILD SUCCEEDED
echo Executable created:
echo build\Game.exe
echo ===================================================
echo.

pause
