#ifndef AtRule_H
#define AtRule_H
#include <string>
#include <iostream>
#include <memory>

namespace krap
{

class AtRule;
using AtRulePtr = std::shared_ptr<AtRule>;

class AtRule
{

private:

    //! A name of an at-rule
    const std::string name_;

    //! Parameters of an at-rule
    const std::string pars_;

public:

    //! Constructs an at-rule with given name and parameters
    AtRule(const std::string& nm, const std::string& pars);

    //! Destroys an at-rule
    ~AtRule();

    //! Prints an at-rule
    template<class NestedType>
    std::ostream& print(const NestedType& nested, std::ostream& ostr) const;

    //! Creates a clone of this at-rule
    AtRulePtr clone() const;
};

} //namespace krap

template<class NT> std::ostream&
krap::AtRule::print(const NT& nested, std::ostream& ostr) const
{
    ostr<< name_ << " " << pars_ 
        << "{" << std::endl;
    nested(ostr);
    ostr<< "}" << std::endl;
    return ostr;
}

#endif

//
//END-OF-FILE
//

