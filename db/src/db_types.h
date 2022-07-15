#ifndef DB_TYPES_H
#define DB_TYPES_H

#define MAX_DATA_BASES 0xff
#define HEADER_SIGNATURE 0xdb


typedef uint64_t offset_list_t;

typedef unsigned int uint128_t __attribute__((mode (TI));
typedef uint128_t entry_sizes_t;

typedef struct
{
  const uint8_t signature =
  HEADER_SIGNATURE;
  uint64_t size_of_database;
  uint16_t member_count;
  entry_sizes_t sizes;
}
__attribute__((packed)) header_t;

#endif /* DB_TYPES_H */
