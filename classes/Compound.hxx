#ifndef Compound_H
#define Compound_H

#include "Element.hxx"
#include <vector>

namespace krap
{

/*---------------------------------------------------------------------------*\
                          Class Compound Declaration
\*---------------------------------------------------------------------------*/

class Compound
:
    public Element
{
protected:

    //- Ordered list of elements in this compound
    std::vector<Element> elements_;


public:
     
    //- Default constructor (creates empty compound)
    Compound();

    //- Copy constructor
    Compound(const Compound&);

    //- Destructor
    ~Compound();

    //- Add new element
    void add (const Element&);

    //- Print elements in compound
    std::ostream& print(std::ostream& ostr);
};


}

#endif

//
//END-OF-FILE
//

