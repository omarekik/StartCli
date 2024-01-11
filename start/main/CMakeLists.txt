project(Start)

find_package(Microsoft.GSL CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Configs
    Microsoft.GSL::GSL
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${Config_SOURCE_DIR}/include
)
