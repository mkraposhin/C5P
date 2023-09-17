#include "DocumentImpl.hxx"
#include "CSS.hxx"

void c5p::DocumentImpl::construct()
{
    #warning "Find how to prevent copying of body() content here"
    mmenu_layout_ % c5p::css::divRow;
    mmenu_layout_.operator()<Div>(1).add(mm_);
    if (mm_.jscript())
        head().jscript(*mm_.jscript());
    if (mm_.link())
        head().link(*mm_.link());
    
    head() ^ mmenu_layout_;
    body().add(three_cols_);
};

c5p::Div& c5p::DocumentImpl::layout()
{
    return three_cols_;
}

c5p::DocumentImpl::DocumentImpl(const Site& site)
:
    Document(),
    site_(site),
    mm_(site.main_menu()),
    three_cols_(),
    left_col_(),
    middle_col_(),
    right_col_(),
    mmenu_layout_()
{
    head().add_meta("viewport", "width=device-width, initial-scale=1.0");

    CSSClass bodyCss
    {
        "bodyCss",
        {css::margin::top20px, css::padding::top20px}
    };

    body() % bodyCss;

    CSSClass textClass
    {
        "middleColumnText, p, a",
        {css::font18px, FontFamily{"Arial, sans-serif"}}
    };

    Div ap_div;
    ap_div % textClass;
    middle_col_.add(ap_div);

    three_cols_ % c5p::css::divRow;
    left_col_ % c5p::css::sideColumn;
    middle_col_ % c5p::css::middleColumn;
    right_col_ % c5p::css::sideColumn;
    three_cols_.add(left_col_);
    three_cols_.add(middle_col_);
    three_cols_.add(right_col_);

    mmenu_layout_ % c5p::css::divRow;
    mmenu_layout_.add(*(left_col_.clone()));
    mmenu_layout_.add(*(middle_col_.clone()));
    mmenu_layout_.add(*(right_col_.clone()));
}

c5p::DocumentImpl::DocumentImpl(const DocumentImpl& di)
:
    Document(di),
    site_(di.site_),
    mm_(di.mm_),
    three_cols_(di.three_cols_),
    left_col_(di.left_col_),
    middle_col_(di.middle_col_),
    right_col_(di.right_col_),
    mmenu_layout_(di.mmenu_layout_)
{
}

c5p::ElementPtr c5p::DocumentImpl::clone() const
{
    return ElementPtr (new DocumentImpl(*this));
}

std::ostream& c5p::DocumentImpl::print(std::ostream& ostr) const
{
    const_cast<DocumentImpl*>(this)->construct();
    return Document::print(ostr);
}

//
//END-OF-FILE
//

