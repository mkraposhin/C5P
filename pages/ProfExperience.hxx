#ifndef ProfExperience_H
#define ProfExperience_H

#include "DocumentImpl.hxx"

namespace c5p
{

class ProfExperience : public DocumentImpl
{

private:

    DISALLOW_ALL(ProfExperience)

public:

    // Ctor
    ProfExperience(const Site& site);

    //- Dtor
    ~ProfExperience(){};

};

}

#endif

//
//END-OF-FILE
//

