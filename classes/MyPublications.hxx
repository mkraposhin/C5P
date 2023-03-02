#ifndef MyPublications_H
#define MyPublications_h

#include "DocumentImpl.hxx"

namespace krap
{

class MyPublications : public DocumentImpl
{

private:

    //DISALLOW_ALL(MyPublications);

public:

    // Ctor
    MyPublications(const Site& site);

    //- Dtor
    ~MyPublications(){};

};

}

#endif

//
//END-OF-FILE
//

