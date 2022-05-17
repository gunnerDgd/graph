#pragma once
#include <stdint.h>

struct synapse_tree			 { void* opaque; };
struct synapse_tree_key_pair { void* opaque; };
struct synapse_tree_node	 { void* opaque; };

struct synapse_tree_key
{
	void*  key_ptr ;
	size_t key_size;

	int  (*key_compare) (struct synapse_tree_key*, struct synapse_tree_key*);
	void (*key_destruct)(struct synapse_tree_key*);
};

struct synapse_tree_value
{
	void*  value_ptr ;
	size_t value_size;
	int  (*value_destruct)(struct synapse_tree_value*);
};

typedef struct synapse_tree			 synapse_tree		  ;
typedef struct synapse_tree_value    synapse_tree_value   ;
typedef struct synapse_tree_key_pair synapse_tree_key_pair;
typedef struct synapse_tree_key		 synapse_tree_key	  ;
typedef struct synapse_tree_node	 synapse_tree_node	  ;
typedef							int(*synapse_tree_node_comparer)(void*, void*);