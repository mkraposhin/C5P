#include "Document.hxx"
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

krap::Document::Document()
{

}

krap::Document::Document(const Document& doc)
:
    head_(doc.head_)
{

}

krap::Document::~Document()
{

}

std::ostream& krap::Document::print(std::ostream& ostr) const
{
    ostr <<  cgicc::HTTPHTMLHeader() << std::endl;

    ostr << cgicc::html() << std::endl;

    head_.print(ostr);
    body_.print(ostr);

    ostr << cgicc::html() << std::endl;

    return ostr;
}

krap::Page& krap::Document::body()
{
    return body_;
}

krap::Head& krap::Document::head()
{
    return head_;
}


//
//END-OF-FILE
//

