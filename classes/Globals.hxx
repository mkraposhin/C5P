#ifndef Globals_H
#define Globals_H

#include <string>

namespace krap
{

namespace constants
{
    const std::string protocol {"http://"};
    //const std::string site_uri {"194.4.51.15/"};
    // const std::string site_uri {"kraposhin.online/"};
    const std::string site_uri {"127.0.0.1/"};
    const std::string log_path {"/var/log/cpp_cms"};
}

}

#define DISALLOW_EQ(class_name)                           \
const class_name& operator = (const class_name&) = delete;\
const class_name& operator = (class_name&&);

#define DISALLOW_COPY(class_name)                         \
class_name(const class_name&) = delete;                   \
class_name(class_name &&) = delete;                       \

#define DISALLOW_ALL(class_name)                          \
class_name();                                             \
DISALLOW_EQ(class_name)                                   \
DISALLOW_COPY(class_name)

#endif

//
//END-OF-FILE
//

