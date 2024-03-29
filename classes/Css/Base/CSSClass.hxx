#ifndef CSSClass_H
#define CSSClass_H

#include "Element.hxx"
#include "CSSElement.hxx"
#include "AtRule.hxx"
#include <map>
#include <initializer_list>

namespace c5p
{

/*---------------------------------------------------------------------------*\
                            Class CSSClass Declaration
\*---------------------------------------------------------------------------*/

class CSSClass
:
    public Element
{
private:

    //! The name of a CSS class
    std::string css_class_;

    //! The list of properties(css elements) that are contained
    //! in a CSS class (a CSSClass object)
    std::map<std::string,std::shared_ptr<CSSElement>> css_properties_;

    //! The type for a record
    using css_rec_type = std::pair<std::string,std::shared_ptr<CSSElement>>;

    //! An AtRule that is applied to a CSSClass object
    AtRulePtr at_rule_;

public:

    /// @brief Forbid Default constructor of CSSClass
    CSSClass() = delete;

    /// @brief Creates a CSSClass object from the text string
    explicit CSSClass(const std::string& name);
 
    /// @brief Creates a copy of CSSClass object and give it 
    /// a new name
    CSSClass(const std::string& name, const CSSClass& cssclass);

    /// @brief Creates a new CSS class from the given name and
    /// the list of elements
    CSSClass
    (
        const std::string& name,
        const std::initializer_list<CSSElement>& elems
    );

    /// @brief Copy constructor
    CSSClass(const CSSClass& );

    //! Destructor
    ~CSSClass();

    //! Print elements in a CSS class (CSSClass object)
    std::ostream& print(std::ostream& ostr) const override;

    //! Creates clone of a CSS class
    ElementPtr clone() const override;

    //! Returns the name of a CSS class 
    const std::string& name() const;

    //! Adds a property to this CSS class
    void add(const CSSElement& element);

    /// @brief Removes a property from this CSS class
    /// @return 'true' if element was found and removed, otherwise returns false
    bool remove(const CSSElement& element);

    //! Assigns properties from an other css class object to this one
    //! creating deep copy of the corresponding map
    const CSSClass& operator = (const CSSClass& css_class);

    /// @brief Adds properties from a CSS class to this CSS class
    /// @param css_class is an object from where properties are copied
    /// @return a reference to modified CSS class
    const CSSClass& operator += (const CSSClass& css_class);

    //! Sets an at-rule for this css class object
    void at_rule(const AtRule& atru);
};

}

#endif

//
//END-OF-FILE
//
