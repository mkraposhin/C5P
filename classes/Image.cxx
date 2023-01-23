
#include "Image.hxx"
#include "Globals.hxx"
#include "CSSClass.hxx"
#include <cgicc/HTMLClasses.h>

krap::Image::Image()
:
    uri_{}
{
}

krap::Image::Image(const std::string& where)
:
    uri_(new Uri{constants::protocol + constants::site_uri + "images/" + where})
{
}

krap::Image::Image(const Image& img)
:
    Element(img),
    uri_
    {
        img.uri_ ? new Uri{*img.uri_}
        : nullptr
    }
{
}

krap::Image::~Image()
{
}

std::ostream& krap::Image::print(std::ostream& ostr) const
{
    cgicc::img html_elem{};

    if (css())
    {
        html_elem.set("class", (*css()).name());
    }
    if (uri_)
    {
        html_elem.set("src", uri_->uri());
    }
    ostr<< html_elem << std::endl;
    
    return ostr;
}

krap::ElementPtr krap::Image::clone() const
{
    return ElementPtr(new Image(*this));
}

//
//END-OF-FILE
//
