
#include "Page.hxx"
#include "CSSClass.hxx"
#include <cgicc/HTMLClasses.h>

krap::Page::Page(CSSClassMap& ccm)
:
    Compound(),
    css_class_map_(ccm)
{
}

krap::Page::Page(const Page& page)
:
    Compound(page),
    css_class_map_(const_cast<CSSClassMap&>(page.css_class_map_))
{
}

krap::Page::~Page()
{
}

std::ostream& krap::Page::print(std::ostream& ostr) const
{
    ostr << cgicc::body() << std::endl;
    Compound::print(ostr);
    ostr << cgicc::body() << std::endl;
    return ostr;
}

const krap::Page& krap::Page::operator = (const krap::Compound& right)
{
    krap::Compound::operator=(right);
    return *this;
}

void krap::Page::register_css_clas(ElementPtr& eptr)
{
    if (eptr)
    {
        Element& nelem = *eptr;
        if (nelem.css())
        {
            CSSClassMapRec new_rec
            {
                (*nelem.css()).name(),
                nelem.css()
            };
            
            css_class_map_.insert(new_rec);
        }
    }
}

krap::ElementPtr& krap::Page::add(const krap::Element& elem)
{
    ElementPtr& nptr = Compound::add(elem);
    register_css_clas(nptr);
    return nptr;
}

krap::ElementPtr& krap::Page::add(Element* elem)
{
    ElementPtr& nptr = Compound::add(elem);
    register_css_clas(nptr);
    return nptr;
}

krap::ElementPtr& krap::Page::add(ElementPtr& elem)
{
    ElementPtr& nptr = Compound::add(elem);
    register_css_clas(nptr);
    return nptr;
}

//
//END-OF-FILE
//

