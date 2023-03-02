#ifndef Contacts_H
#define Contacts_H

#include "DocumentImpl.hxx"

namespace krap
{

class Contacts : public DocumentImpl
{

private:

    DISALLOW_ALL(Contacts)

public:

    // Ctor
    Contacts(const Site& site);

    //- Dtor
    ~Contacts(){};

};

}

#endif

//
//END-OF-FILE
//

