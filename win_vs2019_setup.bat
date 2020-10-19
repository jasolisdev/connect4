@echo ==== Running premake5 to setup Visual Studio 2019 Project Files ====
@echo off 
pushd vendor\windows
premake5 vs2019 --FILE=..\..\premake5.lua
popd

@echo ==== Coping assets over to Visual Stuido Project Directory ====
Xcopy /E /I assets\ build\assets\

@echo ==== Setup Complete ====

@echo ==== Launch the Visual Studio 2019 .sln project from the build folder ====