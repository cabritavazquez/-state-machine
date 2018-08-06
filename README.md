# -state-machine
 traffic light 
 
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
