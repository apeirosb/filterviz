set(PROJECT_SOURCES
        main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(example
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(example
    ${PROJECT_SOURCES}
    )
endif()

target_include_directories(example PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(example PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Charts)
target_link_libraries(example PRIVATE filterviz)

install(TARGETS example)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(example)
endif()
