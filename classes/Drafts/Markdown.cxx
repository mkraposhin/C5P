#include "Markdown.hxx"
#include <iostream>
#include <sstream>
#include <fstream>

#ifdef MADDY_MD_TRANSLATOR
#include "maddy/parser.h"
#endif

#define MD4C_MD_TRANSLATOR
#ifdef MD4C_MD_TRANSLATOR
#include "md4c-html.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>


/// @brief namespace contains functions from original sources for
/// md2html
namespace md4c
{

#warning "Redirect erros to the log file"

struct membuffer
{
    char* data;
    size_t asize;
    size_t size;
};

static void
membuf_init(struct membuffer* buf, MD_SIZE new_asize)
{
    buf->size = 0;
    buf->asize = new_asize;
    buf->data = (char*)malloc(buf->asize);
    if(buf->data == NULL) {
        fprintf(stderr, "membuf_init: malloc() failed.\n");
        exit(1);
    }
}

static void
membuf_fini(struct membuffer* buf)
{
    if(buf->data)
        free(buf->data);
}

static void
membuf_grow(struct membuffer* buf, size_t new_asize)
{
    buf->data = (char*)realloc(buf->data, new_asize);
    if(buf->data == NULL) {
        fprintf(stderr, "membuf_grow: realloc() failed.\n");
        exit(1);
    }
    buf->asize = new_asize;
}

static void
membuf_append(struct membuffer* buf, const char* data, MD_SIZE size)
{
    if(buf->asize < buf->size + size)
        membuf_grow(buf, buf->size + buf->size / 2 + size);
    memcpy(buf->data + buf->size, data, size);
    buf->size += size;
}

static void
process_output(const MD_CHAR* text, MD_SIZE size, void* userdata)
{
    membuf_append((struct membuffer*) userdata, text, size);
}

}

#endif

void krap::MarkdownValue::value_print(std::ostream& ostr) const
{
#ifdef MD4C_MD_TRANSLATOR

    std::string inp_str = text_;

    if (text_.empty())
    {
        std::ifstream inpf{file_name_};
        std::stringstream buffer;
        buffer << inpf.rdbuf();
        inp_str = buffer.str();
    }

    md4c::membuffer buf_out = {
        .data  = 0,
        .asize = 0,
        .size  = 0
    };
    // guess initial size
    md4c::membuf_init(&buf_out, inp_str.size() + inp_str.size()/8 + 64);
    unsigned parser_flags   =
         MD_DIALECT_COMMONMARK  |
         MD_FLAG_TABLES         |
         MD_FLAG_STRIKETHROUGH  |
         MD_FLAG_LATEXMATHSPANS |
         MD_FLAG_TASKLISTS      |
         MD_FLAG_UNDERLINE;
    unsigned renderer_flags = 0;

    md_html
    (
        inp_str.c_str(),
        inp_str.size(),
        &md4c::process_output,
        &buf_out,
        parser_flags,
        renderer_flags
    );

    ostr << std::string {""}.assign(buf_out.data, buf_out.size) << std::endl;

    md4c::membuf_fini(&buf_out);
#endif

#ifdef MADDY_MD_TRANSLATOR
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
#endif
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

