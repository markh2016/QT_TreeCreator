cmake_minimum_required(VERSION 3.12)

project(TreeCreator)

set(CMAKE_CXX_STANDARD 17)

# Find required Qt packages
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

# Add the main executable
add_executable(${PROJECT_NAME} source/main.cpp)

# Link against Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)
