
#ifndef cabecera_h
#define cabecera_h

//Las estructuras que se declaracian en el main sería solamente para semáforos y recursos totales
#include<stdio.h>
#include<string.h>

//Estructura de la región crítica de un proceso
typedef struct regioncritica{
  int tiempoEntrada;
  int duracion;
  char recursoUsado[20];
  struct regioncritica *siguiente;
} REGIONCRITICA;

//Estructura de un proceso
typedef struct proceso{
  int pid;
  int uid;
  int gid;
  int tiempo;
  struct REGIONCRITICA *rc;
  struct proceso *siguiente;
} PROCESO;

//Estructura de la lista de recursos de un semáforo
typedef struct recursodisponible{
  char nombre[20];
  int disponibles;
  struct recurso *siguiente;
} RECURSOSDISPONIBLES;

//Estructura de un semáforo
typedef struct semaforo{
  int semid;
  RECURSOSDISPONIBLES* recursos;
  struct proceso* procesos;
  struct semaforo* siguiente;
} SEMAFORO;

//Estructura de lista de todos los recursos
typedef struct recursototal{
  int num;    //Variable para seleccion a la hora de agregar recursos a una región crítica
  char nombre[20];
  int numerosDeRecursosTotales;
  struct recursototal *siguiente;
} RECURSOSTOTALES;



//Declaración de métodos

/*
        Puesto que la tabla de control de procesos incluye todos los procesos creados, entonces pasamos la lista de semaforos
        para poder recorrer la lista de procesos que contiene cada semaforo.
*/
void mostrarTablaDeContol(SEMAFORO* listaSemaforos);


/*
        Este método sirve para mostrar la informacion de cada semáforo (# de semáforo, total de recursos que controla, recursos
        disponibles, procesos que maneja, Creo que también las listas de estado y los estados de los procesos en forma gráfica).
*/
void informacionDeSemaforos(SEMAFORO* listaSemaforos);


/*
        Esté metodo es para agregar un recurso a la lista general.
*/
RECURSOSTOTALES* agregarRecurso(RECURSOSTOTALES* listaRecursos);


/*
        Esté metodo es para agregar procesos a los semáforos, contiene el método agregarALaLista.
*/
SEMAFORO* agregarSemaforo(SEMAFORO* listaSemaforos, RECURSOSTOTALES* listaRecursos);



/*
        Esté metodo es para crear y añadir el proceso creado, contiene el método agregarRegionCritica.
*/
PROCESO* agregarALaLista(SEMAFORO* cabeza, SEMAFORO* actual);
//PROCESO* agregarALaLista(PROCESO* listaProceso, RECURSOSTOTALES* listaRecursos);
RECURSOSDISPONIBLES* agregarRecursosDisponibles( SEMAFORO* nuevo, RECURSOSTOTALES* listaRecursos);

/*
        Método que sirve para añadir las regiones criticas de un proceso.
*/
REGIONCRITICA* agregarRegionCritica(SEMAFORO actual, PROCESO creado);

#endif