#ifndef HtmlTag_H
#define HtmlTag_H

#include <iostream>
#include <Element.hxx>
#include <CSSClass.hxx>

namespace c5p
{

//!
enum TagId
{
    A = 0,
    P,
    DIV,
    IMAGE,
    TITLE,
    LINK,
    BUTTON,
    LIST_ITEM,
    UNORDERED_LIST,
    ORDERED_LIST
};

//!
extern const char* tag_str[];

//!
template<unsigned int tagid, bool t_has_closing, typename T>
struct ValueBase
{
    //!
    using value_type = std::string;

    //!
    static const std::string tag_str;

    //!
    const bool has_closing    = t_has_closing;

    //!
    T value_;

    //!
    ValueBase(){}

    //!
    ValueBase(const ValueBase& valbase):
    value_(valbase.value_){}

    //!
    virtual void value_print(std::ostream& ostr) const = 0;

    //! Forbid move ctor
    ValueBase (ValueBase&& v) = delete;

    //! Forbid move assignment operator
    const ValueBase& operator = (ValueBase&& v) = delete;
};

template<unsigned int tagid, bool t_has_closing, typename T>
const std::string c5p::ValueBase<tagid,t_has_closing,T>::tag_str =
std::string(c5p::tag_str[tagid]);

//!
template <class ValueType, class ...Attrs>
struct HtmlTagBase : public Element, ValueType, public Attrs...
{
    //!
    using value_type = typename ValueType::value_type;

    //! Copy ctor for a tag
    HtmlTagBase(const HtmlTagBase& TagBase)
    :
        Element(TagBase),
        ValueType(TagBase),
        Attrs(TagBase)...
    {}

    //!
    HtmlTagBase()
    :
        Element(),
        ValueType(),
        Attrs()...
    {}

    //!
    std::ostream& print_attribs(std::ostream& ostr) const
    {
        ((Attrs::print_attribute(ostr)), ...); //C++ 17 folding expression
        //print_attribs(Attrs(this)..., ostr);
        return ostr;
    }

    //! Print elements in this html tag element
    std::ostream& print(std::ostream& ostr) const override
    {
        print_t(ostr);
        return ostr;
    }

    //! This actually prints an html tag into an ostream
    void print_t(std::ostream& ostr) const
    {
        ostr<< "<" << ValueType::tag_str;
        if (css())
        {
            ostr<< " class=\"" << (*css()).name()<< "\" ";
        }
        print_attribs(ostr) << ">";
        ValueType::value_print(ostr);
        if (ValueType::has_closing)
        {
            ostr<< "</"<< ValueType::tag_str << ">" << std::endl;
        }
    }
};

template <typename Base>
class HtmlTagImpl : public Base
{
protected:

    using DerivedType = HtmlTagImpl<Base>; 

    //!
    template <typename ToClass>
    ElementPtr clone_cast() const
    {
        ElementPtr eptr (new ToClass(*dynamic_cast<const ToClass*>(this)));
        return eptr;
    }

public:

    //!
    HtmlTagImpl()
    :
        Base()
    {}

    //!
    HtmlTagImpl(const HtmlTagImpl& html_impl)
    :
        Base(html_impl)
    {}

    //!
    explicit HtmlTagImpl(const typename Base::value_type& val)
    :
        Base()
    {
        Base::value_ = val;
    }

    //!
    virtual ~HtmlTagImpl(){};

    /// @brief  returns clone of this object casted to the wrapped type.
    /// Must be re-implemented in all wrapping (inheriting) types
    /// @return ElementPtr (general pointer) to copy.
    virtual ElementPtr clone () const override
    {
        return clone_cast<DerivedType>();
    }
};

}

#endif

//
//END-OF-FILE
//

