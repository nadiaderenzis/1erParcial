#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED

typedef struct
{
    int idCliente;
    char cuit[13];
    int diasPublicacion;
    char nombreArchivoVideo[50];
    unsigned char estado;

}sContrataciones;

#endif // CONTRATACIONES_H_INCLUDED

#define CONTRATACION_LIBRE 0
#define CONTRATACION_ENCURSO 1
#define CONTRATACION_FINALIZADA 2

int contrataciones_initArray (sContrataciones* arrayContrataciones, int longitud);
int contrataciones_generarProximoIndice (void);
int contrataciones_nuevaContratacion (sContrataciones* arrayContrataciones,int longitud);

