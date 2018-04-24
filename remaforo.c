#include "cabecera.h"
#include <stdlib.h>

SEMAFORO* agregarSemaforo(SEMAFORO* listaSemaforos, RECURSOSTOTALES* listaRecursos){
	if(listaRecursos!=NULL){
		
		//creamos el nuevo semaforo
		SEMAFORO* nuevo=(SEMAFORO*)malloc(sizeof(SEMAFORO));
		//Inicializamos estructuras en NULL para no tener problemas con otros métodos
		nuevo->recursos=NULL;
		nuevo->procesos=NULL;
		nuevo->siguiente=NULL;
		//Pedimos el semid  verificamos que sea válido
		do{
			printf("\n\t\tIngrese el SEMID del semaforo:");
			scanf("%i",&nuevo->semid);
			if(nuevo->semid < 0) printf("\t\t\tSEMID incorrecto!\n");
		} while(nuevo->semid < 0);
		
		//Preguntamos cuantos recursos tiene y verificamos la cantidad
		int rec;
		do{
			printf("\n\t\t¿Cuantos recursos tiene? :");
			scanf("%i",&rec);
			if(rec <= 0) printf("\t\t\tCantidad de recursos invalida!");
		} while(rec <= 0);
		for(int i=0;i<rec;i++){
			nuevo->recursos = agregarRecursosDisponibles(nuevo,listaRecursos);
		}
	}else{
		printf("\n\t\t\tSin recursos!\n");
	}
	return listaSemaforos;
}


SEMAFORO* agregarProceso(SEMAFORO* listaSemaforos){
	//verificamos que haya semaforos a los cuales agregar procesos
	if(listaSemaforos!=NULL){
		SEMAFORO* aux=listaSemaforos;
		//verificamos si hay un solo semaforo
		if(listaSemaforos->siguiente!=NULL){
			//Como hay mas de un semaforo, entonces pedimos a cual semaforo queremos agregar el proceso
			printf("\tSemaforos:\n");
			while(aux!=NULL){
				printf("%i\t",aux->semid);
				aux=aux->siguiente;
			}
			
			int semid,ban=1;
			do{
				printf("\t\t¿A cual semaforo desea agregar el proceso? :");
				scanf("%i",&semid);
				aux=listaSemaforos;
				while(aux!=NULL){
					if(semid==aux->semid){ ban=0; break;}
					aux=aux->siguiente;
				}
				if(ban!=0) printf("\n\t\t\tSemaforo no encontrado!\n");
			} while(ban!=0);
			
		}
		aux->procesos=agregarALaLista(listaSemaforos,aux);
	}else{
		printf("\n\t\t\tSin semaforos!\n");
	}
	return listaSemaforos;
}
