#include "DivVector.hxx"
#include "CSS.hxx"

c5p::Div& c5p::DivVector::init_vector_body()
{
    // set styles only for new vectors
    if (this->size() == 0)
    {
        Div vec_body;
        vec_body % css::divTableBody;

        (*this) % css::divTable;
        Div::add(vec_body);
    }

    Element& eref = this->operator[](0);
    Div& div = dynamic_cast<Div&>(eref);
    return div;
}

c5p::DivVector::DivVector()
:
    Div(),
    vector_body_(init_vector_body())
{}

c5p::DivVector::DivVector(const DivVector &dv)
:
    Div(dv),
    vector_body_(init_vector_body())
{}

c5p::DivVector::~DivVector()
{
}

c5p::ElementPtr& c5p::DivVector::add(const Element& el)
{
    Div vec_el;
    vec_el % this->vector_element_css();
    Div el_cell;
    el_cell % css::divTableCell;

    el_cell.add(el);
    vec_el.add(el_cell);
    return vector_body_.add(vec_el);
}

c5p::ElementPtr& c5p::DivVector::add(Element* eptr)
{
    Div vec_el;
    vec_el % vector_element_css();
    Div el_cell;
    el_cell % css::divTableCell;

    el_cell.add(eptr);
    vec_el.add(el_cell);
    return vector_body_.add(vec_el);
}

c5p::ElementPtr& c5p::DivVector::add(const ElementPtr& eptr)
{
    Div vec_el;
    vec_el % vector_element_css();
    Div el_cell;
    el_cell % css::divTableCell;

    el_cell.add(eptr);
    vec_el.add(el_cell);
    return vector_body_.add(vec_el);
}


//
//END-OF-FILE
//
