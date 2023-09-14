#ifndef CSS_H
#define CSS_H



// #include "CSSElement.hxx"
// #include "CSSClass.hxx"
// #include "FontStyles.hxx"
#include "FontSizes.hxx"
#include "FontStyles.hxx"
#include "Colors.hxx"
#include "Geometries.hxx"

namespace krap::css
{
    /*
     *
     * Bacground colors
     * 
     */
    extern const CSSElement bcolorWhite;
    extern const CSSElement bcolorGray;

    /*
     *
     * Font family
     * 
     */
    // ?


    /*
     *
     * Text alignment
     * 
     */
    extern const CSSElement textAlignLeft;
    extern const CSSElement textAlignRight;
    extern const CSSElement textAlignCenter;
    extern const CSSElement textAlignJustify;

    /*
     *
     * Width values 
     * 
     */
    extern const CSSElement width10perc;
    extern const CSSElement width25perc;
    extern const CSSElement width30perc;
    extern const CSSElement width50perc;
    extern const CSSElement width75perc;
    extern const CSSElement width80perc;
    extern const CSSElement width100perc;

    extern const CSSElement width100px;
    extern const CSSElement width200px;
    extern const CSSElement width300px;
    extern const CSSElement width400px;
    extern const CSSElement width500px;

    /*
     *
     * Bottom space
     * 
     */
    extern const CSSElement bottom0;
    extern const CSSElement top0;
    extern const CSSElement right0;
    extern const CSSElement left0;

    /*
     *
     * Position
     * 
     */
    extern const CSSElement positionFixed;
    extern const CSSElement positionAbsolute;
    extern const CSSElement positionRelative;

    /*
     *
     * Overflow
     * 
     */
    extern const CSSElement overflowHidden;

    /*
     *
     * Display styles
     * 
     */
    extern const CSSElement displayNone;
    extern const CSSElement displayBlock;
    extern const CSSElement displayFlex;
    extern const CSSElement displayTable;
    extern const CSSElement displayTableRowGroup;
    extern const CSSElement displayRow;
    extern const CSSElement displayTableRow;
    extern const CSSElement displayCell;
    extern const CSSElement displayTableCell;

    /*
     *
     * Float
     * 
     */
    extern const CSSElement floatNone;
    extern const CSSElement floatRight;

    /*
     *
     * Other style elements
     * 
     */
    extern const CSSElement boxSizing;
    extern const CSSElement outlineNone;
    extern const CSSElement borderNone;
}

/*
    *
    * CSS Classes
    * 
    */
#include "Classes.hxx"

#endif

//
//END-OF-FILE
//

