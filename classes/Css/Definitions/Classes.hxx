#ifndef Classes_H
#define Classes_H

#include "CSSClass.hxx"

namespace krap::css
{
    extern const CSSClass menuText;
    extern const CSSClass emptyClass;
    extern const CSSClass divRow;
    extern const CSSClass middleColumn;
    extern const CSSClass sideColumn;
    extern const CSSClass divTable;
    extern const CSSClass divTableBody;
    extern const CSSClass divTableRow;
    extern const CSSClass divTableCell;

    void init_globals();
}

#endif
