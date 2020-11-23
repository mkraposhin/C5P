libkrap.a : obj
	ar rcs libkrap.a Element.o Compound.o Page.o Document.o 
obj : Element.o Compound.o Page.o Document.o

clean :
	rm -rf *.o
	rm -rf *.a

CGICC_INC=../../cgicc/include/cgicc

Element.o : Element.cxx Element.hxx
	g++ -c Element.cxx -oElement.o
Compound.o : Compound.cxx Compound.hxx Element.hxx
	g++ -c Compound.cxx -oCompound.o
Page.o : Page.cxx Page.hxx Element.hxx
	g++ -c Page.cxx -oPage.o
Document.o : Document.cxx Document.hxx Compound.hxx Element.hxx Page.hxx
	g++ -c Document.cxx -oDocument.o
