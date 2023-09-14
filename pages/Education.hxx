#ifndef Education_H
#define Education_H

#include "DocumentImpl.hxx"

namespace krap
{

class Education : public DocumentImpl
{

private:

    DISALLOW_ALL(Education)

public:

    // Ctor
    Education(const Site& site);

    //- Dtor
    ~Education(){};

};

}

#endif

//
//END-OF-FILE
//

