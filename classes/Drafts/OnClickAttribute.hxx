#ifndef OnClickAttribute_H
#define OnClickAttribute_H

#include "HtmlAttributeBase.hxx"
#include "JScript.hxx"

namespace krap
{
class OnClickAttribute : public HtmlAttributeBase
{

    //! Contains a name of a function to be executed on the click event
    std::string on_click_;

public:

    //! Sets a java-script function
    void on_click (const JScript& js)
    {
        on_click_ = js.function_name();
    }

    //!
    OnClickAttribute(){};

    //! The copy constructor
    OnClickAttribute(const OnClickAttribute& ona)
    : on_click_(ona.on_click_){}

    //! Prints the attribute pointing to a java script in a document
    void print_attribute(std::ostream& ostr) const override final
    {
        if (on_click_ != std::string(""))
        {
            ostr<<" onclick=" << on_click_ << " ";
        }
    }
};
}

#endif

//
//END-OF-FILE
//

