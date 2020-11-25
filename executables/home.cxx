#include <cgicc/Cgicc.h>
#include "Document.hxx"
#include "ParagraphText.hxx"
#include "Title.hxx"
#include "Head.hxx"

int main (int argc, char * argv[])
{
    cgicc::Cgicc cgi;

    using namespace krap;

    Document homeHtml{};

    Title title {"Matvey Kraposhin personal page"};

    ParagraphText firstPar {"Hello, I\'m Matvey"};
    ParagraphText secondPar {"This is my personal page"};
    ParagraphText thirdPar {"The site is about CFD, C++ and fluids"};
    ParagraphText fourthPar {"The page is written in C++ and CGI"};

    homeHtml.body().add(firstPar);
    homeHtml.body().add(secondPar);
    homeHtml.body().add(thirdPar);
    homeHtml.body().add(fourthPar);

    homeHtml.head() ^ title;

    std::cout << homeHtml << std::endl;

    return 0;
}

//
//END-OF-FILE
//

