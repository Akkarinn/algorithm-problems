
set(LIB fizz_buzz)
set(SOURCE_FILES main.cpp)

include_directories(${CMAKE_INCLUDE_DIR})
add_executable(${LIB} ${SOURCE_FILES})
add_test(NAME ${LIB} COMMAND ${CMAKE_CURRENT_DIR}/${LIB})
