
set(LIB_NAME DetectCapital)
set(SOURCE_FILE DetectCapital.java)

add_jar(${LIB_NAME} ${SOURCE_FILE})

get_target_property(_jarFile ${LIB_NAME} JAR_FILE)
add_custom_target(DetectCapitalTest COMMAND ${Java_JAVA_EXECUTABLE} -cp ${_jarFile} DetectCapital)
#add_test(NAME DetectCapitalTest COMMAND ${Java_JAVA_EXECUTABLE} -cp ${_jarFile} DetectCapital)
