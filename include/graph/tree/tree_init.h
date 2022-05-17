#pragma once
#include <graph/tree/types.h>

synapse_tree* synapse_tree_init     (synapse_tree_mman*, synapse_tree_manipulate*); // Create New Tree
void		  synapse_tree_destruct (synapse_tree*)							      ;