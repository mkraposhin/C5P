#ifndef WidthAttribute_H
#define WidthAttribute_H

#include "HtmlAttributeBase.hxx"

namespace krap
{
class WidthAttribute : public HtmlAttributeBase
{

    //! The width of an html element in pixels (px)
    unsigned int width_;

public:

    //! Sets the width of an image
    int width(int w)
    {
        width_ = w;
        return width_;
    }

    //! Returns the width of an image
    const int width() const
    {
        return width_;
    }

    //!
    WidthAttribute()
    {
        width_ = 0;
    };

    //! The copy constructor
    WidthAttribute(const WidthAttribute& uria)
    : width_{uria.width_}
    {
    }

    //! Prints the attribute pointing to an html resource
    void print_attribute(std::ostream& ostr) const override final
    {
        if (width_)
        {
            ostr<<" width=" << width_ << " ";
        }
    }
};
}

#endif

//
//END-OF-FILE
//

