#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

#include "SiteImpl.hxx"
#include "CSS.hxx"
#include "Globals.hxx"
#include "Exception.hxx"

int main (int argc, char * argv[])
{
    using namespace c5p;
    try
    {
        cgicc::Cgicc cgi;

        SiteImpl site;

        auto goHome = [&cgi, &site]()
        {
            if (cgi.getElements().size() == 0)
            {
                return true;
            }

            if (cgi.getElement("where")->isEmpty())
            {
                return true;
            }

            if (!site.has_document(cgi("where")))
            {
                return true;
            }

            if (cgi("where") == std::string("home"))
            {
                return true;
            }

            return false;
        };

        if (goHome())
        {
            std::cout << site[std::string("home")] << std::endl;
        }
        else
        {
            std::cout << site[cgi("where")] << std::endl;
        }
    }
    catch(const GenericException& ge)
    {
        std::cerr << ge.what() << std::endl;
        ge.write_record();
        return -1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        GenericException::write_record(e.what());
        return -1;
    }
    catch(...)
    {
        std::cerr << "Unknown exception" << '\n';
        GenericException::write_record(std::string("Unknown excepton"));
        return -1;
    }
    return 0;
}

//
//END-OF-FILE
//

