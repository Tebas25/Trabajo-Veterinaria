#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    struct mascota ListaMascota[10];
    struct servicio ListaServicio[10];
    int cont=0;
    int cont2=0;
    int opcion=0;
    do{
        opcion=ingresarOpcion();
        switch (opcion){
        case 1:
            if (cont<10){
                IngresarMascota(&ListaMascota[cont]);
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
            ImprimirFactura(ListaMascota, ListaServicio);
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

