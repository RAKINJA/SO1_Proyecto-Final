
#ifndef cabecera_h
#define cabecera_h

//Las estructuras que se declaracian en el main sería solamente para semáforos y recursos totales
#include<stdio.h>
#include<string.h>

//Estructura de la región crítica de un proceso
typedef struct REGIONCRITICA{
  int tiempoEntrada;
  int duracion;
  char recursoUsado[20];
  struct REGIONCRITICA *siguiente;
};

//Estructura de un proceso
typedef struct PROCESO{
  int pid;
  int uid;
  int gid;
  int tiempo;
  struct REGIONCRITICA *rc;
  struct PROCESO *siguiente;
};

//Estructura de la lista de recursos de un semáforo
typedef struct RECURSOSDISPONIBLES{
  char nombre[20];
  int disponibles;
  struct RECURSOSDISPONIBLES *siguiente;
};

//Estructura de un semáforo
typedef struct SEMAFORO{
  int semid;
  struct RECURSOSDISPONIBLES *recursos;
  struct PROCESOS *procesos;
  struct SEMAFORO *siguiente;
};

//Estructura de lista de todos los recursos
typedef struct RECURSOSTOTALES{
  int num;    //Variable para seleccion a la hora de agregar recursos a una región crítica
  char nombre[20];
  int numerosDeRecursosTotales;
  struct RECURSOSTOTALES *siguiente;
};



//Declaración de métodos

/*
        Puesto que la tabla de control de procesos incluye todos los procesos creados, entonces pasamos la lista de semaforos
        para poder recorrer la lista de procesos que contiene cada semaforo.
*/
void mostrarTablaDeContol(SEMAFORO listaSemaforos);


/*
        Este método sirve para mostrar la informacion de cada semáforo (# de semáforo, total de recursos que controla, recursos
        disponibles, procesos que maneja, Creo que también las listas de estado y los estados de los procesos en forma gráfica).
*/
void informacionDeSemaforos(SEMAFORO listaSemaforos);


/*
        Esté metodo es para agregar un recurso a la lista general.
*/
RECURSOSTOTALES agregarRecurso(RECURSOSTOTALES listaRecursos);


/*
        Esté metodo es para agregar procesos a los semáforos, contiene el método agregarALaLista.
*/
SEMAFORO agregarProceso(SEMAFORO listaSemaforos, RECURSOSTOTALES listaRecursos);



/*
        Esté metodo es para crear y añadir el proceso creado, contiene el método agregarRegionCritica.
*/
PROCESO agregarALaLista(PROCESO listaProceso, RECURSOSTOTALES listaRecursos);


/*
        Método que sirve para añadir las regiones criticas de un proceso.
*/
REGIONCRITICA agregarRegionCritica(RECURSOSTOTALES listaRecursos);

#endif