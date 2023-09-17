#include "DivRow.hxx"
#include "CSS.hxx"
#include "Size.hxx"

c5p::Div &c5p::DivRow::div_row()
{
    #warning "Make it as in DivColumn"
    std::cout<< "krap::DivColumn::div_row s" << std::endl;
    Div& div = this->operator()<Div>(0);
    std::cout<< "krap::DivColumn::div_row e" << std::endl;
    return this->operator()<Div>(0).operator()<Div>(0);
}

c5p::DivRow::DivRow()
:
    Div(),
    div_table_row_ptr_{new CSSClass{css::divTableRow.name()}},
    div_table_cell_ptr_{new CSSClass{css::divTableCell.name()}}
{
    *div_table_row_ptr_ = css::divTableRow;
    *div_table_cell_ptr_= css::divTableCell;

    Div row;
    row % *div_table_row_ptr_;

    Div row_body;
    row_body % css::divTableBody;
    row_body.add(row);

    (*this) % css::divTable;
    Div::add(row_body);
}

c5p::DivRow::~DivRow()
{
}

c5p::ElementPtr& c5p::DivRow::add(const Element& el)
{
    Div &div_row = this->div_row();
    Div el_cell;
    el_cell % *div_table_cell_ptr_;
    el_cell.add(el);

    return div_row.add(el_cell);
}

c5p::ElementPtr& c5p::DivRow::add(Element* eptr)
{
    Div &div_row = this->div_row();
    Div el_cell;
    el_cell % *div_table_cell_ptr_;
    el_cell.add(eptr);

    return div_row.add(el_cell);
}

c5p::ElementPtr& c5p::DivRow::add(const ElementPtr& eptr)
{
    Div &div_row = this->div_row();
    Div el_cell;
    el_cell % *div_table_cell_ptr_;
    el_cell.add(eptr);

    return div_row.add(el_cell);
}

c5p::ElementPtr c5p::DivRow::clone() const
{
    return ElementPtr(new DivRow(*this));
}

void c5p::DivRow::cell_width(int w)
{
    std::string nm = css::divTableCell.name() +
        "_width" + std::to_string(w) + "px";
    div_table_cell_ptr_.reset(new CSSClass{nm});
    *div_table_cell_ptr_ = css::divTableCell;
    div_table_cell_ptr_->add(Width(w));

    for (auto &cell_div : div_row())
    {
        *cell_div % *div_table_cell_ptr_;
    }
}

void c5p::DivRow::row_css(const CSSClass& css_class)
{
    std::string nm_row = css::divTableRow.name() +
        + "_" + css_class.name();
    div_table_row_ptr_.reset(new CSSClass{nm_row});
    *div_table_row_ptr_ = css::divTableRow;
    *div_table_row_ptr_ += css_class;

    std::string nm_table = css::divTable.name() +
        + "_" + css_class.name();
    CSSClass table_css{nm_table};
    table_css = css::divTable;
    table_css+= css_class;
    *this % table_css;

    this->div_row() % *div_table_row_ptr_;
}

//
//END-OF-FILE
//

