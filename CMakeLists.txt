# Copyright (c) 2020 Tom Hancocks
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(Diamane VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/bin")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")


# OpenGL
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLFW3_INCLUDE_DIRS})
include_directories(submodules/glm)

# libDiamane
include_directories(${CMAKE_SOURCE_DIR})
file(GLOB_RECURSE libDiamaneSources
    libDiamane/*.cpp
)
add_library(Diamane ${libDiamaneSources})
target_link_libraries(Diamane ${OPENGL_LIBRARIES} glfw)

# Test App
file(GLOB_RECURSE DiamaneTestSources
    DiamaneTest/*.cpp
)
add_executable(DiamaneTest ${DiamaneTestSources})
target_link_libraries(DiamaneTest Diamane)

# macOS Specific
if(APPLE)
    add_custom_command(TARGET DiamaneTest
        POST_BUILD
        COMMAND rm -rf "${CMAKE_BINARY_DIR}/DiamaneTest.app"
        COMMAND mkdir -p "${CMAKE_BINARY_DIR}/DiamaneTest.app/Contents/MacOS"
        COMMAND mkdir -p "${CMAKE_BINARY_DIR}/DiamaneTest.app/Contents/Resources"
        COMMAND cp "${CMAKE_BINARY_DIR}/DiamaneTest" "${CMAKE_BINARY_DIR}/DiamaneTest.app/Contents/MacOS/DiamaneTestApp"
    )
endif(APPLE)
