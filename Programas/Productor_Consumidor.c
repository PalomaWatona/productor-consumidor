#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

//SE CONSIDERA AL PRODUCTOR (CASA MATRIZ) COMO EL PROCESO PADRE
//SE CONSIDERA AL CONSUMIDOR (CAMION) COMO EL PROCESO HIJO
//LOS ENVÍOS SERÁN SIEMPRE DE 20 PRODUCTOSA
//CUANDO EL CAMIÓN LLEGUE A LA CASA MATRIZ, ESTE SE LLENA Y SALE REPARTIR PRODUCTOS NUEVAMENTE

#define BUFFER_SIZE 20
int itemCount = 0;
int buffer[BUFFER_SIZE];
int contador;

//CASA MATRIZ
void productor(){
    //SE CREAN SOLICITUDES DE ENVÍO DE PRODUCTOS
    srand(time(NULL));
    while(itemCount != BUFFER_SIZE){
        buffer[contador] = rand()%(11-2+1);
        contador++;
        itemCount++;
    }
    contador = 0;
}


//REALIZAR LAS ENTREGAS
void consumidor(){
    ordenar();
    //SE MUESTRAN LAS SUCURSALES ORDENADAS
    printf("Cola de entrega: ");
    for (int i = 0; i < 20; i++){
        printf("%d ", buffer[i]+1);
    }
    sleep(2);
    printf("\n");
    int cont = 0;
    int aux = buffer[19];
    //SE RECORRE EL BUFFER DESDE EL PRINCIPIO HASTA EL FINAL
    for (int i = 0; i < itemCount; i++){
        cont++;
        //DETECTAMOS EL CAMBIO DE SUCURSAL 
        if (buffer[i] < buffer[i+1]){
            int a = (buffer[i+1] - buffer[i])*2;
            printf("\nEl camion llegó al destino: %d con %d paquetes", buffer[i]+1, cont);
            cont = 0;
            sleep(1);
        }
        //SE LLEGA A LA ÚLTIMA SUCURSAL
        if (buffer[i] == buffer[19] && i == itemCount-1){
            printf("\nEl camion llegó al destino: %d con %d paquetes\n", buffer[i]+1, cont);
        }
    }
    //SE VACÍA EL RECORRIDO DEL CAMIÓN
    for (int i = 0; i<20; i++){
        buffer[i] = -1;
    }
    int tiempoFinal = (aux+1)*2;
    sleep(1);
    //EL CAMIÓN VA DE VUELTA A LA CASA MATRIZ
    printf("\nEl camion se demorará %i segundos en llegar a la casa matriz desde el último destino\n", tiempoFinal);
    printf("\n---------------------------------------------------------------------------------------\n");
}

//ORDENAR EL EL RECORRIDO QUE HARÁ EL CAMIÓN
void ordenar(){
    int i, j, temp;
    for(i = 0; i < 20-1; i++) {
        for(j = 0; j < 20-i-1; j++) {
            if(buffer[j] > buffer[j+1]) {
                temp = buffer[j];
                buffer[j] = buffer[j+1];
                buffer[j+1] = temp;
            }
        }
    }
}



int main(){
    productor();
    while (1){
        //EL PRODUCTOR SE PONE A DORMIR EL TIEMPO SUFICIENTE PARA QUE EL CONSUMIDOR TERMINE SU EJECUCIÓN
        sleep(15);
        //SE CREA EL PROCESO HIJO
        int pid = fork();
        //CUANDO EL CONSUMIDOR TERMINE SU EJECUCIÓN, SE PARA SU EJECUCIÓN
        if (pid == 0){
            consumidor();
            break;
        }
        itemCount = 0;
        productor();
    }
    return 0;
}



