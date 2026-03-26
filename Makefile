SRC_x86 = src/sim.cpp src/BaseRadar.cpp src/QuantumRadar.cpp src/Detector.cpp src/Simulator.cpp src/ClassicalRadar.cpp
INCLUDES = -I./include
COMMONFLAGS = $(INCLUDES) -O2 -Wall

AARCH64_CXX = q++
AARCH64_FLAGS = -Vgcc_ntoaarch64le

X86_CXX = g++
X86_FLAGS = -Vgcc_ntox86_64

all: quant_aarch64le quant_x86

quant_aarch64le:
	$(AARCH64_CXX) $(AARCH64_FLAGS) $(COMMONFLAGS) $(SRC) -o quant_aarch64le

quant_x86:
	$(X86_CXX) $(COMMONFLAGS) $(SRC_x86) -o quant_x86

clean:
	rm -f quant_aarch64le quant_x86
	rm -f data/quantum_DMF_data_H0.csv data/quantum_DMF_data_H1.csv data/classical_DMF_data_H0.csv data/classical_DMF_data_H1.csv
