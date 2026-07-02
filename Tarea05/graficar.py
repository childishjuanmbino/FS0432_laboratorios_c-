import numpy as np
import matplotlib.pyplot as plt


data = np.loadtxt("tiempos.txt", skiprows=1)

procesos = data[:, 0].astype(int)
tiempos = data[:, 1]


idx = np.argsort(procesos)
procesos = procesos[idx]
tiempos = tiempos[idx]


plt.figure()
plt.plot(tiempos, procesos, marker='o')

plt.xlabel("Tiempo del bucle (s)")
plt.ylabel("Número de procesos (P)")
plt.title("Tiempo vs número de procesos (MPI)")
plt.grid(True)


plt.savefig("tiempo_vs_procesos.png", dpi=300, bbox_inches="tight")

plt.show()
