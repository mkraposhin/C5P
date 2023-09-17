#include "Exception.hxx"
#include <fstream>
#include <chrono>
#include <ctime>

const std::string c5p::GenericException::log_path_ (c5p::constants::log_path);

#warning "Write check whether log file is writable"

void c5p::GenericException::write_record(const std::string record) noexcept
{
    std::ofstream err_log (log_path_.c_str(), std::ios::ate);
    std::time_t c_time = std::chrono::system_clock::to_time_t
        (std::chrono::system_clock::now());
    err_log<< "[" << std::ctime(&c_time) << "]: " 
           << record << std::endl;
    err_log.close();
}

void c5p::GenericException::write_record() const noexcept
{
    write_record(this->reason_);
}

//
//END-OF-FILE
//

