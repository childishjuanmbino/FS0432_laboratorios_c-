Para compilar ambos programas se utiliza el codigo:

g++ poisson_1d_Jacobi.cpp -o jacobi -I/home/Juanchi/miniconda3/envs/Fis-Comp/include/python3.11 -I$(python -c "import numpy; print(numpy.get_include())") -L/home/Juanchi/miniconda3/envs/Fis-Comp/lib -lpython3.11 -Wl,-rpath,/home/Juanchi/miniconda3/envs/Fis-Comp/lib

Donde el lugar de compilacion debe cambiarse por el usuario a donde desee. El del metodo de gauss es el mismo pero cambiando donde dice Jacobi por GaussSeidel

Una vez hecho ambos comandos, con solo hacer ./"nombre de metodo" deberia de correr cualquiera de los dos programas.
