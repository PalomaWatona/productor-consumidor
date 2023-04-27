#include <stdio.h>


#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//El padré será la sucursal


int tamaño = 20;
bool repartiendo = false;
int despachos = 10;
int tiempo_despacho = 2;
int tiempo_vuelta = 0;
int buffer[20];
int sucursales[10];

void Sucursal(){
  
}

void Camion(){
  
}

int main(void) {

//GENERAR LOS NÙMEROS ALEATORIOS: CANTIDAD DE PAQUETES GENERADOS
    int paquetes; 
    srand(time(NULL));
    paquetes=rand()%(20-0+1);
    if (tamaño+paquetes <= 20){
        tamaño = tamaño+paquetes;
    }
    else{
        paquetes = 0;
    }
    //printf("Cantidad: %i  \n", paquetes);

// GENERAR NÙMEROS ALEATORIOS: DESTINO
    int v; 
    srand(time(NULL));
    v=rand()%(10-1+1);
    printf("Cantidad: %i al Destino: %i  \n", paquetes, v);


  srand(20);
  
  int numero;
  
  

  if(fork() == 0){
    
    if(repartiendo == false){
      numero = rand() ;
    }else{
      
    }
    printf("Aca esta el hijo\n");
    
  }else{
    numero = rand() ; 
    if(repartiendo == false){
      
    }else{
      
    }
    printf("Aca esta el padre\n");
  }

  printf("El numero es = %i\n", numero);
  return 0;
}



int itemCount = 0;
/*
procedure producer() {
    while (true) {
        item = produceItem();

        if (itemCount == BUFFER_SIZE) {
            sleep();
        }

        putItemIntoBuffer(item);
        itemCount = itemCount + 1;

        if (itemCount == 1) {
            wakeup(consumer);
        }
    }
}

procedure consumer() {
    while (true) {

        if (itemCount == 0) {
            sleep();
        }

        item = removeItemFromBuffer();
        itemCount = itemCount - 1;

        if (itemCount == BUFFER_SIZE - 1) {
            wakeup(producer);
        }

        consumeItem(item);
    }
}*/