#include "secuenciabustos.h"
#include <stdlib.h>
#include <time.h>
SecuenciaBustos::SecuenciaBustos()
{

}

void SecuenciaBustos::generar(){
    srand(time(NULL));
    int aux = (rand() % 50) * 2;
    for(int i = 0; i<4; i++) {
        this->sec[i] = pow(aux,i * 69);
    }
}
