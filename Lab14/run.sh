g++ -fopenmp matrix_multiplication.cpp -o matrix_multiplication.x

touch tiempos.txt


OMP_NUM_THREADS=1 ./matrix_multiplication.x > tiempos.txt
OMP_NUM_THREADS=2 ./matrix_multiplication.x >> tiempos.txt
OMP_NUM_THREADS=4 ./matrix_multiplication.x >> tiempos.txt
OMP_NUM_THREADS=8 ./matrix_multiplication.x >> tiempos.txt
OMP_NUM_THREADS=16 ./matrix_multiplication.x >> tiempos.txt
OMP_NUM_THREADS=32 ./matrix_multiplication.x >> tiempos.txt
OMP_NUM_THREADS=64 ./matrix_multiplication.x >> tiempos.txt
OMP_NUM_THREADS=128 ./matrix_multiplication.x >> tiempos.txt


python3 graficar.py

