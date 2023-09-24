#include "DivColumn.hxx"
#include "CSS.hxx"


const c5p::CSSClass& c5p::DivColumn::vector_element_css()
{
    return c5p::css::divTableRow;
}

c5p::DivColumn::~DivColumn()
{
}

c5p::ElementPtr c5p::DivColumn::clone() const
{
    return ElementPtr(new DivColumn(*this));
}

//
//END-OF-FILE
//

