#include "DocumentImpl.hxx"
#include "CSSGlobals.hxx"

void krap::DocumentImpl::construct()
{
    // #warning "Find how to prevent copying of body() content here"
    mmenu_layout_ % krap::css::divRow;
    mmenu_layout_.operator()<Div>(1).add(mm_);
    if (mm_.jscript())
        head().jscript(*mm_.jscript());
    if (mm_.link())
        head().link(*mm_.link());
    
    head() ^ mmenu_layout_;
    body().add(three_cols_);
};

krap::Div& krap::DocumentImpl::layout()
{
    return three_cols_;
}

krap::DocumentImpl::DocumentImpl(const Site& site)
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
    CSSClass bodyCss {"bodyCss"};
    bodyCss.add(css::marginTop20px);
    bodyCss.add(css::paddingTop20px);

    body() % bodyCss;

    CSSClass textClass {"middleColumnText, p, a"};
    textClass.add(css::font18px);
    textClass.add(css::fontOblique);
    textClass.add(FontFamily{"Arial, sans-serif"});
    Div ap_div;
    ap_div % textClass;
    middle_col_.add(ap_div);


    three_cols_ % krap::css::divRow;
    left_col_ % krap::css::sideColumn;
    middle_col_ % krap::css::middleColumn;
    right_col_ % krap::css::sideColumn;
    three_cols_.add(left_col_);
    three_cols_.add(middle_col_);
    three_cols_.add(right_col_);

    mmenu_layout_ % krap::css::divRow;
    mmenu_layout_.add(*(left_col_.clone()));
    mmenu_layout_.add(*(middle_col_.clone()));
    mmenu_layout_.add(*(right_col_.clone()));
}

krap::DocumentImpl::DocumentImpl(const DocumentImpl& di)
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

krap::ElementPtr krap::DocumentImpl::clone() const
{
    return ElementPtr (new DocumentImpl(*this));
}

std::ostream& krap::DocumentImpl::print(std::ostream& ostr) const
{
    const_cast<DocumentImpl*>(this)->construct();
    return Document::print(ostr);
}

//
//END-OF-FILE
//

