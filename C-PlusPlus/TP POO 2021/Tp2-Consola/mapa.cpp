#include "mapa.h"

Mapa::Mapa()
{

}

Mapa::Mapa(int n, int m, int cantP)
{
    this->n = n;
    this->m = m;
    this->cantPastizales = cantP;
}

//se reserva el espacio requerido para el mapa
void Mapa::generarMatriz(){
    this->mapa = new int*[this->n];
    for(int i=0;i<this->n;i++){
        this->mapa[i] = new int[this->m];
        for(int j = 0;j<this->m;j++){
            this->mapa[i][j] = 0;
        }
    }
}

//se establece donde estaran las mesetas y las montañas externas(se generan en el limite del mapa)
// los ceros son montañas
// los unos son mesetas
void Mapa::cargarMontaniasMesetas(){
    for(int i=0;i<this->n;i++)
        for(int j=0;j<this->m;j++){
            if(!i or !j or i == this->n-1 or j == this->m-1)
                this->mapa[i][j] = 0;
            else
                this->mapa[i][j] = 1;
        }
}

//esta funcion se encarga de generar montañas internas(montañas que no estan en los limites del mapa),
//el bucle while verifica si las coordenadas random son una meseta,ya que se colocaran montañas donde
//hay mesetas osea sobre 1s,el bucle no se detendra hasta obtener una posicion valida
void Mapa::generarMontaniasInternas(){
    srand(time(NULL));
    float porcentajeUnos = (((this->n * this->m) - (2*this->n + 2*this->m - 3)) * 0.2) -10;
    int fila = 0;
    int columna = 0;
    for(int j=0;j<porcentajeUnos;j++){
        bool flag = true;
        while (flag){
           fila= rand()%this->n;
           columna = rand()%this->m;
           if (fila == 0)
               fila++;
           if(columna == 0)
               columna++;
           if(this->mapa[fila][columna] == 1){
              this->mapa[fila][columna] = 0;
              flag = false;
           }
       }
    }
}

//esta funcion se encarga de tapar las mesetas que se encuentran cerradas
void Mapa::validarAreasCerradas()
{
    for(int i = 1;i < this->n-1; i++)
        for(int j = 1; j < this->m-1; j++){
            if(this->mapa[i][j] == 1){
                if(this->mapa[i-1][j] != this->mapa[i][j] &&
                   this->mapa[i+1][j] != this->mapa[i][j] &&
                   this->mapa[i][j+1] != this->mapa[i][j] &&
                   this->mapa[i][j-1] != this->mapa[i][j])
                {
                    this->mapa[i][j] = 0;
                }
                if(this->mapa[i-1][j] != this->mapa[i][j] &&
                   this->mapa[i+1][j] != this->mapa[i][j] &&
                   this->mapa[i][j+1] != this->mapa[i][j])
                {
                    this->mapa[i][j] = 0;
                }
                if(this->mapa[i-1][j] != this->mapa[i][j] &&
                   this->mapa[i+1][j] != this->mapa[i][j] &&
                   this->mapa[i][j-1] != this->mapa[i][j])
                {
                    this->mapa[i][j] = 0;
                }
                if(this->mapa[i+1][j] != this->mapa[i][j] &&
                   this->mapa[i][j-1] != this->mapa[i][j] &&
                   this->mapa[i][j+1] != this->mapa[i][j])
                {
                    this->mapa[i][j] = 0;
                }
                if(this->mapa[i-1][j] != this->mapa[i][j] &&
                   this->mapa[i][j-1] != this->mapa[i][j] &&
                   this->mapa[i][j+1] != this->mapa[i][j])
                {
                    this->mapa[i][j] = 0;
                }
            }
        }
}

//se agrega el pastizal creado en el arreglo de pastizales
void Mapa::setPastizal(Pastizal nuevo)
{
        this->pastizales.push_back(nuevo);
}

//esta funcion genera los pastizales,los mismos se identifican con el nro 2
//bool flag se encarga de verificar si la posicion obtenido es valida,osea es igual a 1
//luego se genera la posicion random del pastizal
//si en la posicion generada hay un 1 entonces se crea el pastizal
//sino el bucle seguira hasta que se obtenga una posicion valida para el pastizal
void Mapa::generarPastizales()
{
    int fila;
    int columna;
    for(int j=0;j<this->cantPastizales;j++){
        bool flag = true;
        while (flag){
           fila= rand()%this->n;
           columna = rand()%this->m;
           if (fila == 0)
               fila++;
           if(columna == 0)
               columna++;
           if(this->mapa[fila][columna] == 1){
              this->mapa[fila][columna] = 2;
              Pastizal nuevo;
              nuevo.setPosicion(fila,columna);
              this->setPastizal(nuevo);
              flag = false;
           }
       }
    }
}

//esta funcion recupera todo el mapa recuperado del archivo
void Mapa::recuperarTrazadoMapa()
{
    int aux = 0;
    ifstream file("TrazadoMapa.dat",ios::binary | ios::in);
    for(int i = 0;i < this->n; i++){
        for(int j = 0;j < this->m;j++){
            file.read((char*)&aux,sizeof(int));
            this->mapa[i][j] = aux;
        }
    }
    file.close();
}

