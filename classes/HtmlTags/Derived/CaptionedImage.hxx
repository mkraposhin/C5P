#ifndef CaptionedImage_H
#define CaptionedImage_H

#include "Image.hxx"
#include "Div.hxx"

namespace c5p
{

class CaptionedImage : public Div
{

private:

    //- A stored image
    Image image_;

    //- The caption string of an image
    std::string caption_;

    //- Constructs nested div elements
    void construct();

public:

    //- Default ctor
    CaptionedImage();

    //- Create from the text string
    CaptionedImage(const std::string& text);

    //- Copy constructor
    CaptionedImage(const CaptionedImage& p);

    //- Destructor
    ~CaptionedImage();

    //- Sets the caption of an Image
    const std::string& caption(const std::string& s);

    //- Gives the caption of an Image
    const std::string& caption() const;

    //- Non-const access to an Image
    Image& image();

    //- Const access to an Image
    const Image& image() const;

    //- Print elements of a CaptionedImage
    std::ostream& print(std::ostream& ostr) const override;

    //- Creates clone of itself
    virtual ElementPtr clone() const override;
};

}


#endif

