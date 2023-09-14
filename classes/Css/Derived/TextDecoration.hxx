#ifndef TextDecoration_H
#define TextDecoration_H

#include "CSSElement.hxx"

namespace krap
{

template <char decoration>
class TextDecoration : public CSSElement
{
public:
    
    //- Creates a decoration from the type of underline
    TextDecoration<decoration>()
    :
    CSSElement(std::string("text-decoration"), 
        decoration == 'u' ?  std::string("underline") : std::string("none"))
    {}

    //- Destroys TextDecoration
    ~TextDecoration<decoration>(){}
};

} // krap

#endif

//
//END-OF-FILE
//

