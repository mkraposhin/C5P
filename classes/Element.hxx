#ifndef Element_H
#define Element_H

#include <iostream>

namespace krap
{

class Element
{

public:

    //-
    std::ostream& print(std::ostream& ostr) const;
};


std::ostream& operator << (std::ostream& ostr, const Element& elem);

}//namespace krap

#endif

//
//END-OF-FILE
//

