#include "Div.hxx"

#ifndef DivVector_H
#define DivVector_H

namespace c5p
{

class CSSClass;

class DivVector : public Div
{

protected:

    template <typename TagType>
    void add_elements (const std::initializer_list<TagType>& elems)
    {
        for(auto it_el = elems.begin(); it_el != elems.end(); it_el++)
        {
            add(*it_el);
        }
    }

    /// @brief
    virtual const CSSClass& vector_element_css() = 0;

    /// @brief
    Div& init_vector_body();

    /// @brief
    Div& vector_body_;

public:

    /// @brief Constructs a vector of Div elements
    DivVector();

    /// @brief Creates copy of this object
    DivVector(const DivVector&);

    /// @brief Dtor
    virtual ~DivVector();

    /// @brief Add a new element
    virtual ElementPtr& add (const Element&) override;

    /// @brief Add the element stored by a ordinary pointer
    virtual ElementPtr& add (Element* ept) override;

    /// @brief Add the element stored by a shared_ptr pointer
    virtual ElementPtr& add (const ElementPtr& eptr) override;

    /// @brief Creates copy of this vector of divs
    virtual ElementPtr clone() const = 0;
};

}

#endif

//
//END-OF-FILE
//
