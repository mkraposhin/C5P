#include "CaptionedImage.hxx"
#include "Globals.hxx"
#include "ParagraphText.hxx"

void krap::CaptionedImage::construct()
{
    (*this) % css::divTable;

    Div table_body;
    table_body % css::divTableBody;
    
    Div image_row;
    Div image_div;
    image_row % css::divTableRow;
    image_div % css::divTableCell;
    image_div.add(image_);
    image_row.add(image_div);
    
    Div caption_row;
    Div caption_div;
    ParagraphText caption_txt (caption());
    caption_row % css::divTableRow;
    caption_div % css::divTableCell;
    caption_div.add(caption_txt);
    caption_row.add(caption_div);

    table_body.add(image_row);
    table_body.add(caption_row);

    this->add(table_body);
}

krap::CaptionedImage::CaptionedImage()
:
    Div(),
    image_(),
    caption_(std::string(""))
{
    construct();
}

krap::CaptionedImage::CaptionedImage(const std::string& text)
:
    Div(),
    image_(text),
    caption_(std::string(""))
{
    construct();
}

krap::CaptionedImage::CaptionedImage(const CaptionedImage& p)
:
    Div(),
    image_(p.image_),
    caption_(p.caption_)
{
    construct();
}

krap::CaptionedImage::~CaptionedImage(){}

const std::string& krap::CaptionedImage::caption(const std::string& s)
{
    caption_ = s;
    return caption_;
}

const std::string& krap::CaptionedImage::caption() const
{
    return caption_;
}

krap::Image& krap::CaptionedImage::image()
{
    return image_;
}

const krap::Image& krap::CaptionedImage::image() const
{
    return image_;
}

std::ostream& krap::CaptionedImage::print(std::ostream& ostr) const
{
    return Div::print(ostr);
}

krap::ElementPtr krap::CaptionedImage::clone() const
{
    CaptionedImage* new_image = new CaptionedImage(*this);
    new_image->clear();
    new_image->construct();
    return ElementPtr(new_image);
}

//
//END-OF-FILE
//

