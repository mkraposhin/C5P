#ifndef Title_H
#define Title_H

#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace c5p
{

/*---------------------------------------------------------------------------*\
                            Class Title Declaration
\*---------------------------------------------------------------------------*/

struct TitleValue : public ValueBase<c5p::TagId::TITLE,true,std::string>
{
    //!
    TitleValue() = default;

    //!
    TitleValue(const TitleValue& tval) = default;

    //!
    void value_print(std::ostream& ostr) const override
    {
        ostr << value_;
    }
};

using TitleBase = HtmlTagBase<TitleValue>;
using Title = HtmlTagImpl<TitleBase>;

using TitlePtr = std::shared_ptr<Title>;

}

#endif

//
//END-OF-FILE
//
