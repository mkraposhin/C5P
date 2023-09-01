#ifndef Button_H
#define Button_H

#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                            Class ButtonImpl Declaration
\*---------------------------------------------------------------------------*/

struct ButtonValue : public ValueBase<krap::TagId::BUTTON,true,std::string>
{
    //!
    ButtonValue() = default;

    //!
    ButtonValue(const ButtonValue& tval) = default;

    //!
    void value_print(std::ostream& ostr) const override
    {
        ostr << value_;
    }
};

using ButtonBase = HtmlTagBase<ButtonValue,
    UriAttribute,OnClickAttribute,IdAttribute>;
using Button = HtmlTagImpl<ButtonBase>;

using ButtonPtr = std::shared_ptr<Button>;

}

#endif

//
//END-OF-FILE
//
