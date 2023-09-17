#ifndef Education_H
#define Education_H

#include "DocumentImpl.hxx"

namespace c5p
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

