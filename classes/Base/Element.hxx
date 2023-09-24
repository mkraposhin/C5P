#ifndef Element_H
#define Element_H

#include <iostream>
#include <memory>
#include <list>

#include "Globals.hxx"

namespace c5p
{

//- Forward declaration of Element
class Element;

using ElementPtr = std::shared_ptr<Element>;

class CSSClass;

using CSSClassPtr = std::shared_ptr<CSSClass>;
using CSSClassMapRec = std::pair<std::string,CSSClassPtr>;
//using CSSClassMap = std::map<std::string,CSSClassPtr>;
using CSSClassMap = std::list<CSSClassMapRec>;


class Element
{

private:

    /// @brief Pointer to the child of this Element object
    ElementPtr child_;

    /// @brief Pointer to the css class (if applicable)
    CSSClassPtr css_;

    /// @brief Sets the pointer to new child
    void set_child(ElementPtr& new_child);

    /// @brief Sets the CSS Class for this element
    void set_css_class(const CSSClass& css);

    /// @brief this operator adds child element to the Element el
    friend Element& operator ^ (Element& el, const Element& child);

    /// @brief this operator applies CSSClass stored in the reference css
    friend CSSClassPtr& operator % (Element& el, const CSSClass& css);

    /// @brief this operator applies CSSClass stored in the pointer cssptr
    friend CSSClassPtr& operator % (Element& el, CSSClassPtr& cssptr);

public:

    /// @brief Default constructor
    Element();

    /// @brief Copy constructor
    Element(const Element&);

    /// @brief Destructor
    ~Element();

    /// @brief 
    virtual std::ostream& print(std::ostream& ostr) const;

    /// @brief creates clone of itself
    virtual ElementPtr clone() const;

    /// @brief const-ref access to the child pointr
    const ElementPtr& child() const;

    /// @brief gives const-ref access to the style class
    const CSSClassPtr& css() const;
};

//! ostream output operator
std::ostream& operator << (std::ostream& ostr, const Element& elem);

//- set nested element operator
Element& operator ^ (Element& el, const Element& child);

//- apply CSS Class to this element
CSSClassPtr& operator % (Element& el, const CSSClass& css);

//- apply CSS Class to this element
CSSClassPtr& operator % (Element& el, CSSClassPtr& cssptr);

}//namespace krap

#endif

//
//END-OF-FILE
//

