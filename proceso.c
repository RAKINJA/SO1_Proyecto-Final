PROCESO agregarALaLista(SEMAFORO cabeza, SEMAFORO actual){
	//Creamos el nuevo proceso
	PROCESO nuevo=(PROCESO)malloc(sizeof(PROCESO));
	//inicializamos variables en NULL para que no afecten otros metodo
	nuevo->rc=NULL;
	nuevo->siguiente=NULL;
	//Pedimos el pid y verificamos si es repetido
	int ban;
	do{
		ban=0;
		printf("\n\t\tIngrese el PID: ");
		scanf("%i",&nuevo->pid);
		SEMAFORO auxS=cabeza;
		while(auxS!=NULL){
			PROCESO auxP=auxS->procesos;
			while(auxP!=NULL){
				if(nuevo->pid == auxP->pid){
					ban=1;
					break;
				}
				auxP=auxP->siguiente;
			}
			if(ban==1) break;
			auxS=auxS->siguiente;
		}
		if(ban==1)	printf("\n\t\t\tPID repetido!\n");
		
	} while(ban!=0);
	//Pedimos usuario
	//pedimos grupo
	//Pedimos tiempo y lo válidamos
	do{
		printf("\t\tIngrese el tiempo:");
		scanf("%i",&nuevo->tiempo);
		if(nuevo->tiempo<=0) printf("\n\t\t\tTiempo erroneo!\n");
	} while(nuevo->tiempo<=0);
	//Preguntamos si tiene region crítica
	int opc;
	do{
		printf("\t\t¿Tiene region critica? 0)Si. 1)No.");
		scanf("%i",&opc);
		if(opc == 0){
			int t;
			do{
				printf("\t\t¿Cuantas regiones tiene? :");
				scanf("%i",&t);
				if(t<=0) printf("\n\t\t\tRegiones criticas erroneas!");
			} while(t<=0);
			
			for(int i=0;i<t;i++){
				nuevo->rc=agregarRegionCritica(actual,nuevo);
			}
		}
		if(opc == 1){
			nuevo->rc=NULL;
		}
		if((opc<0) || (opc >1)) printf("\n\t\t\tOpción incorrecta!\n");
	} while((opc<0) || (opc >1));
	
	//Asignamos el proceso a la lista de procesos
	if(actual->procesos==NULL){
		actual->procesos=nuevo;
	}else{
		PROCESO auxP=actual->procesos;
		while(auxP->siguiente!=NULL){
			auxP=auxP->siguiente;
		}
		auxP->siguiente=nuevo;
	}
	return actual->procesos;
}
