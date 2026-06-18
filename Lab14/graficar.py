import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("tiempos.txt")

threads = data[:, 0]
times = data[:, 1]

plt.plot(threads, times, marker='o')
plt.xlabel("Número de hilos")
plt.ylabel("Tiempo (s)")
plt.title("Multiplicación matricial con OpenMP")
plt.grid(True)

plt.savefig("tiempo_vs_hilos.png")
plt.show()
