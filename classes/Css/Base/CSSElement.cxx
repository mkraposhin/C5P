#include "CSSElement.hxx"
#include <cgicc/HTMLClasses.h>

// krap::CSSElement::CSSElement()
// :
//     Element()
// {
//     #warning "Isn't it be better to prohibit default ctor?"
// }

c5p::CSSElement::CSSElement(const std::string& name, const std::string& text)
:
    Element(),
    css_name_(name),
    css_value_(text)
{
}

c5p::CSSElement::CSSElement(const CSSElement& csselem)
:
    Element(csselem),
    css_name_(csselem.css_name_),
    css_value_(csselem.css_value_)
{
}

c5p::CSSElement::~CSSElement()
{
}

std::ostream& c5p::CSSElement::print(std::ostream& ostr) const
{
    ostr << name() << ":" << value() << ";" << std::endl;
    return ostr;
}

c5p::ElementPtr c5p::CSSElement::clone() const
{
    return ElementPtr(new CSSElement(*this));
}

const std::string& c5p::CSSElement::name() const
{
    return css_name_;
}

const std::string& c5p::CSSElement::value() const
{
    return css_value_;
}

//
//END-OF-FILE
//
