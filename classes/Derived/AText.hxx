#ifndef AText_H
#define AText_H

#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                            Class ATextValue Declaration
\*---------------------------------------------------------------------------*/

struct ATextValue
{
    //!
    using value_type = std::string;

    //!
    const std::string tag_str = "a";

    //!
    const bool has_closing    = true;

    //! The text stored in this html element
    std::string text_;

    //!
    ATextValue()
    : text_(""){}

    //!
    ATextValue(const ATextValue& tval)
    : text_(tval.text_){}

    //!
    void value_print(std::ostream& ostr) const
    {
        ostr << text_;
    }
};

using ATextBase = HtmlTagBase<ATextValue,
    UriAttribute,OnClickAttribute,IdAttribute>;

class AText;
using ATextPtr = std::shared_ptr<AText>;

/*---------------------------------------------------------------------------*\
                            Class AText Declaration
\*---------------------------------------------------------------------------*/

class AText
:
    public ATextBase
{
public:

    //! Default constructor
    AText() = default;

    //! Create from the text string
    explicit AText(const std::string& text)
    :
    ATextBase(){text_ = text;}

    //! Copy constructor
    AText(const AText& p) = default;

    //! Destructor
    ~AText(){};

    //! Creates a clone of an "a" html tag
    ElementPtr clone () const override
    {
        return ElementPtr(new AText{*this});
    }
};

}

#endif

//
//END-OF-FILE
//
