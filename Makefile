run: Drivers.o Hwk3Main.o
	g++ Drivers.o Hwk3Main.o -o run

Drivers.o: Drivers.cpp
	g++ -c Drivers.cpp

Hwk3Main.o: Hwk3Main.cpp
	g++ -c Hwk3Main.cpp

clean:
	rm *.o run