#  PREGUNTA 1A:
#  copiar y pegar comando en terminal:

	tail -n +9 datos.dat | awk '$2 ~ /1/ {SUMA++} $2 ~ /2/ {SUM++} END {print "partículas tipo 1:", SUMA, "\npartículas tipo 2:", SUM}'

------------------------------------------------------------
#  PREGUNTA 1B:

#  Para ejecutar el script "pregunta_1b.awk" tipear en terminal el siguiente comando:

	awk -f pregunta_1b.awk datos.dat

------------------------------------------------------------
#  PREGUNTA 1C:
#  Para ejecutar el archivo "pregunta1c.c" tipear en terminal el siguiente comando:

	make run

#  Salida por terminal esperada: datos de distancia máxima y mínima al origen. 
#  se genera un archivo ("datos2.dat") con los datos para elaboración del  histograma, 
#  y otro archivo con el Histograma de distancias al origen de las coordenadas ("grafico.png")
