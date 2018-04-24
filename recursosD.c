RECURSOSDISPONIBLES agregarRecursosDisponibles(SEMAFORO actual, RECURSOSTOTALES listaRecursos){
	//Creamos el contenedor donde estará el recurso
	RECURSOSDISPONIBLES nuevo=(RECURSOSDISPONIBLES)malloc(sizeof(RECURSOSDISPONIBLES));
	nuevo->siguiente=NULL;
	//Mostramos los recursos que hay en total
	RECURSOSTOTALES aux=listaRecursos;
	while(aux!=NULL){
		printf("%i)%s\n",aux->num,aux->nombre);
		aux=aux->siguiente;
	}
	
	//Seleccion de recurso
	int op,ban=1;
	do{
		printf("\n\t\tSeleccione la opcion del recurso quiere agregar :");
		scanf("%i",&op);
		aux=listaRecursos;
		while(aux!=NULL){
			if(aux->num == op){ ban=0; break;}
			aux=aux->siguiente;
		}
	} while(ban!=0);
	
	//Cuanto se va a utilizar de ese recursos
	int utilizado;
	do{
		printf("\n\t\t¿Cuanto recursos usará del total?");
		scanf("%i",&utilizado);
		if((aux->numerosDeRecursosTotales - utilizado) >=0)	break;
		if((aux->numerosDeRecursosTotales - utilizado) <0) printf("\n\t\t\tValor erroneo!\n");
	} while(1==1);
	//descontamos el total de recursos que usará y asignamos los valores de los recursos del semaforo
	aux->numerosDeRecursosTotales=aux->numerosDeRecursosTotales-utilizado;
	strcpy(nuevo->nombre,aux->nombre);
	nuevo->disponibles=utilizado;
	
	//Agregamos al semaforo
	if(actual->recursos == NULL){
		//Agregamos el recurso a la cabeza
		actual->recursos=nuevo;
	}else{
		//Agregamos el recurso a la lista
		RECURSOSDISPONIBLES rec=actual->recursos;
		while(rec->siguiente != NULL){
			rec=rec->siguiente;
		}
		rec->siguiente=nuevo;
	}
	
	return actual->recursos;
}
