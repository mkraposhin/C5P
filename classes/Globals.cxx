#include "Globals.hxx"
#include "CSSGlobals.hxx"


namespace krap
{
    //const std::string constants::site_uri = "kraposhin.online/";
    const std::string constants::protocol = "http://";
    const std::string constants::log_path = "/var/log/cpp_cms";
    //const std::string site_uri {"194.4.51.15/"};
    //constants::site_uri = "kraposhin.online/";
    const std::string site_uri {"127.0.0.1/"};
}

namespace krap
{
    const CSSElement css::colorBlue {"color", "blue"};
    const Black css::colorBlack;
    const Color<0xFF,0xFF,0xFF> css::colorWhite;
    const Gray css::colorGray;

    const CSSElement css::bcolorWhite{"background-color","white"};
    const CSSElement css::bcolorGray{"background-color", "gray"};

    const FontSize<24> css::font24px;
    const FontSize<22> css::font22px;
    const FontSize<20> css::font20px;
    const FontSize<18> css::font18px;
    const FontSize<16> css::font16px;

    const FontStyle<'n'> css::fontStyleNormal;
    const FontStyle<'o'> css::fontOblique;
    const FontStyle<'i'> css::fontItalic;
    const FontWeight<'n'> css::fontWeightNormal;
    const FontWeight<'b'> css::fontBold;

    const CSSElement css::width10perc{"width","10.0%"};
    const CSSElement css::width25perc{"width","25.0%"};
    const CSSElement css::width30perc{"width","30.0%"};
    const CSSElement css::width50perc{"width","50.0%"};
    const CSSElement css::width75perc{"width","75.0%"};
    const CSSElement css::width80perc{"width","80.0%"};
    const CSSElement css::width100perc{"width","100.0%"};

    const CSSElement css::width100px{"width","100.0px"};
    const CSSElement css::width200px{"width","200.0px"};
    const CSSElement css::width300px{"width","300.0px"};
    const CSSElement css::width400px{"width","400.0px"};
    const CSSElement css::width500px{"width","500.0px"};

    const CSSElement css::bottom0{"bottom", "0"};
    const CSSElement css::top0{"top", "0"};
    const CSSElement css::right0{"right", "0"};

    const CSSElement css::positionFixed{"position", "fixed"};
    const CSSElement css::positionAbsolute{"position", "absolute"};
    const CSSElement css::positionRelative{"position", "relative"};

    const CSSElement css::overflowHidden{"overflow", "hidden"};

    const CSSElement css::marginTop0px{"margin-top", "0px"};
    const CSSElement css::marginTop10px{"margin-top", "10px"};
    const CSSElement css::marginTop20px{"margin-top", "20px"};
    const CSSElement css::marginTop50px{"margin-top", "50px"};
    const CSSElement css::marginTop100px{"margin-top", "100px"};
    const CSSElement css::marginTop200px{"margin-top", "200px"};
    //
    const CSSElement css::marginBottom0px{"margin-bottom", "0px"};
    const CSSElement css::marginBottom10px{"margin-bottom", "10px"};
    const CSSElement css::marginBottom20px{"margin-bottom", "20px"};
    const CSSElement css::marginBottom50px{"margin-bottom", "50px"};
    const CSSElement css::marginBottom100px{"margin-bottom", "100px"};
    const CSSElement css::marginBottom200px{"margin-bottom", "200px"};
    //
    const CSSElement css::paddingTop0px{"padding-top", "0px"};
    const CSSElement css::paddingTop10px{"padding-top", "10px"};
    const CSSElement css::paddingTop20px{"padding-top", "20px"};
    const CSSElement css::paddingTop50px{"padding-top", "50px"};
    const CSSElement css::paddingTop100px{"padding-top", "100px"};
    const CSSElement css::paddingTop200px{"padding-top", "200px"};
    //
    const CSSElement css::marginLeft0px{"margin-left","0px"};
    const CSSElement css::marginLeft10px{"margin-left","10px"};
    const CSSElement css::marginLeft20px{"margin-left","20px"};
    const CSSElement css::marginLeft50px{"margin-left","50px"};
    const CSSElement css::marginLeft100px{"margin-left","100px"};
    const CSSElement css::marginLeft200px{"margin-left","200px"};
    //
    const CSSElement css::marginRight0px{"margin-right", "0px"};
    const CSSElement css::marginRight10px{"margin-right", "10px"};
    const CSSElement css::marginRight20px{"margin-right", "20px"};
    const CSSElement css::marginRight50px{"margin-right", "50px"};
    const CSSElement css::marginRight100px{"margin-right", "100px"};
    const CSSElement css::marginRight200px{"margin-right", "200px"};

    const CSSElement css::displayNone {"display","none"};
    const CSSElement css::displayBlock {"display","block"};
    const CSSElement css::displayFlex {"display","flex"};
    const CSSElement css::displayTable {"display","table"};
    const CSSElement css::displayTableRowGroup {"display", "table-row-group"};
    const CSSElement css::displayRow {"display","row"};
    const CSSElement css::displayCell {"display","cell"};

    const CSSElement css::floatNone {"float", "none"};
    const CSSElement css::floatRight {"float", "right"};

    const CSSElement css::boxSizing {"box-sizing", "border-box"};
    const CSSElement css::textAlignLeft {"text-align", "left"};

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

    const_cast<CSSClass&>(css::middleColumn).add(css::width80perc);
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

