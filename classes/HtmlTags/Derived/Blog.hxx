#ifndef Blog_H
#define Blog_H

#include "Compound.hxx"
#include "BlogEntry.hxx"
#include "JScript.hxx"

namespace krap
{

/// @brief keeps and renders blog (list of titled records)
class Blog : public Div
{

private:

    /// @brief
    CSSClass title_css_class_;

    /// @brief 
    CSSClass contents_css_class_;

    /// @brief
    CSSClass hover_css_class_;

    /// @brief Sets properties of CSS classes
    void setup_css();

public:

    /// @brief
    Blog();

    /// @brief
    Blog (const Blog&);

    /// @brief
    ~Blog();

public:
     
    /// @brief Adds a new blog entry from the constant ref
    ElementPtr& add (const BlogEntry&);

    /// @brief returns pointer to the JS responsible for
    /// collapsing of blog entries
    JScriptPtr jscript() const;


private:

    /// @brief Forbid adding of Element specified by reference
    virtual ElementPtr& add (const Element&);

    /// @brief Forbid adding of Element specified by pointer
    virtual ElementPtr& add (Element* ept);

    // /// @brief Forbid adding of Element specifed by ElementPtr
    // virtual ElementPtr& add (ElementPtr& eptr);

};

}

#endif

