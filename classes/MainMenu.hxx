#ifndef MainMenu_H
#define MainMenu_H

#include "Div.hxx"
#include "Uri.hxx"

namespace krap
{

class MainMenu;
using MainMenuPtr = std::shared_ptr<MainMenu> ;

class MainMenu : public Div
{
    //- No copy ctor
    MainMenu(const MainMenu&) = delete;

public:

    //- Default Ctor
    MainMenu();

    //- Dtor
    virtual ~MainMenu(){};

    //- Inserts new element to menu
    void insert(std::string name);

    //- Inserts new element to menu
    void insert(std::string name, const UriPtr& uri_ptr);
};

}

#endif

//END-OF-FILE

