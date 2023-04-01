#include "Markdown.hxx"
#include <iostream>
#include <sstream>
#include <fstream>
#include "maddy/parser.h"

void krap::MarkdownValue::value_print(std::ostream& ostr) const
{
    std::unique_ptr<std::istream> istr_ptr;

    if (!text_.empty())
    {
        istr_ptr.reset(new std::istringstream{text_});
    }
    else
    {
        if (!file_name_.empty())
        {
            std::unique_ptr<std::ifstream> file_stream_ptr
                {new std::ifstream{file_name_}};
            if (file_stream_ptr->is_open())
            {
                istr_ptr.reset(file_stream_ptr.release());
            }
        }
    }

    if (bool(istr_ptr))
    {
        maddy::Parser md_parser{};
        ostr << std::endl << md_parser.Parse(*istr_ptr) << std::endl;
    }
}

void krap::MarkdownValue::set_text(const std::string txt)
{
    file_name_ = "";
    text_ = txt;
}

void krap::MarkdownValue::set_file(const std::string file_name)
{
    text_ = "";
    file_name_ = file_name;
}

//
//END-OF-FILE
//

