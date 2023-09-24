#ifndef DivRow_H
#define DivRow_H

#include "DivVector.hxx"

namespace c5p
{

/// @brief 
class DivRow : public DivVector
{

protected:

    /// @brief
    const CSSClass& vector_element_css() override;

public:

    /// @brief Constructs a row of Div elements
    DivRow() = default;

    /// @brief Creates copy of this object
    DivRow(const DivRow&) = default;

    // @brief Creates Div row from a list of elements
    template <typename TagType>
    explicit DivRow (const std::initializer_list<TagType>& elems)
    : DivVector()
    {
        add_elements(elems);
    }

    /// @brief Dtor
    virtual ~DivRow();

    /// @brief Creates copy 
    ElementPtr clone() const override;
};

}

#endif

//
//END-OF-FILE
//

