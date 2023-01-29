
#include "Image.hxx"
#include "Globals.hxx"
#include "CSSClass.hxx"
#include <cgicc/HTMLClasses.h>

krap::Image::Image()
:
    Element(),
    uri_(),
    width_(-1)
{
}

krap::Image::Image(const std::string& where)
:
    Element(),
    uri_(new Uri{constants::protocol + constants::site_uri + "images/" + where})
{
}

krap::Image::Image(const Image& img)
:
    Element(img),
    uri_
    {
        img.uri_ ? new Uri(*img.uri_)
        : nullptr
    },
    width_(img.width_)
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
    if (width_ > 0)
    {
        html_elem.set("width", std::to_string(width_));
    }
    ostr<< html_elem << std::endl;
    
    return ostr;
}

krap::ElementPtr krap::Image::clone() const
{
    return ElementPtr(new Image(*this));
}

int krap::Image::width(int w)
{
    width_ = w;
    return width_;
}

const int krap::Image::width() const
{
    return width_;
}
//
//END-OF-FILE
//
