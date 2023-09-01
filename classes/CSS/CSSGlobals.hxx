#ifndef CSSGlobals_H
#define CSSGlobals_H

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
     * Text alignment
     * 
     */
    const static CSSElement textAlignLeft;
    const static CSSElement textAlignRight;
    const static CSSElement textAlignCenter;
    const static CSSElement textAlignJustify;

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
    const static CSSElement right0;

    /*
     *
     * Position
     * 
     */
    const static CSSElement positionFixed;
    const static CSSElement positionRelative;
    const static CSSElement positionAbsolute;

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
    const static CSSElement marginBottom0px;
    const static CSSElement marginBottom10px;
    const static CSSElement marginBottom20px;
    const static CSSElement marginBottom50px;
    const static CSSElement marginBottom100px;
    const static CSSElement marginBottom200px;
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
    const static CSSElement displayNone;
    const static CSSElement displayBlock;
    const static CSSElement displayFlex;
    const static CSSElement displayRow;
    const static CSSElement displayCell;
    const static CSSElement displayTable;
    const static CSSElement displayTableRowGroup;
    const static CSSElement displayTableRow;
    const static CSSElement displayTableCell;

    /*
     *
     * Float
     * 
     */
    const static CSSElement floatNone;
    const static CSSElement floatRight;

    /*
     *
     * Other style elements
     * 
     */
    const static CSSElement boxSizing;
    const static CSSElement outlineNone;
    const static CSSElement borderNone;

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

void init_globals();

}

#endif

//
//END-OF-FILE
//

