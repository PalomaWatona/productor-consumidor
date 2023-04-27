#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 20
int itemCount = 0;


int main(){
    int buffer[BUFFER_SIZE];
    srand(time(NULL));

    for (int i = 0; i < BUFFER_SIZE; i++){
        buffer[i] = rand()%(20-1+1);
    }

    printf("Los nùmeros aleatorios generados son: ");
    for (int i = 0; i < BUFFER_SIZE; i++){
        printf("%d ", buffer[i]);
    }
    printf("\n");

    //Inicio del proceso hijo (consumidor)
    if (fork() == 0){
        consumidor();
    }
    else{
        productor();
    }
    return 0;
}

void productor(){
    int n = 0;
    while(n == 0){
        
    }
    printf("Soy el padre\n");
}

void consumidor(){
    printf("Soy el hijo");
}



