#include "Uri.hxx"
#include "Site.hxx"
#include <sstream>
#include <cgicc/HTMLClasses.h>

krap::Uri::Uri(std::string uri)
:
    uri_string_(uri)
{
}

krap::Uri::Uri(std::string doc_name, const Site& site)
:
    uri_string_(std::string(""))
{
    if (site.has_document(doc_name))
    {
        uri_string_ = "home.cgi?where=" + doc_name; 
    }
}

krap::Uri::Uri (const Uri& uri)
{
    uri_string_ = uri.uri_string_;
}

const std::string& krap::Uri::uri() const
{
    return uri_string_;
}

const std::string krap::Uri::html(const std::string& txt) const
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

