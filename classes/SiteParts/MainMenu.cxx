#include "MainMenu.hxx"
#include "AText.hxx"
#include "CSS.hxx"

#include "FontStyles.hxx"
#include "TextDecoration.hxx"
#include "ObjectFloat.hxx"
#include "Colors.hxx"
#include "JScript.hxx"
#include "Link.hxx"

#define MAIN_MENU_ID "MainMenuOfSiteID"

c5p::MainMenu::MainMenu()
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

    CSSClass menu_class_icon ("menuCssClass .icon");

    AtRule media600px ("@media", "screen and (max-width: 600px)");

    CSSClass menu_class_anot("menuCssClass a:not(:first-child)");
    CSSClass menu_class_aicon ("menuCssClass a.icon");

    CSSClass menu_class_resp("menuCssClass.responsive");
    CSSClass menu_class_resp_icon("menuCssClass.responsive .icon");
    CSSClass menu_class_resp_a("menuCssClass.responsive a");
    
    menu_class.add(css::bcolorWhite);
    menu_class.add(css::overflowHidden);
    //menu_class.add(css::top0);
    //menu_class.add(css::positionFixed);
    //menu_class.add(css::width80perc);
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
    menu_class_links.add(css::color::Gray);
    menu_class_links.add(no_decor);
    menu_class_links.add(float_none);
    menu_class_links.add(css::color::DimGray);
    Div emptyDiv1;
    emptyDiv1 % menu_class_links;
    this->add(emptyDiv1);

    menu_class_hover.add(css::color::White);
    menu_class_hover.add(css::bcolorGray);
    Div emptyDiv2;
    emptyDiv2 % menu_class_hover;
    this->add(emptyDiv2);

    menu_class_icon.add(css::displayNone);
    Div emptyDiv3;
    emptyDiv3 % menu_class_icon;
    this->add(emptyDiv3);

    menu_class_anot.at_rule(media600px);
    menu_class_anot.add(css::displayNone);
    Div emptyDiv_media_0;
    emptyDiv_media_0 % menu_class_anot;
    this->add(emptyDiv_media_0);

    menu_class_aicon.add(css::displayBlock);
    menu_class_aicon.add(css::floatRight);
    menu_class_aicon.at_rule(media600px);
    Div emptyDiv_media_1;
    emptyDiv_media_1 % menu_class_aicon;
    this->add(emptyDiv_media_1);

    menu_class_resp.at_rule(media600px);
    menu_class_resp.add(css::positionRelative);
    Div emptyDiv_media_2;
    emptyDiv_media_2 % menu_class_resp;
    this->add(emptyDiv_media_2);
    
    menu_class_resp_icon.at_rule(media600px);
    menu_class_resp_icon.add(css::right0);
    menu_class_resp_icon.add(css::top0);
    menu_class_resp_icon.add(css::positionAbsolute);
    Div emptyDiv_media_3;
    emptyDiv_media_3 % menu_class_resp_icon;
    this->add(emptyDiv_media_3);

    menu_class_resp_a.at_rule(media600px);
    menu_class_resp_a.add(css::floatNone);
    menu_class_resp_a.add(css::displayBlock);
    menu_class_resp_a.add(css::textAlignLeft);
    Div emptyDiv_media_4;
    emptyDiv_media_4 % menu_class_resp_a;
    this->add(emptyDiv_media_4);

    this->id(MAIN_MENU_ID);
    JScript j_script
    {
        "myFunction()",
        "{""\n"
        "  var x = document.getElementById(\"" MAIN_MENU_ID "\");""\n"
        "  if (x.className === \"menuCssClass\") {""\n"
        "    x.className += \" responsive\";""\n"
        "  } else {""\n"
        "    x.className = \"menuCssClass\";""\n"
        "  }""\n"
        "}""\n"
    };
    

    this->jscript_ = j_script.clone();

    Link menu_link;
    menu_link.uri("https://cdnjs.cloudflare.com/ajax/libs/font-awesome/"
        "4.7.0/css/font-awesome.min.css");
    menu_link.rel("stylesheet");

    link_ = std::dynamic_pointer_cast<Link>(menu_link.clone());

    AText hidden_txt;
    this->add(hidden_txt);

    CSSClass icon_class("icon");
    AText resp_txt ("Menu");
    resp_txt % icon_class;
    resp_txt.uri("javascript:void(0);");
    resp_txt.on_click(j_script);
    this->add(resp_txt);
}

void c5p::MainMenu::insert(std::string nm)
{
    ElementPtr item = 
        AText(nm).clone();
    this->add(item);
}

void c5p::MainMenu::insert(std::string name, const UriPtr& uri_ptr)
{
    #warning "function requires simplification"
    ATextPtr atext = std::dynamic_pointer_cast<AText>(AText(name).clone());
    atext->uri(uri_ptr->uri());
    ElementPtr item = std::dynamic_pointer_cast<Element>(atext);
    this->add(item);
}

const std::shared_ptr<c5p::JScript>& c5p::MainMenu::jscript() const
{
    return jscript_;
}

const std::shared_ptr<c5p::Link>& c5p::MainMenu::link() const
{
    return link_;
}

//
//END-OF-FILE
//

