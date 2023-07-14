struct servicio{
    int identificacion;
    char nombre[20];
    char descripcion[100];
    float precio;
};

int ingresarOpcion();
void IngresarMascota(int *id, char *nombre, char *tipo, int *edad, char *dueño);
void IngresarServicio(struct servicio *NuevoServicio);
void ImprimirFactura(int identificacion[10], char nombre[10][50], char tipo[10][50], int edad[10], char dueño[10][50], struct servicio ListaServicio[]);
void modificarMascota(int identificacion[10],char nombre[10][50],char tipo[10][50],int edad[10],char dueño[10][50]);
