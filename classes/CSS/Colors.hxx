#include "CSSElement.hxx"
#include <sstream>
#include <iomanip>

#ifndef Colors_H
#define Colors_H

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

using Black = Color<0x00,0x00,0x00>;
using DarkGrey = Color<0x39,0x39,39>;
using DimGray = Color<0x69,0x69,0x69>;
using Gray = Color<0x80,0x80,0x80>;
using LightGray = Color<0xD3,0xD3,0xD3>;

using SlateGrey = Color<0x70,0x80,0x90>;
using LightSlateGray = Color<0x77,0x88,0x99>;
using DarkSlateGray = Color<0x2F,0x4F,0x4F>;

}

#endif

//
//END-OF-FILE
//

