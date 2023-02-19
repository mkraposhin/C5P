#ifndef Image_H
#define Image_H

#include "Div.hxx"
#include "Uri.hxx"

namespace krap
{

class Uri;

class Image;
using ImagePtr = std::shared_ptr<Image>;

/*---------------------------------------------------------------------------*\
                            Class Image Declaration
\*---------------------------------------------------------------------------*/

class Image
:
    public Element
{
private:
    
    //- The uri
    UriPtr uri_;

    //- Width of an image
    int width_;

public:

    //- Default constructor
    Image();

    //- Create from the text string
    Image(const std::string& text);

    //- Copy constructor
    Image(const Image& p);

    //- Destructor
    ~Image();

    //- Print elements in the Image
    std::ostream& print(std::ostream& ostr) const override;

    //- Creates clone of the Image
    ElementPtr clone() const override;

    //- Sets the width of an image
    int width(int w);

    //- Returns the width of an image
    const int width() const;
};

}

#endif

//
//END-OF-FILE
//
