#ifndef UriAttribute_H
#define UriAttribute_H

#include "HtmlAttributeBase.hxx"
#include "Uri.hxx"

namespace krap
{
class UriAttribute : public HtmlAttributeBase
{

    //! The uri to which an html element may point
    UriPtr uri_;

public:

    //! Sets this uri from the string s
    void uri (const std::string& s)
    {
        if (s.empty())
        {
            uri_.reset();
        }
        else
        {
            uri_.reset(new Uri(s));
        }
    }

    //!
    UriAttribute(){};

    //! The copy constructor
    UriAttribute(const UriAttribute& uria)
    : uri_{nullptr}
    {
        //std::cout << uria.uri_.get() << std::endl;
        if (uria.uri_)
        {
            uri_.reset(new Uri{*uria.uri_});
        }
    }

    //! Prints the attribute pointing to an html resource
    void print_attribute(std::ostream& ostr) const override final
    {
        if (bool(uri_))
        {
            ostr<<" href=" << uri_->uri() << " ";
        }
    }
};
}

#endif

//
//END-OF-FILE
//

