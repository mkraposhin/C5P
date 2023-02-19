#ifndef DivColumn_H
#define DivColumn_H

#include "Div.hxx"

namespace krap
{

class DivColumn : public Div
{

private:

public:

    //- Constructs column of Div elements
    DivColumn();

    //- Creates copy of this object
    DivColumn(const DivColumn&) = default;

    //- Dtor
    ~DivColumn();

    //- Add a new element
    virtual ElementPtr& add (const Element&) override;

    //- Add the element stored by a ordinary pointer
    virtual ElementPtr& add (Element* ept) override;

    //- Add the element stored by a shared_ptr pointer
    virtual ElementPtr& add (ElementPtr& eptr) override;

    //- Creates copy 
    ElementPtr clone() const override;

};

}

#endif

//
//END-OF-FILE
//

