#include "Compound.hxx"

krap::Compound::Compound()
{

}

krap::Compound::Compound(const Compound& compound)
:
    elements_(elements)
{
    
}

krap::Compound::~Compound()
{

}

void krap::Compound::add(const Element& elem)
{
    auto it = elements_.cend();
    elements_.insert(elem);
}

std::ostream& krap::Compound::print(std::ostream& ostr)
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
