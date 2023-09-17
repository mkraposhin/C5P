#ifndef Document_H
#define Document_H

#include "Page.hxx"
#include "Head.hxx"

namespace c5p
{

/*---------------------------------------------------------------------------*\
                          Class Document Declaration
\*---------------------------------------------------------------------------*/


/// @brief Represents one HTML web page
class Document
:
    public Element
{
protected:

    /// @brief  Holds map of CSS classes used in the document
    CSSClassMap css_class_map_;

    /// @brief Represents the header of the document
    Head head_;

    /// @brief Represents the body of the document
    Page body_;

public:
     
    /// @brief Default constructor (creates an empty document)
    Document();

    /// @brief Creates a copy of the given document
    Document(const Document&);

    /// @brief Destruct the document
    virtual ~Document();

    /// @brief Prints the content of the document
    virtual std::ostream& print(std::ostream& ostr) const override;

    /// @brief Gives non-const access to the documents body
    Page& body();
    
    /// @brief Gives non-const access to the documents head
    Head& head();

    /// @brief Creates a clone of itself (copy of the document)
    virtual ElementPtr clone() const override;
};

using DocumentPtr = std::shared_ptr<Document>;

}

#endif

//
//END-OF-FILE
//

