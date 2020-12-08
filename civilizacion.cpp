#include "civilizacion.h"

Civilizacion::Civilizacion()
{
    
}

Civilizacion::Civilizacion(const string &nombre, int ubix, int ubiy, float puntuacion)
{
    this->nombre = nombre;
    this->ubix = ubix;
    this->ubiy = ubiy;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &v)
{
    nombre = v;
}
string Civilizacion::getNombre()
{
    return nombre;
}

void Civilizacion::setUbix(float v)
{
    ubix = v;
}
float Civilizacion::getUbix()
{
    return ubix;
}

void Civilizacion::setUbiy(float v)
{
    ubiy = v;
}
float Civilizacion::getUbiy()
{
    return ubiy;
}

void Civilizacion::setPuntuacion(int v)
{
    puntuacion = v;
}

int Civilizacion::getPuntuacion()
{
    return puntuacion;
}

void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}

void Civilizacion::mostrarAldeano()
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        cout << *it;
    }
}

void Civilizacion::eliminarNombre(const string &nombre)
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        if(nombre == a.getNombrealdeano()){
            aldeanos.erase(it);
            break;
        }
    }
}

bool comparador(const Aldeano &a)
{
    return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if(comparador);
}

void Civilizacion::eliminarSalud(int salud)
{
    aldeanos.remove_if([salud](const Aldeano &a){return a.getSalud() < salud;});
}

void Civilizacion::clasificarNombre()
{
    aldeanos.sort();
}

bool comparadorEdad(const Aldeano &a1, const Aldeano &a2)
{
    return a1.getEdad() > a2.getEdad();
}

void Civilizacion::clasificarEdad()
{
    aldeanos.sort(comparadorEdad);
}

void Civilizacion::clasificarSalud()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

Aldeano* Civilizacion::buscar(const string &a)
{
    auto it = find(aldeanos.begin(), aldeanos.end(), a);

    if(it == aldeanos.end()){
        return nullptr;
    }
    else{
        cout << endl;
        cout << left;
        cout << setw(12) << "Nombre";
        cout << setw(10) << "Edad";
        cout << setw(12) << "Genero";
        cout << setw(8) << "Salud";
        cout <<endl;
        return &(*it);
    }
}

void Civilizacion::respaldarAldeanos()
{
    ofstream alde(getNombre() + ".txt", ios::out);

    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++) {
        Aldeano &aldeano = *it; 
        alde << aldeano.getNombrealdeano() << endl;
        alde << aldeano.getEdad()   << endl;
        alde << aldeano.getGenero() << endl;
        alde << aldeano.getSalud()  << endl;
    }
    alde.close();
}

void Civilizacion::recuperarAldeanos()
{
    ifstream archivo(getNombre() + ".txt");
    if(archivo.is_open()){
        string temp;
        int salud;
        int edad;
        Aldeano* a = nullptr;

        while (!archivo.eof())
        {
            a = new Aldeano();
            getline(archivo, temp); 
            a->setNombrealdeano(temp);

            getline(archivo, temp);
            a->setEdad(atoi(temp.c_str()));

            getline(archivo, temp); 
            a->setGenero(temp);

            getline(archivo, temp);
            a->setSalud(atoi(temp.c_str()));

            agregarFinal(*a);
        }
        aldeanos.pop_back();
        archivo.close(); 
    }
    
}