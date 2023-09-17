#include "BlogEntry.hxx"


c5p::BlogEntry::BlogEntry
(
    const std::string& title, Div entry_contents,
    const CSSClass& title_css, const CSSClass& cont_css
)
:
    Div(),
    entry_title_(title),
    entry_contents_(entry_contents)
{
    entry_title_ % title_css;
    entry_contents_ % cont_css;
    Div::add(entry_title_);
    Div::add(entry_contents_);
}

c5p::BlogEntry::BlogEntry()
:
    BlogEntry
    (
        std::string(""), Div(),
        CSSClass("entry_title_css"), CSSClass("entry_cont_css")
    )
{
}

c5p::BlogEntry::BlogEntry(const BlogEntry& be)
:
    BlogEntry
    (
        be.entry_title_.value_, be.entry_contents_,
        *be.entry_title_.css(), *be.entry_contents_.css()
    )
{
}

c5p::BlogEntry::BlogEntry
(
    const BlogEntry& be, const CSSClass& css_title, const CSSClass& css_cont
)
:
    BlogEntry(be.entry_title_.value_, be.entry_contents_, css_title, css_cont)
{
}

c5p::BlogEntry::BlogEntry(const std::string& title, Div entry_contents)
:
    BlogEntry
    (
        title, entry_contents,
        CSSClass("entry_title_css"), CSSClass("entry_cont_css")
    )
{
}

std::ostream& c5p::BlogEntry::print(std::ostream& ostr) const
{
    Div::print(ostr);
    return ostr;
}

c5p::ElementPtr c5p::BlogEntry::clone() const
{
    return ElementPtr{new BlogEntry{*this}};
}

//
//
//

