#ifndef CSSRegistry_H
#define CSSRegistry_H

#include "CSSClass.hxx"

namespace krap
{

class CSSRegistry
{

private:

    //! Forbid = operators
    DISALLOW_EQ(CSSRegistry);

    //! Forbid copy ctors
    DISALLOW_COPY(CSSRegistry);

protected:

    //! the reference to the map of CSS Classes applied in the document
    CSSClassMap& css_class_map_;

    //! Registers the CSS from a given Element
    void register_css_class(const Element& elem);

    //! Registers the CSS from an ElementPtr
    virtual void register_css_class(const ElementPtr& elemptr);

public:

    //!
    explicit CSSRegistry (CSSClassMap& css_map);

};

}

#endif

//
//END-OF-FILE
//

