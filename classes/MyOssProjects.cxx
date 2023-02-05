#include "MyOssProjects.hxx"
#include "DivColumn.hxx"
#include "AText.hxx"

krap::MyOssProjects::MyOssProjects(const Site& site)
:
    DocumentImpl(site)
{
    DivColumn div_col;

    AText txt_empty {"  "};

    AText txt_hcs {"Hybrid Central Solvers: a set of OpenFOAM programs for"
    " comptational analysis of compressible gas and fluid flow, include"
    " multicomponent and multiphase formulations"};
    txt_hcs.uri("https://github.com/mkraposhin/hybridCentralSolvers");

    AText txt_liba {"lib Acoustics: a OpenFOAM library for computational"
    " analysis"
    " of a far field noise induced by turbulent motions of fluids or gases"};
    txt_liba.uri("https://github.com/mkraposhin/libAcoustics");

    AText txt_qgd {"QGDsolver: is OpenFOAM framework for simulation of fluid"
    " flows using regularized (QGD/QHD) equations approach"};
    txt_qgd.uri("https://github.com/mkraposhin/QGDsolver");

    div_col.add(txt_empty);
    div_col.add(txt_hcs);
    div_col.add(txt_liba);
    div_col.add(txt_qgd);

    Div& mid_col = layout().operator()<Div>(1);
    mid_col.add(div_col);
}

//
//END-OF-FILE
//