//esta funcion se llama cada vez que pasa un dia, sirve para controlar la existencia de los
//pastizales, si su vida es mayor a 0 se le resta,si es == 0 se le pregunta si ya crecio,si lo hizo se lo muestra
//en el mapa, sino se aumenta el contador de crecimiento del pastizal y se lo oculta en el mapa, para verificar
//fue comido se utiliza una bandera que indica si fue comido o si se seco en el caso que se seque se
//le resta la vida una vez mas estableciendola en -1 y luego se lo borra del mapa
void Mapa::revisarPastizales()
{
    if (this->cantPastizales == 0)
        return;
    for(int i = 0;i <this->cantPastizales;i++){
        if(this->pastizales[i].getVida() == 0){
            if(this->pastizales[i].getEstadoComido()){
                if(this->pastizales[i].crecer()){
                    if(this->mapa[this->pastizales[i].getF()][this->pastizales[i].getC()] == 1){
                       this->mapa[this->pastizales[i].getF()][this->pastizales[i].getC()] = 2;
                    }
                }
            }
            else{
                if(this->mapa[this->pastizales[i].getF()][this->pastizales[i].getC()] == 2){
                    this->pastizales[i].restarVida();
                    this->mapa[this->pastizales[i].getF()][this->pastizales[i].getC()] = 1;
                }
            }
        }
        if(this->pastizales[i].getVida() > 0)
            this->pastizales[i].restarVida();
    }
}

//esta funcion hace que el pastizal comido sea informado para que crezca y luego cambia su ubicacion para
//que desaparezca hasta crecer completamente
void Mapa::pastizalComido(int fila, int columna)
{
    for(int i = 0;i<this->cantPastizales;i++){
        if(this->pastizales[i].getC() == columna && this->pastizales[i].getF() == fila){
            this->pastizales[i].pastizalComido();
            this->mapa[fila][columna] = 1;
        }
    }
}

//este funcion tiene el objetivo de llamar a todas las funciones relacionadas con la creacion
//del mapa, osea la matriz
void Mapa::llamarFuncionesMapa()
{
        //se reserva espacio para el mapa
        this->generarMatriz();

        //se generan las montañas(0s) en el limite del mapa y en el interior las mesetas(1s)
        this->cargarMontaniasMesetas();

        //tambien se generan montañas internas en el mapa
        this->generarMontaniasInternas();

        //esta funcion se encarga de matar a toda meseta que este encerrada(la convierte en montaña)
        this->validarAreasCerradas();

        //si hay pastizales recuperados de un archivo,se los ubicara en el mapa,sino generara nuevos
        this->generarPastizales();
}

//esta funcion guarda la configuracion del mapa,se encarga de
//llamar a la funcion guardarPastizales y ademas guarda el trazado del mapa
void Mapa::guardarConfiguracionMapa()
{
    ofstream file("DatosMapa.dat",ios::binary | ios::out | ios::trunc);
    dataMapa aux;
    int cantActualPastizales = this->guardarPastizales();
    aux.cantPastizales = cantActualPastizales;
    aux.m = this->m;
    aux.n = this->n;
    file.write((char*)&aux,sizeof(dataMapa));
    file.close();
    ofstream fileMapa("TrazadoMapa.dat",ios::binary | ios::out | ios::trunc);
    int datoGuardar = 0;
    for(int i = 0;i < this->n; i++){
        for(int j = 0;j < this->m;j++){
            datoGuardar = this->mapa[i][j];
            fileMapa.write((char*)&datoGuardar,sizeof(int));
        }
    }
    fileMapa.close();
}

//aqui se guarda la informacion de los pastizales vivos hasta el momento actual
//la simulacion, ademas devuelve el numero de pastizales vivos
int Mapa::guardarPastizales()
{
    ofstream file("DatosPastizales.dat",ios::binary & ios::out & ios::trunc);
    dataPastizal aux; int contadorPastizalesVivos = 0;
    for(auto i = this->pastizales.begin();i < this->pastizales.end();++i){
        if(i->getVida()>=0){
            aux.columna = i->getC();
            aux.fila = i->getF();
            aux.vida = i->getVida();
            aux.comido = i->getEstadoComido();
            aux.contador = i->getContador();
            contadorPastizalesVivos++;
            file.write((char*)&aux,sizeof (dataPastizal));
        }
    }
    file.close();
    return contadorPastizalesVivos;
}

//esta funcion se encarga de recuperar toda la informacion guardada en el archivo
//binario, la bandera "pastizalesRecuperados" se utilizara en la funcion "llamarFuncionesMapa"
void Mapa::recuperarSimulacionGuardada()
{
    ifstream file("DatosMapa.dat",ios::binary & ios::in);
    dataMapa informacionMapaRecuperada;
    file.read((char*)&informacionMapaRecuperada,sizeof(dataMapa));
    this->cantPastizales = informacionMapaRecuperada.cantPastizales;
    this->m = informacionMapaRecuperada.m;
    this->n = informacionMapaRecuperada.n;
    file.close();

    ifstream file2("DatosPastizales.dat",ios::binary & ios::in);
    dataPastizal aux;
    Pastizal pastizalRecuperado;
    for(int i =0;i < this->cantPastizales;++i){
        file2.read((char*)&aux,sizeof(dataPastizal));
        pastizalRecuperado.setPosicion(aux.fila,aux.columna);
        pastizalRecuperado.setVida(aux.vida);
        pastizalRecuperado.setContador(aux.contador);
        pastizalRecuperado.setEstado(aux.comido);
        this->pastizales.push_back(pastizalRecuperado);
    }
    this->pastizalesRecuperados = true;
    file2.close();
}

