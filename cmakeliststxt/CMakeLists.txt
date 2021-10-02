# CMakeLists.txt
cmake_minimum_required(VERSION 3.1)
project(print-version CXX)

set(wxWidgets_USE_LIBS)
find_package(wxWidgets)
include(${wxWidgets_USE_FILE})

include_directories(${wxWidgets_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} "${PROJECT_NAME}.cpp")

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
