#pragma once
#include <graph/tree/types.h>

synapse_tree_mman* synapse_tree_mman_retrieve		(synapse_tree*);
void			   synapse_tree_mman_set_allocator  (synapse_tree*, void*(*)(void*, size_t));
void			   synapse_tree_mman_set_deallocator(synapse_tree*, void (*)(void*, size_t));

void*			   synapse_tree_mman_allocate		(synapse_tree*, void*, size_t);
void			   synapse_tree_mman_deallocate		(synapse_tree*, void*, size_t);