#include "ProfExperience.hxx"
#include "ParagraphText.hxx"
#include "DivColumn.hxx"
#include "Header.hxx"
#include "Size.hxx"

c5p::ProfExperience::ProfExperience(const Site& site)
:
    DocumentImpl(site)
{

    const int width = 300;

    CSSClass profExperienceColClass ("profExperienceColClass");
    profExperienceColClass.add(Width(width));

    Header<2> head_empl ("Employment history");

    ParagraphText txt_nrcki("2006 - 2014: National Research Center"
    " \"Kurchatow institute\": engineer, junior researcher, researcher"
    " head of a laboratory");

    ParagraphText txt_ispras("2015 - 2022: Institute for system programming"
    " of the RAS: senior researcher, head of a laboratory");

    Header<2> head_techn ("Skills & Technologies");

    ParagraphText txt_cpp ("C++ language - standards ISO98, C++11, g++"
        "compiler");
    ParagraphText txt_bash ("Bash scripting language");
    ParagraphText txt_linux ("Linux operating system experienced user");
    ParagraphText txt_tf ("Tungsten Fabric SDN user & contributor");
    ParagraphText txt_make ("GNU " + Uri("https://www.gnu.org/software/make/").
        html("Make") + " project build system");
    ParagraphText txt_docker ("Docker container virtualization technology");
    ParagraphText txt_latex ("LaTeX document preparation system");
    ParagraphText txt_sql ("SQL (PostgreSQL) user");
    ParagraphText txt_git ("Git version control system");
    ParagraphText txt_parallel ("Parallel and distributed computations (MPI"
    "/Lihux threads");
    ParagraphText txt_openfoam (Uri("https://www.openfoam.com/").
    html("OpenFOAM") + " Finite Volume Method framework");
    ParagraphText txt_salome (Uri("https://www.salome-platform.org/").
    html("SALOME") + " platform for numerical simulations (CAD/meshing)");
    ParagraphText txt_paraview(Uri("https://www.paraview.org/").html("Paraview")
    + " visualization toolkit");

    DivColumn div_col;
    div_col % profExperienceColClass;

    div_col.add(head_empl);
    div_col.add(txt_nrcki);
    div_col.add(txt_ispras);

    div_col.add(head_techn);
    div_col.add(txt_cpp);
    div_col.add(txt_bash);
    div_col.add(txt_linux);
    div_col.add(txt_tf);
    div_col.add(txt_make);
    div_col.add(txt_docker);
    div_col.add(txt_latex);
    div_col.add(txt_sql);
    div_col.add(txt_git);
    div_col.add(txt_parallel);
    div_col.add(txt_openfoam);
    div_col.add(txt_salome);
    div_col.add(txt_paraview);

    Div& mid_col = layout().operator()<Div>(1);
    mid_col.add(div_col);
}

//
//END-OF-FILE
//

