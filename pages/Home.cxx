#include "Home.hxx"
#include "Div.hxx"
#include "ParagraphText.hxx"
#include "DivRow.hxx"
#include "AText.hxx"
#include "Size.hxx"
#include "Markdown.hxx"
#include "Blog.hxx"
#include "MarkdownBlog.hxx"
#include "Header.hxx"

#include "UnorderedList.hxx"
#include "ListItem.hxx"

c5p::Home::Home(const Site& site)
:
    DocumentImpl(site)
{
    head().add_meta("keywords", "Matvey Kraposhin, C++, SDN, OpenSDN, Tungsten Fabric, OpenFOAM, FVM");
    ParagraphText txt_hi ("Welcome to my personal site.");

    ParagraphText txt_about ("This resource is about my professional experience"
    " and interests, they are: "
    " open source software, software development with C++, Tungsten Fabric SDN,"
    " computational analysis of fluids & gases motion.");

    ParagraphText txt_blog("You can find news, list of resources and short notes "
    "about open source software in the blog below."
    " If you have any ideas for sharing or about collaboration,"
    " please feel free to contact me.");

    Header<2> head_notes ("Notes & news");
    Blog blog1;

    body().jscript(*blog1.jscript());

    const std::vector<std::string> md_titles =
        {
            "New OpenSDN IPv6 capabilities",
            "The First Release Of OpenSDN",
            "Implementation of NAT66 (IPv6 NAT) in Tungsten Fabric",
            "The Internal Structure of Route Tables of Tungsten Fabric vRouter Agent",
            "NAT and VxLAN in Tungsten Fabric",
            "Abbreviations",
            "Markdown Rendering Using HTML",
            "Developers And Testers Forum June 2023",
            "Tungsten Fabric Ports",
            "Disable Loading Of vrouter.ko On Boot",
            "List Of Tungsten Fabric Resources",
            "Compilation Of Tungsten Fabric R2011 From Source On CentOS 8",
            "Compilation Of Tungsten Fabric R2011 From Source On Ubuntu 20.04"
        };
    MarkdownBlog md_blog {"../md", md_titles};

    Div& mid_col = layout().operator()<Div>(1);
    mid_col.add(txt_hi);
    mid_col.add(txt_about);
    mid_col.add(txt_blog);
    mid_col.add(head_notes);
    mid_col.add(md_blog);
}
//
//END-OF-FILE
//

