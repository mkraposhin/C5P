#ifndef DocumentImpl_H
#define DocumentImpl_H

#include "Document.hxx"
#include "MainMenu.hxx"
#include "Site.hxx"

namespace krap
{

class DocumentImpl : public Document
{

private:

    //- Disallow default Ctor
    DocumentImpl() = delete;

private:

    //- Reference to the site where this document is located
    const Site& site_;

    //- Reference to the main menu of the site
    const MainMenu& mm_;

protected:

    //- this is invoked to construct the common part of document
    virtual void construct();

public:

    //- Generates empty document with css and basic settings
    DocumentImpl(const Site& site);

    //- Copy constructor
    DocumentImpl(const DocumentImpl&);

    //- creates a clone of this document
    ElementPtr clone() const override;

    //- Print the content of the document
    std::ostream& print(std::ostream& ostr) const override final;

    //- Dtor
    ~DocumentImpl(){};

};

}

#endif

//
//END-OF-FIE
//

