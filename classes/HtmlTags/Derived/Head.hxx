#ifndef Head_H
#define Head_H

#include "Element.hxx"
#include "JScript.hxx"
#include "CSSRegistry.hxx"
#include "Link.hxx"
#include "Title.hxx"
#include <vector>

namespace c5p
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

    /// @brief Storage for a Link stored in this head
    std::shared_ptr<Link> link_;

    /// @brief A list of the meta tags
    std::list<MetaPair> metas_;

    /// @brief Storage for a title of this head
   TitlePtr title_;

    /// @brief forbid the default constructor
    Head() = delete;

    /// @brief forbid copy ctor since it can lead to a broken reference
    Head(const Head&) = delete;
    
    /// @brief Prints the list of styles into a separate section
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

    /// @brief Sets title for this head
    void title(const std::string& title_name);
};

//! this operator is to set a nested element for a given Head
Element& operator ^ (Head& el, const Element& child);

}

#endif

//
//END-OF-FILE
//
