
#include "Head.hxx"
#include "CSSClass.hxx"

#include <cgicc/HTMLClasses.h>

krap::Head::Head(CSSClassMap& css_class_map)
:
    Element(),
    CSSRegistry(css_class_map)
{
}

krap::Head::Head(const Head& h, CSSClassMap& css_class_map)
:
    Element(h),
    CSSRegistry(css_class_map)
{
}

krap::Head::~Head()
{
}

void krap::Head::print_styles(std::ostream& ostr) const
{
    ostr << "<style>" << std::endl;
    for (auto map_rec : css_class_map_)
    {
        ostr << (*map_rec.second) << std::endl; ;
    }
    ostr << "</style>" << std::endl;
}

std::ostream& krap::Head::print(std::ostream& ostr) const
{
    ostr << cgicc::head() << std::endl;
    print_styles(ostr);
    Element::print(ostr);
    ostr << cgicc::head() << std::endl;
    return ostr;
}

krap::Element& krap::operator ^ (Head& el, const Element& child)
{
    dynamic_cast<Element&>(el) ^ child;
    el.register_css_class(el.child());
    return el;
}

//
//END-OF-FILE
//
