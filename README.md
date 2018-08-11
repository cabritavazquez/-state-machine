# -state-machine
 traffic light 

///////////////////////////////////////////////////////////////////////////////////////////

Para hacerla funcionar valdrá con ejecutar el codigo en un terminal y para mandarle las 
señales SIGUSR1 y SIGUSR2 tendremos que abrir otro terminal y ejercutar el siguiente
codigo:
       
       
       > kill -s SIGUSR1 <PID del ejecutable>   // Para la señal SIGUSR1
 
 
       > kill -s SIGUSR2 <PID del ejecutable>   // Para la señal SIGUSR2
 
 ///////////////////////////////////////////////////////////////////////////////////////////
