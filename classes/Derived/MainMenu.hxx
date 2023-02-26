#ifndef MainMenu_H
#define MainMenu_H

#include "Div.hxx"
#include "Uri.hxx"
#include "JScript.hxx"
#include "Link.hxx"

namespace krap
{

class MainMenu;
using MainMenuPtr = std::shared_ptr<MainMenu> ;

class MainMenu : public Div
{
    //! A storage for a java script
    std::shared_ptr<JScript> jscript_;

    //! A storage for a link object
    std::shared_ptr<Link> link_;

private:

    //! No copy ctor
    MainMenu(const MainMenu&) = delete;

public:

    //! Default Ctor
    MainMenu();

    //! Dtor
    virtual ~MainMenu(){};

    //! Inserts a new element to this menu
    void insert(std::string name);

    //! Inserts a new element to this menu
    void insert(std::string name, const UriPtr& uri_ptr);

    //! Returns const reference to the java script stored in this menu object
    const std::shared_ptr<JScript>& jscript() const;

    //! Returns const reference to a stored link object
    const std::shared_ptr<Link>& link() const;
};

}

#endif

//END-OF-FILE

