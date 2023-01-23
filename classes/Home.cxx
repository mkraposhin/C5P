#include "Home.hxx"
#include "ParagraphText.hxx"

krap::Home::Home(const Site& site)
:
    DocumentImpl(site)
{
    ParagraphText txt ("Home");
    body().add(txt);
}
//
//END-OF-FILE
//

