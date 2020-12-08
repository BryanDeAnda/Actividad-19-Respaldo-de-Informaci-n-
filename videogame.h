#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

class Videogame
{

    vector<Civilizacion> civilizaciones;
    string usuario;

public:
    void setUsuario(const string &v);
    string getUsuario();
    Videogame();
    void agregarCivilizacion(const Civilizacion &p);
    void insertar(const Civilizacion &c, size_t pos);
    size_t size();
    void crear(const Civilizacion &c, size_t n);
    void primera();
    void ultimo();
    void ordenarNombre();
    void ordenarX();
    void ordenarY();
    void ordenarPun();
    Civilizacion* eliminar(const string &c);
    Civilizacion* buscar(const string &c);
    Civilizacion* buscarCivil(const Civilizacion &c);
    void total();
    void respaldar(Civilizacion &c1);
    void recuperar();

    friend Videogame& operator<<(Videogame &l, const Civilizacion &p)
    {
        l.agregarCivilizacion(p);

        return l;
    }


};

#endif