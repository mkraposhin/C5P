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
    const static CSSElement width10perc;
    const static CSSElement width25perc;
    const static CSSElement width30perc;
    const static CSSElement width50perc;
    const static CSSElement width75perc;

    /*
     *
     * Display styles
     * 
     */
    const static CSSElement displayFlex;
    const static CSSElement displayTable;
    const static CSSElement displayTableRowGroup;
    const static CSSElement displayRow;
    const static CSSElement displayCell;
    
    /*
     *
     * Other style elements
     * 
     */
    const static CSSElement boxSizing;

    /*
     *
     * CSS Classes
     * 
     */
    const static CSSClass menuText;
    const static CSSClass emptyClass;
    const static CSSClass divRow;
    const static CSSClass middleColumn;
    const static CSSClass sideColumn;
    const static CSSClass divTable;
    const static CSSClass divTableBody;
    const static CSSClass divTableRow;
    const static CSSClass divTableCell;
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

