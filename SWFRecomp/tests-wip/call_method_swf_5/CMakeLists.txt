cmake_minimum_required(VERSION 3.10)

project(call_method_swf_5)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "${ORIGIN}")

# Runtime includes
set(RUNTIME_INCLUDES
    ${CMAKE_SOURCE_DIR}/../../../SWFModernRuntime/include
    ${CMAKE_SOURCE_DIR}/../../../SWFModernRuntime/include/actionmodern
    ${CMAKE_SOURCE_DIR}/../../../SWFModernRuntime/include/libswf
)

# Main test executable
add_executable(${PROJECT_NAME})

set(SOURCES
    ${CMAKE_SOURCE_DIR}/main.c
)

# Find the runtime library
set(SWF_RUNTIME_LIB ${CMAKE_SOURCE_DIR}/../../../SWFModernRuntime/build/libSWFModernRuntime.a)

if(NOT EXISTS ${SWF_RUNTIME_LIB})
    message(FATAL_ERROR "SWFModernRuntime library not found at ${SWF_RUNTIME_LIB}. Please build it first.")
endif()

message(STATUS "Found SWFModernRuntime: ${SWF_RUNTIME_LIB}")

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${SWF_RUNTIME_LIB}
    m  # math library
    pthread  # threading support
)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${RUNTIME_INCLUDES}
)
