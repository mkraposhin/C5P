#ifndef SrcAttribute_H
#define SrcAttribute_H

#include "HtmlAttributeBase.hxx"
#include "Uri.hxx"

namespace c5p
{
class SrcAttribute : public HtmlAttributeBase
{

    //! The uri to which an html element may point
    UriPtr src_uri_;

public:

    //! Sets this uri from the string s
    void src (const std::string& s)
    {
        if (s.empty())
        {
            src_uri_.reset();
        }
        else
        {
            src_uri_.reset(new Uri(s));
        }
    }

    //!
    SrcAttribute(){};

    //! The copy constructor
    SrcAttribute(const SrcAttribute& uria)
    : src_uri_{nullptr}
    {
        //std::cout << uria.uri_.get() << std::endl;
        if (uria.src_uri_)
        {
            src_uri_.reset(new Uri{*uria.src_uri_});
        }
    }

    //! Prints the attribute pointing to an html resource
    void print_attribute(std::ostream& ostr) const override final
    {
        if (bool(src_uri_))
        {
            ostr<<" src=" << src_uri_->uri() << " ";
        }
    }
};
}

#endif

//
//END-OF-FILE
//

