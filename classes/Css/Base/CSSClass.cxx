#include "CSSClass.hxx"
#include <cgicc/HTMLClasses.h>

c5p::CSSClass::CSSClass(const std::string& name)
:
    Element(),
    css_class_(name)
{
}

c5p::CSSClass::CSSClass
(
    const std::string& name,
    const std::initializer_list<CSSElement> &elems
)
:
    Element(),
    css_class_(name)
{
    for(auto it_el = elems.begin(); it_el != elems.end(); it_el++)
    {
        add(*it_el);
    }
}

c5p::CSSClass::CSSClass(const CSSClass& cssclass)
:
    Element(cssclass),
    css_class_(cssclass.css_class_),
    css_properties_(cssclass.css_properties_),
    at_rule_(cssclass.at_rule_)
{
}

c5p::CSSClass::~CSSClass()
{
}

std::ostream& c5p::CSSClass::print(std::ostream& ostr) const
{
    const auto& nm = this->name();
    const auto& css_props = this->css_properties_;
    auto print_css_class = [&nm, &css_props](std::ostream& ostr)
    {
        ostr << "." << nm << std::endl;
        ostr << "{" << std::endl;
        for (auto property : css_props)
        {
            (*property.second).print(ostr);
        }
        ostr << "}" << std::endl;
    };
    if(at_rule_ )
        at_rule_->print(print_css_class, ostr);
    else
        print_css_class(ostr);

    return ostr;
}

c5p::ElementPtr c5p::CSSClass::clone() const
{
    return ElementPtr(new CSSClass(*this));
}

const std::string& c5p::CSSClass::name() const
{
    return css_class_;
}

void c5p::CSSClass::add(const CSSElement& element)
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

bool c5p::CSSClass::remove(const CSSElement& element)
{
    if (css_properties_.count(element.name()))
    {
        css_properties_.erase(element.name());
        return true;
    }
    return false;
}

const c5p::CSSClass& c5p::CSSClass::operator = (const CSSClass& css_class)
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

    if (css_class.at_rule_)
    {
        at_rule_ = css_class.at_rule_->clone();
    }
    else
    {
        at_rule_.reset(css_class.at_rule_.get());
    }
    
    return *this;
}

const c5p::CSSClass& c5p::CSSClass::operator += (const CSSClass& css_class)
{
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

void c5p::CSSClass::at_rule(const AtRule& atru)
{
    this->at_rule_ = atru.clone();
}

//
//END-OF-FILE
//
