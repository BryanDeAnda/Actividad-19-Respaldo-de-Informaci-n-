#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Aldeano
{
private:
    string nombrealdeano;
    int edad;
    string genero;
    int salud;

public:
    Aldeano() {}
    Aldeano(const string &nombrealdeano, int edad, const string &genero, int salud):
    nombrealdeano(nombrealdeano), edad(edad), genero(genero), salud(salud){}

    void setNombrealdeano(const string &nombrealdeano);
    string getNombrealdeano() const; 

    void setEdad(int edad);
    int getEdad() const;

    void setGenero(const string &genero);
    string getGenero();

    void setSalud(int salud);
    int getSalud() const;

    friend ostream& operator<<(ostream &out, const Aldeano &a)
    {
        out << left;
        out << setw(12) << a.nombrealdeano;
        out << setw(10) << a.edad;
        out << setw(12) << a.genero;
        out << setw(8) << a.salud;
        out <<endl;

        return out;
    } 

    bool operator<(const Aldeano &a) const
    {
        return nombrealdeano < a.getNombrealdeano();
    }

    bool operator==(const string& a)
    {

        return nombrealdeano == a;
    }

    bool operator==(const string& a) const
    {

        return nombrealdeano == a;
    }


};

#endif