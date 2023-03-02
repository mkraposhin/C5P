#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

#include "Site.hxx"
#include "CSSGlobals.hxx"
#include "Exception.hxx"

int main (int argc, char * argv[])
{
    using namespace krap;
    try
    {
        cgicc::Cgicc cgi;

        krap::init_globals();

        Site site;

        auto goHome = [&cgi, &site]()
        {
            bool home = false;
            home |= (cgi.getElements().size() == 0);
            if (home) return home;

            home |= (cgi.getElement("where")->isEmpty());
            if (home) return home;

            home |= !site.has_document(cgi("where"));
            if (home) return home;

            home |= (cgi("where") == std::string("home"));
            if (home) return home;

            return home;
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

