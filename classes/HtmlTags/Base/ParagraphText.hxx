#ifndef ParagraphText_H
#define ParagraphText_H

#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace c5p
{
/*---------------------------------------------------------------------------*\
                            Class ParagraphText Declaration
\*---------------------------------------------------------------------------*/

struct ParagraphTextValue : public ValueBase<c5p::TagId::P,true,std::string>
{
    //!
    ParagraphTextValue() = default;

    //!
    ParagraphTextValue(const ParagraphTextValue& tval) = default;

    //!
    void value_print(std::ostream& ostr) const override
    {
        ostr << value_;
    }
};

using ParagraphTextBase = HtmlTagBase<ParagraphTextValue>;
using ParagraphText = HtmlTagImpl<ParagraphTextBase>;

using ParagraphPtr = std::shared_ptr<ParagraphText>;

}

#endif

//
//END-OF-FILE
//
