#include "curso.h"
#include <string.h>
Curso::Curso(char * nombre, int id)
{
    this->nombre = nombre;
    this->id = id;
}

void Curso::setAlumno(Alumno * nuevo)
{
    if(this->alumnos.size()<=30)
        this->alumnos.push_back(nuevo);
}

void Curso::imprimirCondiciones()
{
    cout<<"MOSTRANDO CONDICIONES ALUMNOS\n";
    for(int i = 0; i < (int)this->alumnos.size();++i){
        if(this->alumnos[i]->verificarCondicion())
            cout<<"El alumno "<<this->alumnos[i]->getNombre()<<" aprobo la materia "<<this->nombre<<"\n";
        else
            cout<<"El alumno "<<this->alumnos[i]->getNombre()<<" no aprobo la materia "<<this->nombre<<"\n";
    }
}

void Curso::imprimirMail()
{
    cout<<"\nMOSTRANDO MAILS DE LA FACULTAD\n";
    char * mail = "@uader.edu.ar";
    for(int i = 0; i < (int)this->alumnos.size();++i){
        cout<< "MAIL: " << this->alumnos[i]->getNombre()<<mail<<endl;
    }
}
