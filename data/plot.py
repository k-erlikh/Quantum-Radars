import numpy as np
import matplotlib.pyplot as plt

H0 = np.loadtxt("signalData_H0.csv")
H1 = np.loadtxt("signalData_H1.csv")

plt.hist(H0, bins=100, alpha=0.5, label="H0")
plt.hist(H1, bins=100, alpha=0.5, label="H1")
#plt.axvline(x=0.5, color='red', linestyle='--', label='Threshold')

plt.legend()
plt.xlabel("Detector Match Filtering (Dmf)")
plt.ylabel("Count")
plt.title("Figure 1. Detector Match Filtering for Null Hypothesis and Hypothesis")
plt.savefig("sample_detector_histogram.png", dpi=300)
plt.show()