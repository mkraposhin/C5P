
#include "ParagraphText.hxx"
#include <cgicc/HTMLClasses.h>

krap::ParagraphText::ParagraphText()
{
}

krap::ParagraphText::ParagraphText(const std::string& text)
:
    partext_(text)
{
}

krap::ParagraphText::ParagraphText(const ParagraphText& ptext)
:
    partext_(ptext.partext_)
{
}

krap::ParagraphText::~ParagraphText()
{
}

std::ostream& krap::ParagraphText::print(std::ostream& ostr) const
{
    ostr << cgicc::p() << partext_ << cgicc::p() << std::endl;
    return ostr;
}

krap::ElementPtr krap::ParagraphText::clone() const
{
    return ElementPtr(new ParagraphText(*this));
}

//
//END-OF-FILE
//
