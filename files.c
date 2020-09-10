#include"files.h"

/**
 * Instanciates a new file pointer identified via its name and mode.
 * @param
 *  name (char *):
 *      Name of the file
 *  mode (char *):
 *      Mode of file to be opened {r, rb, a, ab, w, wb}
 *
 * @return FILE * opened_file.
*/

FILE * file_new(char *name, char *mode)
{
  FILE * file;

  file = fopen(name,mode);

  return file;
}


/**
 * Writes a bidimensional buffer array into a file.
 * @param
 *  file (FILE *):
 *      Storage file
 *  columns (size_t ):
 *      length of the buffer array
 *  buff [ ][columns] (long double):
 *      RAM matrix
 *  rows (size_t):
 *      width of the storage buffer
 *
 * @return void.
*/

void file_num_write(FILE * file, size_t columns, long double buff[] [columns], size_t rows)
{
  int count_rows,count_columns=0;
  
  for(count_rows = 0;count_rows < rows;count_rows++)
  {
    fprintf(file,"%.0Lf ",buff[count_rows][count_columns]);
    count_columns++;
    fprintf(file,"%Lf ",buff[count_rows][count_columns]);
    count_columns++;
    fprintf(file,"%Lf",buff[count_rows][count_columns]);

    count_columns=0;
    
    fprintf(file,"\n");
  }

  fclose(file);
}
