#include <stdio.h>
#include <stdlib.h>

#ifndef VECTOR_H
#define VECTOR_H

/* if anyone ever has an alternative, tell me cause this is ugly as shit, i hate it */
#define vec_at(vec, type, index) (vec_length(vec)-1 >= index) ? (*(type *)((char *)vec_arr(vec)+(sizeof(type)*index))) : (fprintf(stderr, "vec_at: Index out of range\n"))

typedef struct {
    void *arr;
    unsigned int length;
    size_t size;
}Vector;

Vector *vec_new(size_t type_size);
/*
 * DO NOT give length of zero
 * behavior would be left to malloc
 * DO NOT pass a NULL pointer for data
 * instead use vec_new() for empty Vector
 */
Vector *vec_init(size_t type_size, const void *data, const int length);

void vec_free(Vector *vec);

void *vec_void(Vector *vec, unsigned int index);

void* vec_arr(Vector *vec);
unsigned int vec_length(Vector *vec);
size_t vec_size(Vector *vec);
size_t vec_sizeof(Vector *vec);

void vec_push_back(Vector *vec, const void *data);
void vec_push_buff(Vector *vec, const void *data, unsigned int num);

/* 
 * DO NOT use on vector of length 1
 * instead use vec_free
 * to remove the vector
 */
void vec_pop_back(Vector *vec);
void vec_pop_buff(Vector *vec, unsigned int num);

void vec_resize(Vector *vec, unsigned int new_length);

void vec_insert(Vector *vec, const void *data,unsigned int index);
void vec_insert_buff(Vector *vec, const void *data, unsigned int index, unsigned int num);

//gotta do vec_delete_buff
/* to delete the last element
 * use pop_back
 */
void vec_delete(Vector *vec, unsigned int index);
void vec_delete_buff(Vector *vec, unsigned intindex, unsigned int num);

void vec_set(Vector *vec, void *data, unsigned int index);

#endif
