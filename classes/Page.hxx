#ifndef Page_H
#define Page_H

#include "Element.hxx"
#include "Compound.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                            Class Page Declaration
\*---------------------------------------------------------------------------*/

class Page
:
    public Compound
{
private:


public:

    //- Default constructor
    Page();

    //- Destructor
    ~Page();

    //- Print elements in the Page
    std::ostream& print(std::ostream& ostr) const;
};

}

#endif

//
//END-OF-FILE
//

