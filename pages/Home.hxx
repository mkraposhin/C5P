#ifndef Home_H
#define Home_H

#include "DocumentImpl.hxx"

namespace krap
{

class Home : public DocumentImpl
{

private:

    DISALLOW_ALL(Home);

public:

    // Ctor
    Home(const Site& site);

    //- Dtor
    ~Home(){};

};

}

#endif

//
//END-OF-FILE
//

