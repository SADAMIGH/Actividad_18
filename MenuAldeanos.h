#include "civilizacion.h"

Aldeano capturar()
{
    Aldeano a;
    string nombre;
    size_t edad;
    string genero;
    size_t salud;

    cout << "Nombre: ";
    getline(cin, nombre);
    a.setNombre(nombre);

    cout << "Edad: ";
    cin >> edad;
    cin.ignore();
    a.setEdad(edad);
    
    cout << "Genero: ";
    getline(cin, genero);
    a.setGenero(genero);

    cout << "Salud: ";
    cin >> salud;
    cin.ignore();
    a.setSalud(salud);

    return a;
}

void menu(Civilizacion &a)
{
    string op = "00";
    while (op != "7")
    {
        cout << "Aldeanos..." << endl;
        cout << "1) Agregar" << endl;
        cout << "2) Eliminar" << endl;
        cout << "3) Clasificar" << endl;
        cout << "4) Buscar" << endl;
        cout << "5) Modificar" << endl;
        cout << "6) Mostrar" << endl;
        cout << "7) salir" << endl;
        getline(cin, op);

        if (op == "1") {
            cout << "1) Agregar al inicio" << endl;
            cout << "2) Agregar al final" << endl;
            cout << "Opcion: " << endl;
            getline(cin,op);
            if (op == "1") {
            a.agregarInicio(capturar());
            int p = 100;
            p = a.getPuntuacion() + 100;
            a.setPuntuacion(p);
            }
            else if (op == "2") {
            a.agregarFinal(capturar());
            int p = 100;
            p = a.getPuntuacion() + 100;
            a.setPuntuacion(p);
            }
        } 
        else if (op == "2") {
        cout << "1) Eliminar por Nombre" << endl;
        cout << "2) Eliminar por Salud menor a X" << endl;
        cout << "3) Eliminar por Edad mayor o igual a 60" << endl;
        cout << "Opcion: " << endl;
            getline(cin,op);
            if (op == "1") {
            string nombre;
            cout << "Nombre: " ;
            getline(cin,nombre);
            a.eliminarPorNombre(nombre);
            }
            else if (op == "2") {
            int salud;
            cout << "Salud: " ;
            cin >> salud;
            cin.ignore();
            a.eliminarPorSaludX(salud);
            }
            else if (op == "3") {
            a.eliminarPorEdad60();
            }
        }
        else if (op == "3") {
        cout << "1) Ordenar por Nombre (Ascendente)" << endl;
        cout << "2) Ordenar por Edad (Descendente)" << endl;
        cout << "3) Ordenar por Salud (Descendente)" << endl;
        cout << "Opcion: " << endl;
        getline(cin,op);
        if (op == "1") {
        a.ordenarNombre();
        }
        if (op == "2") {
        a.ordenarEdad();
        }
        if (op == "3") {
        a.ordenarSalud();
        }
        }
        else if (op == "4") {
        Aldeano o;
        cin >> o; cin.ignore();
        Aldeano *ptr = a.buscar(o);
        if (ptr == nullptr) {
            cout << "Aldeano no encontrado" << endl;
        }
        else {
        cout << "Aldeano encontrado" << endl;
        cout << *ptr << endl;
        }
        }
        else if (op == "5") {
        Aldeano o;
        cin >> o; cin.ignore();
        Aldeano *ptr = a.buscar(o);
        if (ptr == nullptr) {
            cout << "Aldeano no encontrado" << endl;
        }
        else {
        cout << "Aldeano encontrado" << endl;
        cout << *ptr << endl;

            int e = 0;
            do{
            cout << "Modificar..." << endl;
            cout << "1) Nombre" << endl;
            cout << "2) Edad" << endl;
            cout << "3) Genero" << endl;
            cout << "4) Salud" << endl;
            cout << "5) Salir" << endl;
            cout << "Opcion: ";
            cin >> e;
            cin.ignore();
            cout << endl << endl;
            if(e == 1 ){ 
            string nombre;
            cout << "Ingresa el nuevo Nombre: " ;
            getline(cin, nombre);
            ptr->setNombre(nombre); 
            cout << "Resultado:" << endl;
            cout << *ptr << endl;
            }
            else if(e == 2 ){
            int edad;
            cout << "Ingresa la nueva Edad: " ;
            cin>>edad;
            cin.ignore();
            ptr->setEdad(edad);
            cout << "Resultado:" << endl;
            cout << *ptr << endl;
            }
            else if(e == 3 ){
            string genero;
            cout << "Ingresa el nuevo Genero: " ;
            getline(cin,genero);
            ptr->setGenero(genero);
            cout << "Resultado:" << endl;
            cout << *ptr << endl; 
            }
            else if(e == 4 ){
            int salud;
            cout << "Ingresa la nueva Salud: " ;
            cin>>salud;
            cin.ignore();
            ptr->setSalud(salud);
            cout << "Resultado:" << endl;
            cout << *ptr << endl;
                    }
                }while(e != 5);
            }
        }
        else if (op == "6") {
        a.print();
        }
        
     }
    
 }