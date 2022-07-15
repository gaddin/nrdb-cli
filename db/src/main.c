#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "utils/db_cli.h"
#include "db_types.h"
#include "utils/db_header.h"


int
main (int argc, char **argv)
{


  offset_list_t offset[MAX_DATA_BASES];

  FILE *database_file = NULL;

  uint8_t *list_buffer = NULL;
  char *database_buffer = NULL;

  int database_selector = 0;


  if (argc < 2)
    printf ("usage:\tdb <database>"), exit (EXIT_FAILURE);

  database_file = fopen (argv[1], "+r");

  if (database_file == NULL)
    printf ("error opening database\n"), exit (EXIT_FAILURE);

  if (load_database
      (offset[database_selector], database_buffer,
       database_file) == LOAD_FAILURE)
    exit (EXIT_FAILURE);


  unload_database (data_base_buffer);

  fclose (database);


  exit (EXIT_SUCCESS);

}
