#include "DivColumn.hxx"
#include "CSSGlobals.hxx"

krap::DivColumn::DivColumn()
:
    Div()
{
    Div col_body;
    col_body % css::divTableBody;

    (*this) % css::divTable;
    Div::add(col_body);
}

krap::DivColumn::~DivColumn()
{
}

krap::ElementPtr krap::DivColumn::clone() const
{
    return ElementPtr(new DivColumn(*this));
}

krap::ElementPtr& krap::DivColumn::add(const Element& el)
{
    Div el_row;
    el_row % css::divTableRow;
    Div el_cell;
    el_cell % css::divTableCell;

    el_cell.add(el);
    el_row.add(el_cell);
    return this->operator()<Div>(0).add(el_row);
}

krap::ElementPtr& krap::DivColumn::add(Element* eptr)
{
    Div el_row;
    el_row % css::divTableRow;
    Div el_cell;
    el_cell % css::divTableCell;

    el_cell.add(eptr);
    el_row.add(el_cell);
    return this->operator()<Div>(0).add(el_row);
}

krap::ElementPtr& krap::DivColumn::add(ElementPtr& eptr)
{
    Div el_row;
    el_row % css::divTableRow;
    Div el_cell;
    el_cell % css::divTableCell;

    el_cell.add(eptr);
    el_row.add(el_cell);
    return this->operator()<Div>(0).add(el_row);
}

//
//END-OF-FILE
//

