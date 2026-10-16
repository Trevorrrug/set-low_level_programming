# Hash Tables

This project implements a string-keyed hash table using the djb2 hash function
and separate chaining to resolve collisions. It also includes a sorted variant
that keeps bucket chains for lookup and a doubly linked list for ascending and
descending key traversal.

## Files

- `0-hash_table_create.c`: allocate and initialize a hash table.
- `1-djb2.c`: compute a key hash with djb2.
- `2-key_index.c`: map a key hash to a bucket index.
- `3-hash_table_set.c`: add or update a key/value pair.
- `4-hash_table_get.c`: find a value by key.
- `5-hash_table_print.c`: print entries in array and bucket-list order.
- `6-hash_table_delete.c`: free all entries and the table.
- `100-sorted_hash_table.c`: create, update, retrieve, print, and delete a
  hash table with sorted key traversal.

Include `hash_tables.h` when using the public types and functions.
