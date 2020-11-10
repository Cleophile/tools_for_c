/*  
 * Created By Hikari Software
 *
 * Y-Enterprise
 *
 */

#include "vector.h"

IntVector* create_intvector(int32_t length) {
    IntVector* v = malloc(sizeof(IntVector));
    v->current_length = 0;
    v->max_length = length;
    v->vec = malloc(sizeof(int32_t) * length);
    return v;
}

IntVector* intvector_push(IntVector* int_vec, int32_t value) {
    int_vec->current_length += 1;
    if(int_vec->current_length > int_vec->max_length) {
        IntVector* new_vec = create_intvector(int_vec->max_length*2);
        new_vec->current_length = int_vec->current_length;

        for(int32_t i = 0; i < int_vec->current_length - 1; ++i) {
            new_vec->vec[i] = int_vec->vec[i];
        }
        new_vec->vec[new_vec->current_length - 1] = value;
        return new_vec;
    }
    int_vec->vec[int_vec->current_length-1] = value;
    return int_vec;
}

void intvector_change(IntVector* int_vec, int32_t pos, int32_t value) {
    int_vec->vec[pos] = value;
}

int32_t intvector_pop(IntVector* int_vec) {
    int_vec->current_length -= 1;
    return int_vec->vec[int_vec->current_length];
}

void intvector_delete(IntVector* int_vec, int32_t pos) {
    for(int32_t i = pos; i < int_vec->current_length - 1; ++i) {
        int_vec->vec[i] = int_vec->vec[i+1];
    }
    int_vec->current_length -= 1;
}

int32_t intvector_get_element(IntVector* int_vec, int32_t a) {
    return int_vec->vec[a];
}

int32_t intvector_get_last_element(IntVector* int_vec) {
    return int_vec->vec[int_vec->current_length-1];
}
