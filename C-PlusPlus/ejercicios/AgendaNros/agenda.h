#ifndef AGENDA_H
#define AGENDA_H
#include <map>

class Agenda
{
private:
    std::map<std::string,long> personas;
public:
    Agenda();
    void setPersona(std::string nombreCompleto,long telefono);
    long getPersona(std::string nombreP);
};

#endif // AGENDA_H
