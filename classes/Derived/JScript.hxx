#ifndef JScript_H
#define JScript_H

#include "Element.hxx"

namespace krap
{

class JScript// : public Element
{
    //! The JS function name, which stored in this object
    const std::string func_name_;

    //! A text of a script
    const std::string script_txt_;

public:

    //! Creates an instance of JScript using given text
    JScript(const std::string& fname, const std::string& txt);

    //! Returns the name of the S function
    const std::string& function_name() const;

    //! Creates a clone of this JScript object
    std::shared_ptr<JScript> clone() const;

    //! Prints this script
    std::ostream& print(std::ostream&) const;
};

using JScriptPtr = std::shared_ptr<JScript>;

}//namespace krap

#endif

//
//END-OF-FILE
//

