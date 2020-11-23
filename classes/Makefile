obj : Element.o Compound.o Page.o

clean :
	rm -rf *.o

Element.o : Element.cxx Element.hxx
	g++ -c Element.cxx -oElement.o
Compound.o : Compound.cxx Compound.hxx Element.hxx
	g++ -c Compound.cxx -oCompound.o
Page.o : Page.cxx Page.hxx Element.hxx
	g++ -c Page.cxx -oPage.o

