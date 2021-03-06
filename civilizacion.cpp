#include "civilizacion.h"

Civilizacion::Civilizacion()
{

}

Civilizacion::Civilizacion(
                           const string &nombre,
                           float x,
                           float y,
                           int puntuacion)
{
    this->nombre = nombre;
    this->x = x;
    this->y = y;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &c)
{
    nombre = c;
}

string Civilizacion::getNombre()
{
    return nombre;
}

void Civilizacion::setX(float c)
{
    x = c;
}

float Civilizacion::getX()
{
    return x;
}

void Civilizacion::setY(float c)
{
    y = c;
}

float Civilizacion::getY()
{
    return y;
}

void Civilizacion::setPuntuacion(int c)
{
    puntuacion = c;
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

void Civilizacion::print()
{
    cout << left;
    cout << setw(15) << "Aldeano";
    cout << setw(5) << "Edad";
    cout << setw(10) << "Genero";
    cout << setw(5) << "Salud";
    cout << endl;
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++) {
        cout << *it << endl;
    }
}

void Civilizacion::eliminarPorNombre(const string &nombre)
{
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++) {
        Aldeano &a = *it;

        if (nombre == a.getNombre()) {
            aldeanos.erase(it);
            break;
        }
    }
}

void Civilizacion::eliminarPorSaludX(size_t salud)
{
    aldeanos.remove_if([salud](const Aldeano &a){ return a.getSalud() <= salud;});
}

bool comparador60(const Aldeano &a) 
{
    return 60 <= a.getEdad();
}

void Civilizacion::eliminarPorEdad60()
{
    aldeanos.remove_if(comparador60);
}

void Civilizacion::ordenarNombre()
{
    aldeanos.sort();
}

bool comparadorEdad(const Aldeano &a1, const Aldeano &a2)
{
    return a1.getEdad() > a2.getEdad();
}

void Civilizacion::ordenarEdad()
{
    aldeanos.sort(comparadorEdad);
}

bool comparadorSalud(const Aldeano &a1, const Aldeano &a2)
{
    return a1.getSalud() > a2.getSalud();
}

void Civilizacion::ordenarSalud()
{
    aldeanos.sort(comparadorSalud);
}

Aldeano* Civilizacion::buscar(const Aldeano &a)
{
    auto it = find(aldeanos.begin(), aldeanos.end(), a);

    if (it == aldeanos.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}