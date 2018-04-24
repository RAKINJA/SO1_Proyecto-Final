#include "cabecera.h"
#include <stdlib.h>

RECURSOSTOTALES* agregarRecursos(RECURSOSTOTALES* listaRecursos){
	//creamos un nuevo recurso y le asignamos a siguiente NULL
	RECURSOSTOTALES* nuevo=(RECURSOSTOTALES*)malloc(sizeof(RECURSOSTOTALES));
	nuevo->siguiente=NULL;
	
	//aux nos ayuda a hacer el recorrido
	//ban sirve para saber si no está repetido, si es cero si no está repetido, uno si lo está
	RECURSOSTOTALES* aux=listaRecursos;
	int ban=0;
	//Pedimos el nombre del recurso y verificamos si no está repetido
	do{
		
		printf("\n\t\tIngrese nombre del recurso:");
		scanf("%s",nuevo->nombre);
		aux=listaRecursos;
		if(listaRecursos==NULL) break;
		while(aux!=NULL){
			
			if(strcmp(nuevo->nombre,aux->nombre)==0){
				ban=1;
				break;
			}
			aux=aux->siguiente;
			
		}
		if(ban==1) printf("\t\t\t\tNombre de recurso repetido!\n");
		
	} while(ban!=0);
	
	//Pediremos la cantidad de recursos totales y verificaremos dicha cantidad
	do{
		printf("\n\t\tIngrese la cantidad de recursos que tiene:");
		scanf("%i",&nuevo->numerosDeRecursosTotales);
		if(nuevo->numerosDeRecursosTotales <=0 ) printf("\t\t\tcantidad erronea!\n");
	} while(nuevo->numerosDeRecursosTotales <= 0);
	
	
	//agregaremos el nuevo recurso creado a la lista global de recursos
	if(listaRecursos == NULL){
		nuevo->num=0;
		listaRecursos=nuevo;
	}else{
		aux=listaRecursos;
		int contador=1;
		while(aux->siguiente!=NULL){
			contador++;
			aux=aux->siguiente;
		}
		aux->siguiente=nuevo;
	}
	
	return listaRecursos;
}
