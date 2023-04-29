set terminal pngcairo enhanced size 640, 640
set output 'grafico.png'

set style data lines

set title "Histograma de distancia"
set xlabel "distancia del origen"
set xrange [0:85]
set ylabel "Frecuencia"
set yrange [0:7]
set grid

plot 'datos2.dat' ti 'Datos'
