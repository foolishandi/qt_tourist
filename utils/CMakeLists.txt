#静态文件导出
set(TARGET_NAME ${TARGET_UTILS})
add_library(${TARGET_UTILS} STATIC "")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_subdirectory(core)
add_subdirectory(sub_dir)
set(SOURCE_FILES utils.cpp)
target_sources(${TARGET_UTILS} PRIVATE ${SOURCE_FILES})

target_include_directories(${TARGET_UTILS} PUBLIC ${CAMK_CURRRENT_SOURCE_DIR})
target_link_libraries(${TARGET_UTILS} ${QT_LIBS_LINK})

