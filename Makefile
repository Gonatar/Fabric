CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic
TARGET = fabric_app
SOURCES = main.cpp Menu.cpp Keeper.cpp FabricItem.cpp Furniture.cpp Worker.cpp Vehicle.cpp
HEADERS = Menu.h Keeper.h FabricItem.h Furniture.h Worker.h Vehicle.h
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean