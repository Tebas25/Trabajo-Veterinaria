#include <stdio.h>
#include "funciones.h"
#include <string.h>



int ingresarOpcion(){
    int opcion;
    printf("------------------------------------\n");
    printf("\tServicio de Vaterinaria\n");
    printf("1. Ingreso de la mascota\n");
    printf("2. Servicios\n");
    printf("3. Facturar servicios\n");
    printf("4. Modificas mascota\n");
    printf("5. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);
    return opcion;
}

void IngresarMascota(int *id, char *nombre, char *tipo, int *edad, char *dueño){
    fflush(stdin);
    printf("Ingrese el ID de su mascota: ");
    scanf("%d", id);
    
    fflush(stdin);
    printf("Ingrese el nombre de su mascota: ");
    scanf("%[^\n]", nombre);
    
    fflush(stdin);
    printf("Ingrese la raza de su mascota: ");
    scanf("%[^\n]", tipo);

    fflush(stdin);
    printf("Ingrese la edad de su mascota: ");
    scanf("%d", edad);

    fflush(stdin);
    printf("Ingrese el nombre del dueño: ");
    scanf("%[^\n]", dueño);
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

void ImprimirFactura(int identificacion[10], char nombre[10][50], char tipo[10][50], int edad[10], char dueño[10][50], struct servicio ListaServicio[]){
    int k,f, posicionMascota=-1;
    char sn;
    int cantidadServicios=0;
    struct servicio Seleccionado[10];
    float precioFinal=0;

    do{
        printf("Ingrese la identificación de su mascota para la factura: ");
        scanf("%d",&k);
        for (int j = 0; j < 10; j++){
            if (identificacion[j]==k){
                posicionMascota=j;
            }
        }
        if (posicionMascota==-1){
            printf("Mascota no encontrada\n");
        }
    } while (posicionMascota==-1);
    
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
                fflush(stdin);
                printf("\nDesea ingresar otro servicio (S/N)? ");
                scanf("%c",&sn);
            } while (sn!='S' && sn!='N');
        }else{
            printf("Factura llena!!!!");
        }   
    } while (sn!='N'&& cantidadServicios<10);

    for (int t = 0; t < cantidadServicios; t++){
        precioFinal=precioFinal+Seleccionado[t].precio;
    }

    printf("----------------FACTURA------------------\n");
    printf("Datos del cliente\n");
    printf("Nombre: \t\tIdentificación:\t\t Nombre mascota:\n");
    printf("%s \t\t%d\t\t %s\n", dueño[posicionMascota], identificacion[posicionMascota],nombre[posicionMascota]);
    printf("\n");
    printf("Servicios elegidos:\n");
    for (int l = 0; l < cantidadServicios; l++){
        printf("%s \t%s\t %.2f\n",Seleccionado[l].nombre, Seleccionado[l].descripcion, Seleccionado[l].precio);
    }
    printf("Total: %.2f\n",precioFinal);
    printf("--------------------------------------------\n");

    FILE *factura;
    factura=fopen("factura.txt","w");

    fprintf(factura,"----------------FACTURA------------------\n");
    fprintf(factura,"Datos del cliente\n");
    fprintf(factura,"Nombre: \t\tIdentificación:\t\t Nombre mascota:\n");
    fprintf(factura,"%s \t\t%d\t\t %s\n", dueño[posicionMascota], identificacion[posicionMascota],nombre[posicionMascota]);
    fprintf(factura,"\n");
    fprintf(factura,"Servicios elegidos:\n");
    for (int l = 0; l < cantidadServicios; l++){
        fprintf(factura,"%s \t%s\t %.2f\n",Seleccionado[l].nombre, Seleccionado[l].descripcion, Seleccionado[l].precio);
    }
    fprintf(factura,"Total: %.2f\n",precioFinal);
    fprintf(factura,"--------------------------------------------\n");
    
    fclose(factura);
}

void modificarMascota(int *identificacion[10],char *nombre[10][50],char *tipo[10][50],int *edad[10],char *dueño[10][50]){
    int opcion;
    int ID;
    int seleccionado=-1;
    int nuevaid, nuevaedad;
    char nuevonombre[50], nuevotipo[50], nuevodueño[50];
    do{
        printf("Ingrese la identificacion de la mascota a modificar: ");
        scanf("%d",&ID);
        fflush(stdin);
        for (int i = 0; i < ID; i++){
            if (ID==identificacion[i]){
                seleccionado=i;
            }else{
                printf("Mascota no encontrada");
            }
        }
    }while(seleccionado==-1);
    printf("Ingrese el servicio que desea modificar:\n1. Nombre de la mascota.\n2. Tipo\n3. Nombre dueño\n4. Edad");
    scanf("%d",opcion);

    switch (opcion)
    {
    case 1:
        
        printf("Ingrese el nuevo nombre de la mascota: ");
        scanf("%s",nuevonombre[0]);
        strcpy(nuevonombre[0],*nombre[seleccionado][0]);
        break;
    
    case 2:
        printf("Ingrese el nuevo tipo: ");
        scanf("%s",&nuevotipo[0]);
        strcpy(nuevotipo[0],*tipo[seleccionado][0]);
        break;

    case 3:
        printf("Ingrese el nuevo nombre del dueño: ");
        scanf("%s",nuevodueño[0]);
        strcpy(nuevodueño[0],*dueño[seleccionado][0]);
        break;
    
    case 4:
        printf("Ingrese la nueva edad: ");
        scanf("%d",nuevaedad);
        *edad[seleccionado]=nuevaedad;
        break;

    default:
        printf("Opcion no valida");
        break;
    }
}