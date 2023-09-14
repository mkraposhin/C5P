
set(SOURCES ${SOURCES} Home.cxx)
set(SOURCES ${SOURCES} Education.cxx)
set(SOURCES ${SOURCES} ProfExperience.cxx)
set(SOURCES ${SOURCES} MyContributions.cxx)
set(SOURCES ${SOURCES} Contacts.cxx)

add_library(krap-pages ${SOURCES})
target_link_libraries(krap-pages krap-classes)
target_include_directories(krap-pages PRIVATE
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
