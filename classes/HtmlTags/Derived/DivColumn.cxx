#include "DivColumn.hxx"
#include "CSS.hxx"

krap::Div& krap::DivColumn::init_column_body()
{
    Div col_body;
    col_body % css::divTableBody;

    (*this) % css::divTable;
    Div::add(col_body);

    return this->operator()<Div>(0);
}

krap::DivColumn::DivColumn()
:
    Div(),
    column_body_(init_column_body())
{}

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
    return column_body_.add(el_row);
}

krap::ElementPtr& krap::DivColumn::add(Element* eptr)
{
    Div el_row;
    el_row % css::divTableRow;
    Div el_cell;
    el_cell % css::divTableCell;

    el_cell.add(eptr);
    el_row.add(el_cell);
    return column_body_.add(el_row);
}

krap::ElementPtr& krap::DivColumn::add(ElementPtr& eptr)
{
    Div el_row;
    el_row % css::divTableRow;
    Div el_cell;
    el_cell % css::divTableCell;

    el_cell.add(eptr);
    el_row.add(el_cell);
    return column_body_.add(el_row);
}

//
//END-OF-FILE
//

