#pragma once
#include <graph/tree/types.h>

void synapse_tree_init     (synapse_tree**)				 ; // Create New Tree
void synapse_tree_init_from(synapse_tree*, synapse_tree*); // Copy a Tree
void synapse_tree_destruct (synapse_tree*)				 ;

