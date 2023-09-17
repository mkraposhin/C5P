#include "Blog.hxx"
#include "Exception.hxx"
#include "CSS.hxx"

void c5p::Blog::setup_css()
{
    title_css_class_.add(c5p::css::borderNone);
    title_css_class_.add(c5p::css::outlineNone);
    title_css_class_.add(c5p::css::width100perc);
    title_css_class_.add(css::font18px);
    title_css_class_.add(FontFamily{"Arial, sans-serif"});
    title_css_class_.add(c5p::css::textAlignLeft);

    contents_css_class_.add(c5p::css::displayNone);
    contents_css_class_.add(c5p::css::overflowHidden);
    contents_css_class_.add(c5p::css::width100perc);

    hover_css_class_.add(c5p::css::bcolorGray);
}

c5p::Blog::Blog()
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

c5p::Blog::Blog(const Blog& blog)
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

c5p::Blog::~Blog()
{
}

c5p::ElementPtr& c5p::Blog::add (const BlogEntry& be)
{
    return Compound::add(BlogEntry{be, title_css_class_, contents_css_class_});
}

c5p::JScriptPtr c5p::Blog::jscript() const
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


c5p::ElementPtr& c5p::Blog::add (const Element& elt)
{
    throw GenericException {"NotImplemented krap::Blog::add"};
    return Compound::add(elt);
}

c5p::ElementPtr& c5p::Blog::add (Element* eptr)
{
    throw GenericException {"NotImplemented krap::Blog::add"};
    return Compound::add(eptr);
}

// krap::ElementPtr& krap::Blog::add (ElementPtr& eptr)
// {
//     throw GenericException {"NotImplemented krap::Blog::add"};
//     return Compound::add(eptr);
// }

//
//END-OF-FILE
//

