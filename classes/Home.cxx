#include "Home.hxx"
#include "Div.hxx"
#include "ParagraphText.hxx"
#include "DivRow.hxx"
#include "AText.hxx"
#include "Sizes.hxx"
#include "Markdown.hxx"

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

    // //std::view ??? 
    // DivRow row_1;
    // ParagraphText txt_col1 {"Col1"};
    // ParagraphText txt_col2 {"Col2"};
    // ParagraphText txt_col3 {"Col3"};
    // ParagraphText txt_col4 {"Col4"};
    // row_1.add(txt_col1);
    // row_1.add(txt_col2);
    // row_1.add(txt_col3);
    // row_1.add(txt_col4);
    // row_1.cell_width(200);

    Markdown file_md;
    file_md.set_file("../md/main.md");

    layout().operator()<Div>(1).add(row_0);
    layout().operator()<Div>(1).add(file_md);
    // layout().operator()<Div>(1).add(txtHi);
    // layout().operator()<Div>(1).add(txtAbout);
    // layout().operator()<Div>(1).add(row_1);
    //dynamic_cast<Div&>(layout()[1]).add(txt);
    //body().add(txt);
}
//
//END-OF-FILE
//

