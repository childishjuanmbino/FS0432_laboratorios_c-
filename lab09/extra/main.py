import vectores as v
import numpy as np
import time 

A = [1, 2, 3]
B = [4, 5, 6]

C = v.sumar_vectores(A, B)

print(C)

N = 10_000_00
D = np.random.uniform(0, 1, N)
E = np.random.uniform(0, 1, N)

pp_python = 0

t_init = time.time()
for i in range(N):
    pp_python += D[i] * E[i]

t_final = time.time()
t_python = t_final - t_init

print(f"Python: {pp_python:.4f}, tiempo: {t_python:.4f}")

t_init = time.time()
pp_cpp = v.producto_punto(D, E)
t_final = time.time()
t_cpp = t_final - t_init

print(f"C++: {pp_cpp:.4f}, tiempo: {t_cpp:.4f}")
