import numpy as np
import matplotlib.pyplot as plt

np.random.seed(1213)  # Semilla aleatoria
N = 100_000          # Tamaño de la muestra
bins = 100          # Cantidad de bines

# Parámetros por distribución
a, b = 0, 1         # Uniforme
lam = 2             # Exponencial (lambda)
mu, sigma = 0, 1    # Gaussiana (media y desviación estándar)

# ==========================================
# 1. DISTRIBUCIÓN UNIFORME
# ==========================================

data_uni = np.random.uniform(a, b, size=N)

plt.hist(data_uni, bins=bins, density=True, alpha=0.6, color='blue', label='Empírica')

x_uni = np.linspace(a, b, 1000)
pdf_uni = np.ones(1000) / (b - a)
plt.plot(x_uni, pdf_uni, 'r-', lw=2, label='Teórica (PDF)')

plt.title('Distribución Uniforme $U(a, b)$')
plt.xlabel('x')
plt.ylabel('Densidad de probabilidad')
plt.legend()
plt.show()

# ==========================================
# 2. DISTRIBUCIÓN EXPONENCIAL
# ==========================================

# El parmetro es scale, no lambda. Entonces scale = 1/lambda
data_exp = np.random.exponential(scale=1.0/lam, size=N)

plt.hist(data_exp, bins=bins, density=True, alpha=0.6, color='green', label='Empírica')

x_exp = np.linspace(0, max(data_exp), 1000)
pdf_exp = lam * np.exp(-lam * x_exp)
plt.plot(x_exp, pdf_exp, 'r-', lw=2, label='Teórica (PDF)')


plt.title('Distribución Exponencial $Exp(\\lambda)$')
plt.xlabel('x')
plt.ylabel('Densidad de probabilidad')
plt.legend()
plt.show()  

# ==========================================
# 3. DISTRIBUCIÓN GAUSSIANA (NORMAL)
# ==========================================

data_gauss = np.random.normal(loc=mu, scale=sigma, size=N)

plt.hist(data_gauss, bins=bins, density=True, alpha=0.6, color='purple', label='Empírica')
x_gauss = np.linspace(min(data_gauss), max(data_gauss), 1000)

pdf_gauss = (1.0 / (sigma * np.sqrt(2 * np.pi))) * np.exp(-0.5 * ((x_gauss - mu) / sigma)**2)
plt.plot(x_gauss, pdf_gauss, 'r-', lw=2, label='Teórica (PDF)')


plt.title('Distribución Normal $N(\\mu, \\sigma)$')
plt.xlabel('x')
plt.ylabel('Densidad de probabilidad')
plt.legend()
plt.show()