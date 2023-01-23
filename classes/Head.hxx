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

    //- the reference to the map of CSS Classes applied in the document
    CSSClassMap& css_class_map_;

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

}

#endif

//
//END-OF-FILE
//
