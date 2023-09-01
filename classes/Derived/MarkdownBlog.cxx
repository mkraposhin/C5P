#include "MarkdownBlog.hxx"
#include "Markdown.hxx"
#include <string>

krap::MarkdownBlog::MarkdownBlog
(
    const std::string& dir,
    const std::vector<std::string>& titles
)
: Blog(),
  dir_(dir),
  titles_(titles)
{
    auto title_to_filename = [](const std::string& str)
    {
        std::string::size_type space_pos = 0;
        std::string filename = str;
        while ( (space_pos = filename.find(" ")) != std::string::npos)
        {
            filename.replace(space_pos, 1, "_");
        }
        filename = filename + std::string(".md");
        return filename;
    };

    for (auto title : titles_)
    {
        std::string file_name = title_to_filename(title);
        files_.push_back(file_name);
    }

    for (std::vector<std::string>::size_type i = 0;
         i < titles_.size(); i++)
    {
        const std::string& title = titles_[i];
        const std::string& file = files_[i];
        const std::string& md_path = dir_ + "/" + file;
        Markdown md;
        md.set_file(md_path);
        Div be_div;
        be_div.add(md);
        BlogEntry be {title, be_div};
        Blog::add(be);
    }
}

krap::MarkdownBlog::MarkdownBlog(const MarkdownBlog& md_blog)
:
    Blog(md_blog),
    dir_(md_blog.dir_),
    titles_(md_blog.titles_),
    files_(md_blog.files_)
{
}


krap::MarkdownBlog::~MarkdownBlog()
{

}
//
//END-OF-FILE
//

