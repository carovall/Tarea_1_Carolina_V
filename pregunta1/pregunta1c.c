#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float maximo(float distancia[500]);
float minimo(float distancia[500]);
void imprimirHistograma(int *histograma, float num_cuadros, float min, float ancho_cuadros);

int main(int argc, char *argv[]) {

   FILE *archivo = fopen("datos.dat", "r");

   // El archivo será leído linea a linea
   char string[1024]; // variable para alojar cada linea del archivo
   char *token = NULL; // Definimos para separar columnas de la linea
   int num_lineas= 500; // total de lineas
   // Definir arrays para guardar informacion de las posiciones
   float x_posicion[500]={0};
   float y_posicion[500]={0};
   float z_posicion[500]={0};
   float distancia[500]={0};

   // leer primeras 9 lineas
   for (int i=0; i<9; ++i) {
      fgets(string, 1024, archivo); //lee hasta que termine la linea y se lo asigna a string
   }
   for (int i=0; i<num_lineas; ++i) {
      fgets(string,1024, archivo);
      token = strtok(string, " ");
      for (int j = 0; j<8; j++){
        token = strtok(NULL, " ");
        if (j==1){
           x_posicion[i] = atof(token);
       }
        if (j==2){
           y_posicion[i] = atof(token);
       }
        if (j==3){
           z_posicion[i] = atof(token);
       }
     }
   }
   fclose(archivo);

   for(int i=0; i<500; ++i){ // calculo distancia del origen
     distancia[i]=sqrt((x_posicion[i])*(x_posicion[i])+(y_posicion[i])*(y_posicion[i])+(z_posicion[i])*(z_posicion[i]));
     //printf("%f\n", distancia[i]);
   }

   float max = maximo(distancia);
   float min = minimo(distancia);
   printf("Maximo : %f\n" , maximo(distancia));
   printf("Minimo : %f\n" , minimo(distancia));

   float ancho_cuadros = 0.1; // calculado para numero de cuadros entre 50 y 1000
   float num_cuadros = (max - min +1)/ancho_cuadros;

   int *histograma = malloc(sizeof(int)* num_cuadros);
   for (int i=0; i<num_cuadros; ++i){
      histograma[i] = 0;
   }

   // Barras del histograma
   for (int i=0; i<num_cuadros; ++i){
      for (int j=0; j<num_lineas; ++j){ // si la distancia esta en el rago le agregamos +1 a esa barra
        if (min-0.05+i*ancho_cuadros <= distancia[j] && distancia[j] <= min+0.04+i*ancho_cuadros){
          histograma[i]++;
         }
      }
    }
   imprimirHistograma(histograma, num_cuadros, min, ancho_cuadros);
   free(histograma);

   return 0;
}

float maximo(float distancia[500]){
   float max = distancia[0];
   for(int i=0; i<500 ; ++i) {
     if(max < distancia[i]){
       max = distancia[i];
     }
   }
   return max;
}

float minimo(float distancia[500]){
   float min = distancia[0];
   for(int i=0; i<500 ; ++i) {
     if(min > distancia[i]){
       min = distancia[i];
     }
   }
   return min;
}

void imprimirHistograma(int *histograma, float num_cuadros, float min, float ancho_cuadros){
   FILE *archivo = fopen("datos2.dat", "w");
   for (int i=0; i<num_cuadros; ++i){
     fprintf(archivo, "%0.1f %d\n", min+i*ancho_cuadros, histograma[i]);
    }
   fclose(archivo);
}
