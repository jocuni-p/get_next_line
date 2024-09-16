# get_next_line

La funcion get_next_line lee, una linea a cada llamada, hasta llegar al final del archivo al que apunta el "file descriptor". La linea devuelta termina con el caracter '\n' excepto si se llego al final y este no termina en '\n'. Si no hay nada mas que leer o ocurrio un error devuelve "NULL". 
Toma como argumento un fd (file descriptor).
