#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    int velocidadMax;

public:
    Vehiculo(string marca, string modelo, int velocidadMax)
        : marca(marca), modelo(modelo), velocidadMax(velocidadMax) {}

    virtual void mostrarInfo() const {
        cout << marca << " " << modelo << " - " << velocidadMax << " km/h" << endl;
    }

    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
private:
    int numPuertas;

public:
    Auto(string marca, string modelo, int velocidadMax, int numPuertas)
        : Vehiculo(marca, modelo, velocidadMax), numPuertas(numPuertas) {}

    void mostrarInfo() const override {
        cout << "Auto: " << marca << " " << modelo << " - " << velocidadMax
             << " km/h - " << numPuertas << " puertas" << endl;
    }
};

class Motocicleta : public Vehiculo {
private:
    int cilindrada;

public:
    Motocicleta(string marca, string modelo, int velocidadMax, int cilindrada)
        : Vehiculo(marca, modelo, velocidadMax), cilindrada(cilindrada) {}

    void mostrarInfo() const override {
        cout << "Motocicleta: " << marca << " " << modelo << " - " << velocidadMax
             << " km/h - " << cilindrada << " cc" << endl;
    }
};

int main() {
    vector<Vehiculo*> vehiculos;
    vehiculos.push_back(new Auto("Toyota", "Corolla", 180, 4));
    vehiculos.push_back(new Motocicleta("Yamaha", "R6", 260, 600));
    vehiculos.push_back(new Auto("Ford", "Mustang", 250, 2));
    vehiculos.push_back(new Motocicleta("Honda", "CBR500R", 190, 500));
    vehiculos.push_back(new Auto("Nissan", "Versa", 170, 4));

    vector<Vehiculo*>::iterator it;
    for (it = vehiculos.begin(); it != vehiculos.end(); ++it) {
        (*it)->mostrarInfo();
    }

    for (it = vehiculos.begin(); it != vehiculos.end(); ++it) {
        delete *it;
    }

    return 0;
}
