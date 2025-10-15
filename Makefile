all:
	g++ -c FabricItem.cpp Furniture.cpp Worker.cpp Vehicle.cpp main.cpp
	g++ -o test_program main.cpp FabricItem.o Furniture.o Worker.o Vehicle.o
	./test_program

clean:
	rm -f *.o test_program