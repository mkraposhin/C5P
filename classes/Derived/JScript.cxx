#include "JScript.hxx"
#include <cgicc/HTMLClasses.h>

krap::JScript::JScript(const std::string& fname, const std::string& s)
:
    //Element(),
    func_name_(fname),
    script_txt_(s)
{

}

const std::string& krap::JScript::function_name() const
{
    return func_name_;
}

std::shared_ptr<krap::JScript> krap::JScript::clone() const
{
    return std::shared_ptr<JScript>
        {new JScript{this->func_name_,this->script_txt_}};
}

std::ostream& krap::JScript::print(std::ostream& ostr) const
{
    ostr << cgicc::script() << std::endl;
    if (this->func_name_.size())
        ostr << "function " << this->func_name_ << std::endl;
    ostr << this->script_txt_ << std::endl;
    ostr << cgicc::script() << std::endl;

    return ostr;
}

//
//END-OF-FILE
//

