# 必要 CMake バージョン
cmake_minimum_required(VERSION 3.12)
# プロジェクト名
project(ASCII-picture-translator)

# c++コンパイラーバージョン指定
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 必要ライブラリ
find_package(OpenCV REQUIRED)

# ビルド
add_executable(${PROJECT_NAME} main.cpp)
# ライブラリパス指定
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})