#ifndef PANTALLAS_H_INCLUDED
#define PANTALLAS_H_INCLUDED

typedef struct
{
    int idPantalla;
    char tipo[10];
    char nombre[50];
    char direccion[100];
    float precioPorDia;
    unsigned char estado;
    int idCliente;

}sPantallas;

#endif // PANTALLAS_H_INCLUDED

#define PANTALLA_LIBRE 0
#define PANTALLA_CONTRATADA 1


int pantallas_initArray (sPantallas* arrayPantallas, int longitud);
int pantallas_generarProximoId (void);
int pantallas_cargarPantallas (sPantallas* arrayPantallas,int longitud);
int pantallas_buscarIndicePorId (sPantallas* arrayPantallas, int longitud, int id, char* mensaje);
int pantallas_modificarPantallas (sPantallas* arrayPantallas, int longitud);
int pantallas_darDeBajaPantalla (sPantallas* arrayPantallas, int longitud);
int pantallas_listarPantallas (sPantallas* arrayPantallas, int longitud);

