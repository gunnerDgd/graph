#pragma once
#include <graph/tree/types.h>

synapse_tree_node*  synapse_tree_node_init      (synapse_tree*, synapse_tree_key*, synapse_tree_value*);
void				synapse_tree_node_delete    (synapse_tree*, synapse_tree_node*);

synapse_tree_key*   synapse_tree_node_get_key   (synapse_tree_node*);
synapse_tree_value* synapse_tree_node_get_value (synapse_tree_node*);

synapse_tree_node*  synapse_tree_node_get_left  (synapse_tree_node*);
synapse_tree_node*  synapse_tree_node_get_right (synapse_tree_node*);
synapse_tree_node*  synapse_tree_node_get_parent(synapse_tree_node*);