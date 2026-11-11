cmake_minimum_required(VERSION 3.20)
project(c_se_lab C)

# Enforce strict ISO C11 standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Strict compiler warnings (Darnell & Margolis defensive C style)
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror -Wpedantic -Wshadow -Wconversion)
    # Enable AddressSanitizer and UndefinedBehaviorSanitizer on Linux/WSL/Clang
    if(UNIX)
        add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
        add_link_options(-fsanitize=address,undefined)
    endif()
endif()

# 1. Data Structures Library (src/ds)
add_library(c_ds STATIC
        src/ds/list.c
)
target_include_directories(c_ds PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 2. Design Patterns Library (src/patterns) - consumes c_ds
add_library(c_patterns STATIC
        src/patterns/event_bus.c
)
target_include_directories(c_patterns PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(c_patterns PUBLIC c_ds)

# 3. Unit Testing Setup (CTest)
enable_testing()

add_executable(test_list tests/test_list.c)
target_link_libraries(test_list PRIVATE c_ds)
add_test(NAME ListTestSuite COMMAND test_list)