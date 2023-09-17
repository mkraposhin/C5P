#include "Element.hxx"
#include "CSSClass.hxx"

using namespace c5p;

void c5p::Element::set_child(ElementPtr& new_child)
{
    child_ = new_child;
}

void c5p::Element::set_css_class(const CSSClass& css)
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

c5p::Element::Element()
:
    child_(nullptr),
    css_(nullptr)
{

}

c5p::Element::Element(const Element& el)
:
    child_(nullptr),
    css_(el.css_)
{
    if (el.child_)
    {
        child_ = (*el.child_).clone();
    }
}

c5p::Element::~Element()
{

}

c5p::ElementPtr c5p::Element::clone() const
{
    return std::make_shared<Element>(*this);
}

const c5p::ElementPtr& c5p::Element::child() const
{
    return child_;
}

const c5p::CSSClassPtr& c5p::Element::css() const
{
    return css_;
}

std::ostream& c5p::Element::print(std::ostream& ostr) const
{
    if (bool(child_))
    {
        return (*child_).print(ostr);
    }
    return ostr;
}

std::ostream& c5p::operator << (std::ostream& ostr, const c5p::Element& elem)
{
    return elem.print(ostr);
}

c5p::Element& c5p::operator ^ (c5p::Element& el, const c5p::Element& cel)
{
    if (&el == &cel)
    {
        return el;
    }
    ElementPtr pel {cel.clone()};
    el.set_child(pel);

    return el;
}

c5p::CSSClassPtr& c5p::operator % (c5p::Element& el, 
    const c5p::CSSClass& css)
{
    el.set_css_class(css);
    return el.css_;
}

c5p::CSSClassPtr& c5p::operator % 
(
    c5p::Element& el,
    c5p::CSSClassPtr& cssptr
)
{
    el.css_ = cssptr;
    return cssptr;
}

//
//END-OF-FILE
//

