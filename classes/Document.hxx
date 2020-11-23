#ifndef Document_H
#define Document_H

#include "Page.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                          Class Document Declaration
\*---------------------------------------------------------------------------*/

class Document
:
    public Element
{
protected:

    //- Represents the header of the document
    Element header_;

    //- Represents the body of the document
    Compound body_;


public:
     
    //- Default constructor (creates empty compound)
    Document();

    //- Copy constructor
    Document(const Document&);

    //- Destructor
    ~Document();

    //- Print the content of the document
    std::ostream& print(std::ostream& ostr) const;
};

}

#endif

//
//END-OF-FILE
//

