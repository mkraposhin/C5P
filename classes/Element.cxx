#include "Element.hxx"
#include "CSSClass.hxx"

using namespace krap;

void krap::Element::set_child(ElementPtr& new_child)
{
    child_ = new_child;
}

void krap::Element::set_css_class(const CSSClass& css)
{
    if (dynamic_cast<CSSClass*>(this)) //it is a CSSClass
    {
        return;
    }
    else
    {
        CSSClassPtr cssptr (std::dynamic_pointer_cast<CSSClass>(css.clone()));
        if (cssptr)
        {
            css_ = cssptr;
        }
    }
}

krap::Element::Element()
:
    child_(nullptr)
{

}

krap::Element::Element(const Element& el)
:
    child_(nullptr),
    css_(el.css_)
{
    if (el.child_)
    {
        child_ = (*el.child_).clone();
    }
}

krap::Element::~Element()
{

}

krap::ElementPtr krap::Element::clone() const
{
    return std::make_shared<Element>(*this);
}

const krap::ElementPtr& krap::Element::child() const
{
    return child_;
}

const krap::CSSClassPtr& krap::Element::css() const
{
    return css_;
}

std::ostream& Element::Element::print(std::ostream& ostr) const
{
    if (bool(child_))
    {
        return (*child_).print(ostr);
    }
    return ostr;
}

std::ostream& krap::operator << (std::ostream& ostr, const krap::Element& elem)
{
    return elem.print(ostr);
}

krap::Element& krap::operator ^ (krap::Element& el, const krap::Element& cel)
{
    if (&el == &cel)
    {
        return el;
    }
    ElementPtr pel {cel.clone()};
    el.set_child(pel);

    return el;
}

krap::CSSClassPtr& krap::operator % (krap::Element& el, 
    const krap::CSSClass& css)
{
    el.set_css_class(css);
    return el.css_;
}

krap::CSSClassPtr& krap::operator % 
(
    krap::Element& el,
    krap::CSSClassPtr& cssptr
)
{
    el.css_ = cssptr;
    return cssptr;
}

//
//END-OF-FILE
//

