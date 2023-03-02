#ifndef Head_H
#define Head_H

#include "Element.hxx"
#include "JScript.hxx"
#include "CSSRegistry.hxx"
#include "Link.hxx"

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

    //! Storage for a JS stored in this head
    std::shared_ptr<JScript> jscript_;

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

    //! Default constructor
    Head(CSSClassMap& css_class_map);

    //! Copy constructor
    Head(const Head& h, CSSClassMap& css_class_map);

    //! Destructor
    ~Head();

    //! Print elements in the Head
    std::ostream& print(std::ostream& ostr) const override;

    //! Sets a java script for this head
    void jscript(const JScript& js);

    //! Sets the link tag
    void link(const Link& l);

    //! Adds a new meta tag
    void add_meta(const std::string name, const std::string content);
};

//! this operator is to set a nested element for a given Head
Element& operator ^ (Head& el, const Element& child);

}

#endif

//
//END-OF-FILE
//
