/*#include <iostream>
#include <string>
#include <random>

using namespace std;
string generarCadenaAleatoria(int longitud) {
    string cadena;
    cadena.reserve(longitud); // Reservar espacio para evitar realocaciones frecuentes

    // caracteres permitidos
    const std::string caracteresPermitidos = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // generador de números aleatorios
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribucion(0, caracteresPermitidos.size() - 1);


    for (int i = 0; i < longitud; ++i) {
        cadena += caracteresPermitidos[distribucion(gen)];
    }

    return cadena;
}*/