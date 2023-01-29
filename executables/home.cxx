#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

#include "Site.hxx"
#include "Document.hxx"
#include "ParagraphText.hxx"
#include "Title.hxx"
#include "Head.hxx"
#include "Div.hxx"
#include "MainMenu.hxx"
#include "CSSElement.hxx"
#include "CSSClass.hxx"
#include "Globals.hxx"

int main (int argc, char * argv[])
{
    cgicc::Cgicc cgi;

    using namespace krap;

    krap::init_globals();

    Site site;

    auto goHome = [&cgi, &site]()
    {
        bool gohome = false;
        gohome |= (cgi.getElements().size() == 0);
        if (gohome) return gohome;

        gohome |= (cgi.getElement("where")->isEmpty());
        if (gohome) return gohome;

        gohome |= !site.has_document(cgi("where"));
        if (gohome) return gohome;

        gohome |= (cgi("where") == std::string("home"));
        if (gohome) return gohome;

        return gohome;
    };

    // std::cout<< cgicc::HTTPHTMLHeader() << std::endl;
    // std::cout<< cgicc::html() << cgicc::head(cgicc::title("cgicc example"))
    //          << std::endl;
    // std::cout<< cgicc::body() << std::endl;
    if (goHome())
    {
        std::cout << site[std::string("home")] << std::endl;
    }
    else
    {
        std::cout << site[cgi("where")] << std::endl;
    }
    // std::cout << cgicc::body() << cgicc::html();
    return 0;

    Document homeHtml{};

    Title title {"kraposhin.com"};

    ParagraphText firstPar {"Hello, I\'m Matvey"};
    ParagraphText secondPar {"This is my personal page"};
    ParagraphText thirdPar {"The site is about CFD, C++ and fluids"};
    ParagraphText fourthPar {"The page is written in C++ and CGI"};

    // Create 3-column layout
    Div threeCol {};
    Div columnLeft {};
    Div columnMiddle {};
    Div columnRight {};

    Div middleText {};

    middleText.add(firstPar);
    middleText.add(secondPar);
    middleText.add(thirdPar);
    middleText.add(fourthPar);

    columnMiddle.add(middleText);

    threeCol.add(columnLeft);
    threeCol.add(columnMiddle);
    threeCol.add(columnRight);

    CSSElement blueColor {"color", "blue"};
    CSSElement blackBackground {"background-color", "black"};
    CSSElement whiteFont {"color", "white"};
    CSSElement font24px {"font-size", "24px"};
    CSSElement width25perc{"width","25.0%"};
    CSSElement width50perc{"width","50.0%"};
    CSSElement width30perc{"width","30.0%"};
    CSSElement displayFlex{"display","flex"};

    CSSElement floatLeft{"float","left"};
    CSSElement displayTable{"display","table"};
    CSSElement boxSizing{"box-sizing", "border-box"};

    CSSClass emptyClass {"emptyCss"};

    CSSClass parText {"parText"};
    parText.add(blueColor);
    parText.add(font24px);

    CSSClass bodycss {"bodycss"};
    bodycss.add(blackBackground);
    bodycss.add(whiteFont);

    CSSClass divrow {"divrow"};
    // divrow.add(displayFlex);
    // divrow.add(boxSizing);
    CSSClass middlecol {"middlecol"};
    // middlecol.add(width30perc);
    // middlecol.add(displayFlex);
    // middlecol.add(boxSizing);
    CSSClass sidecol{"sidecol"};
    // sidecol.add(width30perc);
    // sidecol.add(displayFlex);
    // sidecol.add(boxSizing);
    threeCol % divrow;
    threeCol[0] % sidecol;
    threeCol[1] % middlecol;
    threeCol[2] % sidecol;

    // secondPar % (firstPar % parText);

    homeHtml.body() % bodycss;

    MainMenu mainm{};

    homeHtml.body().add(mainm);

    homeHtml.body().add(threeCol);
    // homeHtml.body().add(firstPar);
    // homeHtml.body().add(secondPar);
    // homeHtml.body().add(thirdPar);
    // homeHtml.body().add(fourthPar);

    homeHtml.head() ^ mainm;

    std::cout << homeHtml << std::endl;

    return 0;
}

//
//END-OF-FILE
//

