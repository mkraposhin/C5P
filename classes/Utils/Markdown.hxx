#ifndef Markdown_H
#define Markdown_H

#include "HtmlTag.hxx"
#include "Attributes.hxx"

namespace c5p
{
/// @brief This class is responsible for translation from the Markdown to the
/// HTML formats. Today it uses a Maddy library
/// (https://github.com/progsource/maddy)
struct MarkdownValue : public ValueBase<c5p::TagId::DIV,true,void*>
{
    /// @brief 
    MarkdownValue() = default;

    /// @brief 
    /// @param md 
    MarkdownValue(const MarkdownValue& md) = default;

    /// @brief
    ~MarkdownValue(){};

    /// @brief
    /// @param ostr
    void value_print(std::ostream& ostr) const override;

    /// @brief 
    /// @param txt 
    void set_text(const std::string txt);

    /// @brief 
    /// @param file_name 
    void set_file(const std::string file_name);

private:

    /// @brief 
    std::string text_;

    /// @brief 
    std::string file_name_;

};

using MarkdownBase = HtmlTagBase<MarkdownValue,IdAttribute>;
using Markdown = HtmlTagImpl<MarkdownBase>;

}

#endif

