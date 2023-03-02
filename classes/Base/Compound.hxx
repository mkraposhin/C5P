#ifndef Compound_H
#define Compound_H

#include "Element.hxx"
#include <vector>
#include <memory>

namespace krap
{

/*---------------------------------------------------------------------------*\
                          Class Compound Declaration
\*---------------------------------------------------------------------------*/

class Compound
:
    public Element
{
private:


protected:

    //- Ordered list of elements in this compound
    std::vector<ElementPtr> elements_;


public:
     
    //- Default constructor (creates empty compound)
    Compound();

    //- Copy constructor for the Compound
    Compound(const Compound&);

    //- Destructor
    ~Compound();

    //- Add new element
    virtual ElementPtr& add (const Element&);

    //- Add element stored by ordinary pointer
    virtual ElementPtr& add (Element* ept);

    //- Add element stored by shared_ptr pointer
    virtual ElementPtr& add (ElementPtr& eptr);

    //- Print elements in compound
    virtual std::ostream& print(std::ostream& ostr) const override;

    //- Assign operator
    const Compound& operator = (const Compound& right);    


    //- access to elements of a compound

        //- Access with specification of a child type
        template <class CType>
        CType& operator () (int i);

        //- Non-const reference access operator
        Element& operator [] (int i);

        //- begin of a compound
        std::vector<ElementPtr>::iterator begin();

        //- end of a compound
        std::vector<ElementPtr>::iterator end();

        //- const begin of a compound
        std::vector<ElementPtr>::const_iterator cbegin() const;

        //- const end of a compound
        std::vector<ElementPtr>::const_iterator cend() const;

        //- total count of elements of a compound
        int size() const;

        //- remove all child elements
        void clear();
};


//- summation of two Elements is the new Compound with two elements
std::shared_ptr<Compound> operator + 
(
    const Element& elem1, 
    const Element& elem2
);

//- summation of one Compound and one Element is equal to adding element
//  to this compound (const version)
std::shared_ptr<Compound> operator +
(
    const std::shared_ptr<Compound>& comp1,
    const Element& elem
);

//- summation of one Compound and one Element is equal to adding element
//  to this compound (const version)
std::shared_ptr<Compound> operator +
(
    const Element& elem,
    const std::shared_ptr<Compound>& comp1
);

template <class CType> CType& 
krap::Compound::operator () (int i)
{
    return dynamic_cast<CType&>(this->operator[](i));
}

}

#endif

//
//END-OF-FILE
//

