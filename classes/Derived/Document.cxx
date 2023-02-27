#include "Document.hxx"
#include "CSSClass.hxx"
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

krap::Document::Document()
:
    Element(),
    css_class_map_{},
    head_{css_class_map_},
    body_{css_class_map_}
{
}

krap::Document::Document(const Document& doc)
:
    Element(doc),
    css_class_map_(doc.css_class_map_),
    head_(doc.head_, css_class_map_),
    body_(doc.body_, css_class_map_)
{
}

krap::Document::~Document()
{
}

std::ostream& krap::Document::print(std::ostream& ostr) const
{
    ostr <<  cgicc::HTTPHTMLHeader() << std::endl;
    ostr << std::endl << "<!DOCTYPE html>" << std::endl;
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

krap::ElementPtr krap::Document::clone() const
{
    return ElementPtr (new Document(*this));
}

//
//END-OF-FILE
//

