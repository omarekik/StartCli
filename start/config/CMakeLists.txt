project(Configs)

add_subdirectory(tests)

find_package(Boost COMPONENTS boost program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(HEADERS
    ${PROJECT_SOURCE_DIR}/include/StartupConfig.h
)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/StartupConfig.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PUBLIC
    Boost::boost Boost::program_options
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties (${PROJECT_NAME}
    PROPERTIES
        CXX_CLANG_TIDY "${clang_tidy_cmd}"
)

target_compile_options (${PROJECT_NAME} PRIVATE
    ${compiler_warnings}
)
