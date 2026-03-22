SRC = src/main.cpp src/QuantumRadar.cpp src/QuantumDetector.cpp src/Simulator.cpp src/ClassicalRadar.cpp
INCLUDES = -I./include
COMMONFLAGS = $(INCLUDES) -O2 -Wall

AARCH64_CXX = q++
AARCH64_FLAGS = -Vgcc_ntoaarch64le

X86_CXX = q++
X86_FLAGS = -Vgcc_ntox86_64

all: quant_aarch64le quant_x86

quant_aarch64le:
	$(AARCH64_CXX) $(AARCH64_FLAGS) $(COMMONFLAGS) $(SRC) -o quant_aarch64le

quant_x86:
	$(X86_CXX) $(X86_FLAGS) $(COMMONFLAGS) $(SRC) -o quant_x86

clean:
	rm -f quant_aarch64le quant_x86
	rm -f data/signalData_H0.csv data/signalData_H1.csv