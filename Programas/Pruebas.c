#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 20

int buffer[BUFFER_SIZE];

int itemCount = 0;
void productor();

int main(){
	//El buffer deberá ser un arreglo de tamaño fijo
	//Se puede definir que el padre es el productor y el hijo el consumidor
	printf("Item Count --> %d\n",itemCount);

    if (fork() == 0){
        consumidor();
    }
    else{
        productor();
    }

	//O, se puede crear dos procesos uno para productor y otro para consumidor.
	return 0;
}
void productor(){
    printf("Soy el padre y estoy en el productor")
	//Acá debe ir la lógica del productor
	while(true){
		item = producirItem();
		if(itemCount == BUFFER_SIZE){
			sleep();//dormir al productor..
		}
		dejarItemEnBuffer(item);
		itemCount++;
		if(itemCount == 1){ //Se deberìa despertar al consumidor cuando llegue a la casa matriz
			wakeup(consumidor);//despertar al consumidor
		}
	}
}
int producirItem(){

	//Generar un elemento y retornarlo
	return 0;
}
void dormirProductor(){
	//dormir...
}
void dejarItemEnBuffer(int item){
	//poner el item dentro del arreglo
}
void despertarProductor(){
	//despertar...
}
void consumidor(){
    print("Soy el hijo y estoy en el consumidor");
	//Acá debe ir la lógica del consumidor
	while(true){
		if(itemCount == 0){
			sleep();//Dormir al consumidor
		}
		item = sacarItemDelBuffer();
		itemCount--;
		if(itemCount == BUFFER_SIZE){
			wakeup(productor);//despertar al productor
		}
		consumirItem();
	}
}
void consumirItem(){

	//Quitar el elemento del BUFFER, se puede mostrar en pantalla el item consumido
}
int sacarItemDelBuffer(){
	//Quitar el elemento del buffer y retornarlo
	return 0;
}
void dormirCondumidor(){
	//dormir...
}
void despertarConsumidor(){
	//despertar...
}
