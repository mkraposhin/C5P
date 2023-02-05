#include "CSSRegistry.hxx"
#include "Compound.hxx"

krap::CSSRegistry::CSSRegistry(CSSClassMap& cmap)
:
    css_class_map_(cmap)
{
}

void krap::CSSRegistry::register_css_class(const Element& nelem)
{
    if (nelem.css())
    {
        CSSClassMapRec new_rec
        {
            (*nelem.css()).name(),
            nelem.css()
        };
            
        css_class_map_.insert(new_rec);
    }

    if (nelem.child())
    {
        register_css_class(nelem.child());
    }
    if (dynamic_cast<const Compound*>(&nelem))//if it is a Compound
    {
        auto compound_of_elements = 
            dynamic_cast<const Compound&>(nelem);
        for (auto it :compound_of_elements)
        {
            register_css_class(it);
        }
    }
}

void krap::CSSRegistry::register_css_class(const ElementPtr& eptr)
{
    if (eptr)
    {
        Element& nelem = *eptr;
        register_css_class(nelem);
    }
}

//
//END-OF-FILE
//

