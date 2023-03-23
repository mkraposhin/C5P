#ifndef ParagraphText_H
#define ParagraphText_H

#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                            Class ATextValue Declaration
\*---------------------------------------------------------------------------*/

struct ParagraphValue
{
    //!
    using value_type = std::string;

    //!
    const std::string tag_str = "p";

    //!
    const bool has_closing    = true;

    //! The text stored in this html element
    std::string text_;

    //!
    ParagraphValue()
    : text_(""){}

    //!
    ParagraphValue(const ParagraphValue& tval)
    : text_(tval.text_){}

    //!
    void value_print(std::ostream& ostr) const
    {
        ostr << text_;
    }
};

using ParagraphTextBase = HtmlTagBase<ParagraphValue,
    UriAttribute,OnClickAttribute,IdAttribute>;

/*---------------------------------------------------------------------------*\
                            Class ParagraphText Declaration
\*---------------------------------------------------------------------------*/

class ParagraphText
:
    public ParagraphTextBase
{
public:

    //! Default constructor
    ParagraphText() = default;

    //! Create from the text string
    explicit ParagraphText(const std::string& text)
    :
    ParagraphTextBase()
    {
        text_ = text;
    }

    //! Copy constructor
    ParagraphText(const ParagraphText& p) = default;

    //! Destructor
    ~ParagraphText()
    {}

    //! Creates clone of the ParagraphText
    ElementPtr clone() const override
    {
        return ElementPtr(new ParagraphText(*this));
    }
};

}

#endif

//
//END-OF-FILE
//
