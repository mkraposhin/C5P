#ifndef BlogEntry_H
#define BlogEntry_H

#include "Div.hxx"
#include "Button.hxx"

namespace krap
{

/// @brief describes one entry in a blog
class BlogEntry : public Div
{

private:

    /// @brief Holds the title of an entry
    Button entry_title_;

    /// @brief Holds the contents of an entry
    Div entry_contents_;

    /// @brief
    BlogEntry
    (
        const std::string& title, Div entry_contents,
        const CSSClass& title_css, const CSSClass& cont_css
    );

public:

    /// @brief Default ctor for compatibility with base class
    BlogEntry();

    /// @brief  Copy ctor for compatibility with the base class
    /// @param be : another instance of BlogEntry
    BlogEntry(const BlogEntry& be);

    //// @brief
    BlogEntry(const BlogEntry& be, const CSSClass&, const CSSClass&);

    /// @brief Creates a new entry from the title
    /// text and contents
    BlogEntry(const std::string& title, Div entry_contents);

    /// @brief Prints contents of blog entry (title + div element)
    /// @param ostr 
    /// @return reference to ostream with updated html document
    virtual std::ostream& print(std::ostream& ostr) const override;

    /// @brief creates clone of itself
    virtual ElementPtr clone() const override;

};

using BlogEntryPtr = std::shared_ptr<BlogEntry>;

}

#endif

//
//END-OF-FILE
//
