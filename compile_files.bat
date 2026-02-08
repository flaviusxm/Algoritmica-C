@echo off
setlocal enabledelayedexpansion

echo ========================================
echo    Algoritmica-C - Professional Build
echo ========================================

set COMPILER=
set COMPILER_NAME=
set FOUND_COMPILER=0

echo
echo Scanning for C compilers...
echo 

:: 1. Verifica Clang
clang --version >nul 2>&1
if !errorlevel! == 0 (
    set COMPILER=clang
    set COMPILER_NAME=Clang
    set FOUND_COMPILER=1
    echo ✓ Clang detectat
    goto :compiler_found
)

:: 2. Verifica GCC
gcc --version >nul 2>&1
if !errorlevel! == 0 (
    set COMPILER=gcc
    set COMPILER_NAME=GCC
    set FOUND_COMPILER=1
    echo ✓ GCC detectat
    goto :compiler_found
)

:: 3. Verifica Cl (Visual Studio)
cl /? >nul 2>&1
if !errorlevel! == 0 (
    set COMPILER=cl
    set COMPILER_NAME=Microsoft Visual C++
    set FOUND_COMPILER=1
    echo ✓ Microsoft Visual C++ detectat
    goto :compiler_found
)

:: 4. Verifica TCC (Tiny C Compiler)
tcc -version >nul 2>&1
if !errorlevel! == 0 (
    set COMPILER=tcc
    set COMPILER_NAME=Tiny C Compiler
    set FOUND_COMPILER=1
    echo ✓ Tiny C Compiler detectat
    goto :compiler_found
)

:: Niciun compilator gasit
echo.
echo ERROR !! Niciun compilator C nu a fost detectat!! ERROR
echo.
echo Instaleaza unul dintre:
echo.
echo   GCC (Recomandat):
echo   1. TDM-GCC: https://jmeubank.github.io/tdm-gcc/
echo   2. MinGW-w64: https://www.mingw-w64.org/
echo.
echo   Clang:
echo   3. LLVM: https://github.com/llvm/llvm-project/releases
echo.
echo   Visual Studio:
echo   4. Visual Studio Build Tools: https://visualstudio.microsoft.com/downloads/
echo.
echo   Tiny C Compiler:
echo   5. TCC: https://bellard.org/tcc/
echo.
echo  Path ul compilatorului trebuie adaugat în PATH ( Environment Variables)
pause
exit /b 1

:compiler_found
echo.
echo  Compilator selectat: !COMPILER_NAME! (!COMPILER!)
echo.

:: compiler settings 
if "!COMPILER!"=="cl" (
    set CFLAGS=/W4 /O2
    set SHARED_FLAGS=/LD
    set OUTPUT_FLAG=/Fe
    set LIB_FLAG=/link
else (
    set CFLAGS=-Wall -Wextra -O2
    set SHARED_FLAGS=-shared
    set OUTPUT_FLAG=-o
    set LIB_FLAG=-l
)

:: verificari
make --version >nul 2>&1
if !errorlevel! == 0 (
    echo ✓ Make detectat - folosesc Makefile
    echo.
    make clean
    make CC=!COMPILER!
) else (
    echo ! Make nu este instalat - folosesc compilare directă
    echo.
    
        echo Compiling info_module.dll...
        !COMPILER! !CFLAGS! !SHARED_FLAGS! info_lib\info_module.c !OUTPUT_FLAG!info_module.dll
        
        echo Compiling sort_module.dll...
        !COMPILER! !CFLAGS! !SHARED_FLAGS! sort_lib\sort_module.c !OUTPUT_FLAG!sort_module.dll

        echo Compiling search_module.dll...
        !COMPILER! !CFLAGS! !SHARED_FLAGS! search_lib\search_module.c !OUTPUT_FLAG!search_module.dll
        
        echo Compiling main executable...
        !COMPILER! !CFLAGS! main_exec.c !OUTPUT_FLAG!main_exec.exe info_module.lib sort_module.lib psapi.lib
    ) else (
        echo Compiling info_module.dll...
        !COMPILER! !CFLAGS! !SHARED_FLAGS! !OUTPUT_FLAG!info_module.dll info_lib\info_module.c
        
        echo Compiling sort_module.dll...
        !COMPILER! !CFLAGS! !SHARED_FLAGS! !OUTPUT_FLAG!sort_module.dll sort_lib\sort_module.c

        echo Compiling search_module.dll...
        !COMPILER! !CFLAGS! !SHARED_FLAGS! !OUTPUT_FLAG!search_module.dll search_lib\search_module.c
        
        echo Compiling main executable...
        if "!COMPILER!"=="tcc" (
            !COMPILER! !CFLAGS! !OUTPUT_FLAG!main_exec.exe main_exec.c -L. !LIB_FLAG!info_module !LIB_FLAG!sort_module !LIB_FLAG!psapi
        ) else (
            !COMPILER! !CFLAGS! !OUTPUT_FLAG!main_exec.exe main_exec.c -L. !LIB_FLAG!info_module !LIB_FLAG!sort_module !LIB_FLAG!psapi
        )
    )
)

echo.
echo ========================================
echo            BUILD COMPLET!
echo ========================================
pause