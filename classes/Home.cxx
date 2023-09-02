#include "Home.hxx"
#include "Div.hxx"
#include "ParagraphText.hxx"
#include "DivRow.hxx"
#include "AText.hxx"
#include "Sizes.hxx"
#include "Markdown.hxx"
#include "Blog.hxx"
#include "MarkdownBlog.hxx"
#include "Header.hxx"

krap::Home::Home(const Site& site)
:
    DocumentImpl(site)
{
    Header<2> head_techn ("Hello!");
    ParagraphText txt_hi ("I'm Matvey Kraposhin and this is my personal site."
    " I hope you'll find it useful.");

    ParagraphText txt_about ("This resource is about my professional experience,"
    " and interests. Main areas of my expertise are: "
    " open source software, software development with C++ (the site is assemblied using this language),"
    " computational analysis of fluids & gases motion.");

    ParagraphText txt_blog("You can find news, list of resources and short notes "
    "about open source in the blog below."
    " If you have any ideas for sharing or about collaboration,"
    " please feel free to contact me.");

    Header<2> head_notes ("Notes & news");
    Blog blog1;

    body().jscript(*blog1.jscript());

    const std::vector<std::string> md_titles =
        {
            "Developers And Testers Forum June 2023",
            "Tungsten Fabric Ports",
            "Disable Loading Of vrouter.ko On Boot",
            "List Of Tungsten Fabric Resources",
            "Compilation Of Tungsten Fabric R2011 From Source On CentOS 8",
            "Compilation Of Tungsten Fabric R2011 From Source On Ubuntu 20.04"
        };
    MarkdownBlog md_blog {"../md", md_titles};

    Div& mid_col = layout().operator()<Div>(1);
    mid_col.add(head_techn);
    mid_col.add(txt_hi);
    mid_col.add(txt_about);
    mid_col.add(txt_blog);
    mid_col.add(head_notes);
    mid_col.add(md_blog);
}
//
//END-OF-FILE
//

