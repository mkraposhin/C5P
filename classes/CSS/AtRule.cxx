#include "AtRule.hxx"

krap::AtRule::AtRule(const std::string& nm, const std::string& pars)
:
name_(nm),
pars_(pars)
{}

krap::AtRule::~AtRule()
{}

std::shared_ptr<krap::AtRule> krap::AtRule::AtRule::clone() const
{
    return std::shared_ptr<AtRule>{new AtRule{this->name_, this->pars_}};
}

//
//END-OF-FILE
//

