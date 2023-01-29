#include "ProfExperience.hxx"
#include "ParagraphText.hxx"
#include "DivColumn.hxx"

krap::ProfExperience::ProfExperience(const Site& site)
:
    DocumentImpl(site)
{
    ParagraphText txt ("ProfExperience");

    ParagraphText txt_nrcki("2006 - 2014: National Research Center"
    " \"Kurchatow institute\": engineer, junior researcher, researcher"
    " head of a laboratory");

    ParagraphText txt_ispras("2015 - 2022: Institute for system programming"
    " of the RAS: senior researcher, head of a laboratory");

    DivColumn div_col;

    div_col.add(txt_nrcki);
    div_col.add(txt_ispras);

    Div& mid_col = layout().operator()<Div>(1);
    //mid_col.add(txt_nrcki);
    // //body().add(txt);
    mid_col.add(div_col);
}

//
//END-OF-FILE
//

