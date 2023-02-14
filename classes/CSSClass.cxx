#include "CSSClass.hxx"
#include <cgicc/HTMLClasses.h>

krap::CSSClass::CSSClass()
:
    Element()
{
}

krap::CSSClass::CSSClass(const std::string& name)
:
    Element(),
    css_class_(name)
{
}

krap::CSSClass::CSSClass(const CSSClass& cssclass)
:
    Element(cssclass),
    css_class_(cssclass.css_class_),
    css_properties_(cssclass.css_properties_)
{
}

krap::CSSClass::~CSSClass()
{
}

std::ostream& krap::CSSClass::print(std::ostream& ostr) const
{
    ostr << "." << name() << std::endl;
    ostr << "{" << std::endl;
    for (auto property : css_properties_)
    {
        (*property.second).print(ostr);
    }
    ostr << "}" << std::endl;
    return ostr;
}

krap::ElementPtr krap::CSSClass::clone() const
{
    return ElementPtr(new CSSClass(*this));
}

const std::string& krap::CSSClass::name() const
{
    return css_class_;
}

void krap::CSSClass::add(const CSSElement& element)
{
    std::shared_ptr<CSSElement> elptr 
    {
        new CSSElement(element)
    };

    auto new_rec = css_rec_type(element.name(),elptr);
    
    css_properties_.insert
    (
        new_rec
    );
}

const krap::CSSClass& krap::CSSClass::operator = (const CSSClass& css_class)
{
    css_properties_.clear();
    
    for (const auto& property : css_class.css_properties_)
    {
        css_properties_.insert
        (
            css_rec_type
            (
                property.first,
                std::dynamic_pointer_cast<CSSElement>
                    (property.second->clone())
            )
        );
    }
    return *this;
}

//
//END-OF-FILE
//
