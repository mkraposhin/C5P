#ifndef Head_H
#define Head_H

#include "Element.hxx"
#include "JScript.hxx"
#include "CSSRegistry.hxx"
#include "Link.hxx"
#include <vector>

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

    //! Gives access to CSSRegistry functions
    friend Element& operator ^ (Head& el, const Element& child);

    //! This defines a content of the meta tag
    using MetaPair = std::pair<std::string,std::string>;

private:

    /// @brief Storage for JS in this head
    std::vector<JScript> jscripts_;

    //! Storage for a Link stored in this head
    std::shared_ptr<Link> link_;

    //! A list of the meta tags
    std::list<MetaPair> metas_;

    //! forbid the default constructor
    Head() = delete;

    //! forbid copy ctor since it can lead to a broken reference
    Head(const Head&) = delete;
    
    //! Prints the list of styles into a separate section
    void print_styles(std::ostream& ostr) const;

public:

    /// @brief Default constructor
    Head(CSSClassMap& css_class_map);

    /// @brief Copy constructor
    Head(const Head& h, CSSClassMap& css_class_map);

    /// @brief Destructor
    ~Head();

    /// @brief Prints elements in the Head
    std::ostream& print(std::ostream& ostr) const override;

    /// @brief Adds a java script for this head
    void jscript(const JScript& js);

    /// @brief Sets the link tag
    void link(const Link& l);

    /// @brief Adds a new meta tag
    void add_meta(const std::string name, const std::string content);
};

//! this operator is to set a nested element for a given Head
Element& operator ^ (Head& el, const Element& child);

}

#endif

//
//END-OF-FILE
//
