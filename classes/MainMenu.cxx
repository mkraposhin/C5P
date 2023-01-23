#include "MainMenu.hxx"
#include "AText.hxx"

krap::MainMenu::MainMenu()
: Div()
{
    ElementPtr Home = 
        AText("Home").clone();
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

