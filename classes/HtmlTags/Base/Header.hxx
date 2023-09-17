#ifndef Header_H
#define Header_H

#include "Element.hxx"
#include "CSSClass.hxx"
#include <cgicc/HTMLClasses.h>

namespace c5p
{

template <int lev>
class Header : public Element
{

private:

    DISALLOW_EQ(Header<lev>);
    DISALLOW_COPY(Header<lev>);

    //- Text of a Header
    const std::string txt_;

    //- prints using given cgicc header object
    template <class H> std::ostream&
    print_header (H&& h_obj, std::ostream& ostr) const;

public:

    //- Creates an instance of H<lev> html element
    Header<lev>(const std::string txt)
    :
    Element(),
    txt_(txt)
    {}

    // Dtor
    ~Header<lev>(){}

    //- Prints header at different levels (levels 1,2,3 are now supported)
    std::ostream& print(std::ostream& ostr) const override;

    //- creates clone of itself
    virtual ElementPtr clone() const override;
};

template <int lev>
template <class H>
std::ostream& Header<lev>::print_header (H&& h_obj, std::ostream& ostr) const
{
    if (css())
    {
        ostr<< h_obj.set("class", (*css()).name())
            << txt_ << h_obj << std::endl;
    }
    else
    {
        ostr<< h_obj << txt_ << h_obj << std::endl;
    }
    return ostr;
}

template <int lev> std::ostream&
Header<lev>::print(std::ostream& ostr) const
{
    if constexpr (lev == 1)
    {
        return print_header(cgicc::h1(), ostr);
    }
    if constexpr (lev == 2)
    {
        return print_header(cgicc::h2(), ostr);
    }
    if constexpr (lev == 3)
    {
        return print_header(cgicc::h3(), ostr);
    }

    return ostr;
}

template <int lev>
ElementPtr Header<lev>::clone() const
{
    return ElementPtr(new Header<lev>(this->txt_));
}

}

#endif

//
//END-OF-FILE
//

