#include "simulador.h"

Simulador::Simulador()
{

}

void Simulador::setConfiguracion(Mapa *m, int ca, int cb, int dt)
{
    this->unMapa = m;
    this->cantPoblacionA = ca;
    this->cantPoblacionB = cb;
    this->cantTotalPoblaciones = this->cantPoblacionA + this->cantPoblacionB;
    this->duracionTiempo = dt;
}

//esta funcion se llama cuando se desea mostrar el mapa
int ** Simulador::getMatriz()
{
    return this->unMapa->getMatriz();
}

int Simulador::getN()
{
    return this->unMapa->getN();
}

int Simulador::getM()
{
    return this->unMapa->getM();
}

//se reserva espacio para todas las poblaciones
void Simulador::crearPoblaciones()
{

    if(this->cantPoblacionA > 0 && this->cantPoblacionB == 0){
        for(int i = 0;i<this->cantPoblacionA;i++)
           this->poblacionesCiervos.push_back(new Poblacion_A());}

    if(this->cantPoblacionB > 0 && this->cantPoblacionA == 0){
        for(int i = 0;i < this->cantPoblacionB;i++)
                this->poblacionesCiervos.push_back(new Poblacion_B());}

    if(this->cantPoblacionA > 0 && this->cantPoblacionB > 0){
        for(int i = 0;i<this->cantTotalPoblaciones;i++){
           if(i < this->cantPoblacionA){
               this->poblacionesCiervos.push_back(new Poblacion_A());
           }
           else{
               this->poblacionesCiervos.push_back(new Poblacion_B());
           }
        }
    }
}

//esta funcion se llama cada vez que se genera una poblacion nueva luego de que dos poblaciones tipo A
//se encuentran
void Simulador::setPoblacionNueva(Poblacion *nuevaDeTipoA)
{
    this->poblacionesCiervos.push_back(nuevaDeTipoA);
    this->cantPoblacionA++;
    this->cantTotalPoblaciones++;
}

//se establece las posiciones iniciales de todas las poblaciones verificando que se encuentren sobre una
//meseta
void Simulador::setPosicionInicialPoblaciones()
{
    int fila = 0;
    int columna = 0;
    int ** aux = this->unMapa->getMatriz();
    for(int i = 0; i< this->cantTotalPoblaciones;i++){
        bool flag = true;
        while (flag){
           fila= rand()%this->unMapa->getN();
           columna = rand()%this->unMapa->getM();
           if (fila == 0)
               fila++;
           if(columna == 0)
               columna++;
           if(aux[fila][columna] == 1){
               this->poblacionesCiervos[i]->setPosicionActual(fila,columna);
               if(this->poblacionesCiervos[i]->getTipo() == 'A')
                   aux[fila][columna] = 3;
               else
                   aux[fila][columna] = 4;
               flag = false;
           }
        }
    }
}

void Simulador::inicializacionPoblaciones()
{
    if(this->recuperarSimulacion)
        this->recuperarPoblaciones();
    else{
    this->crearPoblaciones();
    this->setPosicionInicialPoblaciones();}
}

