cmake_minimum_required(VERSION 3.26)
project(qt_test)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#MSVC 发布添加debug信息
if (MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "-Od -Zi -MD")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/INCREMENTAL:NO /DEBUG")
endif (MSVC)
#check assert
if (CMAKE_BUILD_TYPE MATCHES "Debug" OR QT_FORCE_ASSERTS)
    message(INFO, "open assert -> ${CMAKE_BUILD_TYPE}${QT_FORCE_ASSERTS}")
ELSE ()
    message(INFO, "close assert -> ${CMAKE_BUILD_TYPE}${QT_FORCE_ASSERTS}")
    add_definitions(-DNDEBUG)
endif ()

# 目录拆分
set(TARGET_UTILS utilsPlugin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#
#输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
# qt 配置
set(CMAKE_PREFIX_PATH "F:/BaiduNetdiskDownload/qt-opensource-windows-x86-5.14.1/qt-opensource-windows-x86-5.14.1/5.14.1/msvc2017")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_LIBS Core
        Gui
        Widgets
        Network
        Quick
        QuickWidgets
        WebEngineWidgets
        WebChannel
        WebSockets
        Multimedia
        Xml
        Svg)
set(QT_LIBS_LINK Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Network
        Qt5::Quick
        Qt5::QuickWidgets
        Qt5::WebEngineWidgets
        Qt5::WebChannel
        Qt5::WebSockets
        Qt5::Multimedia
        Qt5::Xml
        Qt5::Svg)
find_package(Qt5 COMPONENTS ${QT_LIBS})
find_package(QT5 COMPONENTS ${QT_LIBS} REQUIRED)
add_definitions(-DQT_MESSAGELOGCONTEXT)
if (${QY_FORCE_ASSERTS})
    add_definitions(-DQT_FORCE_ASSERTS)
endif ()

#资源文件
include_directories(source)
include_directories(utils)
add_executable(${PROJECT_NAME} WIN32 "")

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "test")

target_sources(${PROJECT_NAME} PRIVATE "")

add_subdirectory(source)
add_subdirectory(utils)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})
target_compile_definitions(${PROJECT_NAME} PRIVATE BUILD_IMPORT)

target_link_libraries(${PROJECT_NAME} ${QT_LIBS_LINK})

#
if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()


