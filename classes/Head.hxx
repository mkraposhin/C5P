#ifndef Head_H
#define Head_H

#include "Element.hxx"
#include "CSSRegistry.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                            Class Head Declaration
\*---------------------------------------------------------------------------*/

class Head
:
    public Element, CSSRegistry
{
protected:

    //- Gives access to CSSRegistry functions
    friend Element& operator ^ (Head& el, const Element& child);

private:

    //- forbid the default constructor
    Head() = delete;

    //- forbid copy ctor since it can lead to a broken reference
    Head(const Head&) = delete;
    
    //- Prints the list of styles into the separate section
    void print_styles(std::ostream& ostr) const;

public:

    //- Default constructor
    Head(CSSClassMap& css_class_map);

    //- Copy constructor
    Head(const Head& h, CSSClassMap& css_class_map);

    //- Destructor
    ~Head();

    //- Print elements in the Head
    std::ostream& print(std::ostream& ostr) const override;
};

//- set nested element for a given Head operator
Element& operator ^ (Head& el, const Element& child);

}

#endif

//
//END-OF-FILE
//
