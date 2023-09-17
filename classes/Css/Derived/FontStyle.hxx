#ifndef FontStyle_H
#define FontStyle_H

#include "Exception.hxx"
#include "CSSElement.hxx"

namespace c5p
{

template<int sz>
class FontSize : public CSSElement
{

private:

    //- Checks that the value in val is between min and max
    template<int min, int max, int val>
    void check_bounds()
    {
        if constexpr (val < min || val > max)
        {
            throw c5p::GenericException
                {"Wrong font size:" + std::to_string(val)};
        }
    }


public:

    //- Creates style only from size value
    FontSize<sz>() : 
    CSSElement("font-size",std::to_string(sz)+std::string("px"))
    {
        check_bounds<6,36,sz>();
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

} // krap

#endif

//
//END-OF-FILE
//

