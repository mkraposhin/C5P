#include "MyOssProjects.hxx"
#include "DivColumn.hxx"
#include "AText.hxx"
#include "Sizes.hxx"
#include "CSSGlobals.hxx"

krap::MyOssProjects::MyOssProjects(const Site& site)
:
    DocumentImpl(site)
{
    const int width = 300;

    DivColumn div_col;

    CSSClass ossProjColClass ("ossProjColClass");
    ossProjColClass.add(Width(width));

    CSSClass textVertSpaces("textVertSpaces");
    textVertSpaces.add(css::marginBottom10px);
    textVertSpaces.add(css::marginTop10px);

    AText txt_hcs { Uri("https://github.com/mkraposhin/hybridCentralSolvers").
        html("Hybrid Central Solvers") + 
        ": a set of OpenFOAM programs for"
    " comptational analysis of compressible gas and fluid flow, include"
    " multicomponent and multiphase formulations"};
    //txt_hcs % textVertSpaces;

    AText txt_liba { Uri("https://github.com/mkraposhin/libAcoustics").
        html("libAcoustics") + 
        ": a OpenFOAM library for computational"
    " analysis"
    " of a far field noise induced by turbulent motions of fluids or gases"};
    //txt_liba % textVertSpaces;

    AText txt_qgd { Uri("https://github.com/mkraposhin/QGDsolver").
        html("QGDsolver") + 
    ": is OpenFOAM framework for simulation of fluid"
    " flows using regularized (QGD/QHD) equations approach"};
    //txt_qgd % textVertSpaces;

    div_col % ossProjColClass;

    div_col.add(txt_hcs);
    div_col.add(txt_liba);
    div_col.add(txt_qgd);

    Div& mid_col = layout().operator()<Div>(1);
    mid_col.add(div_col);
}

//
//END-OF-FILE
//