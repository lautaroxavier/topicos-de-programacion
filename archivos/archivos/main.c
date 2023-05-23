#include <stdio.h>
#include <stdlib.h>

typedef struct sStudent {
    int id;
    char surname[40];
    char name[40];
    float grade;
} tStudent;

typedef struct sEmployee {
    int id;
    char surname[40];
    char name[40];
    double salary;
} tEmployee;

int crearLotePruebas();

int mostrarArchEmpleados();

int mostrarArchEstudiantes();

int main()
{
    crearLotePruebas();
    mostrarArchEmpleados();
    mostrarArchEstudiantes();
    return 0;
}

int crearLotePruebas(){
    tEmployee empleados[10] = {
        {2, "Jones", "Mary", 45000.00},
        {4, "Chen", "Lily", 55000.00},
        {6, "Brown", "Emma", 52000.00},
        {8, "Miller", "Anna", 49000.00},
        {10, "Martin", "Sara", 51000.00},
        {11, "Smith", "John", 50000.00},
        {13, "Lee", "David", 60000.00},
        {15, "Garcia", "Carlos", 48000.00},
        {17, "Singh", "Raj", 58000.00},
        {19, "Nguyen", "Tom", 53000.00}
    };

    tStudent estudiantes[20] = {
        {1, "Wilson", "James", 3.30},
        {2, "Jones", "Mary", 9.00},
        {3, "Kim", "Jin", 7.30},
        {4, "Chen", "Lily", 8.80},
        {5, "Clark", "Henry", 4.00},
        {6, "Brown", "Emma", 9.10},
        {7, "Johnson", "Mark", 5.50},
        {8, "Miller", "Anna", 8.60},
        {9, "Wang", "Leo", 6.00},
        {10, "Martin", "Sara", 8.70},
        {11, "Smith", "John", 5.50},
        {12, "Taylor", "Alice", 9.20},
        {13, "Lee", "David", 9.50},
        {14, "Lopez", "Elena", 4.40},
        {15, "Garcia", "Carlos", 2.20},
        {16, "Patel", "Neha", 9.60},
        {17, "Singh", "Raj", 7.40},
        {18, "Williams", "Zoe", 6.80},
        {19, "Nguyen", "Tom", 8.90},
        {20, "Davis", "Amy", 6.60}
    };

    FILE * pfEmpleados = fopen("empleados.dat", "wb");
    fwrite(empleados, sizeof(tEmployee), 10, pfEmpleados);
    fclose(pfEmpleados);

    FILE * pfEstudiantes = fopen("estudiantes.dat", "wb");
    fwrite(estudiantes, sizeof(tStudent), 20, pfEstudiantes);
    fclose(pfEstudiantes);
    return 1;
}

int mostrarArchEmpleados(){
    tEmployee empleado;
    FILE * pfEmpleados = fopen("empleados.dat", "rb");
    if(!pfEmpleados){
        return 0;
    }
    fread(&empleado, sizeof(empleado), 1, pfEmpleados);
    while(!feof(pfEmpleados)){
        printf("%d %s %s %5.2f\n", empleado.id, empleado.surname, empleado.name, empleado.salary);
        fread(&empleado, sizeof(empleado), 1, pfEmpleados);
    }
    fclose(pfEmpleados);
    return 1;
}

int mostrarArchEstudiantes(){
    tStudent estudiante;
    FILE * pfEstudiantes = fopen("estudiantes.dat", "rb");
    if(!pfEstudiantes){
        return 0;
    }
    fread(&estudiante, sizeof(estudiante), 1, pfEstudiantes);
    while(!feof(pfEstudiantes)){
        printf("%d %s %s %5.2f\n", estudiante.id, estudiante.surname, estudiante.name, estudiante.grade);
        fread(&estudiante, sizeof(estudiante), 1, pfEstudiantes);
    }
    fclose(pfEstudiantes);
    return 1;
}
