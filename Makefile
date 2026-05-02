.PHONY: debug release Debug-compile Release-compile clean
# 生成debug版本工程文件并在项目根目录建软连接
debug:
	cmake -B _build -DCMAKE_BUILD_TYPE=Debug
	ln -sf _build/compile_commands.json .
# 生成release版本工程文件并在项目根目录建软连接
release:
	cmake -B _build -DCMAKE_BUILD_TYPE=Release
	ln -sf _build/compile_commands.json .
# 编译debug版本并在项目根目录建软连接
Debug-compile:
	cmake --build _build
	ln -sf _out/Debug/bin/LineServer .
# 编译release版本并在项目根目录建软连接
Release-compile:
	cmake --build _build
	ln -sf _out/Release/bin/LineServer .
# 清理生成目录
clean:
	rm -rf _build _out
	rm -f compile_commands.json
	rm -f LineServer