//esta funcion se encarga de manejar los movimientos de todas las poblaciones en el mapa
//primero se verifica cual direccion se encuentra disponible para avanzar
//ya se derecha,izquierda,arriba o abajo,una vez que se encuentra una posicion valida
//se establece la posicion anterior de la poblacion igual a 1(meseta),
//se cambia la posicion actual de la poblacion en el objeto, y finalmente
//se cambia la posicion actual de la poblacion(en el objeto)
void Simulador::movimientoDePoblaciones()
{   int fila = 0;
    int columna = 0; int nroRand;
    int ** aux = this->unMapa->getMatriz();
    for(int i = 0; i< this->cantTotalPoblaciones;i++)
    {
        if(this->poblacionesCiervos[i]->getV() > 0){
            fila = this->poblacionesCiervos[i]->getF();
            columna = this->poblacionesCiervos[i]->getC();
            nroRand = rand()%4;

            if (nroRand == 0){
                if(aux[fila][columna-1] == 1)
                    columna--;
                else{
                    if(aux[fila-1][columna] == 1)
                        fila--;
                    else{
                        if(aux[fila][columna+1] == 1)
                            columna++;
                        else{
                            if(aux[fila+1][columna] == 1)
                                fila++;
                        }
                    }
                    }
            }
            if(nroRand == 1){
                if(aux[fila+1][columna] == 1)
                    fila++;
                else{
                    if(aux[fila][columna+1] == 1)
                        columna++;
                    else{
                        if(aux[fila-1][columna] == 1)
                            fila--;
                        else{
                            if(aux[fila][columna-1] == 1){
                                columna--;}
                        }
                    }
                }
            }
            if(nroRand == 2){
                if(aux[fila][columna+1] == 1)
                    columna++;
                else{
                    if(aux[fila-1][columna] == 1)
                        fila--;
                    else{
                        if(aux[fila+1][columna] == 1)
                            fila++;
                        else{
                            if(aux[fila][columna-1] == 1){
                                columna--;}
                        }

                    }

                }

            }
            if(nroRand == 3){
                if(aux[fila-1][columna] == 1)
                    fila--;
                else{
                    if(aux[fila+1][columna] == 1)
                        fila++;
                    else{
                        if(aux[fila][columna-1] == 1)
                            columna--;
                        else{
                            if(aux[fila][columna+1] == 1)
                                columna++;
                        }
                    }
                }
            }

            aux[this->poblacionesCiervos[i]->getF()][this->poblacionesCiervos[i]->getC()] = 1;
            this->poblacionesCiervos[i]->setPosicionActual(fila,columna);
            if(this->poblacionesCiervos[i]->getTipo() == 'A')
                aux[fila][columna] = 3;
            else
                aux[fila][columna] = 4;
        }
    }
}

//esta funcion primero verifica si la poblacion esta vivo o muerta, si esta muerta se la borra del mapa,
//caso contrario,se verifica si esta cerca de un pastizal ya sea derecha,izquierda,arriba o abajo,
//sino se encuentra un pastizal en las cercanias de la poblacion,disminuye la vida de la poblacion
//caso contrario se reinicia la vida de la poblacion  y se notifica al mapa que le comieron un pastizal
void Simulador::controlDePoblacion()
{
    int fila = 0;
    int columna = 0;
    int ** aux = this->unMapa->getMatriz();
    for(int i = 0;i < this->cantTotalPoblaciones;i++){
        if(this->poblacionesCiervos[i]->getV() > 0){
            fila = this->poblacionesCiervos[i]->getF();
            columna = this->poblacionesCiervos[i]->getC();
            if(aux[fila][columna+1] == 2){
                columna++;}
            else{
                if(aux[fila+1][columna] == 2)
                    fila++;
                else{
                    if(aux[fila][columna-1] == 2)
                        columna--;
                    else{
                        if(aux[fila-1][columna] == 2)
                            fila--;}
                }
            }
            if(fila == this->poblacionesCiervos[i]->getF() && columna == this->poblacionesCiervos[i]->getC()){
                this->poblacionesCiervos[i]->restarVida();
            }else{
                this->poblacionesCiervos[i]->setVida(3);
                this->unMapa->pastizalComido(fila,columna);
            }
        }
        else{
            if(!this->poblacionesCiervos[i]->getEstado()){
                this->poblacionesCiervos[i]->setVida(0);
                this->unMapa->getMatriz()[this->poblacionesCiervos[i]->getF()][this->poblacionesCiervos[i]->getC()] = 1;}
        }

    }
}

//esta funcion llama a la funcion del mapa que controla la vida de los pastizales
void Simulador::controlarPastizales()
{
    this->unMapa->revisarPastizales();
}


