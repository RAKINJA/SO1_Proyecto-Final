REGIONCRITICA agregarRegionCritica(SEMAFORO actual, PROCESO creado){
	//Creamos el recurso que requiere el proceso
	REGIONCRITICA nuevo=(REGIONCRITICA)malloc(sizeof(REGIONCRITICA));
	nuevo->siguiente=NULL;
	//pedimos el tiempo donde inicia el proceso
	do{
		printf("\n\t\t¿En qué tiempo inicia la región? : ");
		scanf("%i",&nuevo->tiempoEntrada);
		if(nuevo->tiempoEntrada < 0) printf("\n\t\t\tTiempo erroneo!\n");
	} while(nuevo->tiempoEntrada < 0);
	//Pedimos la duracion que tiene la región Critica
	do{
		printf("\n\t\t¿Cual es la duracion de ejecucion? : ");
		scanf("%i",&nuevo->duracion);
		if(nuevo->duracion < 0) printf("\n\t\t\tTiempo erroneo!\n");
	} while(nuevo->duracion < 0);	
	//hacemos la selecion del recurso que tiene la zona Critica
	RECURSOSDISPONIBLES aux;
	int ban=1;
	do{
		printf("\n\t\t¿A que recurso quiere accesar?: ");
		aux=actual->recursos;
		while(aux!=NULL){
			printf("%s\t",aux->nombre);
			aux=aux->siguiente;
		}
		scanf("%s",nuevo->recursoUsado);
		
		aux=actual->recursos;
		while(aux!=NULL){
			if(strcmp(aux->nombre,nuevo->recursoUsado)==0){	ban=0; break;}	
			aux=aux->siguiente;
		}
		if(ban!=0) printf("\n\t\t\tRecurso no encontrado!\n");
	}while(ban!=0);
	//Agregamos la region critica a la lista de region critica del proceso
	if(creado->rc==NULL){
		creado->rc=nuevo;
	}else{
		REGIONCRITICA rec=creado->rc;
		while(rec->siguiente!=NULL){
			rec=rec->siguiente;
		}
		rec->siguiente=nuevo;
	}
	return creado->rc;
}
