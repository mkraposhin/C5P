add_executable(home.cgi home.cxx)
install(TARGETS home.cgi DESTINATION cgi-bin)

target_link_libraries(home.cgi PRIVATE krap ${CgiCc_DIR}/lib/libcgicc.a)

target_include_directories(home.cgi PRIVATE
    "${PROJECT_SOURCE_DIR}/classes"
    "${CgiCc_DIR}/include"
    )


