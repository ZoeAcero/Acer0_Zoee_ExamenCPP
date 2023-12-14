#include <iostream>
#include <vector>
#include <string>

//estructura estudiante
struct estudiante{
    std::string nombre;
    int edad;
    float promedio;
    std::vector<std::string> materias;
};

//funcion para imprimir los datos de un estudiante

void mostrarEstudiante(const estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;

    //imprimir materias
    std::cout << "Materias: ";
    for (const auto& materia : estudiante.materias) {
        std::cout << materia << std::endl;
    }
}
