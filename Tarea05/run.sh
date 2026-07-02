mpic++ -O3 producto_punto_mpi.cpp -o producto_punto_mpi.x 


touch tiempos.txt
echo "procesos tiempo" > tiempos.txt


for P in 1 2 4 8
do
    echo 

    
    TIME=$(mpirun -np $P ./producto_punto_mpi.x | grep "TIEMPO" | awk '{print $NF}')

    
    echo "$P $TIME" >> tiempos.txt
done

python3 graficar.py
