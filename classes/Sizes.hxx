#ifndef Sizes
#define Sizes

#include "CSSElement.hxx"

namespace krap
{

class Width : public CSSElement
{

public:

    //- Creates a CSS property that sets width of an element
    Width(const int sz)
    :
    CSSElement("width", std::to_string(sz) + std::string("px")){}

    //- Destroys a CSS property
    ~Width(){}

};

class Height : public CSSElement
{

public:

    //- Creates a CSS property that sets width of an element
    Height(const int sz)
    :
    CSSElement("height", std::to_string(sz) + std::string("px")){}

    //- Destroys a CSS property
    ~Height(){}

};

}

#endif

//
//END-OF-FILE
//
