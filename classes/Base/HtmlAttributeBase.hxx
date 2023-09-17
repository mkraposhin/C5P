#ifndef HtmlAttributeBase_H
#define HtmlAttributeBase_H

#include <string>
#include <iostream>

namespace c5p
{

//! A base class to define an html attribute
struct HtmlAttributeBase
{
    //! Prints a given html attribute to a given stream
    virtual void print_attribute(std::ostream& ) const = 0;

    //! Default ctor;
    HtmlAttributeBase(){};

    //! Dtor
    ~HtmlAttributeBase(){};

    //! Copy ctor
    HtmlAttributeBase(const HtmlAttributeBase&){};

private:

    //! Disallow move ctor
    HtmlAttributeBase(HtmlAttributeBase&&) = delete;

    //! Disallow move assignement
    const HtmlAttributeBase& operator = (HtmlAttributeBase&&) = delete;
};
}

#endif

//
//
//

