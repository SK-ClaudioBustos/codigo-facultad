#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>
#include <time.h>

using namespace std;

int ** generarMatriz(int n,int m);//funcion que genera matriz
void vaciarMatriz(int ** matriz,int n);//funcion que vacia matriz
int ** NrosAleatorios(int n,int m);//EJERCICIO1
int ** SumaMatriz (int ** Matriz1,int ** Matriz2,int n, int m);//EJERCICIO2
int ** NroPorParametro(int n,int m, int x);//EJERCICIO3
int ** RotarMatriz(int ** Matriz3,int n,int m);//EJERCICIO4
int ** CargaAleatoria(int n,int m);//EJERCICIO5
bool validar(int ** matriz,int n,int m);//EJERCICIO6
int ** generarMatrizCerrada(int n,int m);//EJERCICIO7

int main()
{
    srand(time(NULL));
    int opcion,n,m,num;
       string opc;
       do
       {
       cout<<"Opciones:"<<endl;
       cout<<"1-EJERCICIO 1"<<"||";
       cout<<"2-EJERCICIO 2"<<"||";
       cout<<"3-EJERCICIO 3"<<"||";
       cout<<"4-EJERCICIO 4"<<"||";
       cout<<"5-EJERCICIO 5"<<"||";
       cout<<"6-EJERCICIO 6"<<"||";
       cout<<"7-EJERCICIO 7"<<endl;
       cout<<"Ingrese una opcion:";
       cin>>opcion;
       cout<<endl<<endl;

       if(opcion>0&&opcion<8)
       {

       switch (opcion)
       {
       case 1:{
           cout<<"REALICE UNA FUNCION QUE RETORNE UNA MATRIZ DE NUMEROS ENTEROS(ALEATORIOS)"<<endl;
           cout<<"DE N FILAS Y M COLUMNAS, SIENDO N Y M PARAMETROS"<<endl;
           cout<<"Ingrese cantidad n:";
           cin>>n;
           cout<<"Ingrese cantidad m:";
           cin>>m;
           int ** matriz1=NrosAleatorios(n,m);
           cout<<endl;
           for(int i=0;i<n;i++){
               for(int j=0;j<m;j++)
                   cout << matriz1[i][j] << " ";
               cout<<endl;
           }
           cout<<endl;
           vaciarMatriz(matriz1,n);
           break;
       }//fin ejercicio 1
       case 2:{
           cout<<"REALICE UNA FUNCION QUE SUME TODOS LOS ELEMENTOS DE 2 MATRICES DE N FILAS Y M COLUMNAS,"<<endl;
           cout<<"SIENDO N Y M PARAMETROS"<<endl;
                                       cout<<"Ingrese cantidad n:";
                                       cin>>n;
                                       cout<<"Ingrese cantidad m:";
                                       cin>>m;
                                       int ** matriz2=NrosAleatorios(n,m);
                                       int ** matriz02=NrosAleatorios(n,m);
                                       int ** matrizresultado=SumaMatriz(matriz2,matriz02,n,m);

                                       cout<<endl<<"MATRIZ 1 GENERADA ALEATORIAMENTE DE "<<n<<" x "<<m<<":"<<endl;

                                       //MUESTRO MATRIZ 1 ALEATORIA DE NXM
                                       for(int i=0;i<n;i++){
                                           for(int j=0;j<m;j++)
                                           {
                                               cout << matriz2[i][j] << " ";
                                           }
                                           cout<<endl;
                                       }
                                       cout<<endl;
                                       cout<<"MATRIZ 2 GENERADA ALEATORIAMENTE DE "<<n<<" x "<<m<<":"<<endl;

                                       //MUESTRO MATRIZ 2 ALEATORIA DE NXM
                                       for(int i=0;i<n;i++){
                                           for(int j=0;j<m;j++)
                                           {
                                               cout << matriz02[i][j] << " ";
                                           }
                                           cout<<endl;

                                       }
                                       cout<<endl;
                                       cout<<"LA SUMA DE LAS DOS MATRICES GENERADAS ALEATORIAMENTE DE N:"<<n<<" X M:"<<m<<" MOSTRADAS ANTERIORMENTE ES:"<<endl;

                                       //Muestro Matriz Resultado
                                       for(int i=0;i<n;i++){
                                           for(int j=0;j<m;j++)
                                           {
                                               cout << matrizresultado[i][j] << " ";
                                           }
                                           cout<<endl;
                                       }
                                       cout<<endl;

                                       vaciarMatriz(matriz2,n);
                                       vaciarMatriz(matriz02,n);
                                       vaciarMatriz(matrizresultado,n);

           break;
       }//fin ejercicio 2

       case 3:{

           cout<<"REALICE UNA FUNCION QUE LLENE UNA MATRIZ DE N FILAS Y M COLUMNAS"<<endl;
           cout<<"CON UN NUMERO PASADO POR PARAMETRO"<<endl;
           cout<<"Ingrese cantidad n:";
           cin>>n;
           cout<<"Ingrese cantidad m:";
           cin>>m;
           cout<<"Ingrese el numero con el que se llenara la matriz: ";
           cin>>num;

           int ** matriz3= NroPorParametro(n,m, num);
           //MUESTRO MATRIZ DE NXM llena con numero num
               cout<<endl;
               for(int i=0;i<n;i++){
                   for(int j=0;j<m;j++)
                   {
                       cout << matriz3[i][j] << " ";
                   }
                   cout<<endl;
               }
               cout<<endl;

               vaciarMatriz(matriz3,n);
           break;
       }//fin ejercicio 3

       case 4:{
           cout<<"REALICE UNA FUNCION QUE ROTE UNA MATRIZ DE N FILAS Y M COLUMNAS"<<endl;
           cout<<"SIENDO N Y M PARAMETROS"<<endl;;
           cout<<"Ingrese cantidad n:";
           cin>>n;
           cout<<"Ingrese cantidad m:";
           cin>>m;
           int ** matriz4= NrosAleatorios(n,m);
           int ** matrizrotada=RotarMatriz(matriz4,n,m);
           //MUESTRO MATRIZ 4 ALEATORIA DE NXM
           cout<<endl<<"MATRIZ GENERADA ALEATORIAMENTE DE "<<n<<" x "<<m<<":"<<endl;
           for(int i=0;i<n;i++){
               for(int j=0;j<m;j++)
               {
                   cout << matriz4[i][j] << " ";
               }
               cout<<endl;
           }

           cout<<endl;

           //MUESTRO MATRIZ ROTADA
           int aux = 0;
           //esto es por si al rotar la matriz me quedo una matriz con dimensiones rotadas
           //ejemplo: genero matriz 4x3 me deberia generar una matriz 3x4 y estas matrices
           //se muestran de distinta manera,para eso sirve este if,para decirle a los ciclos for
           //como deben mostrar la matriz
                      if (m != n){
                          aux = n;

                          n = m;
                          m = aux;
                      }
           cout<<"MATRIZ ROTADA"<<endl;
           for(int i=0;i<n;i++){
               for(int j=0;j<m;j++)
               {
                   cout << matrizrotada[i][j] << " ";
               }
               cout<<endl;
           }
           vaciarMatriz(matriz4,n);
           vaciarMatriz(matrizrotada,n);
           cout<<endl;
           break;
       }//fin ejercicio 4

       case 5:{

           cout<<"REALICE UNA FUNCION QUE LLENE UNA MATRIZ De N POR M (SIENDO N Y M PARAMETROS)"<<endl;
           cout<<"CON 2 NUMEROS, DE FORMA ALEATORIA. LOS 2 NUMEROS PUEDE DEFINIRLO UD."<<endl;;
           cout<<"Ingrese cantidad n:";
           cin>>n;
           cout<<"Ingrese cantidad m:";
           cin>>m;
           int ** matriz5=CargaAleatoria(n,m);
           cout<<endl;
           for(int i=0;i<n;i++){
               for(int j=0;j<m;j++)
                   cout << matriz5[i][j] << " ";
               cout<<endl;
           }
           cout<<endl;
           vaciarMatriz(matriz5,n);
           break;
       }//fin ejercicio 5

       case 6:{
           cout<<"REALICE UNA FUNCION QUE DADA UNA MATRIZ DE N POR M(SIENDO N Y M PARAMETROS)"<<endl;
           cout<<"LLENA DE 2 NUMEROS, VALIDE QUE LA MATRIZ NO TENGA AREAS CERRADAS."<<endl;
           cout<<"Se considera que una matriz de dos numeros tiene un area cerrada"<<endl;
           cout<<"cuando a partir de un numero ( ubicacion ij ),"<<endl;
           cout<<"no puedo acceder al espacio de numeros que le corresponde,"<<endl;
           cout<<"avanzando hacia cualquiera de los 4 costados."<<endl;
           cout<<"Es decir, a traves de un casillero n ij ,"<<endl;
           cout<<"que esta completo por un numero i, debo poder moverme a otro casillero que"<<endl;
           cout<<"tambien tenga ese mismo numero i"<<endl<<endl;
           cout<<"Ingrese cantidad n:";
           cin>>n;
           cout<<"Ingrese cantidad m:";
           cin>>m;
           if(n>2&&m>2)
           {
           cout<<endl;
           int ** matriz6 = CargaAleatoria(n,m);
               //aca se muestra la matriz
               for(int i=0;i<n;i++){
                   for(int j=0;j<m;j++)
                       cout << matriz6[i][j] << " ";
                   cout<<endl;
               }
               //en esta parte se verifica si la matriz es cerrada
               if(validar(matriz6,n,m))
                   cout << "\n\tLA MATRIZ NO ESTA CERRADA" <<endl;
               else
                   cout << "\n\tLA MATRIZ ESTA CERRADA" <<endl;

               cout << endl;
               vaciarMatriz(matriz6,n);
           }
           else
           {
               cout<<"LA DIMENSION DE LA MATRIZ DEBE SER MAYOR A 3X3"<<endl<<endl;
           }
           break;
       }//fin ejercicio 6

       case 7:{
           cout<<"REALICE UNA FUNCION QUE DADA UNA MATRIZ DE N POR M(SIENDO N Y M PARAMETROS)"<<endl;
           cout<<"LLENA DE 2 NUMEROS Y LA MATRIZ NO DEBE TENER AREAS CERRADAS."<<endl;
           cout<<"Ingrese cantidad n:";
           cin>>n;
           cout<<"Ingrese cantidad m:";
           cin>>m;
           if(n>2&&m>2)
           {

           int ** matriz7 = generarMatrizCerrada(n,m);
           //Muestro matriz cerrada
           cout<<endl;
               for(int i=0;i<n;i++){
                   for(int j=0;j<m;j++)
                       cout << matriz7[i][j] << " ";
                   cout << endl;
               }
               vaciarMatriz(matriz7,n);
           }
           else
           {
               cout<<"LA DIMENSION DE LA MATRIZ DEBE SER MAYOR A 3X3"<<endl<<endl;
           }
           cout<<endl;
           break;
        }

       }//finswitch
       }//fin if
       else {
           cout<<"LA OPCION INGRESADA NO PERTENECE A UN EJERCICIO"<<endl<<endl;
       }




       cout<<"DESEA EJECUTAR OTRO EJERCICIO? Y/N:";
       cin>>opc;
       cout<<endl<<endl;
       }while (opc=="Y"||opc=="y");//findowhile
}
//FUNCION QUE GENERA MATRIZ
int ** generarMatriz(int n,int m){
    //se reserva memoria para las filas
    int ** matriz = new int*[n];
    //se reserva memoria para las columnas
    for(int i=0;i<n;i++)
        matriz[i] = new int[m];
    //se devuelve la matriz creada


    return matriz;
}

