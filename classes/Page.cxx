
#include "Page.hxx"
#include "CSSClass.hxx"
#include <cgicc/HTMLClasses.h>

krap::Page::Page(CSSClassMap& ccm)
:
    Compound(),
    css_class_map_(ccm)
{
}

krap::Page::Page(const Page& page, CSSClassMap& css_class_map)
:
    Compound(page),
    css_class_map_(css_class_map)
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
    ostr << cgicc::body() << std::endl;
    return ostr;
}

const krap::Page& krap::Page::operator = (const krap::Compound& right)
{
    krap::Compound::operator=(right);
    return *this;
}

void krap::Page::register_css_class(const Element& nelem)
{
    if (nelem.css())
    {
        CSSClassMapRec new_rec
        {
            (*nelem.css()).name(),
            nelem.css()
        };
            
        css_class_map_.insert(new_rec);
    }
    
    if (nelem.child())
    {
        register_css_class(nelem.child());
    }
    if (&nelem != this) //nelem doesn't point to this object
    {
        if (dynamic_cast<const Compound*>(&nelem))//if it is a Compound
        {
            auto compound_of_elements = 
                dynamic_cast<const Compound&>(nelem);
            for (auto it :compound_of_elements)
            {
                register_css_class(it);
            }
        }
    }
}

void krap::Page::register_css_class(const ElementPtr& eptr)
{
    if (eptr)
    {
        Element& nelem = *eptr;
        register_css_class(nelem);
    }
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

krap::CSSClassPtr& krap::operator % (krap::Page& page,
    const krap::CSSClass& css)
{
    CSSClassPtr& cssptr = dynamic_cast<Element&>(page) % css;
    page.register_css_class(cssptr);
    return cssptr;
}

//
//END-OF-FILE
//

