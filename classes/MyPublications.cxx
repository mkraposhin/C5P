#include "MyPublications.hxx"
#include "AText.hxx"

krap::MyPublications::MyPublications(const Site& site)
:
    DocumentImpl(site)
{
    AText txt_pubs {"A list of my publications counts ~60 items, they are"
    " listed on the Google scholar page"};
    txt_pubs.uri("https://scholar.google.com/citations?user=dNIvricAAAAJ&hl=ru");

    Div& mid_col = layout().operator()<Div>(1);
    mid_col.add(txt_pubs);
}

//
//END-OF-FILE
//