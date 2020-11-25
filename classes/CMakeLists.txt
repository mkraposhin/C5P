set(SOURCES ${SOURCES} Element.cxx)
set(SOURCES ${SOURCES} Compound.cxx)
set(SOURCES ${SOURCES} Document.cxx)
set(SOURCES ${SOURCES} Page.cxx)
set(SOURCES ${SOURCES} Head.cxx)
set(SOURCES ${SOURCES} ParagraphText.cxx)
set(SOURCES ${SOURCES} Title.cxx)

add_library(krap ${SOURCES})

target_include_directories(krap PRIVATE "${CgiCc_DIR}/include")
