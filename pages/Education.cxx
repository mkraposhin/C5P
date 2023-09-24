#include "Education.hxx"
#include "ParagraphText.hxx"
#include "DivColumn.hxx"
#include "CaptionedImage.hxx"
#include "Size.hxx"
#include "CSS.hxx"

c5p::Education::Education(const Site& site)
:
    DocumentImpl(site)
{
    const int width = 300;

    CSSClass eduColClass ("eduColClass", css::divTable);
    eduColClass.add(Width(width));

    DivColumn div_col
    {
       ParagraphText {"2000 - 2006: National University"
       " \"Moscow Power Engineering Institute\": Nuclear Power Plants dept.,"
       " MSc"},
       ParagraphText {"2017: Keldysh institute of applied mathematics"
       " of the RAS, PhD"}
    };
    div_col % eduColClass;
    
    CaptionedImage im_cpp98("cpp_98_scaled.png");
    im_cpp98.image().width(300);
    std::string txt_cpp98 ("2018: Progrmming with Visual Studio C++");
    im_cpp98.caption(txt_cpp98);

    CaptionedImage im_intro_nw ("NYUx_FCS.NET.1_Certificate_edX.png");
    im_intro_nw.image().width(300);
    std::string txt_intro_nw ("2023: Introduction to Networks, EdX," +
        Uri("https://courses.edx.org/certificates/"
            "80ea6e76b8c54c5ebde296d2dfce16da").html("certificate")
    );
    im_intro_nw.caption(txt_intro_nw);

    CaptionedImage im_udemy_sql{"sql_udemy.jpg"};
    im_udemy_sql.image().width(300);
    std::string txt_udemy_sql ("2020: SQL & PostgreSQL for Beginners: "
    " Become an SQL Expert, Udemy " +
        Uri("https://www.udemy.com/certificate/"
        "UC-f1c764ec-acbf-4ac3-aeff-2acfd721f982/").html("certificate")
    );
    im_udemy_sql.caption(txt_udemy_sql);

    div_col.add(im_cpp98);
    div_col.add(im_intro_nw);
    div_col.add(im_udemy_sql);

    Div& mid_col = layout().operator()<Div>(1);
    mid_col.add(div_col);
}

//
//END-OF-FILE
//

