#include "aldeano.h"

void Aldeano::setNombrealdeano(const string &nombrealdeano)
{
    this->nombrealdeano = nombrealdeano;
}
string Aldeano::getNombrealdeano() const
{
    return nombrealdeano;
}

void Aldeano::setEdad(int edad)
{
    this->edad = edad;
}
int Aldeano::getEdad() const
{
    return edad;
}

void Aldeano::setGenero(const string &genero)
{
    this->genero = genero;
}
string Aldeano::getGenero()
{
    return genero;
}

void Aldeano::setSalud(int salud)
{
    this->salud = salud;
}

int Aldeano::getSalud() const
{
    return salud;
}