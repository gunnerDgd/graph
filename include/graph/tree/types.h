#pragma once
#include <stdint.h>

struct synapse_tree			 { void* opaque; };
struct synapse_tree_key_pair { void* opaque; };
struct synapse_tree_node	 { void* opaque; };

struct synapse_tree_key
{
	void*  key_ptr ;
	size_t key_size;
};

struct synapse_tree_value
{
	void*  value_ptr ;
	size_t value_size;
};

struct synapse_tree_mman
{
	void* (*allocate)  (void*, size_t);
	void  (*deallocate)(void*, size_t);
};

struct synapse_tree_manipulate
{
	int (*compare_eq)(void*, void*);
	int (*compare_gt)(void*, void*);
	int (*compare_lt)(void*, void*);
	int (*compare)	 (void*, void*); // -1 for Less, 0 for Equal, 1 for Greater.
};

typedef struct synapse_tree			   synapse_tree			  ;
typedef struct synapse_tree_value      synapse_tree_value     ;
typedef struct synapse_tree_key_pair   synapse_tree_key_pair  ;
typedef struct synapse_tree_key		   synapse_tree_key		  ;
typedef struct synapse_tree_node	   synapse_tree_node	  ;

typedef struct synapse_tree_mman       synapse_tree_mman	  ;
typedef struct synapse_tree_manipulate synapse_tree_manipulate;

typedef							int(*synapse_tree_node_comparer)(void*, void*);