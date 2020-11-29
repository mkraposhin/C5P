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

    //- the reference to the map of CSS Classes applied in the document
    CSSClassMap& css_class_map_;

    //- Forbid the constructor without parameters
    Page() = delete;

    //- Registers CSS from the Element
    void register_css_clas(ElementPtr& elem);


public:

    //-  Constructor with ref to the specified map for CSS Classes
    Page(CSSClassMap& ccm);

    //- Copy constructor
    Page(const Page&);

    //- Destructor
    ~Page();

    //- Print elements in the Page
    std::ostream& print(std::ostream& ostr) const override;

    //- Assign operator
    const Page& operator = (const Compound& );

    //- Adds element and registers its CSS class in the table;
    ElementPtr& add(const Element& elem) override;

    //- Adds element and registers its CSS class in the table;
    ElementPtr& add(Element* elem) override;

    //- Adds element and registers its CSS class in the table;
    ElementPtr& add(ElementPtr& elem) override;

};

}

#endif

//
//END-OF-FILE
//

