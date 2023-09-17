#ifndef DivRow_H
#define DivRow_H

#include "Div.hxx"

namespace c5p
{

/// @brief 
class DivRow : public Div
{

    /// @brief a style for the whole row
    CSSClassPtr div_table_row_ptr_;

    /// @brief a style for an each cell
    CSSClassPtr div_table_cell_ptr_;

    /// @brief gives a non-const access to a list of div's in the row
    Div &div_row();

public:

    /// @brief Constructs a row of Div elements
    DivRow();

    /// @brief Creates copy of this object
    DivRow(const DivRow&) = default;

    /// @brief Dtor
    ~DivRow();

    /// @brief Adds a new element to a div row
    virtual ElementPtr& add (const Element&) override;

    /// @brief Adds an element stored by a ordinary pointer to a div row
    virtual ElementPtr& add (Element* ept) override;

    /// @brief Adds an element stored by a shared_ptr pointer to a div row
    virtual ElementPtr& add (const ElementPtr& eptr) override;

    /// @brief Creates copy 
    ElementPtr clone() const override;

    /// @brief Sets width for each element
    void cell_width(int w);

    /// @brief Sets css class of the contained row
    void row_css(const CSSClass& css);
};

}

#endif

//
//END-OF-FILE
//

