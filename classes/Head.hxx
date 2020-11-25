#ifndef Head_H
#define Head_H

#include "Element.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                            Class Head Declaration
\*---------------------------------------------------------------------------*/

class Head
:
    public Element
{
private:


public:

    //- Default constructor
    Head();

    //- Destructor
    ~Head();

    //- Print elements in the Head
    std::ostream& print(std::ostream& ostr) const override;

    //- Creates clone of itself
    virtual ElementPtr clone() const;
};

}

#endif

//
//END-OF-FILE
//
