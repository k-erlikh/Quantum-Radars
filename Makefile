CXX = g++
CXXFLAGS = -I./include -O2 -Wall

SRC = src/main.cpp src/QuantumRadar.cpp src/QuantumDetector.cpp src/Simulator.cpp

# Build
all: quant

quant:
	$(CXX) $(CXXFLAGS) $(SRC) -o quant

# Clean
clean:
	rm -f quant
