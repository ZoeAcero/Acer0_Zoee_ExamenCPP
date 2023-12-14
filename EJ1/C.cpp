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

//Estructura estudiante con gestion de asistencia
struct EstudianteConAsistencia {
    struct Estudiante estudiante;
    struct Asistencia* asistencias;
    int numAsistencias;
};

//Registrar y mostrar asistencia
void registrarAsistencia(struct EstudianteConAsistencia* estudianteConAsistencia, const struct Asistencia* asistencia) {
    estudianteConAsistencia->asistencias[estudianteConAsistencia->numAsistencias] = *asistencia;
        estudianteConAsistencia->numAsistencias++;
}

void mostrarAsistencias(const struct EstudianteConAsistencia* estudianteConAsistencia) {
    printf("\n Registro de Asistencia:\n");
    for (int i = 0; i < estudianteConAsistencia->numAsistencias; i++) {
        printf("Fecha: %s | Materia: %s | Estado: %s\n", estudianteConAsistencia->asistencias[i].fecha,
               estudianteConAsistencia->asistencias[i].materia, estudianteConAsistencia->asistencias[i].estado);
    }
}

int main() {

    struct EstudianteConAsistencia estudianteAsistencia;

    strcpy(estudianteAsistencia.estudiante.nombre, "Zoe");
    estudianteAsistencia.estudiante.edad = 18;
    estudianteAsistencia.estudiante.promedio = 7.0;

    estudianteAsistencia.estudiante.numMaterias = 2;
    estudianteAsistencia.estudiante.materias = (char**)malloc(estudianteAsistencia.estudiante.numMaterias * sizeof(char*));
    estudianteAsistencia.estudiante.materias[0] = "Matemáticas";
    estudianteAsistencia.estudiante.materias[1] = "Programación";

 struct Asistencia asistencia1 = {"2023-01-15", "Matemáticas", "Asistió"};
    struct Asistencia asistencia2 = {"2023-01-16", "Programación", "Falta"};

    registrarAsistencia(&estudianteAsistencia, &asistencia1);
    registrarAsistencia(&estudianteAsistencia, &asistencia2);

    printf("Información del Estudiante:\n");
    mostrarEstudiante(&estudianteAsistencia.estudiante);

    mostrarAsistencias(&estudianteAsistencia);

// Liberar memoria
    for (int i = 0; i < estudianteAsistencia.estudiante.numMaterias; ++i) {
        free(estudianteAsistencia.estudiante.materias[i]);
    }
    free(estudianteAsistencia.estudiante.materias);
    free(estudianteAsistencia.asistencias);

    return 0;
}


