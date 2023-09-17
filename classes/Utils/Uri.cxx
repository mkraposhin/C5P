#include "Uri.hxx"
#include "Site.hxx"
#include <sstream>
#include <cgicc/HTMLClasses.h>

c5p::Uri::Uri(std::string uri)
:
    uri_string_(uri)
{
}

c5p::Uri::Uri(std::string doc_name, const Site& site)
:
    uri_string_(std::string(""))
{
    if (site.has_document(doc_name))
    {
        uri_string_ = "home.cgi?where=" + doc_name; 
    }
}

c5p::Uri::Uri (const Uri& uri)
{
    uri_string_ = uri.uri_string_;
}

const std::string& c5p::Uri::uri() const
{
    return uri_string_;
}

const std::string c5p::Uri::html(const std::string& txt) const
{
    std::stringstream ostr;

    cgicc::a html_elem{};

    ostr<< cgicc::a().set("href", this->uri())
        << txt 
        << cgicc::a();
    
    return ostr.str();
}

//
//END-OF-FILE
//

