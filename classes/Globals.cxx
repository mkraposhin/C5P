#include "Globals.hxx"

namespace krap
{
    const CSSElement css::colorBlue {"color", "blue"};
    const CSSElement css::colorBlack {"color", "black"};
    const CSSElement css::colorWhite {"color", "white"};

    const CSSElement css::font24px {"font-size", "24px"};

    const CSSElement css::width25perc{"width","25.0%"};
    const CSSElement css::width50perc{"width","50.0%"};
    const CSSElement css::width30perc{"width","30.0%"};

    const CSSElement css::displayFlex {"display","flex"};

    const CSSClass css::menuText {"menuText"};
}


void krap::init_globals()
{
    //const_cast<CSSClass&>(css::menuText).add(css::font24px);
}

//
//END-OF-FILE
//

