#ifndef Div_H
#define Div_H

#include "Compound.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                            Class Div Declaration
\*---------------------------------------------------------------------------*/

class Div
:
    public Compound
{
private:

public:

    //- Default constructor (Empty Div container)
    Div();

    //- Copy constructor
    Div(const Div& );

    //- Destructor
    ~Div();

    //- Print elements in a Div
    std::ostream& print(std::ostream& ostr) const override;

    //- Creates clone of a Div
    virtual ElementPtr clone() const override;
};

}

#endif

//
//END-OF-FILE
//
