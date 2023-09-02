set(FILES
        ${CMAKE_CURRENT_LIST_DIR}/common.cpp
        ${CMAKE_CURRENT_LIST_DIR}/core.cpp
        ${CMAKE_CURRENT_LIST_DIR}/widget.cpp
        ${CMAKE_CURRENT_LIST_DIR}/worker.cpp
)
target_sources(${PROJECT_NAME} PRIVATE ${FILES})