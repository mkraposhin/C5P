#include "AtRule.hxx"

c5p::AtRule::AtRule(const std::string& nm, const std::string& pars)
:
name_(nm),
pars_(pars)
{}

c5p::AtRule::~AtRule()
{}

std::shared_ptr<c5p::AtRule> c5p::AtRule::AtRule::clone() const
{
    return std::shared_ptr<AtRule>{new AtRule{this->name_, this->pars_}};
}

//
//END-OF-FILE
//

