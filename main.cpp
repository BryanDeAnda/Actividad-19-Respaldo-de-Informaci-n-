#include <iostream>
#include "videogame.h"
#include "menualdeano.h"
#include "civilizacion.h"

using namespace std;

int main(){
    Videogame v;
    string op;

    while(true)
    {
        cout << "------------MENU CIVILIZACIONES--------------" << endl;
        cout << "1) Nombre de usuario" << endl;
        cout << "2) Agregar civilización" << endl;
        cout << "3) Insertar civilización" << endl;
        cout << "4) Crear civilizaciones" << endl;
        cout << "5) Primera civilización" << endl;
        cout << "6) Ultima civilización" << endl;
        cout << "7) Ordenar" << endl;
        cout << "8) Eliminar civilización" << endl;
        cout << "9) Buscar civilización por nombre" << endl;
        cout << "10) Modificar" << endl;
        cout << "11) Resumen" << endl;
        cout << "12) Buscar civilizaciones" << endl;
        cout << "13) Respaldar civilizaciones con sus aldeanos" << endl;
        cout << "14) Recuperar civilizaciones con sus aldeanos" << endl;
        cout << "15) Salir" << endl;
        getline(cin, op);

        if(op == "1"){
            string usuario;
            cout << "Ingresa el nombre del usuario: " << endl;
            getline(cin, usuario); 
            v.setUsuario(usuario);
            cout << endl;
        }
        if(op == "2"){
            Civilizacion c;
            cin >> c;
            v.agregarCivilizacion(c);
            cin.ignore();
            cout << endl;
        }
        else if (op == "3")     
        {
            Civilizacion c;
            cin >> c;
            size_t pos;
            cout << "posición: ";
            cin >> pos; cin.ignore();

            if(pos >= v.size()){
                cout << "Posición no válida" << endl;
            }
            else{
                v.insertar(c, pos);
            }
        }

        else if (op == "4")     
        {
            Civilizacion c;
            cin >> c;
            size_t n;
            cout << "n: ";
            cin >> n; cin.ignore();

            v.crear(c, n);
        }

        else if (op == "5")     
        {
            if(v.size() == 0){
                cout << "Vector vacio" << endl;
            }
            else{
                v.primera();
            }
            cout << endl;
        }

        else if (op == "6")     
        {
            if(v.size() == 0){
                cout << "Vector vacio" << endl;
            }
            else{
                v.ultimo();
            }
            cout << endl;
        }

        else if (op == "7")     
        {
            string opc;
            cout <<"1) Ordenar por nombre" << endl;
            cout << "2) Ordenar por ubicacion en X" << endl;
            cout << "3) Ordenar por ubicacion en Y" << endl;
            cout << "4) Ordenar por puntuacion" << endl; 
            getline(cin, opc);

            if(opc == "1"){
                v.ordenarNombre();
            }
            else if(opc == "2"){
                v.ordenarX();
            }
            else if(opc == "3"){
                v.ordenarY();
            }
            else if(opc == "4"){
                v.ordenarPun();
            }
            else{
                cout << "Ordenamiento inexistente" << endl;
            }
            cout << endl;
        }

        else if (op == "8")     
        {
            string c;
            cout << "Ingrese el nombre de la civilización que desea eliminar: " << endl;
            getline(cin, c);
            
            Civilizacion *ptr = v.eliminar(c);
            if(ptr == nullptr){
                cout << "No encontrado" << endl;
            }
            else{
                *ptr;
            }
            cout << endl;

        }

        else if (op == "9")     
        {
            string c;
            cout << "Ingrese el nombre de la civilización que desea buscar: " << endl;
            getline(cin, c);

            Civilizacion *ptr = v.buscar(c);

            if(ptr == nullptr){
                cout << "No encontrado" << endl;
            }
            else{
                cout << *ptr << endl;
            }
            cout << endl;
        }

        else if (op == "10")     
        {
            string opc;
            string temp;
            int aux;
            float pun;
            string c;
            cout << "Ingrese la civilización que desea modificar: " << endl;
            getline(cin, c);

            Civilizacion *ptr = v.buscar(c);

            if(ptr == nullptr){
                cout << "No encontrado" << endl;
            }
            else{
                cout << *ptr << endl;
                cout << "¿Qué desea modificar?" << endl;
                cout << "1) Nombre de la civilización: " << endl;
                cout << "2) Ubicacion en X de la civilización: " << endl;
                cout << "3) Ubicacion en Y de la civilización: " << endl;
                cout << "4) Puntuación de la civilización: " << endl;
                getline(cin, opc);

                if(opc == "1"){
                    cout << "Nuevo nombre de la civilización: " << endl;
                    getline(cin, temp);
                    ptr->setNombre(temp);
                }
                else if(opc == "2"){
                    cout << "Nueva ubicación en X de la civilización: " << endl;
                    cin >> aux; cin.ignore();
                    ptr->setUbix(aux);
                }
                else if(opc == "3"){
                    cout << "Nueva ubicación en Y de la civilización: " << endl;
                    cin >> aux; cin.ignore();
                    ptr->setUbiy(aux);
                }
                else if(opc == "4"){
                    cout << "Nueva puntuación de la civilización: " << endl;
                    cin >> pun; cin.ignore();
                    ptr->setPuntuacion(pun);
                }
                else{
                    cout << "opción invalida" << endl;
                }
                cout << endl;
            }
        }

        else if (op == "11")     
        {
            cout << "Usuario: " << v.getUsuario() << endl;
            v.total();
            cout << endl;
        }

        else if(op == "12")
        {
            Civilizacion c;
            cout << "Ingresa la civilización que desea buscar: " << endl;
            cin >> c; cin.ignore();

            Civilizacion *ptr = v.buscarCivil(c);

            if(ptr == nullptr){
                cout << "No encontrado" << endl;
            }
            else{
                cout << *ptr << endl;
                menu(*ptr);
            }
            cout << endl;
        }
        else if(op == "13"){
            Civilizacion c1;
            v.respaldar(c1);
        }
        else if(op == "14"){
            v.recuperar();
        }
        
        else if(op == "15"){
            break;
        }
        
    }

}