//cada vez que se desea revisar si una poblacion esta cerca de otra se llama a esta funcion,
//lo que se debe tener en cuenta ademas de la posicion de ambas poblaciones es tambien el tipo,ya que:
//-poblacion A :
//    +si se encuentra con otra población de tipo A,se cruzan y generan una nueva población,
//     es decir, el resultado del encuentro son 3 poblaciones
//    +si se encuentra con otra población de tipo B,no hay conflictos y cada población sigue su camino.
//-poblacion B:
//    +si se encuentra con población B,se unen formando una sola población.
//la funcion evalua si se dentro del rango de la poblacion se encunentra otra poblacion del mismo tipo,entonces
//lo que hace es verificar si los valores de fila y columna cambian,si por lo menos se modifica una de las
//variables significa que hay otra del mismo tipo cerca,luego se busca la poblacion en el vector de punteros
//para asi obtener su tipo y controlar que se acciones se realizaran a cabo
void Simulador::controlarRelacionesPoblacion()
{   int fila = 0;
    int columna = 0;
    char poblacion1;
    int ** aux = this->unMapa->getMatriz();
    for(int i = 0;i < this->cantTotalPoblaciones;i++){
        if(this->poblacionesCiervos[i]->getV() > 0){
            fila = this->poblacionesCiervos[i]->getF();
            columna = this->poblacionesCiervos[i]->getC();
            poblacion1 = this->poblacionesCiervos[i]->getTipo();
            if(poblacion1 == 'A'){
                if(aux[fila][columna+1] == 3)
                   columna++;
                else
                    if(aux[fila+1][columna] == 3)
                       fila++;
                    else
                       if(aux[fila][columna-1] == 3)
                           columna--;
                        else
                           if(aux[fila-1][columna] == 3)
                               fila--;
            }
            else{
                if(aux[fila][columna+1] == 4)
                   columna++;
                else
                    if(aux[fila+1][columna] == 4)
                       fila++;
                    else
                       if(aux[fila][columna-1] == 4)
                           columna--;
                        else
                           if(aux[fila-1][columna] == 4)
                               fila--;
            }
            if(fila != this->poblacionesCiervos[i]->getF() || columna != this->poblacionesCiervos[i]->getC()){
                char poblacion2;
                for(int j = 0;j < this->cantTotalPoblaciones;j++){
                    if(this->poblacionesCiervos[j]->getF() == fila && this->poblacionesCiervos[j]->getC() == columna){
                        poblacion2 = this->poblacionesCiervos[j]->getTipo();
                        if(poblacion1 == 'A' && poblacion2 == 'A'){
                                Poblacion_A * nuevo = new Poblacion_A();
                                int filaPadre = this->poblacionesCiervos[i]->getF();
                                int columnaPadre = this->poblacionesCiervos[i]->getC();
                                if(aux[filaPadre-1][columnaPadre+1] == 1){
                                    filaPadre--;
                                    columnaPadre++;}
                                else{
                                    if(aux[filaPadre-1][columnaPadre-1] == 1){
                                        filaPadre--;
                                        columnaPadre--;}
                                    else{
                                        if(aux[filaPadre+1][columnaPadre-1] == 1){
                                            columnaPadre--;
                                            filaPadre++;}
                                        else{
                                            if(aux[filaPadre+1][columnaPadre+1] == 1){
                                                columnaPadre++;
                                                filaPadre++;}
                                        }
                                    }

                                }
                                nuevo->setPosicionActual(filaPadre,columnaPadre);
                                aux[filaPadre][columnaPadre] = 3;
                                this->setPoblacionNueva(nuevo);
                        }
                        if(poblacion1 == 'B' && poblacion2 == 'B'){
                                this->unMapa->getMatriz()[this->poblacionesCiervos[j]->getF()][this->poblacionesCiervos[j]->getC()] = 1;
                                this->poblacionesCiervos[i]->setVida(3);
                                this->poblacionesCiervos[j]->setVida(0);
                                this->poblacionesCiervos[j]->restarVida();
                        }
                     }
                        break;
                    }
                }
            }

    }
}

//se encarga de verificar si existe un archivo de configuracion guardado anteriormente
bool Simulador::verificarExistenciaArchivoConfig()
{
    ifstream file("config.txt");
    if(file.is_open())
    {
        file.close();
        return true;
    }
    return false;
}

bool Simulador::verificarExistenciaSimulacionGuardada()
{
    ifstream file("DatosSimulador.dat",ios::binary);
    if(file.is_open())
    {
        file.close();
        return true;
    }
    return false;
}

// el formato en el que se guarda la informacion tiene este orden:
// cantidad de filas
// cantidad de columnas
// cantidad de pastizales
// duracion del dia
// cantidad de poblacion A
// cantidad de poblacion B
//esta funcion guarda la ultima configuracion ingresada por el usuario
void Simulador::guardarConfiguracionIngresada()
{
    ofstream file("config.txt",ios::trunc);
    if(file.is_open())
    {
        file << to_string(this->unMapa->getN()) << "\n";
        file << to_string(this->unMapa->getM()) << "\n";
        file << to_string(this->unMapa->getCantidadPastizales()) << "\n";
        file << to_string(this->duracionTiempo) << "\n";
        file << to_string(this->cantPoblacionA) << "\n";
        file << to_string(this->cantPoblacionB) << "\n";
    }
    file.close();
}

