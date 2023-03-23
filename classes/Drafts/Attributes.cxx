#include "Attributes.hxx"

void krap::IdAttribute::id (const std::string& id)
{
    id_ = id;
}

const std::string krap::IdAttribute::id() const
{
    return id_;
}

//
//END-OF-FILE
//

