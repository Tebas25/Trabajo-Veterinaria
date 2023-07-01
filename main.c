#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    int identificacion[10];
    char nombre[10][50];
    char tipo[10][50];
    int edad[10];
    char dueño[10][50];
    struct servicio ListaServicio[10];
    int cont=0;
    int cont2=0;
    int opcion=0;
    do{
        opcion=ingresarOpcion();
        switch (opcion){
        case 1:
            if (cont<10){
                IngresarMascota(&identificacion[cont], &nombre[cont][0], &tipo[cont][0], &edad[cont], &dueño[cont][0]);
            }else{
                printf("Nustro sistema esta completo.\n");
            }
            cont++;
            break;

        case 2:
            if (cont2<10){
                IngresarServicio(&ListaServicio[cont2]);
            }else{
                printf("No se pueden ingresar más servicios.\n");
            }
            cont2++;
            break;

        case 3:
            ImprimirFactura(identificacion, nombre, tipo, edad, dueño, ListaServicio);
            break;

        case 4:
            printf("Fin del programa\n");
            break;
        
        default:
            printf("Opción no válida. Ingrese otra opción\n\n");
            break;
        }
    }while(opcion!=4);
    return 0;
}

