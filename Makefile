CXX = g++
CXXFLAGS = -I./include -O2 -Wall

SRC = src/main.cpp src/QuantumRadar.cpp
TARGET = quant

# Build
all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean
clean:
	rm -f $(TARGET)