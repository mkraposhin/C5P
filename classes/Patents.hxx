#ifndef Patents_H
#define Patents_H

#include "DocumentImpl.hxx"

namespace krap
{

class Patents : public DocumentImpl
{

private:

    DISALLOW_ALL(Patents)

public:

    // Ctor
    Patents(const Site& site);

    //- Dtor
    ~Patents(){};

};

}

#endif

//
//END-OF-FILE
//

