
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
    CSSRegistry(css_class_map),
    jscript_(h.jscript_)
{
}

krap::Head::~Head()
{
}

void krap::Head::print_styles(std::ostream& ostr) const
{
    ostr << "<style>" << std::endl;
    for(auto it=css_class_map_.cbegin();
        it!=css_class_map_.cend(); it++)
    {
        ostr << *(it->second) << std::endl;
    }
    ostr << "</style>" << std::endl;
}

std::ostream& krap::Head::print(std::ostream& ostr) const
{
    ostr << cgicc::head() << std::endl;
    print_styles(ostr);
    if (jscript_)
        jscript_->print(ostr);
    if (link_)
        link_->print(ostr);
    Element::print(ostr);
    ostr << cgicc::head() << std::endl;
    return ostr;
}

void krap::Head::jscript(const JScript& js)
{
    jscript_ = js.clone();
}

void krap::Head::link(const Link& l)
{
    link_ = std::dynamic_pointer_cast<Link>(l.clone());
}

krap::Element& krap::operator ^ (Head& el, const Element& child)
{
    dynamic_cast<Element&>(el) ^ child;
    el.register_css_class(el.child());
    #warning "Make this map unique and both ordered"
    // std::cout << "---" << std::endl;
    // for (auto it=el.css_class_map_.cbegin(); it!=el.css_class_map_.cend(); it++)
    //         std::cout << "name = " << it->first << std::endl;
    // std::cout << "---" << std::endl;
    return el;
}

//
//END-OF-FILE
//
