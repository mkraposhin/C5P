#include "DivColumn.hxx"
#include "CSS.hxx"

c5p::Div& c5p::DivColumn::init_column_body()
{
    Div col_body;
    col_body % css::divTableBody;

    (*this) % css::divTable;
    Div::add(col_body);

    Element& eref = this->operator[](0);
    Div& div = dynamic_cast<Div&>(eref);
    return div;
}

c5p::DivColumn::DivColumn()
:
    Div(),
    column_body_(init_column_body())
{}

c5p::DivColumn::~DivColumn()
{
}

c5p::ElementPtr c5p::DivColumn::clone() const
{
    return ElementPtr(new DivColumn(*this));
}

c5p::ElementPtr& c5p::DivColumn::add(const Element& el)
{
    Div el_row;
    el_row % css::divTableRow;
    Div el_cell;
    el_cell % css::divTableCell;

    el_cell.add(el);
    el_row.add(el_cell);
    return column_body_.add(el_row);
}

c5p::ElementPtr& c5p::DivColumn::add(Element* eptr)
{
    Div el_row;
    el_row % css::divTableRow;
    Div el_cell;
    el_cell % css::divTableCell;

    el_cell.add(eptr);
    el_row.add(el_cell);
    return column_body_.add(el_row);
}

c5p::ElementPtr& c5p::DivColumn::add(const ElementPtr& eptr)
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

