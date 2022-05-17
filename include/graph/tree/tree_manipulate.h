#pragma once
#include <graph/tree/types.h>

void			   synapse_tree_manip_insert	   (synapse_tree*, synapse_tree_key*, synapse_tree_value*);
void			   synapse_tree_manip_delete	   (synapse_tree*, synapse_tree_key*);

synapse_tree_node* synapse_tree_manip_get_node	   (synapse_tree*, synapse_tree_key*);
synapse_tree_node* synapse_tree_manip_get_leftmost (synapse_tree*);
synapse_tree_node* synapse_tree_manip_get_rightmost(synapse_tree*);