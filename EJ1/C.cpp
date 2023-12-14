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

//Funcion para imprimir los datos de un estudiante
void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);

    //Imprimir materias
    printf("Materias: ");
    for (int i = 0; i < estudiante->numMaterias; i++) {
        printf("%s ", estudiante->materias[i]);
    }
    printf("\n");
}

//Estructura asistencia
struct Asistencia {
    char fecha[11];
    char materia[50];
    char estado[10];
};