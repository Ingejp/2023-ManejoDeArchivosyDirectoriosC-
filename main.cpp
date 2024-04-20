#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "windows.h"

using namespace std;
void crearArchivos(int cantidad);
void agregarTexto();
int contarArchivosDeDirectorio();
int contarArchivosDeDirectorio2();
void mostrarDetalles();
void mostrarDetalles2();
string generarCadenaAleatoria(int cantidad);
void renombrar();

int main() {
    int opc;
    cout << "Bienvenido al Programa de Manejo de Archivos" << endl;
    do {
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Elija una opcion a realizar" << endl;
        cout << "[1] Crear Archivos" << endl;
        cout << "[2] Mostrar el peso de los archivos" << endl;
        cout << "[3] Renombrar" << endl;
        cout << "[0] Salir" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                cout << "Opcion seleccionada -> Crear Archivos" << endl;
                int cantidad;
                cout << "Ingrese la cantidad de archivos que desea crear" << endl;
                cin >> cantidad;
                crearArchivos(cantidad);
                break;
            case 2:
                cout << "Opcion seleccionada -> Mostrar el peso de los archivos" << endl;
                mostrarDetalles();
                mostrarDetalles2();
                break;
            case 3:
                cout << "Opcion seleccionada -> Renombrar archivos" << endl;
                //renombrar();
                break;
            case 0:
                cout << "Gracias por Utilizar el Programa" << endl;
                break;
            default:
                cout << "Opcion incorrecta, vuelva a intentarlo" << endl;
                break;
        }
    } while (opc != 0);
    return 0;
}

void crearArchivos(int cantidad){
    string nombreArchivo = "documento";
    if (cantidad % 2 == 0){
        cout << "Cantidad de Archivos par" << endl;
        for (int i = 0; i < cantidad; ++i) {
            ofstream file;
            file.open("C:/Users/JP/Documents/par/" + nombreArchivo + to_string(i + 1) + ".txt");
            agregarTexto();
            for (int j = 0; j < i+1; ++j) {
                file << "linea de texto" << endl;
            }
            file.close();
        }
        cout << cantidad << " Archivos creados con Exito" << endl;
        contarArchivosDeDirectorio();
    }else{
        cout << "Cantidad de Archivos impar" << endl;
        for (int i = 0; i < cantidad; ++i) {
            ofstream file;
            file.open("C:/Users/JP/Desktop/impar/" + nombreArchivo + to_string(i + 1) + ".txt");
            agregarTexto();
            for (int j = 0; j < i+1; ++j) {
                file << "linea de texto" << endl;
            }
            file.close();
        }
        cout << cantidad << " Archivos creados con Exito" << endl;
        contarArchivosDeDirectorio2();
    }
}

void agregarTexto(){
    cout << "Agregando texto..." << endl;
}

int contarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:/Users/JP/Documents/par/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE){
        cout << "Ruta incorrecta" << endl;
    }else{
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;
        }
    }
    return cantidadDeArchivos-1;
}

int contarArchivosDeDirectorio2(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:/Users/JP/Desktop/impar/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE){
        cout << "Ruta incorrecta" << endl;
    }else{
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;
        }
    }
    return cantidadDeArchivos-1;
}

void mostrarDetalles(){
    filesystem::directory_iterator directoryIterator("C:/Users/JP/Documents/par/");
    cout <<"======================DIRECTORIO========================="<< endl;
    for(const auto& entry: directoryIterator){
        if (!filesystem::is_directory(entry.status())){
            cout<< endl;
            cout << "Peso: " << file_size(entry.path()) << " bytes" << endl;
            cout << "Nombre de Archivo: " << entry.path().filename() << endl;
        }
    }
}

void mostrarDetalles2(){
    filesystem::directory_iterator directoryIterator("C:/Users/JP/Desktop/impar/");

    cout<< endl <<"======================DIRECTORIO========================="<< endl;
    for(const auto& entry: directoryIterator){
        if (!filesystem::is_directory(entry.status())){
            cout<< endl;
            cout << "Peso: " << file_size(entry.path()) << " bytes" << endl;
            cout << "Nombre de Archivo: " << entry.path().filename() << endl;
        }
    }
}
void renombrar(){
    filesystem::directory_iterator directoryIterator("C:/Users/JP/Documents/par/");
/*
    for(const auto& entry: directoryIterator){
        if (!filesystem::is_directory(entry.status())){
            filesystem::rename(entry.path().filename(), "nuevoNombre");
        }
    }*/
}

