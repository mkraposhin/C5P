#ifndef MyContributions_H
#define MyContributions_H

#include "DocumentImpl.hxx"

namespace c5p
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