//funcion vaciar matriz
void vaciarMatriz(int ** matriz,int n){
    for(int i = 0;i < n;i++)
            delete []matriz[i];

    delete []matriz;
}

//funcion ejercicio 1
int ** NrosAleatorios(int n,int m){
    //se crea la matriz
    int ** matriz = generarMatriz(n,m);
    //se carga la matriz con numeros aleatorios
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            matriz[i][j]=rand()%99+1;
        }
    //finalmente se devuelve la matriz
    return matriz;
}

//funcion ejercicio 2
int ** SumaMatriz (int ** Matriz1,int ** Matriz2,int n,int m)
{
    //GENERO MATRIZ AUXILIAR
    int ** matriz = generarMatriz(n,m);

    //SE SUMAN LAS DOS MATRICES Y CARGO MATRIZ AUXILIAR
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            matriz[i][j]=Matriz1[i][j]+Matriz2[i][j];
        }
    }
    //FINALMENTE SE DEVUELVE MATRIZ AUXILIAR
    return matriz;
}

//funcion ejercicio 3
int ** NroPorParametro(int n,int m, int x){
    int ** matriz = generarMatriz(n,m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
         matriz[i][j] = x;
        }
    }

    return matriz;

}

//funcion ejercicio 4
int ** RotarMatriz(int ** Matriz4,int n,int m){
    int ** matriz;
    int i,j;
    if(n == m){
        matriz = generarMatriz(n,m);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
             matriz[j][i] = Matriz4[i][j];
    }
    if (n != m){
        matriz = generarMatriz(m,n);
        for(i= 0;i<m;i++)
            for(j=0;j<n;j++)
                matriz [i][j] = Matriz4[j][i];
    }

    return matriz;
}
//funcion ejercicio 6
int ** CargaAleatoria(int n,int m){
   int ** matriz = generarMatriz(n,m);
   //se carga la matriz con numeros
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

//funcion ejercicio 6
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
//funcion ejercicio 7
int ** generarMatrizCerrada(int n,int m){
    //
    int valor = rand() % 3;
    int nro;

    int ** matriz = generarMatriz(n,m);
    if(valor % 2 == 0)
        nro = 1;
    else
        nro = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j==0)
                matriz[i][j] = nro;
            else{
                if(matriz[i][j-1] == 0)
                    matriz[i][j] = 1;
                else
                   matriz[i][j] = 0;
            }
        }
        if(nro == 1)
            nro = 0;
        else
            nro = 1;
    }

    return matriz;
}
