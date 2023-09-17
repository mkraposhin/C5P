
#include "Page.hxx"
#include "CSSClass.hxx"
#include <cgicc/HTMLClasses.h>

c5p::Page::Page(CSSClassMap& ccm)
:
    Element(),
    Compound(),
    CSSRegistry(ccm)
{
}

c5p::Page::Page(const Page& page, CSSClassMap& css_class_map)
:
    Element(page),
    Compound(page),
    CSSRegistry(css_class_map),
    jscripts_(page.jscripts_)
{
}

c5p::Page::~Page()
{
}

std::ostream& c5p::Page::print(std::ostream& ostr) const
{
    if (css())
    {
        ostr<< cgicc::body().set("class", (*css()).name())
            << std::endl;
    }
    else
    {
        ostr << cgicc::body() << std::endl;
    }
    Compound::print(ostr);
    for (auto js : jscripts_)
    {
        js.print(ostr);
    }
    ostr << cgicc::body() << std::endl;
    return ostr;
}

const c5p::Page& c5p::Page::operator = (const c5p::Compound& right)
{
    c5p::Compound::operator=(right);
    return *this;
}

c5p::ElementPtr& c5p::Page::add(const c5p::Element& elem)
{
    ElementPtr& nptr = Compound::add(elem);
    register_css_class(nptr);
    return nptr;
}

c5p::ElementPtr& c5p::Page::add(Element* elem)
{
    ElementPtr& nptr = Compound::add(elem);
    register_css_class(nptr);
    return nptr;
}

c5p::ElementPtr& c5p::Page::add(const ElementPtr& elem)
{
    ElementPtr& nptr = Compound::add(elem);
    register_css_class(nptr);
    return nptr;
}

void c5p::Page::jscript(const JScript& js)
{
    jscripts_.push_back(*js.clone());
}

c5p::CSSClassPtr& c5p::operator % (c5p::Page& page,
    const c5p::CSSClass& css)
{
    Element& elem = dynamic_cast<Element&>(page);
    CSSClassPtr& cssptr = elem % css;
    page.register_css_class(elem);
    return cssptr;
}

//
//END-OF-FILE
//

