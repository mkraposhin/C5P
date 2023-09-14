
#include "Page.hxx"
#include "CSSClass.hxx"
#include <cgicc/HTMLClasses.h>

krap::Page::Page(CSSClassMap& ccm)
:
    Element(),
    Compound(),
    CSSRegistry(ccm)
{
}

krap::Page::Page(const Page& page, CSSClassMap& css_class_map)
:
    Element(page),
    Compound(page),
    CSSRegistry(css_class_map),
    jscripts_(page.jscripts_)
{
}

krap::Page::~Page()
{
}

std::ostream& krap::Page::print(std::ostream& ostr) const
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

const krap::Page& krap::Page::operator = (const krap::Compound& right)
{
    krap::Compound::operator=(right);
    return *this;
}

krap::ElementPtr& krap::Page::add(const krap::Element& elem)
{
    ElementPtr& nptr = Compound::add(elem);
    register_css_class(nptr);
    return nptr;
}

krap::ElementPtr& krap::Page::add(Element* elem)
{
    ElementPtr& nptr = Compound::add(elem);
    register_css_class(nptr);
    return nptr;
}

krap::ElementPtr& krap::Page::add(ElementPtr& elem)
{
    ElementPtr& nptr = Compound::add(elem);
    register_css_class(nptr);
    return nptr;
}

void krap::Page::jscript(const JScript& js)
{
    jscripts_.push_back(*js.clone());
}

krap::CSSClassPtr& krap::operator % (krap::Page& page,
    const krap::CSSClass& css)
{
    Element& elem = dynamic_cast<Element&>(page);
    CSSClassPtr& cssptr = elem % css;
    page.register_css_class(elem);
    return cssptr;
}

//
//END-OF-FILE
//

