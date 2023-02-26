#include "MyPublications.hxx"
#include "AText.hxx"
#include "DivColumn.hxx"
#include "Header.hxx"
#include "Sizes.hxx"
#include "CSSGlobals.hxx"

krap::MyPublications::MyPublications(const Site& site)
:
    DocumentImpl(site)
{
    const int width = 300;

    CSSClass myPubClass ("myPubClass");
    myPubClass.add(Width(width));

    CSSClass textVertSpaces("textVertSpaces");
    textVertSpaces.add(css::marginBottom10px);
    textVertSpaces.add(css::marginTop10px);

    DivColumn col_content;

    Header<1> h_top5 ("Top 5 cited works");

    AText txt_adapt{"1. Adaptation of Kurganov-Tadmor numerical scheme "
    "for applying in combination with the PISO method in numerical "
    "simulation of flows in a wide range of Mach numbers, 2015"};
    txt_adapt.uri("https://www.researchgate.net/publication/"
    "284913682_Adaptation_of_Kurganov-Tadmor_Numerical_Scheme_for_"
    "Applying_in_Combination_with_the_PISO_Method_in_Numerical_"
    "Simulation_of_Flows_in_a_Wide_Range_of_Mach_Numbers");
    txt_adapt % textVertSpaces;

    AText txt_qgd_caf{"2. Development of a new OpenFOAM solver using"
    " regularized gas dynamic equations"};
    txt_qgd_caf.uri("https://www.researchgate.net/publication/"
    "323147173_Development_of_a_new_OpenFOAM_solver_using_regularized"
    "_gas_dynamic_equations");
    txt_qgd_caf % textVertSpaces;

    AText txt_hybrid{"3. A hybrid pressure-based solver for nonideal single-phase"
    " fluid flows at all speeds"};
    txt_hybrid.uri("https://www.researchgate.net/publication/325025590_A_hybrid"
    "_pressure-based_solver_for_non-ideal_single-phase_fluid_flows_at_all"
    "_speeds_Non-ideal_single-phase_fluid_flow_solver");
    txt_hybrid % textVertSpaces;

    AText txt_caa{"4. Development of a dynamic library for computational "
    "aeroacoustics applications using the OpenFOAM open source package"};
    txt_caa.uri("https://www.researchgate.net/publication/284913730_Development"
    "_of_a_Dynamic_Library_for_Computational_Aeroacoustics_Applications_Using"
    "_the_OpenFOAM_Open_Source_Package");
    txt_caa % textVertSpaces;

    AText txt_qgd_ieee{"5. Development of OpenFOAM solver for compressible viscous"
    " flows simulation using quasi-gas dynamic equations"};
    txt_qgd_ieee.uri("https://www.researchgate.net/publication/284913730_"
    "Development_of_a_Dynamic_Library_for_Computational_Aeroacoustics_"
    "Applications_Using_the_OpenFOAM_Open_Source_Package");
    txt_qgd_ieee % textVertSpaces;

    Header<1> h_other ("Other works");

    AText txt_pubs {"Other publications (~60 items) can"
    " be found at the Google scholar page"};
    txt_pubs.uri("https://scholar.google.com/citations?user=dNIvricAAAAJ&hl=ru");

    col_content % myPubClass;
    col_content.add(txt_adapt);
    col_content.add(txt_qgd_caf);
    col_content.add(txt_hybrid);
    col_content.add(txt_caa);
    col_content.add(txt_qgd_ieee);

    Div& mid_col = layout().operator()<Div>(1);
    mid_col.add(h_top5);
    mid_col.add(col_content);
    mid_col.add(h_other);
    mid_col.add(txt_pubs);
}

//
//END-OF-FILE
//