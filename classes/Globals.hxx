#ifndef Globals_H
#define Globals_H

#include "CSSElement.hxx"
#include "CSSClass.hxx"

namespace krap
{

struct css
{
    /*
     *
     * Colors
     *
     */
    const static CSSElement colorBlue;
    const static CSSElement colorBlack;
    const static CSSElement colorWhite;

    /*
     *
     * Font sizes
     * 
     */
    const static CSSElement font24px;

    /*
     *
     * Width values 
     * 
     */
    const static CSSElement width25perc;
    const static CSSElement width50perc;
    const static CSSElement width30perc;

    /*
     *
     * Other style elements
     * 
     */
    const static CSSElement displayFlex;

    /* CSS Classes */
    const static CSSClass menuText;
};

namespace constants
{
    const std::string protocol {"http://"};
    const std::string site_uri {"127.0.0.1/"};
}

void init_globals();

}

#define DISALLOW_EQ(class_name)                           \
const class_name& operator = (const class_name&) = delete;\
const class_name& operator = (class_name&&);

#define DISALLOW_COPY(class_name)                         \
class_name(const class_name&) = delete;                   \
class_name(class_name &&) = delete;                       \

#define DISALLOW_ALL(class_name)                          \
class_name();                                             \
DISALLOW_EQ(class_name)                                   \
DISALLOW_COPY(class_name)

#endif

//
//END-OF-FILE
//

