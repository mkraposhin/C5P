#ifndef Title_H
#define Title_H

#include "Element.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                            Class Title Declaration
\*---------------------------------------------------------------------------*/

class Title
:
    public Element
{
private:

    //- The text in the title
    std::string ttext_;

public:

    //- Default constructor
    Title();

    //- Create from the text string
    Title(const std::string& text);

    //- Copy constructor
    Title(const Title& );

    //- Destructor
    ~Title();

    //- Print elements in the Title
    std::ostream& print(std::ostream& ostr) const override;

    //- Creates clone of the ParagraphText
    ElementPtr clone() const override;
};

}

#endif

//
//END-OF-FILE
//
