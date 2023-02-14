#ifndef Globals_H
#define Globals_H

#include "CSSElement.hxx"
#include "CSSClass.hxx"
#include "FontStyles.hxx"
#include "Colors.hxx"

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
    const static Black colorBlack;
    const static Color<0xFF,0xFF,0xFF> colorWhite;
    const static Gray colorGray;

    /*
     *
     * Bacground colors
     * 
     */
    const static CSSElement bcolorWhite;
    const static CSSElement bcolorGray;

    /*
     *
     * Font family
     * 
     */

    /*
     *
     * Font sizes
     * 
     */
    const static FontSize<24> font24px;
    const static FontSize<22> font22px;
    const static FontSize<20> font20px;
    const static FontSize<18> font18px;
    const static FontSize<16> font16px;

    /*
     *
     * Font styles and weights
     * 
     */
    const static FontStyle<'n'> fontStyleNormal;
    const static FontStyle<'o'> fontOblique;
    const static FontStyle<'i'> fontItalic;
    const static FontWeight<'n'> fontWeightNormal;
    const static FontWeight<'b'> fontBold;

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
    const static CSSElement width80perc;
    const static CSSElement width100perc;

    const static CSSElement width100px;
    const static CSSElement width200px;
    const static CSSElement width300px;
    const static CSSElement width400px;
    const static CSSElement width500px;

    /*
     *
     * Bottom space
     * 
     */
    const static CSSElement bottom0;
    const static CSSElement top0;

    /*
     *
     * Position
     * 
     */
    const static CSSElement positionFixed;

    /*
     *
     * Overflow
     * 
     */
    const static CSSElement overflowHidden;

    /*
     *
     * Body geometry
     * 
     */
    const static CSSElement marginTop0px;
    const static CSSElement marginTop10px;
    const static CSSElement marginTop20px;
    const static CSSElement marginTop50px;
    const static CSSElement marginTop100px;
    const static CSSElement marginTop200px;
    //
    const static CSSElement paddingTop0px;
    const static CSSElement paddingTop10px;
    const static CSSElement paddingTop20px;
    const static CSSElement paddingTop50px;
    const static CSSElement paddingTop100px;
    const static CSSElement paddingTop200px;
    //
    const static CSSElement marginLeft0px;
    const static CSSElement marginLeft10px;
    const static CSSElement marginLeft20px;
    const static CSSElement marginLeft50px;
    const static CSSElement marginLeft100px;
    const static CSSElement marginLeft200px;
    //
    const static CSSElement marginRight0px;
    const static CSSElement marginRight10px;
    const static CSSElement marginRight20px;
    const static CSSElement marginRight50px;
    const static CSSElement marginRight100px;
    const static CSSElement marginRight200px;

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
    //const std::string site_uri {"194.4.51.15/"};
    // const std::string site_uri {"kraposhin.online/"};
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

