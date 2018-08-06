/* 
Se	trata	de	hacer	el	sistema	de	control	de	un	semáforo	inteligente instalado	en	un	cruce
que	atiende	peticiones	de	peatones	en	el	propio	semáforo	y,	además,	tiene	un	detector	
de	tráfico	en	una	calle	transversal.

La	descripción	de	funcionamiento	sería	la	siguiente.	Inicialmente,	el	semáforo	está	en	
estado	VERDE1.	En	este	estado	permanece	hasta	un	máximo	de	2	minutos	hasta	pasar	
al	estado VERDE2.	Si	durante	este	tiempo	llega	bien	una	señal	de	que	hay	un	peatón	
esperando	 (SIGUSR1)	 o	 que	 hay	 tráfico	 intenso	 en	 el	 cruce	 (SIGUSR2),	 se	 pasa	
directamente	a	VERDE2.	En	el	estado	VERDE2	está durante	10	segundos,	tiempo	tras	el	
que	se	pasa	al	estado	AMBAR.	Ahí	se	está	durante	15	segundos	antes	de	pasar	a	ROJO,	
donde	 se	 permanece	 durante	 45	 segundos. Estando	en	VERDE2,	AMBAR	 o	 ROJO,	las	
señales	de	peatón	y	tráfico	no	se	tienen	en	cuenta:	se	permanece	en	el	mismo	estado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// DEFINIMOS LOS ESTADOS
#define VERDE1 1
#define VERDE2 2
#define AMBAR 3
#define ROJO 4

// DEFINIMOS LOS EVENTOS 
#define USR 1
#define TIME 2

// DECLARAMOS LAS VARIABLES
int estado = VERDE1;
int evento = 0;

// REGISTRAMOS MANEJADORES

void time (int sig){
	evento = TIME;
	signal(sig,time);
}
void usr (int sig){
	evento = USR;
	estado = VERDE2;
	signal(sig,usr);
}

int main (){
	printf("-------EMPEZAMOS CON EL SEMAFORO------\n");
	printf("PID -> %d\n",getpid());
	signal(SIGALRM,time);
	
	while(1){
		switch (estado){
			case VERDE1 :
				signal(SIGUSR1,usr);
				signal(SIGUSR2,usr);
				printf("ESTADO -> VERDE1\n");
				alarm(10);
				pause();

				switch (evento){
					case USR:
						evento = 0;
						estado = VERDE2;
					break;
					case TIME:
						evento = 0;
						estado = VERDE2;
					break;
				}
				break;
			case VERDE2 :
				signal(SIGUSR1,SIG_IGN);
				signal(SIGUSR2,SIG_IGN);
				printf("ESTADO -> VERDE2\n");

				alarm(3);
				pause();

				switch (evento){
					case USR:
						evento = 0;
					break;
					case TIME:
						evento = 0;
						estado = AMBAR;
					break;
				}
				break;				
			case AMBAR :
				printf("ESTADO -> AMBAR\n");
				signal(SIGUSR1,SIG_IGN);
				signal(SIGUSR2,SIG_IGN);
				alarm(3);
				pause();
				switch (evento){
					case USR:
						evento = 0;
					break;
					case TIME:
						evento = 0;
						estado = ROJO;
					break;
				}
				break;
			case ROJO :
				printf("ESTADO -> ROJO\n");
				signal(SIGUSR1,SIG_IGN);
				signal(SIGUSR2,SIG_IGN);
				alarm(5);
				pause();
				switch (evento){
					case USR:
						evento = 0;
					break;
					case TIME:
						evento = 0;
						estado = VERDE1;
					break;
				}
			break;	
		}
		
	}
	return 0;
}
