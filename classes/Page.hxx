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

    //- Forbid copy ctor because it can produce broken links
    //to css_class_map_
    Page(const Page&) = delete;

    //- Registers CSS from the Element
    void register_css_class(const Element& elem);
    
    //- Registers CSS from the ElementPtr
    void register_css_class(const ElementPtr& elemptr);

    //- Declare % as friend to this class
    friend CSSClassPtr& operator % (Page& page, const CSSClass& css);


public:

    //-  Constructor with ref to the specified map for CSS Classes
    Page(CSSClassMap& ccm);

    //- Copy constructor with specified css_class_map
    Page(const Page&, CSSClassMap&);

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

//- apply CSS Class to the page
CSSClassPtr& operator % (Page& el, const CSSClass& css);

}

#endif

//
//END-OF-FILE
//

