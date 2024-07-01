-- premake5.lua
workspace "2DMaze_Gen"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "2DMaze-App"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Core"
	include "2DMaze-Core/Build-Core.lua"
group ""

include "2DMaze-App/Build-App.lua"