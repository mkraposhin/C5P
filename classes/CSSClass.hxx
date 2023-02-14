#ifndef CSSClass_H
#define CSSClass_H

#include "Element.hxx"
#include "CSSElement.hxx"
#include <map>

namespace krap
{

/*---------------------------------------------------------------------------*\
                            Class CSSClass Declaration
\*---------------------------------------------------------------------------*/

class CSSClass
:
    public Element
{
private:

    //- The name of CSS Class
    std::string css_class_;

    //- The list of properties(css elements)
    std::map<std::string,std::shared_ptr<CSSElement>> css_properties_;

    //- The type for the record
    using css_rec_type = std::pair<std::string,std::shared_ptr<CSSElement>>;

public:

    //- Default constructor
    CSSClass();

    //- Create from the text string
    CSSClass(const std::string& name);

    //- Copy constructor
    CSSClass(const CSSClass& );

    //- Destructor
    ~CSSClass();

    //- Print elements in the CSSClass
    std::ostream& print(std::ostream& ostr) const override;

    //- Creates clone of the CSSClass
    ElementPtr clone() const override;

    //- Returns the name of the class 
    const std::string& name() const;

    //- Adds property
    void add(const CSSElement& element);

    //- Assigns properties from other css class object to this one
    // creating deep copy of the corresponding map
    const CSSClass& operator = (const CSSClass& css_class);
};

}

#endif

//
//END-OF-FILE
//
