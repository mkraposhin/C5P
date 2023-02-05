#ifndef MyOssProjects_H
#define MyOssProjects_H

#include "DocumentImpl.hxx"

namespace krap
{

class MyOssProjects : public DocumentImpl
{

private:

    DISALLOW_ALL(MyOssProjects);

public:

    // Ctor
    MyOssProjects(const Site& site);

    //- Dtor
    ~MyOssProjects(){};

};

}

#endif

//
//END-OF-FILE
//

