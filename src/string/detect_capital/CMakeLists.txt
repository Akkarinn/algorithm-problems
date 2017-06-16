
set(LIB DetectCapital)
set(SOURCE_FILES DetectCapital.scala)

add_jar(${LIB} ${SOURCE_FILES})

get_target_property(_jarFile ${LIB} JAR_FILE)
add_test(NAME ${LIB}Test COMMAND ${Java_JAVA_EXECUTABLE} -cp ${_jarFile} DetectCapital)
