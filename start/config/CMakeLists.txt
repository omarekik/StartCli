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

#Compilers will not issue warnings from header files originating from SYSTEM
#Header files will generate warning within the library project
#Header files will not generate warning when used by other project
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} SYSTEM INTERFACE ${PROJECT_SOURCE_DIR}/include)

set_target_properties (${PROJECT_NAME}
    PROPERTIES
        CXX_CLANG_TIDY "${clang_tidy_cmd}"
)

target_compile_options (${PROJECT_NAME} PRIVATE
    ${compiler_warnings}
)
