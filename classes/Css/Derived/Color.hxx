#include "CSSElement.hxx"
#include <sstream>
#include <iomanip>

#ifndef Color_H
#define Color_H

namespace krap
{

template<unsigned char r, unsigned char g, unsigned char b>
class Color : public CSSElement
{

private:

    //- Converts an r,g,b triple into string
    std::string to_string()
    {
        std::stringstream stream;
        stream<< "#" << std::setfill ('0')
               << std::setw(sizeof(unsigned char)*2)
              << std::hex << int(r) << int(g) << int(b);
        return stream.str();
    }

public:

    //- Creates a style for a given element of a given color
    Color<r,g,b>()
    :
    CSSElement("color", to_string())
    {}

    //- Destroys the style
    ~Color<r,g,b>(){}

};

} // krap

#endif

//
//END-OF-FILE
//

