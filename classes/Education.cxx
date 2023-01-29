#include "Education.hxx"
#include "ParagraphText.hxx"
#include "DivColumn.hxx"

krap::Education::Education(const Site& site)
:
    DocumentImpl(site)
{
    ParagraphText txt ("Education");

    ParagraphText txt_mpei("2000 - 2006: National University"
    " \"Moscow Power Engineering Institute\": Nuclear Power Plants dept.,"
    " MSc");

    ParagraphText txt_kiam("2017: Keldysh institute of applied mathematics"
    " of the RAS, PhD");
    
    ParagraphText txt_cpp98 ("201X: C++ ISO98");
    ParagraphText txt_intro_nw ("2023: Introduction to Networks, EdX");


    DivColumn div_col;

    div_col.add(txt_mpei);
    div_col.add(txt_kiam);
    div_col.add(txt_cpp98);
    div_col.add(txt_intro_nw);

    Div& mid_col = layout().operator()<Div>(1);
    //mid_col.add(txt_nrcki);
    // //body().add(txt);
    mid_col.add(div_col);
}

//
//END-OF-FILE
//

