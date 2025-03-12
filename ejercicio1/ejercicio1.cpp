#include <iostream>
using namespace std;

int **asignacion_memoria(int n)
{
    try
    {
        int **matriz = new int *[n];
        for (int i = 0; i < n; i++)
        {
            matriz[i] = new int[n]; // lenado de columnas
        }
        return matriz;
    }
    catch (bad_alloc &e)
    {  
        return nullptr;
    }
}

void matriz_valores(int** matriz, int n){
    int valor=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matriz[i][j] = valor++;
        }
    }
}

int **crear_matriz(int n)
{
    int **matriz = asignacion_memoria(n);
    if(!matriz) return nullptr;
    matriz_valores(matriz, n);
    return matriz;
}

void imprimir_matriz(int ** matriz, int n){
    int cantidad_elementos = 0;
    cout<<"Los elementos de la matriz son:"<<endl;
    for(int i=(n*n-1); i>=0; i--){
        int j = static_cast<int>(i/n);
        int k = i%n; //la columna es #elem mod3 8,5,2 mod3 = 2
        cout<<"M["<<j<<"]["<<k<<"]: "<<matriz[j][k]<<endl;
    }

}

void destruir_matriz(int ** matriz, int n){
    for(int i=0;i<n;i++){
        delete[] matriz[i];
    }
    delete[] matriz;
}

int main(){
    int n;
    cout<<"Ingrese el tamaño de la matriz:"<<endl;
    cin>>n;
    int ** matriz = crear_matriz(n);
    //caso de falla de asignacion de memoria
    if(!matriz){
        cout<<"No se pudo asignar memoria para la matriz."<<endl; 
        return 1; 
    }

    imprimir_matriz(matriz, n);
    destruir_matriz(matriz, n); 

    return 0;
}
