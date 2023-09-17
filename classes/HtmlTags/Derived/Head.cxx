
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
    jscripts_(h.jscripts_),
    link_(h.link_),
    metas_(h.metas_)
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
    for (auto js : jscripts_)
    {
        js.print(ostr);
    }
    if (link_)
        link_->print(ostr);
    for (auto it=metas_.cbegin(); it!=metas_.cend(); it++)
    {
        ostr<<cgicc::meta().set("name",it->first).set("content",it->second)
            <<std::endl;
    }
    Element::print(ostr);
    ostr << cgicc::head() << std::endl;
    return ostr;
}

void krap::Head::jscript(const JScript& js)
{
    jscripts_.push_back(*js.clone());
}

void krap::Head::link(const Link& l)
{
    link_ = std::dynamic_pointer_cast<Link>(l.clone());
}

void krap::Head::add_meta(const std::string name, const std::string content)
{
    metas_.insert(metas_.cend(), MetaPair{name,content});
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