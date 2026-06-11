#include <stdio.h>
#include <string.h>
#include "funciones.h"


int main(void)
{
    int opc=0;                                                     
    articulos_t articulos[CANT_ARTICULOS] = {0};        //Creo mis fichas, segun CANT_ARTICULOS

    printf("Bienvendio al primer TP de Info2\n\n");     //Mensaje de Bienvenida


    do
    {
        cargar_articulo(articulos);                                     //Cargo Fichas

        printf("Desea ingresar otro articulo? 1-Si, 2-No");             //Verifico si el usuario quiere ingresar mas articulos
        scanf("%d",&opc); 

    } while (opc==1);                                   

    print_fichas(articulos);                                       //Imprimo las fichas

    sort_fichas(articulos);                                        //Ordeno las fichas segun cantidad de articulos
 
    printf("\n\n###################################");
    printf("\n##############ORDENADO################");
    printf("\n################################### \n");

    print_fichas(articulos);                                       //Imprimo las fichas ordenadas

    return 0;
}