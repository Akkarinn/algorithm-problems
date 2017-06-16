cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME "algorithm-problems")
set(PLUGIN_PATH ${CMAKE_SOURCE_DIR}/build/bin)
set(CMAKE_JAVA_COMPILE_FLAGS "-source" "1.6" "-target" "1.6")
set(CMAKE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

project(${PROJECT_NAME})
enable_testing()

# Java component
find_package(Java COMPONENTS Runtime)
if(JAVA_FOUND)
    include(UseJava)
else()
    message(WARNING "Couldn't find Java")
endif()

# Scala plugin
find_jar(SCALA_JAR "scala-library-2.11.11" PATHS ${PLUGIN_PATH})
find_jar(JAR "scalactic_2.11-3.0.3" PATHS ${PLUGIN_PATH})
find_jar(JAR "scalatest_2.11-2.1.3" PATHS ${PLUGIN_PATH})
find_jar(JAR "scala-xml_2.11-1.0.6" PATHS ${PLUGIN_PATH})
message("Found Scala library: ${SCALA_JAR}")

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
