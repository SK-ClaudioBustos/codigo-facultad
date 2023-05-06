#include <iostream>
#include<time.h>
using namespace std;
/*
5) Realice una función que llene una matriz de n por m (siendo n y m parámetros) con 2
números, de forma aleatoria. Los dos números puede definirlos usted
 */

int ** generarMatriz(int n,int m){
    //se crea la matriz
    int ** matriz = new int*[n];
    //se carga la matriz
    for(int i=0;i<m;i++)
        matriz[i] = new int[m];
    //se devuelve la matriz creada
    return matriz;
}


int ** CargaAleatoria(int n,int m){
   int ** matriz = generarMatriz(n,m);
   //se carga la matriz con numeros "aleatorios"
   //en este caso el enunciado nos permite definirlos
    int nro1 = 1; int nro2 = 0;
   //se carga la matriz de manera aleatoria
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            int valor = rand() % 1500;
            if(valor%2 == 0)
                matriz[i][j] = nro1;
            else
                matriz[i][j] = nro2;
        }
    //finalmente se devuelve la matriz
    return matriz;
}

int main()
{   srand(time(NULL));
    int n = 4; int m = 4;
    int ** matriz=CargaAleatoria(n,m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout << matriz[i][j] << " ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
