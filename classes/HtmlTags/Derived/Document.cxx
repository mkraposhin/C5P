#include "Document.hxx"
#include "CSSClass.hxx"
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

c5p::Document::Document()
:
    Element(),
    css_class_map_{},
    head_{css_class_map_},
    body_{css_class_map_}
{
}

c5p::Document::Document(const Document& doc)
:
    Element(doc),
    css_class_map_(doc.css_class_map_),
    head_(doc.head_, css_class_map_),
    body_(doc.body_, css_class_map_)
{
}

c5p::Document::~Document()
{
}

std::ostream& c5p::Document::print(std::ostream& ostr) const
{
    ostr <<  cgicc::HTTPHTMLHeader() << std::endl;
    ostr << std::endl << "<!DOCTYPE html>" << std::endl;
    ostr << cgicc::html() << std::endl;

    head_.print(ostr);
    body_.print(ostr);

    ostr << cgicc::html() << std::endl;

    return ostr;
}

c5p::Page& c5p::Document::body()
{
    return body_;
}

c5p::Head& c5p::Document::head()
{
    return head_;
}

c5p::ElementPtr c5p::Document::clone() const
{
    return ElementPtr (new Document(*this));
}

//
//END-OF-FILE
//

