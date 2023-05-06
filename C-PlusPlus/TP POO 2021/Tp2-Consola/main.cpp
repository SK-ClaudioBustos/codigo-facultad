#include <iostream>
#include "mapa.h"
#include "simulador.h"
#include "poblacion.h"
#include <windows.h>
#include <time.h>
using namespace std;

/*
-----------------------------------------ACLARACION-----------------------------------------
este programa posee las siguientes caracteristicas:
+ cuando se ejecuta el programa, primero se debe ingresar la configuracion
+ el tamaño del mapa debe ser mayor o igual a 10x10,si es menor se pondra el valor por default
+ la simulacion se puede detener una vez que haya pasado el tiempo ingresado
+ si existe una archivo de configuracion existente se le preguntara al usario si desea cargarlo
+ si existe una simulacion guardada se le preguntara al usuario si desea cargarla,
  en el caso que acepte y ademas el usuario haya aceptado cargar la ultima configuaracion guardada,
  esta ultima no se aplicara
+ el simulador realiza las siguientes acciones:
+ la simulacion empieza desde el dia cero, osea el dia en el que se muestra las posiciones iniciales
  de las poblaciones
  1 - muestra el mapa en el dia correspondiente
  2 - movimiento de poblaciones
  3 - controla la vida de las poblaciones y se verifica si tienen un pastizal cerca
  4 - controlar la vida y crecimiento de los pastizales
  5 - manejar relaciones entre poblaciones
+ las montañas internas(montañas que estan dentro del limite del mapa) se generan si el mapa es lo suficientemente grande
+ una vez que los pastizales se secan se mueren para siempre
+ se debe esperar la cantidad de segundos ingresados cada vez que pase un dia
+ luego que pasen los segundos se debe apretar ENTER(esto tendra un aviso)
+ se considera que una poblacion se encuentra con otra poblacion cuando esta una al lado de otra,osea a su izquierda,derecha,arriba o abajo
+ se considera que una poblacion encuentra un pastizal cuando lo tiene al lado suyo
+ el mapa se representa con numeros, siendo 0=montañas,1=mesetas,2=pastizales,3=poblaciones de ciervos de tipo A,4=poblaciones de ciervos de tipo B
+ la ultima configuracion ingresada siempre se guarda al final del programa
+ si el usuario desea salir de la simulacion se le preguntara si quiere guardar la simulacion

FUNCIONAMIENTO DE ARCHIVOS:
    se crea un archivo txt con la ultima configuracion ingresada si es que no existe dicho archivo(ESTO NO SE PREGUNTA)
    , cuando se finaliza una simulacion se le pregunta al usuario si quiere guardar la simulacion, si
    presiona que SI se guardara la configuracion del simulador, la informacion de las poblaciones vivas
    , la informacion del mapa y la informacion de los pastizales que aun no se secaron
*/


//esta funcion muestra la matriz,reemplazando los numeros por simbolos mas "amigables"
void mostrarMapa(int filas,int columnas,int ** array){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(array[i][j] == 4)
                cout << "B ";//poblacion de ciervos de tipo B
            if(array[i][j] == 3)
                cout << "A ";//poblacion de ciervos de tipo A
            if(array[i][j] == 2)
                cout << "p ";//pastizales
            if(array[i][j] == 0)
                cout << "+ ";//montañas
            if(array[i][j] == 1)
                cout << "  ";//mesetas
        }
        cout << endl;
    }
}

//esta funcion simula la duracion de un dia
char contadorSegundos(int segundos){
    char rpta;
    int timer = 1;
    cout << endl << "Segundos... 0";
    while(true){
        Sleep(1000);
        if(timer > segundos)
            break;
        cout << " " << timer;
        timer++;
    }
    cout << endl <<"Desea seguir la simulacion(Y/N)?:  ";
    cin >> rpta;
    cin.ignore(1,'\n');
    return rpta;
}

//si la dimension ingresada para el mapa es < 10 se settea el valor por defecto que es 30
int controlarTamanioMapa(){
    int dimension;
    cin >> dimension;
    if(dimension < 10)
        return 30;
    return dimension;
}

int main()
{   //DECLARACION VARIABLES
    srand(time(NULL));
    int diaActual = 0; bool flag = false;
    int filas,columnas,cantPastizales,duracionTiempo,cantPoblacionA,cantPoblacionB;
    char rpta = 'N';    Mapa * mapa;
    char rptaUsuario; int ** aux;

    //CARGA DE DATOS
    cout <<"\tBIENVENIDO AL SIMULADOR DE POBLACION DE CIERVOS COLORADOS\n\n";
    cout << "Configuracion de paramatros\n\n";
    cout << "+Ingrese la cantidad de filas del mapa(un valor < 10 se tomara como 30): ";
    filas = controlarTamanioMapa();
    cout << "+Ingrese la cantidad de columnas del mapa(un valor < 10 se tomara como 30): ";
    columnas = controlarTamanioMapa();
    cout << "+Ingrese cantidad de pastizales: ";
    cin >> cantPastizales;
    cout << "+Ingrese duracion del dia(segundos): ";
    cin >> duracionTiempo;
    cout << "+Ingrese cantidad de ciervos de la poblacion A: ";
    cin >> cantPoblacionA;
    cout << "+Ingrese cantidad de ciervos de la poblacion B: ";
    cin >> cantPoblacionB;
    cin.ignore(1,'\n');

    //CREACION OBJETOS
    Simulador unSimulador;
    if(unSimulador.verificarExistenciaArchivoConfig()){
        cout << "Desea cargar la ultima configuracion ingresada?(Y/N): ";
        cin >> rpta;
        if(rpta == 'Y' || rpta == 'y'){
            vector<int>config = unSimulador.recuperarConfiguracionIngresada();
            filas= config[0];
            columnas = config[1];
            cantPastizales= config[2];
            duracionTiempo = config[3];
            cantPoblacionA = config[4];
            cantPoblacionB = config[5];
        }
    }
    if(unSimulador.verificarExistenciaSimulacionGuardada()){
         cout << "Desea cargar la simulacion guardada?(Y/N): ";
         cin >> rpta;
         if(rpta == 'Y' || rpta == 'y'){
            flag = true;
         }
    }
    if(flag){
        unSimulador.recuperarSimulacionGuardada();
        diaActual = unSimulador.recuperarDiaActual();
        filas = unSimulador.getN();
        columnas = unSimulador.getM();
    }
    else{
        mapa = new Mapa(filas,columnas,cantPastizales);
        unSimulador.setConfiguracion(mapa,cantPoblacionA,cantPoblacionB,duracionTiempo);
        mapa->llamarFuncionesMapa();
    }

    unSimulador.inicializacionPoblaciones();
    aux = unSimulador.getMatriz();
    duracionTiempo = unSimulador.getDuracionTiempo();
    //---------------------
    while(true){
        cout << endl << "\tDIA " << diaActual <<"\n\n";
        mostrarMapa(filas,columnas,aux);
        rptaUsuario = contadorSegundos(duracionTiempo);
        if(rptaUsuario == 'n' || rptaUsuario == 'N'){
            cout << "Desea guardar la simulacion(Y/N)?: ";
            cin >> rpta;
            if(rpta == 'Y' || rpta == 'y'){
               unSimulador.guardarSimulacion(diaActual);
            }
            break;
        }
        diaActual++;
        unSimulador.movimientoDePoblaciones();
        unSimulador.controlDePoblacion();
        unSimulador.controlarPastizales();
        unSimulador.controlarRelacionesPoblacion();
    }
    unSimulador.guardarConfiguracionIngresada();
  return 0;
}
