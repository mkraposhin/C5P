#ifndef DivColumn_H
#define DivColumn_H

#include "DivVector.hxx"

namespace c5p
{

class DivColumn : public DivVector
{

protected:

    /// @brief
    const CSSClass& vector_element_css() override;

public:

    /// @brief Constructs column of Div elements
    DivColumn() : DivVector(){};

    /// @brief Creates copy of this column of Divs
    DivColumn(const DivColumn& divc) : DivVector(divc){};

    /// @brief Creates Div column from a list of elements
    template <typename TagType>
    explicit DivColumn (const std::initializer_list<TagType>& elems)
    : DivVector()
    {
        add_elements(elems);
    }

    /// @brief Dtor
    virtual ~DivColumn();

    /// @brief Creates copy 
    ElementPtr clone() const override;

};

}

#endif

//
//END-OF-FILE
//

