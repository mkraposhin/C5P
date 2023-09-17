#ifndef MarkdownBlog_H
#define MarkdownBlog_H

#include "Blog.hxx"

namespace c5p
{

class MarkdownBlog : public Blog
{

    /// @brief 
    std::string dir_;

    /// @brief 
    std::vector<std::string> titles_;

    /// @brief 
    std::vector<std::string> files_;

public:

    /// @brief Creates a new MarkdownBlog by specifying directory
    /// with files and the list of files (list of titles)
    MarkdownBlog
    (
        const std::string& dir,
        const std::vector<std::string>& titles
    );

    /// @brief Creates Markdown as copy
    MarkdownBlog(const MarkdownBlog& md_blog);

    /// @brief Destroys a MarkdownBlog
    ~MarkdownBlog();

};

}

#endif

//
//END-OF-FILE
//

