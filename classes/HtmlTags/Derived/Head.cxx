
#include "Head.hxx"
#include "CSSClass.hxx"

#include <cgicc/HTMLClasses.h>

c5p::Head::Head(CSSClassMap& css_class_map)
:
    Element(),
    CSSRegistry(css_class_map)
{
}

c5p::Head::Head(const Head& h, CSSClassMap& css_class_map)
:
    Element(h),
    CSSRegistry(css_class_map),
    jscripts_(h.jscripts_),
    link_(h.link_),
    metas_(h.metas_),
    title_(h.title_)
{
}

c5p::Head::~Head()
{
}

void c5p::Head::print_styles(std::ostream& ostr) const
{
    ostr << "<style>" << std::endl;
    for(auto it=css_class_map_.cbegin();
        it!=css_class_map_.cend(); it++)
    {
        ostr << *(it->second) << std::endl;
    }
    ostr << "</style>" << std::endl;
}

std::ostream& c5p::Head::print(std::ostream& ostr) const
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
    if (bool(title_)) {
        title_->print(ostr);
    }
    Element::print(ostr);
    ostr << cgicc::head() << std::endl;
    return ostr;
}

void c5p::Head::jscript(const JScript& js)
{
    jscripts_.push_back(*js.clone());
}

void c5p::Head::link(const Link& l)
{
    link_ = std::dynamic_pointer_cast<Link>(l.clone());
}

void c5p::Head::add_meta(const std::string name, const std::string content)
{
    metas_.insert(metas_.cend(), MetaPair{name,content});
}

void c5p::Head::title(const std::string& title_name) {
    title_.reset(new Title{title_name});
}

c5p::Element& c5p::operator ^ (Head& el, const Element& child)
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
