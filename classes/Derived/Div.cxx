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
    std::string id_str="";
    if (id() != std::string(""))
    {
        id_str = " id=" + std::string("\"") + id() + "\" ";
    }
    if (css())
    {
        ostr<< "<div class=\"" << (*css()).name()
            << "\"" << id_str << ">" << std::endl;
    }
    else
    {
        ostr<< "<div " << id_str << ">" << std::endl;
    }
    Compound::print(ostr)
        << std::endl << "</div>" << std::endl;
    return ostr;
}

krap::ElementPtr krap::Div::clone() const
{
    return ElementPtr(new Div(*this));
}

//
//END-OF-FILE
//
