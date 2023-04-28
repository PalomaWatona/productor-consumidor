#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BUFFER_SIZE 20;

int camion[BUFFER_SIZE];

int itemCount = 0;
void productor();
void consumidor();
void dejarItemEnBuffer(int item);
void consumirItem();
bool entregando;

int main(){
	
	printf("Item Count --> %d\n",itemCount);

    if (fork() == 0){
        consumidor();
    }
    else{
        productor();
    }

	return 0;
}
void productor(){
    printf("Soy el padre y estoy en el productor\n");
  int cont = 0;
	while(1){
		
		if(itemCount == BUFFER_SIZE){
			sleep(5);//dormir al productor..
		}else{
      int y = 0;
      y = producirItem();
      camion[itemCount] = y;
      itemCount++;
      printf("Produccion exitosa\n");
    }
    
		if(itemCount == 1){ //Se deberìa despertar al consumidor cuando llegue a la casa matriz
			//wakeup(consumidor);//despertar al consumidor
		}
    cont++;
	}
}

void consumidor(){
    printf("Soy el hijo y estoy en el consumidor\n");
	
	while(1){
		if(itemCount == 0){
			sleep(4);//Dormir al consumidor
		}else{
      int pack = camion[itemCount];
      printf("La distancia hacia la sucursal %d es %d\n",pack,pack*2);
    }
		
	}
}

int producirItem(){
  int item = rand() % 10;
	//Generar un elemento y retornarlo
	return item;
}
void dormirProductor(){
	//dormir...
}
void dejarItemEnBuffer(int item){
	camion[itemCount] = item;
  itemCount++;
}
void despertarProductor(){
	//despertar...
}


void consumirItem(){
  int i = 0;
  for(i = 0; i < BUFFER_SIZE; i++){
    
  }
  camion[itemCount] = 
	//Quitar el elemento del BUFFER, se puede mostrar en pantalla el item consumido
}
int sacarItemDelBuffer(){
	
	return 0;
}
void dormirCondumidor(){
	
}
void despertarConsumidor(){
	
}
