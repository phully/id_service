#ifndef HASHT_H
#define HASHT_H

/** \file ds_hasht.h
	This hash table saves pointer only.
*/

#include <stdint.h>

#include "cJSON.h"

//#include "ds_memvec.h"

#define	BUCKET_DEFAULT_SIZE	1024

typedef uint32_t hashval_t;
typedef struct {
	int offset;
	int len;
} hashkey_t;
typedef uint32_t hash_func_t(const void *ptr, size_t len);

typedef void hasht_t;

typedef void (*hasht_modify_cb_pt) (void *item, void *args);

hasht_t *hasht_new(hash_func_t*, int);
int hasht_delete(hasht_t*);

int hasht_add_item(hasht_t*, const hashkey_t*, void*);

void *hasht_find_item(hasht_t*, const hashkey_t*, void*);

void *hasht_fetch_item(hasht_t*, const hashkey_t*, void*);

int hasht_delete_item(hasht_t*, const hashkey_t*, void*);

int hasht_clean_table(hasht_t *h);

int hasht_modify_item(hasht_t *h, const hashkey_t *key, void *data, hasht_modify_cb_pt modify, void *args);

cJSON *hasht_info_cjson(hasht_t*, cJSON *(*content_serialize)(void*));

#endif

