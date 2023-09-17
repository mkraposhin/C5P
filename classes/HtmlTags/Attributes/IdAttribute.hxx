#ifndef IdAttribute_H
#define IdAttribute_H

#include "HtmlAttributeBase.hxx"

namespace c5p
{

class IdAttribute : public HtmlAttributeBase
{

    //! A string with the id of a tag
    std::string id_;

public:

    //! Sets the id attribute of an element
    void id (const std::string& id)
    {
        id_ = id;
    }

    //! Returs the id attribute of an element
    const std::string id() const
    {
        return id_;
    }

    //!
    IdAttribute():id_(std::string("")){};

    //! The copy constructor
    IdAttribute(const IdAttribute& attr)
    : id_(attr.id_){}

    //! Prints the attribute pointing to a java script in a document
    void print_attribute(std::ostream& ostr) const override final
    {
        if (id_ != std::string(""))
        {
            ostr<<" id=" << id_ << " ";
        }
    }
};

}

#endif

//
//END-OF-FILE
//

