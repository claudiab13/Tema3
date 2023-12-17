cmake_minimum_required(VERSION 3.10)
project(OOPIntro VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory(lib)
add_executable(HM3 main.cpp)
target_link_libraries(HM3 PUBLIC HM3Lib)
target_include_directories(HM3 PUBLIC
                        "$(PROJECT_BINARY_DIR)"
                        "$(PROJECT_SOURCE_DIR/lib)"
                        )
