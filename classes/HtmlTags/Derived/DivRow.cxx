#include "DivRow.hxx"
#include "CSS.hxx"
#include "Size.hxx"

const c5p::CSSClass& c5p::DivRow::vector_element_css()
{
    return c5p::css::divTableColumn;
}

c5p::DivRow::~DivRow()
{
}

c5p::ElementPtr c5p::DivRow::clone() const
{
    return ElementPtr(new DivRow(*this));
}

//
//END-OF-FILE
//

