set(TARGET_NAME ${PROJECT_NAME})
target_compile_definitions(${PROJECT_NAME} PRIVATE BUILD_IMPORT)
add_subdirectory(qt_html)
add_subdirectory(qt_qml_test)
add_subdirectory(qt_ui_test)
set(FILES
        ${CMAKE_CURRENT_LIST_DIR}/mainWidget.cpp
        ${CMAKE_CURRENT_LIST_DIR}/mainWindow.cpp
)

set(RESOURCES
        resource/qml.qrc
        resource/images.qrc
        resource/qss.qrc
        resource/html.qrc
        resource/src/react/app/build/build.qrc
)

target_sources(${PROJECT_NAME} PRIVATE ${FILES} ${RESOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CAMK_CURRRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/utils)
#公共静态文件导入
if (WIN32)
    set(UTILS_LIB ${CMAKE_BINARY_DIR}/lib/utilsPlugin.lib)
else ()
    set(UTILS_LIB ${CMAKE_BINARY_DIR}/lib/utilsPlugin.so)
endif ()

target_link_libraries(${PROJECT_NAME} ${QT_LIBS_LINK} ${UTILS_LIB})
