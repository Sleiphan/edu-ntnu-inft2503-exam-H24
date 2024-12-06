
set(EXECUTABLE "Run")
add_executable(${EXECUTABLE} Run.cpp)
target_link_libraries(${EXECUTABLE} ${LIBRARY})
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Task_5")
add_executable(${EXECUTABLE} Task_5.cpp)
target_link_libraries(${EXECUTABLE} ${LIBRARY})
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Task_6")
add_executable(${EXECUTABLE} Task_6.cpp)
target_link_libraries(${EXECUTABLE} ${LIBRARY})
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Task_7")
add_executable(${EXECUTABLE} Task_7.cpp)
target_link_libraries(${EXECUTABLE} ${LIBRARY})
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Task_8")
add_executable(${EXECUTABLE} Task_8.cpp)
target_link_libraries(${EXECUTABLE} ${LIBRARY})
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)

set(EXECUTABLE "Task_9")
add_executable(${EXECUTABLE} Task_9.cpp)
target_link_libraries(${EXECUTABLE} ${LIBRARY})
set_target_properties(${EXECUTABLE}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin
)