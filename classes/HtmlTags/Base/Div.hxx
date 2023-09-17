#ifndef Div_H
#define Div_H

#include "Compound.hxx"
#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace krap
{

//!
struct DivValue : public ValueBase<krap::TagId::DIV,true,void*>, public Compound
{
    //!
    DivValue() = default;
    
    //!
    DivValue(const DivValue& divval) = default;

    //!
    void value_print(std::ostream& ostr) const override
    {
        Compound::print(ostr);
    }
};

using DivBase = HtmlTagBase<DivValue,IdAttribute>;
using Div = CompoundTagInitializer<HtmlTagImpl<DivBase>>;
// using Div = HtmlTagImpl<DivBase>;

}

#endif

//
//END-OF-FILE
//
