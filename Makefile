CXX = g++
CXXFLAGS = -I./include -O2 -Wall

SRC = src/main.cpp src/QuantumRadar.cpp src/QuantumDetector.cpp

# Build
all: quant

quant:
	$(CXX) $(CXXFLAGS) $(SRC) -o quant

# Clean
clean:
	rm -f quant
