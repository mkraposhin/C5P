#include "Element.hxx"

using namespace krap;

std::ostream& Element::Element::print(std::ostream& ostr) const
{
    return ostr;
}

std::ostream& krap::operator << (std::ostream& ostr, const krap::Element& elem)
{
    return elem.print(ostr);
}


//
//END-OF-FILE
//

