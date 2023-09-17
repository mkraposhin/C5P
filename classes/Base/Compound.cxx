#include "Compound.hxx"

c5p::Compound::Compound()
{

}

c5p::Compound::Compound(const Compound& compound)
:
    elements_(compound.elements_)
{

}

c5p::Compound::~Compound()
{
}

c5p::ElementPtr& c5p::Compound::add(const Element& elem)
{
    auto it = elements_.cend();
    ElementPtr cloned_elem = elem.clone();
    return *elements_.insert(it, cloned_elem);
}

c5p::ElementPtr& c5p::Compound::add(Element* eptr)
{
    ElementPtr newElem {eptr};
    auto it = elements_.insert(elements_.cend(), newElem);
    return *it;
}

c5p::ElementPtr& c5p::Compound::add(const ElementPtr& eptr)
{
    auto it = elements_.cend();
    return *elements_.insert(it, eptr->clone());
}

std::ostream& c5p::Compound::print(std::ostream& ostr) const
{
    ostr<<std::endl;
    for(auto it=elements_.cbegin();
        it!=elements_.cend(); it++)
    {
        (*it)->print(ostr);
    }

    return ostr;
}


const c5p::Compound& c5p::Compound::operator = 
(
    const c5p::Compound& right
)
{
    this->clear();
    elements_.insert(elements_.cend(),
        right.elements_.cbegin(),right.elements_.cend());
    return *this;
}

c5p::Element& c5p::Compound::operator [] (int i)
{
    return *(elements_[i]);
}

std::vector<c5p::ElementPtr>::iterator c5p::Compound::begin()
{
    return elements_.begin();
}

std::vector<c5p::ElementPtr>::iterator c5p::Compound::end()
{
    return elements_.end();
}

std::vector<c5p::ElementPtr>::const_iterator c5p::Compound::cbegin() const
{
    return elements_.cbegin();
}

std::vector<c5p::ElementPtr>::const_iterator c5p::Compound::cend() const
{
    return elements_.cend();
}

int c5p::Compound::size() const
{
    return elements_.size();
}

void c5p::Compound::clear()
{
    elements_.erase(elements_.cbegin(), elements_.cend());
}

/*
 * 
 * Operators  
 * 
 */

std::shared_ptr<c5p::Compound> c5p::operator + 
(
    const c5p::Element& elem1, 
    const c5p::Element& elem2
)
{
    std::shared_ptr<c5p::Compound> cmptr = std::make_shared<c5p::Compound>();
    (*cmptr).add(elem1);
    (*cmptr).add(elem2);
    return cmptr;
}

std::shared_ptr<c5p::Compound> c5p::operator +
(
    const std::shared_ptr<c5p::Compound>& comp1,
    const c5p::Element& elem1
)
{
    std::shared_ptr<c5p::Compound> ncomp(comp1);
    (*ncomp).add(elem1);
    return ncomp;
}

std::shared_ptr<c5p::Compound> c5p::operator +
(
    const c5p::Element& elem1,
    const std::shared_ptr<c5p::Compound>& comp1
)
{
    return c5p::operator+(comp1,elem1);
}

//
//END-OF-FILE
//

