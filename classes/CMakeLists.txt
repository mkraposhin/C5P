set(SOURCES ${SOURCES} Globals/Globals.cxx)

set(SOURCES ${SOURCES} Base/Debug.cxx)
set(SOURCES ${SOURCES} Base/Exception.cxx)
set(SOURCES ${SOURCES} Base/Element.cxx)
set(SOURCES ${SOURCES} Base/Compound.cxx)
set(SOURCES ${SOURCES} Base/HtmlTag.cxx)

set(SOURCES ${SOURCES} Css/Base/CSSRegistry.cxx)
set(SOURCES ${SOURCES} Css/Base/CSSElement.cxx)
set(SOURCES ${SOURCES} Css/Base/CSSClass.cxx)
set(SOURCES ${SOURCES} Css/Base/AtRule.cxx)
set(SOURCES ${SOURCES} Css/Definitions/CSS.cxx)
set(SOURCES ${SOURCES} Css/Definitions/Classes.cxx)
set(SOURCES ${SOURCES} Css/Definitions/Geometries.cxx)
set(SOURCES ${SOURCES} Css/Definitions/Colors.cxx)
set(SOURCES ${SOURCES} Css/Definitions/FontSizes.cxx)
set(SOURCES ${SOURCES} Css/Definitions/FontStyles.cxx)

set(SOURCES ${SOURCES} Utils/Uri.cxx)
set(SOURCES ${SOURCES} Utils/Markdown.cxx) #(it will be better to split Markdown into Tag and renderer)

set(SOURCES ${SOURCES} HtmlTags/Base/JScript.cxx)
set(SOURCES ${SOURCES} HtmlTags/Derived/Page.cxx)
set(SOURCES ${SOURCES} HtmlTags/Derived/Head.cxx)
set(SOURCES ${SOURCES} HtmlTags/Derived/Document.cxx)
set(SOURCES ${SOURCES} HtmlTags/Derived/CaptionedImage.cxx)
set(SOURCES ${SOURCES} HtmlTags/Derived/DivColumn.cxx)
set(SOURCES ${SOURCES} HtmlTags/Derived/DivRow.cxx)
set(SOURCES ${SOURCES} HtmlTags/Derived/Blog.cxx)
set(SOURCES ${SOURCES} HtmlTags/Derived/BlogEntry.cxx)
set(SOURCES ${SOURCES} HtmlTags/Derived/MarkdownBlog.cxx)

set(SOURCES ${SOURCES} SiteParts/MainMenu.cxx)
set(SOURCES ${SOURCES} SiteParts/DocumentImpl.cxx)
set(SOURCES ${SOURCES} SiteParts/Site.cxx)

add_library(c5p-classes ${SOURCES})
target_link_libraries(c5p-classes ${CgiCc_DIR}/lib/libcgicc.a ${MD4C_LIB_DIR}/libmd4c-html.a ${MD4C_LIB_DIR}/libmd4c.a)
target_include_directories(c5p-classes PRIVATE
    "Globals"
    "Base"
    "Css/Base"
    "Css/Definitions"
    "Css/Derived"
    "Utils"
    "HtmlTags/Base"
    "HtmlTags/Attributes"
    "HtmlTags/Derived"
    "SiteParts"
    "${CgiCc_DIR}/include"
    "${MADDY_SRC}/include"
    "${MD4C_INC_DIR}")
#    "${CMAKE_SOURCE_DIR}/classes"
