#ifndef Link_H
#define Link_H

#include "Element.hxx"

namespace krap
{

class Link : public Element
{

private:

    //!
    const std::string rel_;

    //!
    const std::string href_;

public:

    //!
    Link(const std::string& rel, const std::string& href);

    //!
    ~Link();

    //! creates clone of itself
    ElementPtr clone() const override;

    //! Print elements in the Link
    std::ostream& print(std::ostream& ostr) const override;

};

}

#endif

//
//END-OF-FILE
//

