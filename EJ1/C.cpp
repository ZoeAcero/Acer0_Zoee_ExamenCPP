#include <string>
#include <cstring>

//Estructura estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    char** materias;
    int numMaterias;
};