#ifndef UnorderedList_H
#define UnorderedList_H

#include "Compound.hxx"
#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace c5p
{

//!
struct UnorderedListValue : public ValueBase<c5p::TagId::UNORDERED_LIST,true,void*>, public Compound
{
    //!
    UnorderedListValue() = default;
    
    //!
    UnorderedListValue(const UnorderedListValue& uolist)
    :
        ValueBase(),
        Compound(uolist)
    {}

    //!
    void value_print(std::ostream& ostr) const override
    {
        Compound::print(ostr);
    }
};

using UnorderedListBase = HtmlTagBase<UnorderedListValue,IdAttribute>;
using UnorderedList = CompoundTagInitializer<HtmlTagImpl<UnorderedListBase>>;

}

#endif

//
//END-OF-FILE
//
