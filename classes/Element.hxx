#ifndef Element_H
#define Element_H

#include <iostream>
#include <memory>
#include <map>

namespace krap
{

//- Forward declaration of Element
class Element;

typedef std::shared_ptr<Element> ElementPtr;

class CSSClass;

typedef std::shared_ptr<CSSClass> CSSClassPtr;

typedef std::map<std::string,CSSClassPtr> CSSClassMap;

typedef std::pair<std::string,CSSClassPtr> CSSClassMapRec;


class Element
{

private:

    //- Pointer to the child
    ElementPtr child_;

    //- Pointer to the css class (if applicable)
    CSSClassPtr css_;

    //- Sets the pointer to new child
    void set_child(ElementPtr& new_child);

    //- Sets the CSS Class for this element
    void set_css_class(CSSClass& css);

    //-
    friend Element& operator ^ (Element& el, Element& child);

    //-
    friend CSSClassPtr& operator % (Element& el, CSSClass& css);

    //-
    friend CSSClassPtr& operator % (Element& el, CSSClassPtr& cssptr);

public:

    //- Default constructor
    Element();

    //- Copy constructor
    Element(const Element&);

    //- Destructor
    ~Element();

    //-
    virtual std::ostream& print(std::ostream& ostr) const;

    //- creates clone of itself
    virtual ElementPtr clone() const;

    //- gives const-ref access to the style class
    const CSSClassPtr& css() const;
};


//- ostream output operator
std::ostream& operator << (std::ostream& ostr, const Element& elem);

//- set nested element operator
Element& operator ^ (Element& el, Element& child);

//- apply CSS Class to this element
CSSClassPtr& operator % (Element& el, CSSClass& css);

//- apply CSS Class to this element
CSSClassPtr& operator % (Element& el, CSSClassPtr& cssptr);;

}//namespace krap

#endif

//
//END-OF-FILE
//

