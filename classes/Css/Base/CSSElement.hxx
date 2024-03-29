#ifndef CSSElement_H
#define CSSElement_H

#include "Element.hxx"

namespace c5p
{

/*---------------------------------------------------------------------------*\
                            Class CSSElement Declaration
\*---------------------------------------------------------------------------*/

class CSSElement
:
    public Element
{
private:

    //- The property name of CSS
    std::string css_name_;

    //- The property value
    std::string css_value_;

public:

    /// @brief Forbid default constructor
    CSSElement() = delete;

    //- Create from the name and the text string 
    CSSElement(const std::string& name, const std::string& text);

    //- Copy constructor
    CSSElement(const CSSElement& css_elem);

    //- Destructor
    ~CSSElement();

    //- Print elements in the CSSElement
    std::ostream& print(std::ostream& ostr) const override;

    //- Creates clone of the CSSElement
    ElementPtr clone() const override;

    //- Returns the name of the property
    const std::string& name() const;

    //- Returns the std::string of the value
    const std::string& value() const;
};

}

#endif

//
//END-OF-FILE
//
