#ifndef SiteImpl_H
#define SiteImpl_H


#include "Home.hxx"
#include "Education.hxx"
#include "ProfExperience.hxx"
#include "MyContributions.hxx"
#include "Contacts.hxx"
#include "Site.hxx"

namespace c5p
{

class SiteImpl : public Site
{

protected:

    void create_pages () override
    {
        insert_doc("home", Home {*this});
        insert_doc("education", Education{*this});
        insert_doc("prof_experience", ProfExperience{*this});
        insert_doc("my_contributions", MyContributions(*this));
        insert_doc("contacts", Contacts{*this});
    }

public:

    SiteImpl() : Site()
    {
        create_pages();
    }

};

}

#endif

//
//END-OF-FILE
//
