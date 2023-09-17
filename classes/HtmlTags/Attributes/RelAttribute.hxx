#ifndef RelAttribute_H
#define RelAttribute_H

#include "HtmlAttributeBase.hxx"
#include "Uri.hxx"

namespace c5p
{
class RelAttribute : public HtmlAttributeBase
{

    //! sets relationship type
    std::string rel_;

public:

    //! Sets this uri from the string s
    void rel (const std::string& rel)
    {
        rel_ = rel;
    }

    //!
    RelAttribute(){};

    //! The copy constructor
    RelAttribute(const RelAttribute& rel)
    : rel_{rel.rel_}
    {}

    //! Prints the attribute pointing to an html resource
    void print_attribute(std::ostream& ostr) const override final
    {
        if (!rel_.empty())
        {
            ostr<<" rel=" << rel_ << " ";
        }
    }
};
}

#endif

//
//END-OF-FILE
//

