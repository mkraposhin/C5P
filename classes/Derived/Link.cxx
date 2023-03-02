#include "Link.hxx"
#include <cgicc/HTMLClasses.h>

krap::Link::Link(const std::string& rel, const std::string& href)
: 
    Element(),
    rel_(rel),
    href_(href)
{

}

krap::Link::~Link()
{

}

krap::ElementPtr krap::Link::clone() const
{
    return ElementPtr{new Link{this->rel_, this->href_}};
}

std::ostream& krap::Link::print(std::ostream& ostr) const
{
    cgicc::link lnk;
    lnk.set("rel", rel_);
    lnk.set("href", href_);
    ostr << lnk << std::endl;
    return ostr;
}

