#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#include "database.h"

uint64_t current_offset;    // we keep this global variable to ourselves so the user doesn't need
                            // to worry about where in memory he/she should be.

static int _read_header(FILE *database_file, header_t header)
{
    int size;
    uint8_t check_signature;
    uint64_t size_of_database;
    uint64_t member_count;

    fread(check_signature, 1, 1, database_file);
    
    if( check_signature != HEADER_SIGNATURE )
        printf("invalid signature"), return INVALID_HEADER;
    
    // load the header info from the file into the buffer
    fread(header.size_of_database, sizeof uint64_t, 1, database_file);
    fread(header.member_count, sizeof uint64_t, 1, database_file);
    fread(header.sizes, sizeof uint128_t, 1, database_file); 
    
    return VALID_HEADER;
}


static int _write_header(int byte_offset, char *db_buffer, header_t header)
{
    
}


void update_database(char *db_buffer, header_t *header)
{
    
}


int load_database(int byte_offset, char *db_buffer, FILE *database_file)
{
    int file_size = 0;
    header_t header;

    fseek(database_file, 0, SEEK_END);
    file_size = ftell(database_file);
    rewind(database);


    if(byte_offset > file_size)
        printf("invalid database offset\n"), return LOAD_FAILURE;
    
    fseek(database_file, byte_offset, SEEK_SET);

    if(_read_header(database_file, &header) == INVALID_HEADER)
        printf("invalid header\n"), return LOAD_FAILURE;
    
    // load the database into memory
    fread(db_buffer, 1, header.size_of_database, dababase_file);
    
    return LOAD_SUCCESS;
}


void unload_database(char *db_buffer, FILE *database_file)
{
    free(db_buffer);
    db_buffer = NULL;
}
