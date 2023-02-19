#include "MainMenu.hxx"
#include "AText.hxx"
#include "CSSGlobals.hxx"

#include "FontStyles.hxx"
#include "TextDecoration.hxx"
#include "ObjectFloat.hxx"
#include "Colors.hxx"


krap::MainMenu::MainMenu()
: 
    Div()
{

    //- A base css class for the main menu
    CSSClass menu_class ("menuCssClass");

    //- A css class for links inside the main menu
    CSSClass menu_class_links ("menuCssClass a");

    //- A css class for links when a mouse pointer 
    // hovers over them
    CSSClass menu_class_hover ("menuCssClass a:hover");

    menu_class.add(css::bcolorWhite);
    menu_class.add(css::overflowHidden);
    menu_class.add(css::top0);
    menu_class.add(css::positionFixed);
    menu_class.add(css::width80perc);
    *this % menu_class;

    
    FontSize<26> fnt_25px;
    FontWeight<'b'> fnt_bold;
    FontFamily fnt_families ("Arial, Helvetica, sans-serif");
    TextDecoration<'n'> no_decor;
    ObjectFloat<'n'> float_none;

    menu_class_links.add(fnt_25px);
    menu_class_links.add(fnt_families);
    menu_class_links.add(fnt_bold);
    menu_class_links.add(css::fontStyleNormal);
    menu_class_links.add(css::colorGray);
    menu_class_links.add(no_decor);
    menu_class_links.add(float_none);
    menu_class_links.add(DimGray{});
    Div emptyDiv1;
    emptyDiv1 % menu_class_links;
    this->add(emptyDiv1);

    menu_class_hover.add(css::colorWhite);
    menu_class_hover.add(css::bcolorGray);
    Div emptyDiv2;
    emptyDiv2 % menu_class_hover;
    this->add(emptyDiv2);

    // ElementPtr Home = 
    //     AText("Home").clone();
    // ElementPtr Education = 
    //     AText("Education").clone();
    // ElementPtr ProfExp =
    //     AText("Professional Experience").clone();
    // ElementPtr Publications = 
    //     AText("Publications").clone();
    // ElementPtr Projects =
    //     AText("Projects").clone();
    // ElementPtr Patents = 
    //     AText ("Patents").clone();
    // ElementPtr Technologies =
    //     AText ("Tecnologies").clone();
    // ElementPtr OtherInfo =
    //     AText ("OtherInfo").clone();

    // this->add(Education);
    // this->add(ProfExp);

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

void krap::MainMenu::insert(std::string nm)
{
    ElementPtr item = 
        AText(nm).clone();
    this->add(item);
}

void krap::MainMenu::insert(std::string name, const UriPtr& uri_ptr)
{
    #warning "function requires simplification"
    ATextPtr atext = std::dynamic_pointer_cast<AText>(AText(name).clone());
    atext->uri(uri_ptr->uri());
    ElementPtr item = std::dynamic_pointer_cast<Element>(atext);
    this->add(item);
}

//
//END-OF-FILE
//

