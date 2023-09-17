#include "Contacts.hxx"
#include "ParagraphText.hxx"
#include "Uri.hxx"
#include "DivColumn.hxx"
#include "Size.hxx"

krap::Contacts::Contacts(const Site& site)
:
    DocumentImpl(site)
{
    const int width = 300;

    CSSClass contactsColClass ("contactsColClass");
    contactsColClass.add(Width(width));

    DivColumn div_col
    {
        ParagraphText {"You can reach me using these means: "},

        //ResearchGate
        ParagraphText {
            Uri("https://www.researchgate.net/profile/Matvey-Kraposhin").
            html("ResearchGate account")},

        //Linkedin
        ParagraphText {
            Uri("https://www.linkedin.com/in/matvey-kraposhin-413869163").
            html("Linkedin account")},

        //GitHub
        ParagraphText {
            Uri("https://github.com/mkraposhin").
            html("GitHub account")},

        //E-Mail

        //Telegram
        ParagraphText {
            Uri("https://t.me/kraposhin").
            html("Telegram account")}
    };

    div_col % contactsColClass;

    Div& mid_col = layout().operator()<Div>(1);
    mid_col.add(div_col);
}

//
//END-OF-FILE
//

