#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>


#define BUFFER_SIZE 20
int itemCount = 0;
int buffer[BUFFER_SIZE];
int contador;

//2 segundos de espera para cada destino
//CASA MATRIZ
void productor(){
    printf("Sucursal:\n");
    srand(time(NULL));
    while(itemCount != BUFFER_SIZE){
        buffer[contador] = rand()%(11-2+1);
        contador++;
        itemCount++;
    }
    for (int i = 0; i < 20; i++){
        printf("%d ", buffer[i]);
    }
    contador = 0;
}


//REALIZAR LAS ENTREGAS
void consumidor(){
    sleep(2);
    ordenar();
    int cont = 0;
    int aux = buffer[19];
    for (int i = 0; i < itemCount; i++){
        //sleep(1);
        cont++;
        //printf("El camion llegò al destino: %d\n", buffer[i]+1);
        if (buffer[i] < buffer[i+1]){
            int a = (buffer[i+1] - buffer[i])*2;
            printf("El camion llegò al destino: %d con %d paquetes\n", buffer[i]+1, cont);
            cont = 0;
            //sleep(a);
        }
        if (buffer[i] == buffer[19] && i == itemCount-1){
            printf("El camion llegò al destino: %d con %d paquetes\n", buffer[i]+1, cont);
        }
    }
    //SE VACÌA EL BUFFER
    for (int i = 0; i<20; i++){
        buffer[i] = -1;
    }
    int tiempoFinal = (aux+1)*2;
    printf("\nEl camion se demorará %i segundos en llegar a la casa matriz desde el último destino\n", tiempoFinal);
}

//ORDENAR EL BUFFER
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
        sleep(4);
        int pid = fork();
        printf("\nid hijo: %d\n", pid);
        if (pid == 0){
            consumidor();
            break;
        }
        itemCount = 0;
        productor();
    }
    return 0;
}



