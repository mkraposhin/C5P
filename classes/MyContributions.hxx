#ifndef MyContributions_H
#define MyContributions_H

#include "DocumentImpl.hxx"

namespace krap
{

class MyContributions : public DocumentImpl
{

private:

    DISALLOW_ALL(MyContributions);

public:

    /// @brief Ctor
    MyContributions(const Site& site);

    /// @brief Dtor
    ~MyContributions();

};

}

#endif

