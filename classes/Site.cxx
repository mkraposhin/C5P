#include "Site.hxx"
#include "Uri.hxx"
#include "Home.hxx"
#include "Education.hxx"
#include "Patents.hxx"
#include "ProfExperience.hxx"
#include "MyOssProjects.hxx"
#include "MyPublications.hxx"

void krap::Site::insert_doc(std::string nm, const Document& doc)
{
    DocumentPtr doc_ptr = std::dynamic_pointer_cast<Document>(doc.clone());

    doc_map_.insert
    (
        std::make_pair
        (
            nm,
            doc_ptr
        )
    );

    UriPtr uri {new Uri{nm, *this}};

    main_menu_.insert(nm, uri);
}

krap::Site::Site()
:
    doc_map_{},
    blank_doc_{},
    main_menu_{}
{
    insert_doc("home", Home {*this});
    insert_doc("education", Education{*this});
    insert_doc("patents", Patents{*this});
    insert_doc("prof_experience", ProfExperience{*this});
    insert_doc("my_oss_projects", MyOssProjects{*this});
    insert_doc("my_publications", MyPublications{*this});
}

int krap::Site::n_documents() const
{
    return doc_map_.size();
}

bool krap::Site::has_document(const std::string& name) const
{
    return doc_map_.count(name);
}

const krap::Document&
krap::Site::operator[] (const std::string& doc_name) const
{
    if (has_document(doc_name))
    {
        return doc_map_.at(doc_name).operator*();
    }
    return blank_doc_;
}

const krap::MainMenu&
krap::Site::main_menu() const
{
    return main_menu_;
}

//
//END-OF-FILE
//

