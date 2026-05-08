# 这个makefile负责cmake相关的生成和编译操作，premake相关操作请自行编写脚本
.PHONY: debug release Debug-compile Release-compile clean
# 生成debug版本工程文件并在项目根目录建软连接
debug:
	cmake -B build -DCMAKE_BUILD_TYPE=Debug
	ln -sf build/compile_commands.json .
# 生成release版本工程文件并在项目根目录建软连接
release:
	cmake -B build -DCMAKE_BUILD_TYPE=Release
	ln -sf build/compile_commands.json .
# 编译debug版本并在项目根目录建软连接
Debug-compile: debug
	cmake --build build
	ln -sf out/Debug/bin/LineServer .
# 编译release版本并在项目根目录建软连接
Release-compile: release
	cmake --build build
	ln -sf out/Release/bin/LineServer .
# 清理生成目录
clean:
	rm -rf build out
	rm -f compile_commands.json
	rm -f LineServer