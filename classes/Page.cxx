
#include "Page.hxx"
#include <cgicc/HTMLClasses.h>

krap::Page::Page()
:
    Compound()
{
}

krap::Page::~Page()
{

}

std::ostream& krap::Page::print(std::ostream& ostr) const
{
    ostr << cgicc::body() << std::endl;
    Compound::print(ostr);
    ostr << cgicc::body() << std::endl;
    return ostr;
}

const krap::Page& krap::Page::operator = (const krap::Compound& right)
{
    krap::Compound::operator=(right);
    return *this;
}

//
//END-OF-FILE
//

