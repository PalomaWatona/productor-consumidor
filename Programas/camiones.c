#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <stdbool.h>

#define BUFFER_SIZE 20
int itemCount = 0;
int buffer[BUFFER_SIZE];
int contador;
bool entregando = false;
//2 segundos de espera para cada destino

//CASA MATRIZ
void productor(){
    printf("Padre:\n");
    srand(time(NULL));
    while(itemCount != BUFFER_SIZE){
        buffer[contador] = rand()%(11-2+1);
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
    int aux = buffer[19];
    printf("Soy el hijo");
    //printf("a: %i", itemCount);
    for (int i = 0; i < itemCount; i++){
        //sleep(1);
        printf("El camion llegò al destino: %d\n", buffer[i]+1);
        if (buffer[i] < buffer[i+1]){
            int a = (buffer[i+1] - buffer[i])*2;
            //sleep(a);
        }
    }
    //SE VACÌA EL BUUFFER
    for (int i = 0; i<20; i++){
        buffer[i] = -1;
        printf("\nBuffer vacio = %d\n", buffer[i]);
    }
    int tiempoFinal = (aux+1)*2;
    printf("\nEl camion se demorará %i segundos en llegar a la casa matriz desde el último destino\n", tiempoFinal);
    //sleep(5)
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
    
    //while(1){
    productor();
    int pid = fork();
    kill(pid, SIGCONT);
    if (pid == 0){
        kill(pid, SIGKILL);
    }
    //sleep(3);
    //kill(pid, SIGCONT);
    //}
    return 0;
}



