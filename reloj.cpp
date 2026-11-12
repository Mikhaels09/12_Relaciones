#include <iostream>
using namespace std;

class Hora {
private:
    int hora;
    int minutos;
    int segundos;

public:
    Hora(int h, int m, int s) {
        hora = h;
        minutos = m;
        segundos = s;
    }
    int getHora() {
        return hora;
    }
    int getMinutos() {
        return minutos;
    }
    int getSegundos() {
        return segundos;
    }
};

class Display {
private:
    string tipo;

public:
    Display() {
        tipo = "digital";
    }
    Display(string t) {
        tipo = t;
    }
    string getTipo() {
        return tipo;
    }
};

class Reloj {
private:
    Display *pDisplay;
    Hora *pHora;

public:
    Reloj(int h, int m, int s) {
        pHora = new Hora(h, m, s);
        pDisplay = 0;
    }

    ~Reloj() {
        delete pHora;
    }

    void asignarDisplay(Display *pD) {
        pDisplay = pD;
    }

    void mostrarReloj() {
        if (pDisplay == 0) {
            cout << "El reloj no tiene display asignado" << endl;
            return;
        }

        string tipoDisplay = pDisplay->getTipo();

        if (tipoDisplay == "digital") {
            cout << "[";
            cout << pHora->getHora();
            cout << ":";
            cout << pHora->getMinutos();
            cout << ":";
            cout << pHora->getSegundos();
            cout << "]" << endl;
        }
        else if (tipoDisplay == "analogico") {
            cout << "-->";
            cout << pHora->getHora();
            cout << ":";
            cout << pHora->getMinutos();
            cout << ":";
            cout << pHora->getSegundos();
            cout << "<--" << endl;
        }
    }
};

int main() {
    Display display1("digital");
    Display display2("analogico");

    Reloj reloj1(10, 15, 55);
    reloj1.asignarDisplay(&display1);

    Reloj reloj2(10, 15, 55);
    reloj2.asignarDisplay(&display2);

    reloj1.mostrarReloj();
    reloj2.mostrarReloj();

    return 0;
}
