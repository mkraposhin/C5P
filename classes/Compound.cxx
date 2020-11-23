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

void krap::Compound::add(const Element& elem)
{
    auto it = elements_.cend();
    elements_.insert(it, elem);
}

std::ostream& krap::Compound::print(std::ostream& ostr) const
{
    for (auto elem : elements_)
    {
        elem.print(ostr);
    }

    return ostr;
}

//
//END-OF-FILE
//
