add_executable(home.cgi home.cxx)
install(TARGETS home.cgi DESTINATION cgi-bin)

target_link_libraries(home.cgi krap ${CgiCc_DIR}/lib/libcgicc.a ${MD4C_LIB_DIR}/libmd4c-html.a ${MD4C_LIB_DIR}/libmd4c.a)

target_include_directories(home.cgi PRIVATE
    "${PROJECT_SOURCE_DIR}/classes"
    "${PROJECT_SOURCE_DIR}/classes/Base"
    "${PROJECT_SOURCE_DIR}/classes/Drafts"
    "${PROJECT_SOURCE_DIR}/classes/Derived"
    "${PROJECT_SOURCE_DIR}/classes/CSS"
    "${CgiCc_DIR}/include"
    )


