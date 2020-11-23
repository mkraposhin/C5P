#include "Document.hxx"

krap::Document::Document()
{

}

krap::Document::Document(const Document& doc)
:
    header_(doc.header_),
    body_(doc.body_)
{

}

krap::Document::~Document()
{

}

std::ostream& krap::Document::print(std::ostream& ostr) const
{
    return ostr;
}

//
//END-OF-FILE
//

