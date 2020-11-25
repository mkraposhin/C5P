
#include "Head.hxx"
#include <cgicc/HTMLClasses.h>

krap::Head::Head()
:
    Element()
{
}

krap::Head::~Head()
{

}

std::ostream& krap::Head::print(std::ostream& ostr) const
{
    ostr << cgicc::head() << std::endl;
    Element::print(ostr);
    ostr << cgicc::head() << std::endl;
    return ostr;
}

krap::ElementPtr krap::Head::clone() const
{
    return ElementPtr(new Head(*this));
}

//
//END-OF-FILE
//
