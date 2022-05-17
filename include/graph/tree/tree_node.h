#pragma once
#include <graph/tree/types.h>

synapse_tree_node* synapse_tree_node_get		  (synapse_tree*);
synapse_tree_node* synapse_tree_node_get_leftmost (synapse_tree*);
synapse_tree_node* synapse_tree_node_get_rightmost(synapse_tree*);

void*			   synapse_tree_node_get_key	  (synapse_tree_node*);
void*			   synapse_tree_node_get_value	  (synapse_tree_node*);

synapse_tree_node* synapse_tree_node_init							  (synapse_tree_key*, synapse_tree_value*);
void			   synapse_tree_node_init_existing(synapse_tree_node*, synapse_tree_key*, synapse_tree_value*);

void			   synapse_tree_node_destruct	  (synapse_tree_node*);
int				   synapse_tree_node_compare	  (synapse_tree_node*, synapse_tree_node*, int(*)(void*, void*)); 