#include "Div.hxx"
#include "CSSClass.hxx"
#include <cgicc/HTMLClasses.h>

krap::Div::Div()
:
    Compound()
{
}

krap::Div::Div(const Div& div)
:
    Compound(div)
{
}

krap::Div::~Div()
{
}

std::ostream& krap::Div::print(std::ostream& ostr) const
{
    if (css())
    {
        //ostr << cgicc::div().set("class", (*css()).name()) << std::endl;
        ostr << "<div class=\"" << (*css()).name() << "\">" << std::endl;
    }
    else
    {
        //ostr << cgicc::div() << std::endl;
        ostr << "<div " << ">" << std::endl;
    }
    Compound::print(ostr)
        << std::endl << "</div>" << std::endl;
        //<< std::endl << cgicc::div() << std::endl;
    return ostr;
}

krap::ElementPtr krap::Div::clone() const
{
    return ElementPtr(new Div(*this));
}

//
//END-OF-FILE
//