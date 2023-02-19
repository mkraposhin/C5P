#ifndef ParagraphText_H
#define ParagraphText_H

#include "Element.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                            Class ParagraphText Declaration
\*---------------------------------------------------------------------------*/

class ParagraphText
:
    public Element
{
private:

    //- The text in the paragraph
    std::string partext_;

public:

    //- Default constructor
    ParagraphText();

    //- Create from the text string
    ParagraphText(const std::string& text);

    //- Copy constructor
    ParagraphText(const ParagraphText& p);

    //- Destructor
    ~ParagraphText();

    //- Print elements in the ParagraphText
    std::ostream& print(std::ostream& ostr) const override;

    //- Creates clone of the ParagraphText
    ElementPtr clone() const override;
};

}

#endif

//
//END-OF-FILE
//
