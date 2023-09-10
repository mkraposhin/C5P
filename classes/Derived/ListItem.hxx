#ifndef ListItem_H
#define ListItem_H

#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                            Class ListItemImpl Declaration
\*---------------------------------------------------------------------------*/

/// @brief represents <li> </li> HTML element
struct ListItemValue : public ValueBase<krap::TagId::LIST_ITEM,true,std::string>
{
    /// @brief default constructor
    ListItemValue() = default;

    // @brief default copy constructor
    ListItemValue(const ListItemValue& tval) = default;

    //!
    void value_print(std::ostream& ostr) const override
    {
        ostr << value_;
    }
};

using ListItemBase = HtmlTagBase<ListItemValue,UriAttribute>;
using ListItem = HtmlTagImpl<ListItemBase>;

using ListItemPtr = std::shared_ptr<ListItem>;

}

#endif

//
//END-OF-FILE
//
