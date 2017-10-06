#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantallas.h"
#include "contrataciones.h"
#include "validar.h"

#define MAXPANT 100
#define MAXCONT 1000

int main()

{
    sPantallas pantallas[MAXPANT];
    sContrataciones contrataciones[MAXCONT];


    pantallas_initArray(pantallas,MAXPANT);
    contrataciones_initArray(contrataciones,MAXCONT);

    char opcion[5];
    int salir = 11;
    do
    {
        val_getUnsignedInt(opcion,
                           "\n\n1- Alta de pantalla.\n2- Modificar datos de pantalla.\n3- Baja de pantalla.\n4- Contratar una publicidad.\n5- Modificar condiciones de publicacion.\n6- Cancelar contratacion.\n7- Consulta facturacion.\n8- Listar pantallas.\n10- Informar\nIngrese una opcion: ",
                           "\nIngrese una opcion valida.\n",3,10);

        switch(atoi(opcion))
        {
        case 1:
            pantallas_cargarPantallas(pantallas,MAXPANT);
            break;
        case 2:
            pantallas_modificarPantallas(pantallas,MAXPANT);
            break;
        case 3:
            pantallas_darDeBajaPantalla(pantallas,MAXPANT);
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            salir = 0;
            break;
        case 8:

            break;
        case 9:

            break;
        case 10:

            break;
        }
    }
    while(salir != 0);
    return 0;
}

