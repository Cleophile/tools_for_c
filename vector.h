#pragma once

#include <stdlib.h>
#include <stdint.h>

typedef struct {
    int32_t   max_length;
    int32_t   current_length;
    int32_t*  vec;
} IntVector;


IntVector* create_intvector(int32_t length);

IntVector* intvector_push(IntVector* int_vec, int32_t value);
void intvector_change(IntVector* int_vec, int32_t pos, int32_t value);

int32_t intvector_pop(IntVector* int_vec);
void intvector_delete(IntVector* int_vec, int32_t pos);

int32_t intvector_get_element(IntVector* int_vec, int32_t a);
int32_t intvector_get_last_element(IntVector* int_vec);
