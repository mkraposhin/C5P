#ifndef Document_H
#define Document_H

#include "Page.hxx"
#include "Head.hxx"

namespace krap
{

/*---------------------------------------------------------------------------*\
                          Class Document Declaration
\*---------------------------------------------------------------------------*/

class Document;

using DocumentPtr = std::shared_ptr<Document>;

class Document
:
    public Element
{
protected:

    //-
    CSSClassMap css_class_map_;

    //- Represents the header of the document
    Head head_;

    //- Represents the body of the document
    Page body_;


public:
     
    //- Default constructor (creates empty compound)
    Document();

    //- Copy constructor
    Document(const Document&);

    //- Destructor
    ~Document();

    //- Print the content of the document
    virtual std::ostream& print(std::ostream& ostr) const override;

    //- Non-const access to the documents body
    Page& body();
    
    //- Non-const access to the documents head
    Head& head();

    //- creates a clone of itself
    virtual ElementPtr clone() const override;
};

}

#endif

//
//END-OF-FILE
//

