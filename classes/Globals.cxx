#include "Globals.hxx"

namespace krap
{
    const CSSElement css::colorBlue {"color", "blue"};
    const CSSElement css::colorBlack {"color", "black"};
    const CSSElement css::colorWhite {"color", "white"};
    const CSSElement css::colorGray {"color", "gray"};

    const CSSElement css::bcolorWhite{"background-color","white"};
    const CSSElement css::bcolorGray{"background-color", "gray"};

    const CSSElement css::font24px {"font-size", "24px"};
    const CSSElement css::font22px {"font-size", "22px"};
    const CSSElement css::font20px {"font-size", "20px"};
    const CSSElement css::font18px {"font-size", "18px"};
    const CSSElement css::font16px {"font-size", "16px"};

    const CSSElement css::width10perc{"width","10.0%"};
    const CSSElement css::width25perc{"width","25.0%"};
    const CSSElement css::width30perc{"width","30.0%"};
    const CSSElement css::width50perc{"width","50.0%"};
    const CSSElement css::width75perc{"width","75.0%"};
    const CSSElement css::width100perc{"width","100.0%"};

    const CSSElement css::width100px{"width","100.0px"};
    const CSSElement css::width200px{"width","200.0px"};
    const CSSElement css::width300px{"width","300.0px"};
    const CSSElement css::width400px{"width","400.0px"};
    const CSSElement css::width500px{"width","500.0px"};

    const CSSElement css::bottom0{"bottom", "0"};

    const CSSElement css::positionFixed{"position", "fixed"};

    const CSSElement css::overflowHidden{"overflow", "hidden"};

    const CSSElement css::displayFlex {"display","flex"};
    const CSSElement css::displayTable {"display","table"};
    const CSSElement css::displayTableRowGroup {"display", "table-row-group"};
    const CSSElement css::displayRow {"display","row"};
    const CSSElement css::displayCell {"display","cell"};

    const CSSElement css::boxSizing {"box-sizing", "border-box"};

    const CSSClass css::menuText {"menuText"};
    const CSSClass css::emptyClass {"emptyCss"};
    const CSSClass css::divRow {"divRow"};
    const CSSClass css::middleColumn {"middleColumn"};
    const CSSClass css::sideColumn {"sideColumn"};
    const CSSClass css::divTable {"divTable"};
    const CSSClass css::divTableBody {"divTableBody"};
    const CSSClass css::divTableRow {"divTableRow"};
    const CSSClass css::divTableCell {"divTableCell"};
}


void krap::init_globals()
{
    //const_cast<CSSClass&>(css::menuText).add(css::font24px);

    const_cast<CSSClass&>(css::divRow).add(css::boxSizing);
    const_cast<CSSClass&>(css::divRow).add(css::displayFlex);

    const_cast<CSSClass&>(css::middleColumn).add(css::width75perc);
    //const_cast<CSSClass&>(css::middleColumn).add(css::displayFlex);
    const_cast<CSSClass&>(css::middleColumn).add(css::boxSizing);

    const_cast<CSSClass&>(css::sideColumn).add(css::width10perc);
    const_cast<CSSClass&>(css::sideColumn).add(css::displayFlex);
    const_cast<CSSClass&>(css::sideColumn).add(css::boxSizing);

    const_cast<CSSClass&>(css::divTable).add(css::displayTable);
    const_cast<CSSClass&>(css::divTableBody).add(css::displayTableRowGroup);
    const_cast<CSSClass&>(css::divTableRow).add(css::displayRow);
    const_cast<CSSClass&>(css::divTableCell).add(css::displayCell);
}

//
//END-OF-FILE
//

