#include "MyContributions.hxx"
#include "Blog.hxx"
#include "BlogEntry.hxx"
#include "DivColumn.hxx"
#include "AText.hxx"
#include "CaptionedImage.hxx"
#include "Header.hxx"
#include "Sizes.hxx"
#include "CSSGlobals.hxx"

krap::MyContributions::MyContributions(const Site& site)
:
    DocumentImpl(site)
{
    const int width = 300; //px
    Div& mid_col = layout().operator()<Div>(1);
    Blog contributions;
    body().jscript(*contributions.jscript());

    // Open source projects
    {
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

        AText txt_qgd { Uri("https://github.com/mkraposhin/QGDsolver").
            html("QGDsolver") + 
            ": is OpenFOAM framework for simulation of fluid"
            " flows using regularized (QGD/QHD) equations approach"};

        AText txt_tf { Uri("https://github.com/tungstenfabric/tf-controller/graphs/contributors?from=2020-01-06&to=2023-09-01&type=a").
            html("Tungsten Fabric controller") +
            " Improvements of TF controller modules (Metadata service, VxLAN)"};

        AText txt_tf_rest { Uri("https://github.com/mkraposhin/tf-rest-bash-wrappers").
            html("TF REST bash wrappers") + 
            " A set of bash scripts wrapping REST commands for Tungsten Fabric"};

        div_col % ossProjColClass;


        div_col.add(txt_tf_rest);
        div_col.add(txt_tf);
        div_col.add(txt_hcs);
        div_col.add(txt_liba);
        div_col.add(txt_qgd);

        BlogEntry be ("My contributions to open source projects", div_col);
        contributions.add(be);
    }

    // Publications
    {
        CSSClass myPubClass ("myPubClass");
        myPubClass.add(Width(width));

        CSSClass textVertSpaces("textVertSpaces");
        textVertSpaces.add(css::marginBottom10px);
        textVertSpaces.add(css::marginTop10px);

        DivColumn col_content;

        Header<2> h_top5 ("Top 5 cited works");

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

        Header<2> h_other ("Other works");

        AText txt_pubs {"Other publications (~60 items) can"
        " be found at the Google scholar page"};
        txt_pubs.uri("https://scholar.google.com/citations?user=dNIvricAAAAJ&hl=ru");

        col_content % myPubClass;
        col_content.add(txt_adapt);
        col_content.add(txt_qgd_caf);
        col_content.add(txt_hybrid);
        col_content.add(txt_caa);
        col_content.add(txt_qgd_ieee);

        DivColumn div_col;
        div_col.add(h_top5);
        div_col.add(col_content);
        div_col.add(h_other);
        div_col.add(txt_pubs);

        BlogEntry be ("My publications", div_col);
        contributions.add(be);
    }

    // Patents
    {
        CSSClass patCss {"patCss"};
        patCss.add(css::width300px);

        //Contents
        CaptionedImage pat_tvel_img {"photo_5332597018251608572_y.jpg"};
        pat_tvel_img.image().width(width);
        std::string img1_txt ("State registration of a program for numerical"
        " modelling of interaction between liquid metal and gas in order to"
        " compute a droplet distribution properties of yilding metal powder");
        pat_tvel_img.caption(img1_txt);
        pat_tvel_img % patCss;

        CaptionedImage pat_acostic_img{"2017660047.jpg"};
        pat_acostic_img.image().width(width);
        std::string img2_txt ("State registration of a program for numerical"
        " analysis of a far-field acoustics"
        );
        pat_acostic_img.caption(img2_txt);
        pat_acostic_img % patCss;

        CaptionedImage pat_hcs{"2017660155.jpg"};
        pat_hcs.image().width(width);
        std::string img3_txt ("State registration of a program for numerical"
        " of compressible flows in a wide range of Mach number value");
        pat_hcs.caption(img3_txt);
        pat_hcs % patCss;

        CaptionedImage pat_qgd{"2018663951.jpg"};
        pat_qgd.image().width(width);
        std::string img4_txt ("State registration of a program for numerical"
        " modelling of viscous gas flows using regularized gas dynamics equations"
        " (QGD)");
        pat_qgd.caption(img4_txt);
        pat_qgd % patCss;

        DivColumn div_col;
        div_col % patCss;

        div_col.add(pat_tvel_img);
        div_col.add(pat_acostic_img);
        div_col.add(pat_hcs);
        div_col.add(pat_qgd);

        BlogEntry be ("My patents", div_col);
        contributions.add(be);
    }

    mid_col.add(contributions);
/*
    Contact information.
    Academic history (if you're not in academia or a recent graduate this can be moved beneath Professional experience)
    Qualifications and skills.
    Professional experience.
    Publications and presentations.
    Awards and honors.
    Grants and scholarships.
    Licenses and certifications.
*/
}

krap::MyContributions::~MyContributions()
{

};

//
//
//

