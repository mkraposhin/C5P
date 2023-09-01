#include "Home.hxx"
#include "Div.hxx"
#include "ParagraphText.hxx"
#include "DivRow.hxx"
#include "AText.hxx"
#include "Sizes.hxx"
#include "Markdown.hxx"
#include "Blog.hxx"
#include "MarkdownBlog.hxx"

krap::Home::Home(const Site& site)
:
    DocumentImpl(site)
{
    ParagraphText txtHi ("Hi! I'm Matvey Kraposhin and I'm extremely happy"
    " to see you here.");

    ParagraphText txtAbout ("This site is about my professional experience,"
    " education, certification and professional interests. Main areas of my"
    " expertise are: open source software, software development with C++,"
    " computational analysis of fluids & gases motion.");//" I hope that provided"
    //" information would be helpful for you to estimate whether you need my"
    //" service");

    DivRow row_0;
    row_0.add(txtHi);
    row_0.add(txtAbout);

    CSSClass row_0_css {"greet_wcss"};
    row_0_css.add(MaxWidth(600));
    row_0.row_css(row_0_css);

    Blog blog1;

    body().jscript(*blog1.jscript());

    ParagraphText pTxt1 {"Paragraph Text 1"};
    ParagraphText pTxt2 {"Paragraph Text 2"};
    Div div1; div1.add(pTxt1);
    Div div2; div2.add(pTxt2);
    BlogEntry be1{"Blog entry 1", div1};
    BlogEntry be2{"Blog entry 2", div2};
    blog1.add(be1);
    blog1.add(be2);

    Markdown file_md;
    file_md.set_file("../md/main.md");

    const std::vector<std::string> md_titles =
        {
            "Developers And Testers Forum June 2023",
            "Tungsten Fabric Ports"
        };
    MarkdownBlog md_blog {"../md", md_titles};

    layout().operator()<Div>(1).add(row_0);
    layout().operator()<Div>(1).add(file_md);
    layout().operator()<Div>(1).add(blog1);
    layout().operator()<Div>(1).add(md_blog);
    // layout().operator()<Div>(1).add(txtHi);
    // layout().operator()<Div>(1).add(txtAbout);
    // layout().operator()<Div>(1).add(row_1);
    //dynamic_cast<Div&>(layout()[1]).add(txt);
    //body().add(txt);
}
//
//END-OF-FILE
//

