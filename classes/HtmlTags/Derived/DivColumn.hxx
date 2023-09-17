#ifndef DivColumn_H
#define DivColumn_H

#include "Div.hxx"

namespace c5p
{

class DivColumn : public Div
{

private:

    /// @brief
    Div& init_column_body();

    /// @brief
    Div& column_body_;

public:

    //- Constructs column of Div elements
    DivColumn();

    //- Creates copy of this object
    DivColumn(const DivColumn&) = default;

    // @brief Creates Div column from a list of elements
    template <typename TagType>
    explicit DivColumn (const std::initializer_list<TagType>& elems)
    : column_body_(init_column_body())
    {
        for(auto it_el = elems.begin(); it_el != elems.end(); it_el++)
        {
            add(*it_el);
        }
    }

    //- Dtor
    virtual ~DivColumn();

    //- Add a new element
    virtual ElementPtr& add (const Element&) override;

    //- Add the element stored by a ordinary pointer
    virtual ElementPtr& add (Element* ept) override;

    //- Add the element stored by a shared_ptr pointer
    virtual ElementPtr& add (const ElementPtr& eptr) override;

    //- Creates copy 
    ElementPtr clone() const override;

};

}

#endif

//
//END-OF-FILE
//

