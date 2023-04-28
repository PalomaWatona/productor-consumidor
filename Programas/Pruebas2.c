#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 20
int itemCount = 0;
int buffer[BUFFER_SIZE];
int contador;
//2 segundos de espera para cada destino

//CASA MATRIZ
void productor(){
    printf("Padre:\n");
    srand(time(NULL));
    while(itemCount != BUFFER_SIZE){
        //if(itemCount == BUFFER_SIZE){
            //sleep();
        //}
        //else{
        buffer[contador] = rand()%(11-2+1);
        //}
        //printf("a");
        //printf("%d ", buffer[contador]);
        contador++;
        itemCount++;
    }
    for (int i = 0; i < 20; i++){
        printf("%d ", buffer[i]);
    }
    printf("\nItem Count= %i\n", itemCount);
    //printf("Soy el padre\n");
}


//REALIZAR LAS ENTREGAS
void consumidor(){
    sleep(2);
    ordenar();
    printf("Soy el hijo");
    //printf("a: %i", itemCount);
    for (int i = 0; i < itemCount; i++){
        sleep(1);
        printf("El camion llegò al destino: %d\n", buffer[i]+1);
    }
    //wakeup(productor);
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
    //for (int i = 0; i < 20; i++){
    //    printf("%d ", buffer[i]);
    //}
}



int main(){
    
    //srand(time(NULL));
/*
    for (int i = 0; i < BUFFER_SIZE; i++){
        buffer[i] = rand()%(20-1+1);
    }

    printf("Los nùmeros aleatorios generados son: ");
    for (int i = 0; i < BUFFER_SIZE; i++){
        printf("%d ", buffer[i]);
    }
    printf("\n");
*/
    //Inicio del proceso hijo (consumidor)

    productor();
    if (fork() == 0){
        consumidor();
    }
    return 0;
}