//se recupera la ultima configuracion ingresada
std::vector<int> Simulador::recuperarConfiguracionIngresada()
{
    ifstream file("config.txt");
    vector<int>aux;
    int index = 0;
    string line;
    if(file.is_open())
    {
        while(getline(file,line)){
            aux.push_back(stoi(line));
            index++;
        }
    }
    file.close();
    return aux;
}

//esta funcion recupera toda la informacion almacenada sobre la simulacion guardada
void Simulador::recuperarSimulacionGuardada()
{
    this->recuperarSimulacion = true;
    Mapa * mapaRecuperado = new Mapa;
    mapaRecuperado->recuperarSimulacionGuardada();
    mapaRecuperado->generarMatriz();
    mapaRecuperado->recuperarTrazadoMapa();
    ifstream file("DatosSimulador.dat",ios::binary & ios::in);
    dataSimulador aux;
    file.read((char*)&aux,sizeof (dataSimulador));
    this->cantPoblacionA = aux.cantPobA;
    this->cantPoblacionB = aux.cantPobB;
    this->cantTotalPoblaciones = aux.cantPobA + aux.cantPobB;
    this->duracionTiempo = aux.duracionTiempo;
    this->unMapa = mapaRecuperado;
    file.close();
}

void Simulador::recuperarPoblaciones()
{
    ifstream file("DatosPoblaciones.dat",ios::binary & ios::in);
    dataPoblacion aux;

    Poblacion * ptr = NULL;
    for(int i = 0; i < this->cantTotalPoblaciones;i++){
        file.read((char*)&aux,sizeof (dataPoblacion));
        if(aux.tipo == 'A'){
            ptr = new Poblacion_A;
        }
        else{
            ptr = new Poblacion_B;
        }
        ptr->setPosicionActual(aux.fila,aux.columna);
        ptr->setVida(aux.vida);
        this->poblacionesCiervos.push_back(ptr);
    }
    file.close();
}

int Simulador::recuperarDiaActual()
{
    ifstream file("DatosSimulador.dat",ios::binary & ios::in);
    dataSimulador aux; int diaRecuperado;
    file.read((char*)&aux,sizeof (dataSimulador));
    diaRecuperado = aux.diaActual;
    file.close();
    return diaRecuperado;
}

//esta funcion se encarga de llamar a los metodos correspondientes para guardar
//toda la informacion actual de la simulacion
void Simulador::guardarSimulacion(int diaActual)
{
    this->guardarDatosPoblaciones(diaActual);
    this->guardarPoblaciones();
    this->unMapa->guardarConfiguracionMapa();
}

//se encarga de guardar los datos del simulador
void Simulador::guardarDatosPoblaciones(int dia)
{
    int cPa = 0; int cPb = 0;
    for(int i = 0;i < (int)this->poblacionesCiervos.size();++i){
        if(this->poblacionesCiervos[i]->getV()>0){
            if(this->poblacionesCiervos[i]->getTipo() == 'A')
                cPa++;
            else
                cPb++;
        }
    }
    ofstream file("DatosSimulador.dat",ios::binary & ios::out & ios::trunc);
    dataSimulador aux;
    aux.duracionTiempo = this->duracionTiempo;
    aux.cantPobA = cPa;
    aux.cantPobB = cPb;
    aux.diaActual = dia;
    if(file.is_open()){
           file.write((char*)&aux,sizeof(dataSimulador));
    }
    file.close();
}

//guarda la informacion de cada poblacion
void Simulador::guardarPoblaciones()
{
    ofstream file("DatosPoblaciones.dat",ios::binary | ios::out | ios::trunc);
    dataPoblacion aux;
    for(int i = 0;i < (int)this->poblacionesCiervos.size();++i){
        if(this->poblacionesCiervos[i]->getV() >= 0){
            aux.fila = this->poblacionesCiervos[i]->getF();
            aux.columna = this->poblacionesCiervos[i]->getC();
            aux.vida = this->poblacionesCiervos[i]->getV();
            aux.tipo = this->poblacionesCiervos[i]->getTipo();
            file.write((char*)&aux,sizeof(dataPoblacion));
        }
    }
    file.close();
}

