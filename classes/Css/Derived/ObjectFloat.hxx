#ifndef ObjectFloat_H
#define ObjectFloat_H

#include "CSSElement.hxx"

namespace c5p
{

template<char float_type>
class ObjectFloat : public CSSElement
{

public:

    //- Creates a css only from the object float type:
    // left/right/start/end/none
    ObjectFloat<float_type>() : 
    CSSElement("float",
        float_type == 'l' ?  std::string("left") : 
            float_type == 'r' ? std::string("right") : 
                float_type == 's' ? std::string("inline-start") :
                    float_type == 'e' ? std::string("inline-end") :
                        std::string("none"))
    {}

    //- Destroys the css
    ~ObjectFloat<float_type>(){}
};

} // krap

#endif

//
//END-OF-FILE
//

