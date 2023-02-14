#ifndef FontStyles_H
#define FontStyles_H

#include "CSSElement.hxx"

namespace krap
{
template<int sz>
class FontSize : public CSSElement
{

public:

    //- Creates style only from size value
    FontSize<sz>() : 
    CSSElement("font-size",std::to_string(sz)+std::string("px"))
    {
        #warning "Add checks for illegal values"
    }

    ~FontSize<sz>(){};
};

template <char style>
class FontStyle : public CSSElement
{

public:

    //- Creates a css only from font style type:
    // normal/italic/oblique
    FontStyle<style>() : 
    CSSElement("font-style",
        style == 'i' ?  std::string("italic") : 
            style == 'o' ? std::string("oblique") : 
                std::string("normal"))
    {
    }

    ~FontStyle<style>(){};
};

template <char weight>
class FontWeight : public CSSElement
{

public:

    //- Creates a css only from font weight type:
    // normal/bold
    FontWeight<weight>() : 
    CSSElement("font-weight",
        weight == 'b' ?  std::string("bold") :
            std::string("normal"))
    {
    }

    ~FontWeight<weight>(){};
};

class FontFamily : public CSSElement
{

public:

    //- Creates a css only from font family names
    FontFamily(const std::string s) : 
    CSSElement("font-family",std::string(s))
    {
    }

    ~FontFamily(){};
};

}

#endif

//
//END-OF-FILE
//

