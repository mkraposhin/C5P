#ifndef AText_H
#define AText_H

#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                            Class ATextImpl Declaration
\*---------------------------------------------------------------------------*/

struct ATextValue : public ValueBase<krap::TagId::A,true,std::string>
{
    //!
    ATextValue() = default;

    //!
    ATextValue(const ATextValue& tval) = default;

    //!
    void value_print(std::ostream& ostr) const override
    {
        ostr << value_;
    }
};

using ATextBase = HtmlTagBase<ATextValue,
    UriAttribute,OnClickAttribute,IdAttribute>;
using AText = HtmlTagImpl<ATextBase>;

using ATextPtr = std::shared_ptr<AText>;

}

#endif

//
//END-OF-FILE
//
