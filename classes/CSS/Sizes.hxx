#ifndef Sizes
#define Sizes

#include "CSSElement.hxx"

namespace krap
{

class Width : public CSSElement
{

public:

    /// @brief Creates a CSS property that sets width of an element
    Width(const int sz)
    :
    CSSElement("width", std::to_string(sz) + std::string("px")){}

    /// @brief Destroys a CSS property
    ~Width(){}
};

class MaxWidth : public CSSElement
{

public:

    /// @brief Creates a CSS property that sets max-width of an element
    MaxWidth(const int sz)
    :
    CSSElement("max-width", std::to_string(sz) + std::string("px")){}

    /// @brief Destroys a CSS property
    ~MaxWidth(){}
};

class Height : public CSSElement
{

public:

    /// @brief Creates a CSS property that sets width of an element
    Height(const int sz)
    :
    CSSElement("height", std::to_string(sz) + std::string("px")){}

    /// @brief Destroys a CSS property
    ~Height(){}
};

class MaxHeight : public CSSElement
{

public:

    /// @brief Creates a CSS property that sets width of an element
    MaxHeight(const int sz)
    :
    CSSElement("max-height", std::to_string(sz) + std::string("px")){}

    /// @brief Destroys a CSS property
    ~MaxHeight(){}
};

}

#endif

//
//END-OF-FILE
//
