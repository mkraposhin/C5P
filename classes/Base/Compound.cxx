#include "Compound.hxx"

krap::Compound::Compound()
{

}

krap::Compound::Compound(const Compound& compound)
:
    elements_(compound.elements_)
{

}

krap::Compound::~Compound()
{
}

krap::ElementPtr& krap::Compound::add(const Element& elem)
{
    auto it = elements_.cend();
    ElementPtr cloned_elem = elem.clone();
    return *elements_.insert(it, cloned_elem);
}

krap::ElementPtr& krap::Compound::add(Element* eptr)
{
    ElementPtr newElem {eptr};
    auto it = elements_.insert(elements_.cend(), newElem);
    return *it;
}

krap::ElementPtr& krap::Compound::add(const ElementPtr& eptr)
{
    auto it = elements_.cend();
    return *elements_.insert(it, eptr->clone());
}

std::ostream& krap::Compound::print(std::ostream& ostr) const
{
    ostr<<std::endl;
    for(auto it=elements_.cbegin();
        it!=elements_.cend(); it++)
    {
        (*it)->print(ostr);
    }

    return ostr;
}


const krap::Compound& krap::Compound::operator = 
(
    const krap::Compound& right
)
{
    this->clear();
    elements_.insert(elements_.cend(),
        right.elements_.cbegin(),right.elements_.cend());
    return *this;
}

krap::Element& krap::Compound::operator [] (int i)
{
    return *(elements_[i]);
}

std::vector<krap::ElementPtr>::iterator krap::Compound::begin()
{
    return elements_.begin();
}

std::vector<krap::ElementPtr>::iterator krap::Compound::end()
{
    return elements_.end();
}

std::vector<krap::ElementPtr>::const_iterator krap::Compound::cbegin() const
{
    return elements_.cbegin();
}

std::vector<krap::ElementPtr>::const_iterator krap::Compound::cend() const
{
    return elements_.cend();
}

int krap::Compound::size() const
{
    return elements_.size();
}

void krap::Compound::clear()
{
    elements_.erase(elements_.cbegin(), elements_.cend());
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

