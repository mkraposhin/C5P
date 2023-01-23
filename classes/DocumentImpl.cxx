#include "DocumentImpl.hxx"

void krap::DocumentImpl::construct()
{
    head() ^ mm_;
};

krap::DocumentImpl::DocumentImpl(const Site& site)
:
    Document(),
    site_(site),
    mm_(site.main_menu())
{
}

krap::DocumentImpl::DocumentImpl(const DocumentImpl& di)
:
    Document(di),
    site_(di.site_),
    mm_(di.mm_)
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

