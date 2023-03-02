#include "Contacts.hxx"
#include "ParagraphText.hxx"
#include "Uri.hxx"
#include "DivColumn.hxx"
#include "Sizes.hxx"

krap::Contacts::Contacts(const Site& site)
:
    DocumentImpl(site)
{
    const int width = 300;

    CSSClass contactsColClass ("contactsColClass");
    contactsColClass.add(Width(width));

    DivColumn div_col;

    ParagraphText txt_contacts {"You can reach me using these means: "};

    //ResearchGate
    ParagraphText txt_rg {
        Uri("https://www.researchgate.net/profile/Matvey-Kraposhin").
        html("ResearchGate account")};

    //Linkedin
    ParagraphText txt_linkedin {
        Uri("https://www.linkedin.com/in/matvey-kraposhin-413869163").
        html("Linkedin account")};

    //GitHub
    ParagraphText txt_github {
        Uri("https://github.com/mkraposhin").
        html("GitHub account")};

    //E-Mail

    //Telegram
    ParagraphText txt_telegram {
        Uri("https://t.me/kraposhin").
        html("Telegram account")};

    div_col % contactsColClass;
    div_col.add(txt_contacts);
    div_col.add(txt_rg);
    div_col.add(txt_linkedin);
    div_col.add(txt_github);
    div_col.add(txt_telegram);

    Div& mid_col = layout().operator()<Div>(1);
    mid_col.add(div_col);
}

//
//END-OF-FILE
//

