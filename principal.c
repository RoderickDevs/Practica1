#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#include"Sequences.h"
#include"files.h"

#define AMOUNT 30
#define INDEX 0
#define ITERATIVE 1
#define RECURSIVE 2
#define STATISTIC 1000.0
#define COLUMNS 3

int main(void)
{
  long long int number;
  size_t index;
  long long int result = 0;
  clock_t start, stop;
  double cpu_time = 0;
  size_t statistic = 0;

  long double buffer_matrix[AMOUNT][COLUMNS] = {0};

  FILE * Archivo = NULL;

  Archivo = file_new("TIME_FIBONACCI.dat","w");

  for(index = 0;index < AMOUNT;index++)
    {
      printf("%zu\n",index+1);
        
      /*Realizamos el calculo iterativamente*/
      start = clock();
      for (statistic = 0; statistic < STATISTIC; statistic ++){
	result = Sequences_sfibo(index);
      
      }
      stop = clock();
      printf("Result: %lld ", result);

      cpu_time = ((double)(stop-start)) / CLOCKS_PER_SEC/STATISTIC;

      /*Guardamos el los valores en la matriz*/
      buffer_matrix[index][INDEX] = index;
      buffer_matrix[index][ITERATIVE] = cpu_time*1e3;

      printf("\nSequential Fibo Time: %f ms\n",cpu_time*1e3);


      /*Realizamos el calculo recursivamente*/
      start = clock();
      Sequences_rfibo(index);
      stop = clock();

      cpu_time = ((double)(stop-start))/CLOCKS_PER_SEC;

      /*Guardamos el los valores en la matriz*/
      buffer_matrix[index][RECURSIVE] = cpu_time;
        
      printf("Recursive Fibo Time: %f s\n",cpu_time);

      printf("\n\n");
        
    }

  /*Para terminar, llamamos a nuestra funcion que escribira la matriz en el archivo.*/
  file_num_write(Archivo,COLUMNS,buffer_matrix,AMOUNT);

  printf("\n");

  return 0;
        
}
