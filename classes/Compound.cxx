#include "Compound.hxx"

krap::Compound::Compound()
{

}

krap::Compound::~Compound()
{

}

void krap::Compound::add(const Element& elem)
{
    auto it = elements_.cend();
    elements_.insert(it, elem.clone());
}

void krap::Compound::add(Element* eptr)
{
    auto it = elements_.cend();
    ElementPtr newElem {eptr};
    elements_.insert(it, newElem);
    eptr = nullptr;
}

void krap::Compound::add(ElementPtr& eptr)
{
    auto it = elements_.cend();
    elements_.insert(it, eptr);
}

std::ostream& krap::Compound::print(std::ostream& ostr) const
{
    for (auto elem : elements_)
    {
        (*elem).print(ostr);
    }

    return ostr;
}


const krap::Compound& krap::Compound::operator = 
(
    const krap::Compound& right
)
{
    for (auto elem : elements_)
    {
        elem.reset();
    }
    elements_ = right.elements_;
    return *this;
}

/*
 * 
 * Operators  
 * 
 */

std::shared_ptr<krap::Compound> krap::operator + 
(
    const krap::Element& elem1, 
    const krap::Element& elem2
)
{
    std::shared_ptr<krap::Compound> cmptr = std::make_shared<krap::Compound>();
    (*cmptr).add(elem1);
    (*cmptr).add(elem2);
    return cmptr;
}

std::shared_ptr<krap::Compound> krap::operator +
(
    const std::shared_ptr<krap::Compound>& comp1,
    const krap::Element& elem1
)
{
    std::shared_ptr<krap::Compound> ncomp(comp1);
    (*ncomp).add(elem1);
    return ncomp;
}

std::shared_ptr<krap::Compound> krap::operator +
(
    const krap::Element& elem1,
    const std::shared_ptr<krap::Compound>& comp1
)
{
    return krap::operator+(comp1,elem1);
}

//
//END-OF-FILE
//

