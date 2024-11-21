@echo off
REM ----------------------------------------------------
REM Fichier batch pour compiler et exécuter le projet
REM ----------------------------------------------------

REM Définir les chemins
set INCLUDE_DIR=includes
set SRC_DIR=src
set BUILD_DIR=build
set EXECUTABLE=%BUILD_DIR%\gestionMotsVoyelles.exe

REM Créer le dossier build s'il n'existe pas
if not exist "%BUILD_DIR%" (
    mkdir "%BUILD_DIR%"
)

REM Compiler le projet
echo Compilation en cours...
g++ -I%INCLUDE_DIR% -o %EXECUTABLE% %SRC_DIR%\gestionMotsVoyelles.cpp %SRC_DIR%\ListeAscii.cpp %SRC_DIR%\ListeMots.cpp %SRC_DIR%\ListeVoyelles.cpp -std=c++17 -mconsole
if %errorlevel% neq 0 (
    echo Erreur lors de la compilation.
    pause
    exit /b %errorlevel%
)

REM Exécuter le programme
echo Exécution du programme...
"%EXECUTABLE%"
pause
