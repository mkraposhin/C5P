set(SOURCES ${SOURCES} Home.cxx)
set(SOURCES ${SOURCES} Education.cxx)
set(SOURCES ${SOURCES} ProfExperience.cxx)
set(SOURCES ${SOURCES} MyContributions.cxx)
set(SOURCES ${SOURCES} Contacts.cxx)

add_library(c5p-pages ${SOURCES})
target_link_libraries(c5p-pages c5p-classes)
target_include_directories(c5p-pages PRIVATE
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
