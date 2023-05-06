#include <iostream>
#include<time.h>
using namespace std;
/*
6) Realice una función que dada una matriz de n por m (siendo n y m parámetros) llena
de 2 números, valide que la matriz no tenga áreas cerradas. Se considera que una
matriz de dos números tiene un área cerrada cuando a partir de un número
(​ubicación ij​), no puedo acceder al espacio de números que le corresponde,
avanzando hacia cualquiera de los 4 costados. Es decir, a través de un casillero n​ij​,
que está completo por un ​número i, ​debo poder moverme a otro casillero que
también tenga ese mismo número i
*/

int ** generarMatriz(int n,int m){
    //se crea la matriz
    int ** matriz = new int*[n];

    for(int i=0;i<m;i++)
        matriz[i] = new int[m];

    //se carga la matriz con numeros "aleatorios"
    int nro1 = 1; int nro2 = 0;

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

bool validar(int ** matriz,int n,int m){
   //lo que se hace en los if anudados es comparar los nros que
   //estan alrededor de la posicion actual
       for(int i = 1;i < n-1;i++){
            for(int j = 1;j < m-1;j++){
                if(matriz[i][j]==1)
                {
                    if(matriz[i-1][j] != matriz[i][j] && matriz[i+1][j] != matriz[i][j] && matriz[i][j+1] != matriz[i][j] && matriz[i][j-1] != matriz[i][j])
                    {
                        return false;
                    }
                }
                 }//fin segundo for
        }//fin primer for

            return true;
}

int main()
{   int m = 30; int n = 30;
    int ** matriz = generarMatriz(n,m);
    srand(time(NULL));
    //aca se muestra la matriz
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout << matriz[i][j] << " ";
        cout<<endl;
    }
    //en esta parte se verifica si la matriz es cerrada
    if(!validar(matriz,n,m))
        cout << "\n\tLA MATRIZ ESTA CERRADA" <<endl;
    else
        cout << "\n\tLA MATRIZ NO ESTA CERRADA" <<endl;
    cout << endl;
    return 0;
}
