#include <stdio.h>

int main(){
   int a = 1; //tamaño lado de cada cuadrado
   int v = 9; // vertices por lado
   int n = v*v; // numero de particulas

   int posicion[n][2]; //array Nx2 para almacenar posiciones
   int indice=0; //inicializar indice

   for(int i=0; i<v; i++){ //rellenar array 
      for(int j=0; j<v; j++){
         posicion[indice][0]=i*a;
         posicion[indice][1]=j*a;
         indice=indice+1;
      }
   }

   for(int i=0; i<n; i++){ //imprimir resultados
      printf("Coordenadas partícula # %d: (%d,%d)\n", i+1, posicion[i][0], posicion[i][1]);
   }

   return 0;
}
