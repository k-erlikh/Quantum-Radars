import numpy as np
import matplotlib.pyplot as plt

H0_q = np.loadtxt("quantum_DMF_data_H0.csv")
H1_q = np.loadtxt("quantum_DMF_data_H1.csv")

plt.hist(H0_q, bins=100, alpha=0.5, label="H0")
plt.hist(H1_q, bins=100, alpha=0.5, label="H1")
#plt.axvline(x=0.5, color='red', linestyle='--', label='Threshold')

plt.legend()
plt.xlabel("Detector Match Filtering (Dmf)")
plt.ylabel("Count")
plt.title("Figure 1. Quantum Detector Match Filtering for Hypothesis")
plt.savefig("sample_quantum_DMF_histogram.png", dpi=300)
plt.show()

plt.clf()

H0_c = np.loadtxt("classical_DMF_data_H0.csv")
H1_c = np.loadtxt("classical_DMF_data_H1.csv")

plt.hist(H0_c, bins=100, alpha=0.5, label="H0")
plt.hist(H1_c, bins=100, alpha=0.5, label="H1")
#plt.axvline(x=0.5, color='red', linestyle='--', label='Threshold')

plt.legend()
plt.xlabel("Detector Match Filtering (Dmf)")
plt.ylabel("Count")
plt.title("Figure 2. Classical Detector Match Filtering for Hypothesis")
plt.savefig("sample_classical_DMF_detector_histogram.png", dpi=300)
plt.show()