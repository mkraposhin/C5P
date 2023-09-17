#include "CSS.hxx"
#include "Classes.hxx"

namespace krap::css
{
    const CSSClass menuText {"menuText"};
    const CSSClass emptyClass {"emptyCss"};
    const CSSClass divRow
    {
        "divRow",
        {boxSizing, displayFlex}
    };
    const CSSClass middleColumn
    {
        "middleColumn",
        {width80perc, boxSizing}
    };
    const CSSClass sideColumn
    {
        "sideColumn",
        {width10perc, displayFlex, boxSizing}
    };
    const CSSClass divTable {"divTable", {displayTable}};
    const CSSClass divTableBody {"divTableBody", {displayTableRowGroup}};
    const CSSClass divTableRow {"divTableRow", {displayTableRow}};
    const CSSClass divTableCell {"divTableCell", {displayTableCell}};
}

//
//END-OF-FILE
//
