add_executable(home.cgi home.cxx)
install(TARGETS home.cgi DESTINATION cgi-bin)

target_link_libraries(home.cgi c5p-pages)

target_include_directories(home.cgi PRIVATE
"${PROJECT_SOURCE_DIR}/pages"
"${PROJECT_SOURCE_DIR}/classes/Css/Base"
"${PROJECT_SOURCE_DIR}/classes/Css/Definitions"
"${PROJECT_SOURCE_DIR}/classes/Css/Derived"
"${PROJECT_SOURCE_DIR}/classes/SiteParts"
"${PROJECT_SOURCE_DIR}/classes/HtmlTags/Base"
"${PROJECT_SOURCE_DIR}/classes/HtmlTags/Attributes"
"${PROJECT_SOURCE_DIR}/classes/HtmlTags/Derived"
"${PROJECT_SOURCE_DIR}/classes/Base"
"${PROJECT_SOURCE_DIR}/classes/Globals"
"${PROJECT_SOURCE_DIR}/classes/Utils"
"${CgiCc_DIR}/include")


