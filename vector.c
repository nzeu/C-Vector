#include <stdlib.h>
#include <string.h>
#include "vector.h"

Vector *vec_new(size_t type_size) {
    Vector *vec = malloc(sizeof(Vector));
    if (NULL == vec) { 
	return NULL; }
    vec->length = 0;
    vec->size = type_size;
    return vec;
}

Vector *vec_init(size_t type_size, const void* data, const int init_length) {
    Vector *vec = malloc(sizeof(Vector));
    if (NULL == vec) {
	return NULL; }
    vec->length = init_length;
    vec->size = type_size;
    vec->arr = malloc(type_size*init_length);
    memcpy(vec->arr, data, type_size*init_length);
    return vec;
}

void vec_free(Vector *vec) {
    free(vec->arr);
    free(vec);
}

void *vec_void(Vector *vec, unsigned int index) {
    return (void*)((char*)vec->arr+index*vec->size);
}

void *vec_arr(Vector *vec) { return vec->arr; }
unsigned int vec_length(Vector *vec) { return vec->length; }
size_t vec_size(Vector *vec) { return vec->size; }
size_t vec_sizeof(Vector *vec) { return vec->size*vec->length; }

void vec_push_back(Vector *vec, const void *data) {
    if (vec->length > 0) {
	void *tmp = realloc(vec->arr, vec->size * (vec->length+1));
	if (NULL == tmp) { 
	    fprintf(stderr, "Failed to realocate memory in push_back\n"); 
	    return;
	}
	vec->arr = tmp;

	memcpy((void*)((char*)vec->arr+vec->length*vec->size),
		data, vec->size);
	vec->length++;
	return;
    }
    vec->arr = malloc(vec->size);
    if (NULL == vec->arr) { 
	return; }
    memcpy(vec->arr, data, vec->size);
    vec->length++;
    return;
}

void vec_push_buff(Vector *vec, const void *data, unsigned int num) {
    if (vec->length > 0) {
	void *tmp = realloc(vec->arr, vec->size * (vec->length+num));
	if (NULL == tmp) { 
	    return; }
	vec->arr = tmp;

	memcpy((void*)((char*)vec->arr+vec->length*vec->size),
		data, vec->size*num);
	vec->length += num;
	return;
    }
    vec->arr = malloc(vec->size*num);
    if (NULL == vec->arr) { 
	return; }
    memcpy(vec->arr, data, vec->size*num);
    vec->length += num;
    return;
}

void vec_pop_back(Vector *vec) {
    void *tmp = realloc(vec->arr, vec->size*(vec->length-1));
    if (NULL == tmp) {
	return; }
    vec->arr = tmp;
    vec->length--;
    return;
}

void vec_pop_buff(Vector *vec, unsigned int num) {
    void *tmp = realloc(vec->arr, vec->size*(vec->length-num));
    if (NULL == tmp) {
	return; }
    vec->arr = tmp;
    vec->length -= num;
    return;
}

void vec_resize(Vector *vec, unsigned int new_length) {
    void *tmp = realloc(vec->arr, new_length);
    if (NULL == tmp) {
	return; }
    vec->arr = tmp;
    vec->length = new_length;
    return;
}

void vec_insert(Vector *vec, const void *data,unsigned int index) {
    void *tmp = realloc(vec->arr, vec->length*vec->size+vec->size);
    if (NULL == tmp){
	return; }
    vec->arr = tmp;
    vec->length++;
    /* oh my fucking god... i have to thank C for the pointer
     * artithmetic syntax
     */
    memcpy((void*)((char*)vec->arr+(index*vec->size+vec->size)), 
	    (void*)((char*)vec->arr+index*vec->size), 
	    (vec->length-index)*vec->size);
    memcpy((void*)((char*)vec->arr+index*vec->size), 
	    data, vec->size);
    return; 
}

void vec_insert_buff(Vector *vec, const void *data, unsigned int index,unsigned int num) {
    void *tmp = realloc(vec->arr, vec->length*vec->size+vec->size*num);
    if (NULL == tmp) {
	return; }
    vec->arr = tmp;
    vec->length += num;
    
    memcpy((void*)((char*)vec->arr+(index*vec->size+vec->size*num)),
	  (void*)((char*)vec->arr+index*vec->size),
	  (vec->length-index)*vec->size);
    memcpy((void*)((char*)vec->arr+index*vec->size),
	    data, vec->size*num);
    return;
}

void vec_delete(Vector *vec, unsigned int index) {
    memcpy((void*)((char*)vec->arr+index*vec->size), 
	    (void*)((char*)vec->arr+index*vec->size+vec->size), 
	    (vec->length-index-1)*vec->size);
    void *tmp = realloc(vec->arr, vec->size*vec->length-vec->size);
    if (NULL == tmp) {
	return; }
    vec->arr == tmp;
    vec->length--;
    return; 
}

void vec_delete_buff(Vector *vec, unsigned int index, unsigned int num) {
    memcpy((void*)((char*)vec->arr+index*vec->size), 
	    (void*)((char*)vec->arr+index*vec->size+vec->size*num), 
	    (vec->length-index-1-num)*vec->size);
    void *tmp = realloc(vec->arr, vec->size*vec->length-vec->size*num);
    if (NULL == tmp) {
	return; }
    vec->arr == tmp;
    vec->length -= num;
    return; 
}

void vec_set(Vector *vec, void *data, unsigned int index) {
    memcpy(vec->arr+vec->size*index, data, 1);
    return;
}

