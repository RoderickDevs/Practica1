#include<time.h>

#include"Sequences.h"
#include"files.h"

#define AMOUNT 45

#define INDEX 0
#define ITERATIVE 1
#define RECURSIVE 2

int main(void)
{
  long long int number;
  size_t index;
  clock_t start, stop;
  double cpu_time = 0;

  long double buffer_matrix[AMOUNT][3] = {0};

  FILE * Archivo = NULL;

  Archivo = file_new("TIME_FIBONACCI.dat","w");

  for(index = 0;index < AMOUNT;index++)
  {
    printf("%zu\n",index+1);
    
    /*Realizamos el calculo iterativamente*/
    start = clock();
    Sequences_sfibo(index);
    stop = clock();

    cpu_time = ((double)(stop-start))/CLOCKS_PER_SEC;

    /*Guardamos el los valores en la matriz*/
    buffer_matrix[index][INDEX] = index;
    buffer_matrix[index][ITERATIVE] = cpu_time*1e3;

    printf("Sequential Fibo Time: %f ms\n",cpu_time*1e3);


    /*Realizamos el calculo recursivamente*/
    start = clock();
    number = Sequences_rfibo(index);
    stop = clock();

    cpu_time = ((double)(stop-start))/CLOCKS_PER_SEC;

    /*Guardamos el los valores en la matriz*/
    buffer_matrix[index][RECURSIVE] = cpu_time;
    
    printf("Recursive Fibo Time: %f s\n",cpu_time);

    printf("\n\n");
    
  }

  /*Para terminar, llamamos a nuestra funcion que escribira la matriz en el archivo.*/
  file_num_write(Archivo,3,buffer_matrix,AMOUNT);

  printf("\n");

  return 0;
}
