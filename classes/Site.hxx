#ifndef Site_H
#define Site_H

#include "Globals.hxx"
#include "Document.hxx"
#include "MainMenu.hxx"
#include <map>

namespace krap
{

/*---------------------------------------------------------------------------*\
                          Class Site Declaration
\*---------------------------------------------------------------------------*/

class Site
{
private:

    using DocumentMap = std::map<std::string,DocumentPtr>;

    DISALLOW_COPY(Site)

    DISALLOW_EQ(Site)

private:

    /// @brief a map of documents
    DocumentMap doc_map_;

    /// @brief An empty document to return when there is nothing
    /// found in doc_map_
    const Document blank_doc_;

    /// @brief A main menu which is syncrhonized with
    /// the content of this site
    MainMenu main_menu_;

    /// @brief Inserts a new document into the site
    void insert_doc(std::string nm, const Document& doc);

public:

    /// @brief Ctor
    Site();

    /// @brief Dtor
    ~Site(){};

    /// @brief Returns count of documents in the site
    int n_documents() const;

    /// @brief Does this site contains the document with the name doc_name
    bool has_document(const std::string& doc_name) const;

    /// @brief Returns document if it is present
    const Document& operator[] (const std::string& doc_name) const;

    /// @brief Returns const reference to the main menu of this site
    const MainMenu& main_menu() const;
};

}

#endif

//
//END-OF-FILE
//

