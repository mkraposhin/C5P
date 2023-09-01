set(SOURCES ${SOURCES} Base/Debug.cxx)
set(SOURCES ${SOURCES} Base/Exception.cxx)
set(SOURCES ${SOURCES} Base/Element.cxx)
set(SOURCES ${SOURCES} Base/Compound.cxx)
set(SOURCES ${SOURCES} Base/Uri.cxx)

set(SOURCES ${SOURCES} Drafts/HtmlTag.cxx)
set(SOURCES ${SOURCES} Drafts/Markdown.cxx)

set(SOURCES ${SOURCES} CSS/CSSRegistry.cxx)
set(SOURCES ${SOURCES} CSS/CSSElement.cxx)
set(SOURCES ${SOURCES} CSS/CSSClass.cxx)
set(SOURCES ${SOURCES} CSS/AtRule.cxx)

set(SOURCES ${SOURCES} Derived/Document.cxx)
set(SOURCES ${SOURCES} Derived/Page.cxx)
set(SOURCES ${SOURCES} Derived/Head.cxx)
set(SOURCES ${SOURCES} Derived/CaptionedImage.cxx)
set(SOURCES ${SOURCES} Derived/DivColumn.cxx)
set(SOURCES ${SOURCES} Derived/DivRow.cxx)
set(SOURCES ${SOURCES} Derived/MainMenu.cxx)
set(SOURCES ${SOURCES} Derived/JScript.cxx)
set(SOURCES ${SOURCES} Derived/Blog.cxx)
set(SOURCES ${SOURCES} Derived/MarkdownBlog.cxx)
set(SOURCES ${SOURCES} Derived/BlogEntry.cxx)

set(SOURCES ${SOURCES} Globals.cxx)
set(SOURCES ${SOURCES} Site.cxx)
set(SOURCES ${SOURCES} DocumentImpl.cxx)
set(SOURCES ${SOURCES} Home.cxx)
set(SOURCES ${SOURCES} Education.cxx)
set(SOURCES ${SOURCES} ProfExperience.cxx)
set(SOURCES ${SOURCES} MyContributions.cxx)
set(SOURCES ${SOURCES} Contacts.cxx)

add_library(krap ${SOURCES})
target_include_directories(krap PRIVATE
    "${CgiCc_DIR}/include"
    "Base"
    "CSS"
    "Derived"
    "Drafts"
    "${CMAKE_SOURCE_DIR}/classes"
    "${MADDY_SRC}/include")
