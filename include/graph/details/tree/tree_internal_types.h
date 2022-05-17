#pragma once
#include <graph/tree/types.h>

typedef struct __synapse_tree
{
	synapse_tree_mman		mman		  ; // 
	synapse_tree_manipulate manipulate	  ;
	size_t					node_count	  ;
	
	synapse_tree_node*		node		  ,
					 *		leftmost_node ,
					 *		rightmost_node;
} __synapse_tree;

typedef struct __synapse_tree_key_pair
{ 
	synapse_tree_key   key  ;
	synapse_tree_value value;
} __synapse_tree_key_pair;

typedef struct __synapse_tree_node
{
	__synapse_tree_key_pair     node_kpair ;
	struct __synapse_tree_node* node_left  ,
							  * node_right ,
							  * node_parent;
}   __synapse_tree_node;