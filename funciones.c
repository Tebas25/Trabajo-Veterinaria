#include <stdio.h>
#include "funciones.h"



int ingresarOpcion(){
    int opcion;
    printf("\tServicio de Vaterinaria\n");
    printf("1. Ingreso de la mascota\n");
    printf("2. Servicios\n");
    printf("3. Facturar servicios\n");
    printf("4. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);
    return opcion;
}

void IngresarMascota(struct mascota *NuevaMascota){
    fflush(stdin);
    printf("Ingrese el ID de su mascota: ");
    scanf("%d", &(*NuevaMascota).identificacion);
    
    fflush(stdin);
    printf("Ingrese el nombre de su mascota: ");
    scanf("%[^\n]",(*NuevaMascota).nombre);
    
    fflush(stdin);
    printf("Ingrese la raza de su mascota: ");
    scanf("%[^\n]",(*NuevaMascota).tipo);

    fflush(stdin);
    printf("Ingrese la edad de su mascota: ");
    scanf("%d",&(*NuevaMascota).edad);

    fflush(stdin);
    printf("Ingrese el nombre del dueño: ");
    scanf("%[^\n]",(*NuevaMascota).dueño);
}

void IngresarServicio(struct servicio *NuevoServicio){
    fflush(stdin);
    printf("Ingrese el ID del servicio: ");
    scanf("%d",&(*NuevoServicio).identificacion);

    fflush(stdin);
    printf("Ingrese el nombre del servicio: ");
    scanf("%[^\n]",(*NuevoServicio).nombre);

    fflush(stdin);
    printf("Ingrese la descripción del servicio: ");
    scanf("%[^\n]",(*NuevoServicio).descripcion);

    fflush(stdin);
    printf("Ingrese el precio del servicio: ");
    scanf("%f",&(*NuevoServicio).precio);
}

void ImprimirFactura(struct mascota ListaMascota[], struct servicio ListaServicio[]){
    int k,f, posicionMascota=-1;
    char sn;
    int cantidadServicios=0;
    struct servicio Seleccionado[10];
    float precioFinal=0;

    do{
        printf("Ingrese la identificación de su mascota para la factura: ");
        scanf("%d",&k);
        for (int j = 0; j < 10; j++){
            if (ListaMascota[j].identificacion==k){
                posicionMascota=j;
            }
        }
        if (posicionMascota==-1){
            printf("Mascota no encontrada\n");
        }
    } while (posicionMascota!=-1);
    
    do{
        printf("\nIngrese la identificación del servicio a facturar: ");
        scanf("%d",&f);

        for (int i = 0; i < 10; i++){
            if (ListaServicio[i].identificacion==f){
                Seleccionado[cantidadServicios] = ListaServicio[i];
                cantidadServicios= cantidadServicios + 1;
            }  
        }
        if (cantidadServicios<10)
        {
            do{
                printf("\nDesea ingresar otro servicio (S/N)? ");
                scanf("%c",&sn);
            } while (sn!='S' || sn!='N');
        }else{
            printf("Factura llena!!!!");
        }   
    } while (sn!='N'|| cantidadServicios<10);

    for (int t = 0; t < cantidadServicios; t++){
        precioFinal=precioFinal+Seleccionado[t].precio;
    }
        

    printf("-----------FACTURA------------");
    printf("Datos del cliente\n");
    printf("%d %c",ListaMascota[posicionMascota].dueño, ListaMascota[posicionMascota].identificacion);
    printf("Servicios a facturar\n");
    for (int l = 0; l < cantidadServicios; l++){
        printf("%s %s %f",Seleccionado[l].nombre, Seleccionado[l].descripcion, Seleccionado[l].precio);
    }
    printf("Total: %.2f",precioFinal);
    
    
}