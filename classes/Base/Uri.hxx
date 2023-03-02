#ifndef Uri_H
#define Uri_H

#include "Element.hxx"

namespace krap
{

class Site;

class Uri;

using UriPtr = std::shared_ptr<Uri>;

class Uri
{

private:

    //- Disallow move
    Uri (Uri&&) = delete;

    //- Disallow default uri
    Uri() = delete;

private:

    //- uri of a resource where this object points to
    std::string uri_string_;

public:

    //- Constructs Uri object from a string
    //containing uri
    Uri(std::string uri = std::string(""));

    //- Constructs Uri object for a document
    //in the given site
    Uri(std::string doc_name, const Site& site);

    //- Copy ctor
    Uri (const Uri&);

    //- Dtor
    ~Uri(){};

    //- Returns string representation of URI
    const std::string& uri() const;

    //- Return =s string with html representation
    //of URI with text
    const std::string html(const std::string& txt) const;
};

}

#endif

//
//END-OF-FILE
//

