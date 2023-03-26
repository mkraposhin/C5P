#ifndef Image_H
#define Image_H

#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                            Class Image Declaration
\*---------------------------------------------------------------------------*/

struct ImageValue : public ValueBase<krap::TagId::IMAGE,true,void*>
{
    //!
    ImageValue() = default;

    //!
    ImageValue(const ImageValue& tval) = default;

    //!
    void value_print(std::ostream& ostr) const override final
    {}
};

using ImageBase = HtmlTagBase<ImageValue,
    SrcAttribute,WidthAttribute>;
using Image = HtmlTagImpl<ImageBase>;
using ImagePtr = std::shared_ptr<Image>;

}

#endif

//
//END-OF-FILE
//
