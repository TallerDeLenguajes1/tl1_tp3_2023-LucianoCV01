#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXIMO_CLIENTES 5
#define MINIMO_CLIENTES 1

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
}typedef Cliente;

//Declaro Funciones
float costoTotal(Producto producto);

int main(){
    //Declaraciones de variables
    int numClientes;
    Cliente *vectorClientes;
    char *buff; 
    float costoTotalCliente = 0;

    //Asignacion de memoria dinamica
    buff = (char *) malloc(sizeof(char) * 100);
    //Apartado i)
    puts("------ o ------ o ------ o ------");
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &numClientes);

    if (MINIMO_CLIENTES <= numClientes && numClientes <= MAXIMO_CLIENTES)
    {
        //Apartado ii) 
        vectorClientes = (Cliente *) malloc(sizeof(Cliente) * numClientes);

        for (int i = 0; i < numClientes; i++)
        {
            puts("------ o ------ o ------ o ------");
            printf("------ Datos del cliente %dº ------\n", i + 1);
            vectorClientes[i].ClienteID = i + 1;
            fflush(stdin);
            printf("Ingrese el/los nombre/s: \n");
            gets(buff);
            vectorClientes[i].NombreCliente = (char *) malloc(sizeof(char) * (strlen(buff)+1));
            strcpy(vectorClientes[i].NombreCliente,buff);
            srand(time(NULL));
            //Apartado iii)
            vectorClientes[i].CantidadProductosAPedir = rand() % 5 + 1;
            vectorClientes[i].Productos = (Producto *) malloc(sizeof(Producto) * vectorClientes[i].CantidadProductosAPedir);
            for (int j = 0; j < vectorClientes[i].CantidadProductosAPedir; j++)
            {
                vectorClientes[i].Productos[j].ProductoID = j + 1;
                vectorClientes[i].Productos[j].Cantidad = rand() % 10 + 1;
                vectorClientes[i].Productos[j].TipoProducto = TiposProductos[rand()%5];
                vectorClientes[i].Productos[j].PrecioUnitario = rand() % 91 + 10;
            }   
        }

        //Apartado v)
        puts("------ o ------ o ------ o ------");
        for (int i = 0; i < numClientes; i++)
        {
            printf("------ Datos del cliente %dº ------\n", i + 1);
            printf("Cliente ID: %d\n", vectorClientes[i].ClienteID);
            printf("Nombre/s: %s\n", vectorClientes[i].NombreCliente);
            printf("Cantidad producto a pedir: %d\n", vectorClientes[i].CantidadProductosAPedir);
            for (int j = 0; j < vectorClientes[i].CantidadProductosAPedir; j++)
            {
                puts("------ Datos del Producto ------");
                printf("Producto ID: %d\n", vectorClientes[i].Productos[j].ProductoID);
                printf("Cantidad: %d\n", vectorClientes[i].Productos[j].Cantidad);
                printf("Tipo de Producto: %s\n", vectorClientes[i].Productos[j].TipoProducto);
                printf("Precio unitario: %.2f\n", vectorClientes[i].Productos[j].PrecioUnitario);
                costoTotalCliente += costoTotal(vectorClientes[i].Productos[j]);
            }   
            printf("Total a pagar: %.2f\n", costoTotalCliente);
            costoTotalCliente = 0;
        }

    } else
    {
        puts("------ o ------ o ------ o ------");
        puts("No puede cargar datos de mas de cinco clientes");
    }

    //Libero memoria
    free(buff);
    for (int i = 0; i < numClientes; i++)
    {
        free(vectorClientes[i].NombreCliente);
        free(vectorClientes[i].Productos);
    }

    return 0;
}
//Desarrollo Funciones
float costoTotal(Producto producto) //Apartado iv)
{
    return (producto.Cantidad * producto.PrecioUnitario);
}