workspace "LineServer"
    configurations { "Debug", "Release" }
    platforms { "x64" }
    location "build"
    startproject "LineServer"

    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{cfg.buildcfg}"

    -- ============================================
    -- Utils 静态库
    -- ============================================
    project "Utils"
        kind "StaticLib"
        language "C++"
        cppdialect "C++17"
        targetname "utils"

        files {
            "Source/Utils/include/**.h",
            "Source/Utils/src/**.cpp"
        }

        includedirs {
            "Source/Utils/include"
        }

        filter { "system:windows" }
            systemversion "latest"
            staticruntime "On"

        filter { "system:linux" }
            buildoptions { "-Wall", "-Wextra" }

        filter {}

    -- ============================================
    -- LineServer 可执行文件
    -- ============================================
    project "LineServer"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        targetname "lineserver"

        files {
            "Source/LineServer/include/**.h",
            "Source/LineServer/src/**.cpp"
        }

        includedirs {
            "Source/LineServer/include",
            "Source/Utils/include"
        }

        links {
            "Utils"
        }

        filter { "system:windows" }
            systemversion "latest"
            staticruntime "On"
            links { "ws2_32" }

        filter { "system:linux" }
            buildoptions { "-Wall", "-Wextra" }

        filter {}