#ifndef DATABASE_H
#define DATABASE_H

#include "../db_types.h"
#include <stdbool.h>

#define LOAD_SUCCESS 0
#define LOAD_FAILURE 1

#define INVALID_HEADER 0xee
#define VALID_HEADER 0x1

static int _read_header (FILE * database_file, header_t header);
static int _write_header (char *db_buffer, header_t * header);


void update_database (char *db_buffer, header_t * header);


int load_database (int byte_offset, char *db_buffer, FILE * database);
void unload_database (char *db_buffer);



#endif /* DATABASE_H */
