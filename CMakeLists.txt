cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

### Definitions
set(PROJECT_NAME cpp_sdl_template)
set(OUTPUT_NAME ${PROJECT_NAME}.out)
project( ${PROJECT_NAME} VERSION 1.0)

### Dependencies
add_subdirectory(libs/SDL3 EXCLUDE_FROM_ALL)

include_directories("game"
                    )

set(SOURCE_FILES
    main.cpp
    game/Game.cpp
    )


add_executable( ${OUTPUT_NAME} ${SOURCE_FILES} )
target_compile_options( ${OUTPUT_NAME} PRIVATE -Wall -Werror )
target_link_libraries(${OUTPUT_NAME} PRIVATE SDL3::SDL3)