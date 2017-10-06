#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contrataciones.h"
#include "validar.h"
#include "pantallas.h"

/** \brief initArray inicializa los campos de la esctructura
 * \param array recibido por referencia
 * \param longitud del array
 * \return 0 OK  o -1 error
 *
 */

int contrataciones_initArray (sContrataciones* arrayContrataciones, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayContrataciones != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayContrataciones[i].estado = CONTRATACION_LIBRE;
        }

    }
    return retorno;
}

//************************************************************************************************************************
/** \brief genera un id autoincrementable
 * \return retorna idAutoincrementable
 */

static int idContraAutoincrementable = -1;

int contrataciones_generarProximoIndice (void)
{
    idContraAutoincrementable++;
    return idContraAutoincrementable;
}
//************************************************************************************************************************
//
///** \brief cargaPersona realiza la carga de datos
// * \param arrayPersona array recibido por parametro
// * \param longitud del array
// * \return 0 si se realizo la carga correctamente o -1 si no se pudo
// *
// */
//int contrataciones_nuevaContratacion (sContrataciones* arrayContrataciones,int longitud)
//{
//    int retorno = -1;
//    int i, indice;
//    char bCuit[51];
//    char bDias[50];
//    char bnombreArchivo[50];
//
//    if(arrayContrataciones!= NULL && longitud >= 0)
//    {
//        for(i=0; i<longitud; i++)
//        {
//            if(arrayContrataciones[i].estado == CONTRATACION_LIBRE)
//            {
//                indice = i;
//                break;
//            }
//        }
//
//        if(val_getCuit(bCuit,"\nIngrese el CUI: ","\nError, el formato es xx-xxxxxxxx-xx: ",3,51)==0)
//        {
//            if(val_getUnsignedInt(bDias, "\nIngresa la cantidad de dias a alquilar: ", "\nError, puede ingresar numeros: ",3,50)== 0)
//            {
//                if(val_getString(bnombreArchivo,"Ingrese el nombre del archivo: ","Error, solo puede ingresar letras",3,50)==0)
//                {
//                    {
//                        strncpy(arrayContrataciones[indice].cuit,bCuit,51);
//                        arrayContrataciones[indice].diasPublicacion=atoi(bDias);
//                        strncpy(arrayContrataciones[indice].nombreArchivoVideo,bnombreArchivo,50);
//                        arrayContrataciones[indice].idCliente = contrataciones_generarProximoIndice();
//                        arrayContrataciones[indice].estado = CONTRATACION_ENCURSO;
//                        retorno = 0;
//                    }
//                }
//            }
//        }
//    }
//
//    return retorno;
//}
//************************************************************************************************************************

/** \brief recorre array busca espacio libre para generar una llamada
 *
 * \param array recibido por referencia
 * \param array recibido por referencia
 * \param longitud del array
 * \param longit del array
 * \param mensaje1 y mensaje2 de error para el usuario
 * \param id ecibido por parametro para buscar llamadas pendientes
 * \return 0 OK  o -1 error
 *
 */

int contrataciones_contratarPublicidad (sPantallas* arrayPantalla,sContrataciones* arrayContrataciones,int longitudPantalla,
                                        int longitudContrataciones, char* mensajeError, char* mensajeError2)
{
    int retorno = -1;
    int idAux, indice;
    int flagMotivo = 0;
    char buffer[10];
    int indicePantalla;
    int i;
    int indiceContrataciones;
    char bCuit[51];
    char bDias[50];
    char bnombreArchivo[50];

    if((arrayPantalla != NULL && arrayContrataciones != NULL) && (longitudPantalla >= 0 && longitudContrataciones  >= 0))
    {
        pantallas_listarPantallas(arrayPantalla,longitudPantalla);
        val_getUnsignedInt(buffer,"\nIngrese el id de la pantalla: ", "\nIngrese solo numeros",3,10);
        idAux=atoi(buffer);
        indicePantalla=pantallas_buscarIndicePorId(arrayPantalla,longitudPantalla,idAux,"No se encontro id");
        if(indicePantalla!=-1)
        {
            for(i=0; i<longitudContrataciones; i++)
            {
                if(arrayContrataciones[i].estado == CONTRATACION_LIBRE)
                {
                    indiceContrataciones = i;
                    break;
                }
            }

            if(val_getCuit(bCuit,"\nIngrese el CUI: ","\nError, el formato es xx-xxxxxxxx-xx: ",3,51)==0)
            {
                if(val_getUnsignedInt(bDias, "\nIngresa la cantidad de dias a alquilar: ", "\nError, puede ingresar numeros: ",3,50)== 0)
                {
                    if(val_getString(bnombreArchivo,"Ingrese el nombre del archivo: ","Error, solo puede ingresar letras",3,50)==0)
                    {
                        {
                            strncpy(arrayContrataciones[indiceContrataciones].cuit,bCuit,51);
                            arrayContrataciones[indiceContrataciones].diasPublicacion=atoi(bDias);
                            strncpy(arrayContrataciones[indiceContrataciones].nombreArchivoVideo,bnombreArchivo,50);
                            arrayContrataciones[indiceContrataciones].idCliente = contrataciones_generarProximoIndice();
                            arrayContrataciones[indiceContrataciones].estado = CONTRATACION_ENCURSO;
                            arrayPantalla[indicePantalla].idCliente=arrayContrataciones[indiceContrataciones].idCliente;
                            arrayPantalla[indicePantalla].estado=PANTALLA_CONTRATADA;
                            retorno = 0;
                        }
                    }


                }
            }
        }
        return retorno;
    }
}
