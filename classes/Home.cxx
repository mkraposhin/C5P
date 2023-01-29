#include "Home.hxx"
#include "Div.hxx"
#include "ParagraphText.hxx"

krap::Home::Home(const Site& site)
:
    DocumentImpl(site)
{
    ParagraphText txt ("Home");
    layout().operator()<Div>(1).add(txt);
    //dynamic_cast<Div&>(layout()[1]).add(txt);
    //body().add(txt);
}
//
//END-OF-FILE
//

