workspace "LineServer"
    configurations { "Debug", "Release" }
    platforms { "x64" }
    location "_build"
    startproject "LineServer"

    -- 输出目录（与 CMake 的 _out 对应）
    targetdir "_out/%{cfg.buildcfg}/bin"
    objdir "_out/%{cfg.buildcfg}/obj"

    -- ============================================
    -- Utils 静态库
    -- ============================================
    project "Utils"
        kind "StaticLib"
        language "C++"
        cppdialect "C++17"
        targetname "Utils"

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

        filter { "configurations:Debug" }
            symbols "On"
            optimize "Off"

        filter { "configurations:Release" }
            symbols "Off"
            optimize "Speed"

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
            links { "pthread" }

        filter { "configurations:Debug" }
            symbols "On"
            optimize "Off"

        filter { "configurations:Release" }
            symbols "Off"
            optimize "Speed"

        filter {}