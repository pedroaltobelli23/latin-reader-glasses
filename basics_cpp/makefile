CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
TARGET = programa
SRCS = basic_1.cpp add.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

debug: $(TARGET)
	gdb ./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run debug clean