#include "CSS.hxx"
#include "Classes.hxx"

namespace krap::css
{
    const CSSClass menuText {"menuText"};
    const CSSClass emptyClass {"emptyCss"};
    const CSSClass divRow {"divRow"};
    const CSSClass middleColumn {"middleColumn"};
    const CSSClass sideColumn {"sideColumn"};
    const CSSClass divTable {"divTable"};
    const CSSClass divTableBody {"divTableBody"};
    const CSSClass divTableRow {"divTableRow"};
    const CSSClass divTableCell {"divTableCell"};
}

void krap::css::init_globals()
{
    //const_cast<CSSClass&>(menuText).add(font24px);

    const_cast<CSSClass&>(divRow).add(boxSizing);
    const_cast<CSSClass&>(divRow).add(displayFlex);

    const_cast<CSSClass&>(middleColumn).add(width80perc);
    //const_cast<CSSClass&>(middleColumn).add(displayFlex);
    const_cast<CSSClass&>(middleColumn).add(boxSizing);

    const_cast<CSSClass&>(sideColumn).add(width10perc);
    const_cast<CSSClass&>(sideColumn).add(displayFlex);
    const_cast<CSSClass&>(sideColumn).add(boxSizing);

    const_cast<CSSClass&>(divTable).add(displayTable);
    const_cast<CSSClass&>(divTableBody).add(displayTableRowGroup);
    const_cast<CSSClass&>(divTableRow).add(displayTableRow);
    const_cast<CSSClass&>(divTableCell).add(displayTableCell);
}

//
//END-OF-FILE
//
