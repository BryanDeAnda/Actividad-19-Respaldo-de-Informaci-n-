
#include "civilizacion.h"
#include "videogame.h"

Aldeano capturar()
{
    Aldeano a;
    string nombre;
    int edad;
    string genero;
    float salud;

    cout << "Nombre del aldeano: ";
    getline(cin, nombre);
    a.setNombrealdeano(nombre);

    cout << "Edad del aldeano: ";
    cin >> edad; cin.ignore();
    a.setEdad(edad);

    cout << "Genero del aldeano: ";
    getline(cin, genero);
    a.setGenero(genero);

    cout << "Salud del aldeano: ";
    cin >> salud; cin.ignore();
    a.setSalud(salud);


    return a;
}

void menu(Civilizacion &c)
{
    string opc;

    while(true)
    {
        cout << endl;
        cout << "------------MENU ALDEANOS--------------" << endl << endl;
        cout << "1) Agregar aldeano" << endl;
        cout << "2) Eliminar aldeano" << endl;
        cout << "3) Clasificar aldeanos" << endl;
        cout << "4) Buscar aldeano" << endl;
        cout << "5) Modificar aldeano" << endl;
        cout << "6) Mostrar aldeanos" << endl;
        cout << "0) Salir" << endl;
        getline(cin, opc);

        if(opc == "1"){
            string op;
            int puntaje;
            cout << "1) Agregar aldeano al inicio" << endl;
            cout << "2) Agregar aldeano al final" << endl;
            getline(cin, op);

            if(op == "1"){
                c.agregarInicio(capturar());
                puntaje = c.getPuntuacion();
                c.setPuntuacion(puntaje+100);

            }else if(op == "2"){
                c.agregarFinal(capturar());
                puntaje = c.getPuntuacion();
                c.setPuntuacion(puntaje+100);

            }else{
                cout << "Opción no valida" << endl;
            }
            cout << endl;

        }else if(opc == "2"){
            string op;
            cout << "1) Eliminar por nombre" << endl;
            cout << "2) Eliminar aldeanos donde su salud sea menor a x" << endl;
            cout << "3) Eliminar aldeanos donde su edad sea mayor o igual a 60" << endl;
            getline(cin, op);

            if(op == "1"){
                string nombre;

                cout << "Nombre del aldeano: ";
                getline(cin, nombre);

                c.eliminarNombre(nombre);

            }else if(op == "2"){
                float salud;
                cout << "Limite de salud: ";
                cin >> salud; cin.ignore();

                c.eliminarSalud(salud);

            }else if(op == "3"){
                c.eliminarEdad();
            }else{
                cout << "opcion no valida" << endl;
            }

        }else if(opc == "3"){
            string op;
            cout << "1) Clasificar aldeanos por nombre (ascendente)" << endl;
            cout << "2) Clasificar aldeanos por edad (descendente)" << endl;
            cout << "3) Clasificar aldeanos por salud (desentente)" << endl;
            getline(cin, op);

            if(op == "1"){
                c.clasificarNombre();

            }else if(op == "2"){
                c.clasificarEdad();

            }else if(op == "3"){
                c.clasificarSalud();
            }else{
                cout << "opcion no valida" << endl;
            }
        }else if(opc == "4"){
            string a;
            cout << "Ingrese el nombre del aldeano que desea buscar: " << endl;
            getline(cin, a);

            Aldeano *ptr = c.buscar(a);

            if(ptr == nullptr){
                cout << "No encontrado" << endl;
            }
            else{
                cout << *ptr << endl;
            }

        }else if(opc == "5"){
            string opc;
            string nombre;
            size_t edad;
            string genero;
            int salud;
            string a;
            cout << "Ingrese el nombre del aldeano que desea modificar: " << endl;
            getline(cin, a);

            Aldeano *ptr = c.buscar(a);

            if(ptr == nullptr){
                cout << "No encontrado" << endl;
            }
            else{
                cout << *ptr << endl;
                cout << "¿Qué desea modificar?" << endl;
                cout << "1) Nombre del aldeano: " << endl;
                cout << "2) Edad del aldeano: " << endl;
                cout << "3) Genero del aldeano: " << endl;
                cout << "4) Salud del aldeano: " << endl;
                getline(cin, opc);
                if(opc == "1"){
                    cout << "Nuevo nombre del aldeano: " << endl;
                    getline(cin, nombre);
                    ptr->setNombrealdeano(nombre);
                }
                else if(opc == "2"){
                    cout << "Nueva Edad del aldeano: " << endl;
                    cin >> edad; cin.ignore();
                    ptr->setEdad(edad);
                }
                else if(opc == "3"){
                    cout << "Nuevo genero del aldeano: " << endl;
                    cin >> genero; cin.ignore();
                    ptr->setGenero(genero);
                }
                else if(opc == "4"){
                    cout << "Nueva salud del aldeano: " << endl;
                    cin >> salud; cin.ignore();
                    ptr->setSalud(salud);
                }
                else{
                    cout << "opción no valida" << endl;
                }
                cout << endl;
            }
        }else if(opc == "6"){
            
            cout << endl << endl;
            cout << left;
            cout << setw(12) << "Nombre";
            cout << setw(10) << "Edad";
            cout << setw(12) << "Genero";
            cout << setw(8) << "Salud";
            cout <<endl;
            c.mostrarAldeano();
            cout << endl;

        }else if(opc == "0"){
            break;
        }
    }
}
