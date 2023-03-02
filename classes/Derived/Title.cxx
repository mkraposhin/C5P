#include "Title.hxx"
#include <cgicc/HTMLClasses.h>

krap::Title::Title()
:
    Element()
{
}

krap::Title::Title(const std::string& text)
:
    Element(),
    ttext_(text)
{
}

krap::Title::Title(const Title& ttext)
:
    Element(ttext),
    ttext_(ttext.ttext_)
{
}

krap::Title::~Title()
{
}

std::ostream& krap::Title::print(std::ostream& ostr) const
{
    ostr << cgicc::title() << ttext_ << cgicc::title() << std::endl;
    return ostr;
}

krap::ElementPtr krap::Title::clone() const
{
    return ElementPtr(new Title(*this));
}

//
//END-OF-FILE
//
