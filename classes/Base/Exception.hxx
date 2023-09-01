#ifndef Exception_H
#define Exception_H

#include <string>
#include <exception>
#include "Globals.hxx"

namespace krap
{

class GenericException : public std::exception
{

private:
    
    //- an exception reason
    std::string reason_;

    //- the full path to the file where a log is stored
    const static std::string log_path_;

public:

    //- Ctor with reason
    GenericException(std::string reason)
    :
    std::exception(),
    reason_(reason)
    {}

    //- returns a string containing exception descrition
    const char* what() const noexcept override
    {
        return reason_.c_str();
    }

    //- writes a record (from the argument) to the log file
    static void write_record(const std::string) noexcept;

    //- writes a record using exception reason to the log file
    void write_record() const noexcept;

};

}//namespace krap

#endif

//
//END-OF-FILE
//

