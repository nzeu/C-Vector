# C-Vector

A dynamic array library in C. Similar to std::vector.

## Example code (dosen't use all features, see header file)

```
//an array of values to initialize the vector with  
int *x = {4, 5, 6};  
int *z = {46, 343, 345, 334, 666, 9987, 776};  
int y = 45;  
//vec_init to initialize with values, vec_new for empty  
Vector *vec = vec_init(sizeof(int), x, 3);  
//add stuff to end of array with either push_buff or push_back for one element  
vec_push_buff(vec, z, 7);  
vec_push_back(vec, &y);  
//remove with pop_buff or pop_back, same logic for all the functions that can  
vec_pop_buff(vec, 4);  
vec_pop_back(vec);  
//delete an element with delete, same logic again  
vec_delete_buff(vec, 1, 2);  
vec_delete(vec, 1);  
//insert in the vector with vec_insert, same logic again  
vec_insert(vec, &y, 3);  
vec_insert_buff(vec, &x, 2, 3);
//don't check the definition of the macro vec_at and you'll be fine
printf("%d\n", vec_at(vec, int, 2));
  
//once youre done call vec_free  
vec_free(vec);
```

## DO NOT
- Use pop_back or pop_buff on a vector of size 1, use vec_free;
- Use delete or delete_buff to remove the last element, use pop_back;
- Give length of 0 to either vec_init or vec_new;
- Pass in a NULL pointer anywhere;
