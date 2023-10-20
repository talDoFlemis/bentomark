OBJECTS = main.o NewtonModified.o Newton.o Secant.o Model.o ModelResult.o Function.o

ALL: main

main: $(OBJECTS)
	g++ $(OBJECTS) -o main

%.o: %.cpp
	g++ -c $<

clean:
	rm -rf *.o