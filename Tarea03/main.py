import ecuaciones
import numpy as np
import matplotlib.pyplot as plt

x0 = 1
y0 = 1
z0 = 1
tf = 40
t0 = 0
h = 0.01

N = int((tf - t0) / h) + 1
print(N)
t = np.linspace(t0, tf, N)
sol_euler = ecuaciones.euler(t0, tf, h, x0, y0, z0)
sol_rk2 = ecuaciones.rk2(t0, tf, h, x0, y0, z0)
sol_rk4 = ecuaciones.rk4(t0, tf, h, x0, y0, z0)

r1 = [x0, y0, z0]



print("solucion con euler:")
for i in range(10):
    x, y, z = sol_euler[i]
    print(f"{i:4d}  x={x:10.5f}  y={y:10.5f}  z={z:10.5f}")
print("Solucion rk2")
for i in range(10):
    x, y, z = sol_rk2[i]
    print(f"{i:4d}  x={x:10.5f}  y={y:10.5f}  z={z:10.5f}")
print("Solucion rk4:")
for i in range(10):
    x, y, z = sol_rk4[i]
    print(f"{i:4d}  x={x:10.5f}  y={y:10.5f}  z={z:10.5f}")


sol_euler = np.array(ecuaciones.euler(t0, tf, h, x0, y0, z0))
sol_rk2 = np.array(ecuaciones.rk2(t0, tf, h, x0, y0, z0))
sol_rk4 = np.array(ecuaciones.rk4(t0, tf, h, x0, y0, z0))    
    
fig = plt.figure(figsize=(8,6))
ax = fig.add_subplot(111, projection='3d')

ax.plot(sol_euler[:,0],
        sol_euler[:,1],
        sol_euler[:,2])

ax.set_title("Sistema de Lorenz - Euler")
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("z")

plt.savefig("trayectoria_3d_euler.png", dpi=300)
plt.close()


fig = plt.figure(figsize=(8,6))
ax = fig.add_subplot(111, projection='3d')

ax.plot(sol_rk2[:,0],
        sol_rk2[:,1],
        sol_rk2[:,2])

ax.set_title("Sistema de Lorenz - RK2")
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("z")

plt.savefig("trayectoria_3d_rk2.png", dpi=300)
plt.close()

fig = plt.figure(figsize=(8,6))
ax = fig.add_subplot(111, projection='3d')

ax.plot(sol_rk4[:,0],
        sol_rk4[:,1],
        sol_rk4[:,2])

ax.set_title("Sistema de Lorenz - RK4")
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("z")

plt.savefig("trayectoria_3d_rk4.png", dpi=300)
plt.close()

x0= 1 + 10**(-8)

sol_rk4_2 = ecuaciones.rk4(t0, tf, h, x0, y0, z0)

sol_rk4_2 = np.array(ecuaciones.rk4(t0, tf, h, x0, y0, z0)) 


d = np.linalg.norm(sol_rk4 - sol_rk4_2, axis=1)

print(f"Separación inicial: {d[0]:.10e}")
print(f"Separación final:   {d[-1]:.10e}")

fig = plt.figure(figsize=(8,6))
ax = fig.add_subplot(111, projection='3d')

ax.plot(sol_rk4_2[:,0],
        sol_rk4_2[:,1],
        sol_rk4_2[:,2])

ax.set_title("Sistema de Lorenz - RK4")
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("z")

plt.savefig("sensibilidad.png", dpi=300)
plt.close()
