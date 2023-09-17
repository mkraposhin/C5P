#ifndef Link_H
#define Link_H

#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace c5p
{

/*---------------------------------------------------------------------------*\
                            Class Link Declaration
\*---------------------------------------------------------------------------*/

struct LinkValue : public ValueBase<c5p::TagId::LINK,false,void*>
{
    //!
    LinkValue() = default;

    //!
    LinkValue(const LinkValue& tval) = default;

    //!
    void value_print(std::ostream& ostr) const override
    {}
};

using LinkBase = HtmlTagBase<LinkValue,RelAttribute,UriAttribute>;
using Link = HtmlTagImpl<LinkBase>;

using LinkPtr = std::shared_ptr<Link>;

}

#endif

//
//END-OF-FILE
//

