#include "Element.hxx"

using namespace krap;

void krap::Element::Element::set_child(ElementPtr& new_child)
{
    child_ = new_child;
//    child_.reset(new_child.get());
}

krap::Element::Element()
:
    child_(nullptr)
{

}

krap::Element::Element(const Element& el)
:
    child_(nullptr)
{
    if (el.child_)
    {
        child_ = (*el.child_).clone();
    }
}

krap::Element::~Element()
{

}

ElementPtr krap::Element::clone() const
{
    return std::make_shared<Element>(*this);
}

std::ostream& Element::Element::print(std::ostream& ostr) const
{
    if (child_)
    {
        return (*child_).print(ostr);
    }
    return ostr;
}

std::ostream& krap::operator << (std::ostream& ostr, const krap::Element& elem)
{
    return elem.print(ostr);
}

krap::Element& krap::operator ^ (krap::Element& el, krap::Element& cel)
{
    if (&el == &cel)
    {
        return el;
    }
    ElementPtr pel {cel.clone()};
    el.set_child(pel);

    return el;
}

//
//END-OF-FILE
//

