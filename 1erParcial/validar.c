#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contrataciones.h"
#include "pantallas.h"
#include "validar.h"

#define MAX_INPUT_BUFFER 4096

/** \brief Recibe un buffer y en la ultima posicion coloca un \0
 *
 * \param buffer donde se guarda el string
 * \param tamaño del string
 *
 */

void myFgets(char* buffer, int limite,FILE* archivo)
{
    int i=0;
    fflush(archivo);
    fgets(buffer, limite,archivo);
    buffer[limite-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}
/** \brief Valida ingreso de numeros enteros
 *
 * \param destino donde se guarda el string
 * \param mensaje, mensaje para el usuario
 * \param mensajeError mensaje a mostrar en caso de error
 * \param intentos, cantidad de veces antes de mostrar error
 * \param limite, tamaño del string
 * \return 0 OK -1 en caso de error
 *
 */

int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarUnsignedInt(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Valida que solo se ingresen numeros
 *
 * \param buffer donde se guarda el string
 * \return 0 OK -1 en caso de error
 *
 */
int val_validarUnsignedInt(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}

/** \brief Valida que solo se ingresen letras
 *
 * \param destino donde se guarda el string
 * \param mensaje, mensaje para el usuario
 * \param mensajeError mensaje a mostrar en caso de error
 * \param intentos, cantidad de veces antes de mostrar error
 * \param limite,tamaño del string
 * \return 0 OK -1 en caso de error
 *
 */

int val_getString(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarString(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Valida lo ingresado tenga formato DNI
 *
 * \param buffer donde se guarda el string
 * \return 0 OK -1 en caso de error
 *
 */

int val_validarString(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && buffer[i] != ' ')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}
//*******************************************************************************************************************

/** \brief Toma un string y lo guarda
 *
 * \param destino donde se guarda el string
 * \param mensaje, mensaje para el usuario
 * \param mensajeError mensaje a mostrar en caso de error
 * \param intentos, cantidad de veces antes de mostrar error
 * \param limite, tamaño del string
 * \return 0 OK -1 en caso de error
 *
 */

int val_getAlfanumericoConSignos(char* destino, char* mensaje, char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarAlfanumericoConSignos(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

//*******************************************************************************************************************
/** \brief Valida que solo se ingresen numeros, letras y algunos signos
 *
 * \param buffer donde se guarda el string
 * \return 0 OK -1 en caso de error
 *
 */

int val_validarAlfanumericoConSignos(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') &&
                (buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] < '0' || buffer[i] > '9') &&
                (buffer[i] != '.') && (buffer[i] != '-') && (buffer[i] != '_') && (buffer[i] != '@') && (buffer[i]!= ' '))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}
//*******************************************************************************************************************

/** \brief Valida que el string ingresado corresponga un flotante
 *
 * \param destino donde se guarda el string
 * \param mensaje, mensaje para el usuario
 * \param mensajeError mensaje a mostrar en caso de error
 * \param intentos, cantidad de veces antes de mostrar error
 * \param limite, tamaño del string
 * \return 0 OK -1 en caso de error
 *
 */

int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarFloat(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
//*******************************************************************************************************************
/** \brief Valida que solo se ingresen numeros, un punto, y - solo en la 1ra posicion
 *
 * \param buffer donde se guarda el string
 * \return 0 OK -1 en caso de error
 * \return
 *
 */


int val_validarFloat(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '.' && buffer[i] != '-' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}

/** \brief Valida lo ingresado tenga formato CUIT
 *
 * \param destino donde se guarda el string
 * \param mensaje, mensaje para el usuario
 * \param mensajeError mensaje a mostrar en caso de error
 * \param intentos, cantidad de veces antes de mostrar error
 * \param limite, tamaño del string
 * \return 0 OK -1 en caso de error
 *
 */
int val_getCuit(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarDni(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Valida que solo se ingresen numeros y puntos
 *
 * \param buffer donde se guarda el string
 * \return 0 OK -1 en caso de error
 *
 */
int val_validarCuit(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagGuion = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '-')
        {
            retorno = -1;
            break;
        }
        else
        {
            if((buffer[i] == '.' && i == 2) || (buffer[i] == '.' && i == 11))
            {
                flagGuion++;
            }
        }
        i++;
    }
    if(flagGuion != 2)
    {
        retorno = -1;
    }
    return retorno;
}
