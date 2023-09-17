#ifndef Compound_H
#define Compound_H

#include "Element.hxx"
#include <vector>
#include <memory>
#include <initializer_list>

namespace krap
{

/*---------------------------------------------------------------------------*\
                          Class Compound Declaration
\*---------------------------------------------------------------------------*/

//!
class Compound
{
private:


protected:

    //! Ordered list of elements in this compound
    std::vector<ElementPtr> elements_;

public:
     
    //! Default constructor (creates empty compound)
    Compound();

    //! Copy constructor for the Compound
    explicit Compound(const Compound&);

    //! Destructor
    ~Compound();

    //! Adds a new element
    virtual ElementPtr& add (const Element&);

    /// @brief Adds an element stored by ordinary pointer. Takes ownership
    /// of the object
    virtual ElementPtr& add (Element* ept);

    //! Adds an element stored by shared_ptr pointer
    virtual ElementPtr& add (const ElementPtr& eptr);

    //! Prints elements in compound
    virtual std::ostream& print(std::ostream& ostr) const;

    //! Assign operator
    const Compound& operator = (const Compound& right);    


    //- access to elements of a compound

        //! Access with specification of a child type
        template <class CType>
        CType& operator () (int i);

        //! Non-const reference access operator
        Element& operator [] (int i);

        //! begin of a compound
        std::vector<ElementPtr>::iterator begin();

        //! end of a compound
        std::vector<ElementPtr>::iterator end();

        //! const begin of a compound
        std::vector<ElementPtr>::const_iterator cbegin() const;

        //! const end of a compound
        std::vector<ElementPtr>::const_iterator cend() const;

        //! total count of elements of a compound
        int size() const;

        //! removes all child elements from a compound
        void clear();
};


/// @brief Template structure to allow initialization of compound HTML elements
/// @tparam BaseType 
template <typename BaseType>
struct CompoundTagInitializer : public BaseType
{
    CompoundTagInitializer()
    :
        BaseType()
    {}

    CompoundTagInitializer(const CompoundTagInitializer<BaseType>& c)
    :
        BaseType(c)
    {}

    CompoundTagInitializer(const BaseType& c)
    :
        BaseType(c)
    {}

    /// @brief Adds support for initialization from list of object (tags) with similar type
    /// @tparam TagType is a type of HTML elements in the list
    /// @param elems is the list of given HTML elements
    template <typename TagType>
    explicit CompoundTagInitializer(const std::initializer_list<TagType> &elems)
    :
        BaseType()
    {
        for(auto it_el = elems.begin(); it_el != elems.end(); it_el++)
        {
            BaseType::add(*it_el);
        }
    }

    ElementPtr clone () const override
    {
        using CompoundDerivedType = CompoundTagInitializer<BaseType>;
        return this->template clone_cast<CompoundDerivedType>();
    }

    virtual ~CompoundTagInitializer(){};
};

//- summation of two Elements is the new Compound with two elements
std::shared_ptr<Compound> operator + 
(
    const Element& elem1, 
    const Element& elem2
);

//- summation of one Compound and one Element is equal to adding element
//  to this compound (const version)
std::shared_ptr<Compound> operator +
(
    const std::shared_ptr<Compound>& comp1,
    const Element& elem
);

//- summation of one Compound and one Element is equal to adding element
//  to this compound (const version)
std::shared_ptr<Compound> operator +
(
    const Element& elem,
    const std::shared_ptr<Compound>& comp1
);

// actually we have to check correctness of casting here
template <class CType> CType& 
krap::Compound::operator () (int i)
{
    return dynamic_cast<CType&>(this->operator[](i));
}

}

#endif

//
//END-OF-FILE
//

