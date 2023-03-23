#ifndef HtmlTag_H
#define HtmlTag_H

// #include <tuple>
#include <iostream>
#include <Element.hxx>
#include <CSSClass.hxx>

namespace krap
{

const char* tag_str[] = {"a", "p", "div"};

template<int tag, bool t_has_closing>
struct ValueBase
{
    //!
    const std::string tag_str = tag_str[tag];

    //!
    const bool has_closing    = t_has_closing;

    //!
    ValueBase(){}

    //!
    ValueBase(const ValueBase& valbase){}

    //!
    virtual void value_print(std::ostream& ostr) const
    {
    }
};

//! A type to hold several attributes
template <class ...Attrs>
using AttributesList = std::tuple<Attrs...>;

//!
template <class ValueType, class ...Attrs>
struct HtmlTagBase : public Element, ValueType, public Attrs...
{
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

    // //!
    // template<class T>
    // void print_attribs
    // (const T*, const Attrs* ...attrs, std::ostream &ostr) const
    // {
    //     T::print_attribute(ostr);
    //     print_attribs(attrs..., ostr);
    // }

    // //!
    // template<class T>
    // void print_attribs
    // (const T* cattr, std::ostream &ostr) const
    // {
    //     T::print_attribute(ostr);
    // }

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

    //using Base_T = HtmlTagBase<ValueType, Attrs...>;

    // //! Creates a clone of an html tag
    // ElementPtr clone() const override
    // {
    //     return ElementPtr(new Base_T{*this});
    // }
};

// //!
// template <class AL, int pos>
// void print_attributes(AL& attrib_list, std::ostream& ostr)
// {
//     if constexpr (pos >= 0)
//     {
//         auto c_attr = std::get<pos>(attrib_list);
//         c_attr.print_attribute(ostr);
//         print_attributes<pos-1>(attrib_list);
//     }
// }

// template <class ...Attrs>
// struct HtmlTagBase
// {

//     AttributesList<Attrs...> attribs_;


//     HtmlTagBase(const HtmlTagBase& tag)
//     {}

// };

// //!
// template <class TagType>
// struct HtmlTag : public TagType
// {

//     //!
//     HtmlTag (const HtmlTag& html_tag)
//     :
//         TagType(html_tag)
//     {

//     }

//     //!
//     void print(std::ostream& ostr)
//     {
//         if (TagType == EmptyType)
//         {
//             //that might be a container object
//             //value_print(ostr) ??
//         }
//         ostr<< "<" << tag_str << ">";
//         value_print(ostr);
//         if (has_closing)
//         {
//             ostr<< "</"<< tag_str << ">" << std::endl;
//         }
//     }

//     //!
//     virtual void value_print(std::ostream& ostr) = 0;

// };

}

#endif

//
//END-OF-FILE
//

