cmake_minimum_required(VERSION 3.16)

project(FilterVisualizer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Charts)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Charts)

set(PROJECT_SOURCES
        src/filterviz.cpp
        include/filterviz.h
        include/filterviz_global.h
        src/filterwidget.cpp
        include/filterwidget.h
        src/filterwidget.ui
        src/filterwidget.qrc
)

add_library(filterviz SHARED
    ${PROJECT_SOURCES}
)

target_include_directories(filterviz PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(filterviz PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Charts)

target_compile_definitions(filterviz PRIVATE FILTERVIZ_LIBRARY)

install(TARGETS filterviz)
install(FILES ${PROJECT_SOURCE_DIR}/include/filterviz.h DESTINATION include)

add_subdirectory(example)
