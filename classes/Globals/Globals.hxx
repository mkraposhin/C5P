#ifndef Globals_H
#define Globals_H

#include <string>

namespace c5p
{

struct constants
{
    static const std::string protocol;
    static const std::string site_uri;
    static const std::string log_path;
    static const int column_width = 300; //px
};

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

