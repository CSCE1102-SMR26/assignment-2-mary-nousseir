cmake_minimum_required(VERSION 3.16)

set(QCORO_WITH_QTQML OFF CACHE BOOL "" FORCE)
set(QCORO_WITH_QTQUICK OFF CACHE BOOL "" FORCE)
set(QCORO_WITH_QTWEBSOCKETS OFF CACHE BOOL "" FORCE)
set(QCORO_WITH_QTDBUS OFF CACHE BOOL "" FORCE)
set(QCORO_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(QCORO_BUILD_TESTING OFF CACHE BOOL "" FORCE)

set(Qt6Qml_FOUND FALSE CACHE BOOL "" FORCE)
set(Qt6Quick_FOUND FALSE CACHE BOOL "" FORCE)

project(ClientChat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets Network)

include(FetchContent)
FetchContent_Declare(
  QCoro
  GIT_REPOSITORY https://github.com/danvratil/qcoro.git
  GIT_TAG v0.13.0
)
FetchContent_MakeAvailable(QCoro)

add_executable(ClientChat main.cpp client.cpp client.h client.ui)

target_link_libraries(ClientChat PRIVATE 
    Qt6::Widgets 
    Qt6::Network
    QCoro6::Core
    QCoro6::Network
)