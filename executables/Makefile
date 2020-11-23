home.cgi : home.o
	g++ home.o -L../classes -lkrap -ohome.cgi
home.o : home.cxx
	g++ -c -I../classes home.cxx -ohome.o

clean:
	rm -rf home.cgi
	rm -rf home.o