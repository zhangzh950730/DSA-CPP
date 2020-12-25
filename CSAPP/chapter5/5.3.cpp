//
// Created by zhang on 2020/11/5.
//
#define IDENT 1
#define OP *

#include <cstdlib>

typedef long data_t;
typedef struct {
    long len;
    data_t *data;
} vec_rec, *vec_ptr;

data_t *get_vec_start(vec_ptr v) {
    return v->data;
}

vec_ptr new_vec(long len) {
    vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
    data_t *data = NULL;
    if (!result) {
        return NULL;
    }
    result->len = len;
    if (len > 0) {
        data = (data_t *) calloc(len, sizeof(data_t));
        if (!data) {
            free((void *) result);
            return NULL;
        }
    }
    result->data = data;
    return result;
}

int get_vec_element(vec_ptr v, long index, data_t *dest) {
    if (index < 0 || index >= v->len) {
        return 0;
    }
    *dest = v->data[index];
    return 1;
}

long vec_length(vec_ptr v) {
    return v->len;
}

void combine3(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    data_t *data = get_vec_start(v);

    *dest = IDENT;
    for (i = 0; i < length; ++i) {
        *dest = *dest OP data[i];
    }
}


void combine4(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    data_t *data = get_vec_start(v);
    data_t acc = IDENT;

    *dest = IDENT;
    for (i = 0; i < length; ++i) {
        acc = acc OP data[i];
    }
    *dest = acc;
}

int main() {

}




