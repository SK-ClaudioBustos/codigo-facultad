#include "mainwindow.h"
#include <QApplication>

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


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    w.show();
    return a.exec();
}
