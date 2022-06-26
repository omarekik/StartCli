project(Start)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Configs
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${Config_SOURCE_DIR}/include
)
