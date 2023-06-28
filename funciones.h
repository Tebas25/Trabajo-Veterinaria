struct mascota{
    int identificacion;
    char nombre[20];
    char tipo[20];
    int edad;
    char dueño[50];
};

struct servicio{
    int identificacion;
    char nombre[20];
    char descripcion[100];
    float precio;
};

int ingresarOpcion();
void IngresarMascota(struct mascota  *NuevaMascota);
void IngresarServicio(struct servicio *NuevoServicio);
void ImprimirFactura(struct mascota ListaMascota[], struct servicio ListaServicio[]);