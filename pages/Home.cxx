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
    ParagraphText txt_hi ("Ahoy and welcome to a personal page showcasing "
        "my professional experience and interests! These include, but are "
        "not limited to: open source software, software development with C++, "
        "OpenSDN (Tungsten Fabric SDN), and computational analysis of fluid "
        "and gas motion.");

    ParagraphText txt_blog("You might find the news, resources, and short "
        "notes about open source software in the blog below useful. If you "
        "have any ideas for sharing information or collaboration, please "
        "feel free to contact me.");

    Header<2> head_notes ("Notes & news");
    Blog blog1;

    body().jscript(*blog1.jscript());

    const std::vector<std::string> md_titles =
        {
            "The OpenSDN transition to Rocky9",
            "10th Anniversary of Hybrid Central Solvers",
            "OpenSDN vRouter Forwarder flows tutorial",
            "Basic OpenSDN vRouter Forwarder Tutorial",
            "CFD programs verification and validation automation using GitHub and OpenFOAM",
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
    mid_col.add(txt_blog);
    mid_col.add(head_notes);
    mid_col.add(md_blog);
}
//
//END-OF-FILE
//

