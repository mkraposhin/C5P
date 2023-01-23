#ifndef AText_H
#define AText_H

#include "Element.hxx"
#include "Uri.hxx"

namespace krap
{

class Uri;

class AText;
using ATextPtr = std::shared_ptr<AText>;

/*---------------------------------------------------------------------------*\
                            Class AText Declaration
\*---------------------------------------------------------------------------*/

class AText
:
    public Element
{
private:

    //- The text
    std::string text_;
    
    //- The uri
    UriPtr uri_;

public:

    //- Default constructor
    AText();

    //- Create from the text string
    AText(const std::string& text);

    //- Copy constructor
    AText(const AText& p);

    //- Destructor
    ~AText();

    //- Print elements in the AText
    std::ostream& print(std::ostream& ostr) const override;

    //- Creates clone of the AText
    ElementPtr clone() const override;

    //- Sets uri
    void uri (const std::string& s);
};

}

#endif

//
//END-OF-FILE
//
