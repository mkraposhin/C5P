#ifndef Div_H
#define Div_H

#include "Compound.hxx"
#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace krap
{

struct DivValue : public Compound
{
    //!
    const std::string tag_str = "div";

    //!
    const bool has_closing    = true;

    //!
    DivValue()
    : Compound(){}

    //!
    DivValue(const DivValue& divval)
    : Compound(divval){}

    //!
    void value_print(std::ostream& ostr) const
    {
        Compound::print(ostr);
    }
};

using DivBase = HtmlTagBase<DivValue,IdAttribute>;

/*---------------------------------------------------------------------------*\
                            Class Div Declaration
\*---------------------------------------------------------------------------*/

class Div
:
    public DivBase
{
private:

public:

    //! Default constructor (Empty Div container)
    Div()
    :
    DivBase(){}

    //! Copy constructor
    Div(const Div& div)
    :
    DivBase(div){}

    //! Destructor
    ~Div(){};

    //! Creates clone of a Div
    virtual ElementPtr clone() const override
    {
        return ElementPtr(new Div(*this));
    }    
};

}

#endif

//
//END-OF-FILE
//
