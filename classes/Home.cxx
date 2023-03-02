#include "Home.hxx"
#include "Div.hxx"
#include "ParagraphText.hxx"

krap::Home::Home(const Site& site)
:
    DocumentImpl(site)
{
    ParagraphText txtHi ("Hi! I'm Matvey Kraposhin and I'm extremely happy"
    " to see you here");

    ParagraphText txtAbout ("This site is about my professional experience,"
    " education, certification and professional interests. Main areas of my"
    " expertise are: open source software, software development with C++,"
    " computational analysis of fluids & gases motion.");//" I hope that provided"
    //" information would be helpful for you to estimate whether you need my"
    //" service");
    layout().operator()<Div>(1).add(txtHi);
    layout().operator()<Div>(1).add(txtAbout);
    //dynamic_cast<Div&>(layout()[1]).add(txt);
    //body().add(txt);
}
//
//END-OF-FILE
//

