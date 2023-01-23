
#include "AText.hxx"
#include "CSSClass.hxx"
#include <cgicc/HTMLClasses.h>

krap::AText::AText()
{
}

krap::AText::AText(const std::string& text)
:
    text_(text)
{
}

krap::AText::AText(const AText& ptext)
:
    Element(ptext),
    text_(ptext.text_),
    uri_
    {
        ptext.uri_ ? new Uri{*ptext.uri_}
        : nullptr
    }
{
}

krap::AText::~AText()
{
}

std::ostream& krap::AText::print(std::ostream& ostr) const
{
    cgicc::a html_elem{};

    if (css())
    {
        html_elem.set("class", (*css()).name());
    }
    if (uri_)
    {
        html_elem.set("href", uri_->uri());
    }
    ostr<< html_elem
        << text_ << cgicc::a() << std::endl;
    
    return ostr;
}

krap::ElementPtr krap::AText::clone() const
{
    return ElementPtr(new AText(*this));
}

void krap::AText::uri (const std::string& s)
{
    if (s.empty())
    {
        uri_.reset();
    }
    else
    {
        uri_.reset(new Uri(s));
    }
}

//
//END-OF-FILE
//
