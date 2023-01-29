#include "Patents.hxx"
#include "ParagraphText.hxx"
#include "Image.hxx"
#include "CaptionedImage.hxx"

krap::Patents::Patents(const Site& site)
:
    DocumentImpl(site)
{
    //Constants
    const int patent_width  = 300;

    //Contents
    CaptionedImage pat_tvel_img {"photo_5332597018251608572_y.jpg"};
    pat_tvel_img.image().width(patent_width);
    std::string img1_txt ("State registration of a program for numerical"
    " modelling of interaction between liquid metal and gas in order to"
    " compute a droplet distribution properties of yilding metal powder");
    pat_tvel_img.caption(img1_txt);

    CaptionedImage pat_acostic_img{"2017660047.jpg"};
    pat_acostic_img.image().width(patent_width);
    std::string img2_txt ("State registration of a program for numerical"
    " analysis of a far-field acoustics"
    );
    pat_acostic_img.caption(img2_txt);

    CaptionedImage pat_hcs{"2017660155.jpg"};
    pat_hcs.image().width(patent_width);
    std::string img3_txt ("State registration of a program for numerical"
    " of compressible flows in a wide range of Mach number value");
    pat_hcs.caption(img3_txt);

    CaptionedImage pat_qgd{"2018663951.jpg"};
    pat_qgd.image().width(patent_width);
    std::string img4_txt ("State registration of a program for numerical"
    " modelling of viscous gas flows using regularized gas dynamics equations"
    " (QGD)");
    pat_qgd.caption(img4_txt);

    Div& mid_col = layout().operator()<Div>(1);

    mid_col.add(pat_tvel_img);
    mid_col.add(pat_acostic_img);
    mid_col.add(pat_hcs);
    mid_col.add(pat_qgd);
}

//
//END-OF-FILE
//

