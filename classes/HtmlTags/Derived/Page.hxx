#ifndef Page_H
#define Page_H

#include "Element.hxx"
#include "Compound.hxx"
#include "CSSRegistry.hxx"
#include "JScript.hxx"

namespace krap
{

class Document;

/*---------------------------------------------------------------------------*\
                            Class Page Declaration
\*---------------------------------------------------------------------------*/

class Page
:
    public Element, Compound, CSSRegistry
{
private:

    /// @brief Forbid the constructor without parameters
    Page() = delete;

    /// @brief Forbid copy ctor because it can produce broken links
    /// to css_class_map_
    Page(const Page&) = delete;

    /// @brief Declare % as friend to this class
    friend CSSClassPtr& operator % (Page& page, const CSSClass& css);

    /// @brief Storage for JS in this body
    std::vector<JScript> jscripts_;

public:

    /// @brief Constructor with ref to the specified map for CSS Classes
    Page(CSSClassMap& ccm);

    /// @brief Copy constructor with specified css_class_map
    Page(const Page&, CSSClassMap&);

    /// @brief Destructor
    ~Page();

    /// @brief Print elements in the Page
    std::ostream& print(std::ostream& ostr) const override;

    /// @brief Assign operator
    const Page& operator = (const Compound& );

    /// @brief Adds element and registers its CSS class in the table;
    ElementPtr& add(const Element& elem) override;

    /// @brief Adds element and registers its CSS class in the table;
    ElementPtr& add(Element* elem) override;

    /// @brief Adds element and registers its CSS class in the table;
    ElementPtr& add(const ElementPtr& elem) override;

    /// @brief Adds a java script for this body
    void jscript(const JScript& js);
};

/// @brief apply CSS Class to the page
CSSClassPtr& operator % (Page& el, const CSSClass& css);

}

#endif

//
//END-OF-FILE
//

