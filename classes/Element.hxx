#ifndef Element_H
#define Element_H

#include <iostream>
#include <memory>

namespace krap
{

//- Forward declaration of Element
class Element;

typedef std::shared_ptr<Element> ElementPtr;


class Element
{

private:

    //- Pointer to the child
    ElementPtr child_;

    //- Sets the pointer to new child
    void set_child(ElementPtr& new_child);

    //-
    friend Element& operator ^ (Element& el, Element& child);

public:

    //- Default constructor
    Element();

    //- Copy constructor
    Element(const Element&);

    //- Destructor
    ~Element();

    //-
    virtual std::ostream& print(std::ostream& ostr) const;

    //-
    virtual ElementPtr clone() const;
};


//- ostream output operator
std::ostream& operator << (std::ostream& ostr, const Element& elem);

//- set nested element operator
Element& operator ^ (Element& el, Element& child);

}//namespace krap

#endif

//
//END-OF-FILE
//

