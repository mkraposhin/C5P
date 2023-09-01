#include "Blog.hxx"
#include "Exception.hxx"
#include "CSSGlobals.hxx"

void krap::Blog::setup_css()
{
    title_css_class_.add(krap::css::borderNone);
    title_css_class_.add(krap::css::outlineNone);

    contents_css_class_.add(krap::css::displayNone);
    contents_css_class_.add(krap::css::overflowHidden);

    hover_css_class_.add(krap::css::bcolorGray);
}

krap::Blog::Blog()
:
    Div(),
    title_css_class_("title_css_class"),
    contents_css_class_("contents_css_class"),
    hover_css_class_("active, ." + title_css_class_.name() + ":hover")
{
    setup_css();

    // Add empty div to publish hover css class
    Div hoverDiv1;
    hoverDiv1 % hover_css_class_;
    Compound::add(hoverDiv1);
}

krap::Blog::Blog(const Blog& blog)
:
    Div(blog),
    title_css_class_("title_css_class"),
    contents_css_class_("contents_css_class"),
    hover_css_class_("active, ." + title_css_class_.name() + ":hover")
{
    setup_css();

    // Add empty div to publish hover css class
    Div hoverDiv1;
    hoverDiv1 % hover_css_class_;
    Compound::add(hoverDiv1);
}

krap::Blog::~Blog()
{
}

krap::ElementPtr& krap::Blog::add (const BlogEntry& be)
{
    return Compound::add(BlogEntry{be, title_css_class_, contents_css_class_});
}

krap::JScriptPtr krap::Blog::jscript() const
{
    return JScriptPtr
    {
        new JScript
        {
            "",
            "var coll = document.getElementsByClassName(\""+title_css_class_.name()+"\");\n"
            "var i;\n"
            "\n"
            "for (i = 0; i < coll.length; i++) {\n"
            "coll[i].addEventListener(\"click\", function() {\n"
            "    this.classList.toggle(\"active\");\n"
            "    var content = this.nextElementSibling;\n"
            "    if (content.style.display === \"block\") {\n"
            "    content.style.display = \"none\";\n"
            "    } else {\n"
            "    content.style.display = \"block\";\n"
            "    }\n"
            "});\n"
            "}\n"
        }
    };
}


krap::ElementPtr& krap::Blog::add (const Element& elt)
{
    throw GenericException {"NotImplemented krap::Blog::add"};
    return Compound::add(elt);
}

krap::ElementPtr& krap::Blog::add (Element* eptr)
{
    throw GenericException {"NotImplemented krap::Blog::add"};
    return Compound::add(eptr);
}

krap::ElementPtr& krap::Blog::add (ElementPtr& eptr)
{
    throw GenericException {"NotImplemented krap::Blog::add"};
    return Compound::add(eptr);
}

//
//END-OF-FILE
//

