#include "Education.hxx"
#include "ParagraphText.hxx"

krap::Education::Education(const Site& site)
:
    DocumentImpl(site)
{
    ParagraphText txt ("Education");
    body().add(txt); 
}

//
//END-OF-FILE
//

