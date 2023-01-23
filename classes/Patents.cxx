#include "Patents.hxx"
#include "ParagraphText.hxx"
#include "Image.hxx"

krap::Patents::Patents(const Site& site)
:
    DocumentImpl(site)
{
    ParagraphText txt ("Patents");
    body().add(txt);

    Image pat_tvel_img{"photo_5332597018251608572_y.jpg"};
    body().add(pat_tvel_img);
}

//
//END-OF-FILE
//

