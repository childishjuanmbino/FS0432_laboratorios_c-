"""
Compara integración por Simpson vs Monte Carlo.

I = int_0^1 ... int_0^1 prod_i sin(pi x_i) dx_1 ... dx_d
"""

import numpy as np
from scipy.integrate import simpson
import time

d = 3  # dimensión del problema
valor_analitico = (2.0 / np.pi)**d

# ---------------------------------------------------------
# MÉTODO DE MONTE CARLO
# ---------------------------------------------------------
def montecarlo(d, valor_analitico):
	print(f"--- Integración en d={d} ---")
	print(f"Analítico:   {valor_analitico:.8f}")
	N_total_mc = 10**6


	t0_mc = time.time()

	integral_mc = 0.0
	sumatoria = 0.0

	for i in range(N_total_mc):
		xi = np.random.uniform(0.0, 1.0, d)
		
		producto = np.prod(np.sin(np.pi * xi))
		
		sumatoria += producto
		
	integral_mc = (1/N_total_mc)*sumatoria

	t1_mc = time.time()
	error_mc = abs(integral_mc - valor_analitico)   

	print(
	    f"Monte Carlo: {integral_mc:.8f} "
	    f"(Error: {error_mc:.8f}, Tiempo: {t1_mc - t0_mc:.4f}s)"
	)

# ---------------------------------------------------------
# MÉTODO DE SIMPSON
# ---------------------------------------------------------

def simpsons(d, valor_analitico):
	N_simpson = 10
	N_total_simpson = N_simpson**d

	t0_simpson = time.time()

	x_1d = np.linspace(0, 1, N_simpson)
	malla = np.meshgrid(*[x_1d] * d, indexing="ij")

	Z = np.prod([np.sin(np.pi * m) for m in malla], axis=0)

	integral_simpson = Z
	for _ in range(d):
	    integral_simpson = simpson(integral_simpson, x=x_1d, axis=0)

	t1_simpson = time.time()
	error_simpson = abs(integral_simpson - valor_analitico)

	print(
	    f"Simpson:     {integral_simpson:.8f} "
	    f"(Error: {error_simpson:.8f}, Tiempo: {t1_simpson - t0_simpson:.4f}s)"
	)
for i in range(8):
	valor_analitico = (2.0 / np.pi)**(i+1)
	montecarlo(i+1, valor_analitico)
	simpsons(i+1, valor_analitico)
	
print("Ya para este punto muere el simpsons, por lo que se continua hasta llegar a un valor entre 9 y 100 en montecarlo")
for i in range(100):
	valor_analitico = (2.0 / np.pi)**(i+8)
	montecarlo(i+8, valor_analitico)
print(f"Con N_simpson {N_total_simpson}")
print(f"Con N_mc {N_total_mc}")
 
