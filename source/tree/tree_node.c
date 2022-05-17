#include <graph/tree/tree_node.h>
#include <graph/tree/tree_mman.h>

#include <graph/headers/tree_define.h>
#include <graph/details/tree/tree_internal_types.h>

#include <stdint.h>
#include <stdlib.h>

synapse_tree_node* synapse_tree_node_init(synapse_tree* pTree, synapse_tree_key* pKey, synapse_tree_value* pValue)
{
	synapse_tree_node* ptr_node			= synapse_tree_mman_allocate(pTree, NULL, sizeof(synapse_tree_node));
					   ptr_node->opaque = synapse_tree_mman_allocate(pTree, NULL, sizeof(__synapse_tree_node));

	SYNAPSE_TREE_OPAQUE(ptr_node->opaque, __synapse_tree_node*)->node_kpair.key   = *pKey  ;
	SYNAPSE_TREE_OPAQUE(ptr_node->opaque, __synapse_tree_node*)->node_kpair.value = *pValue;
}

void				synapse_tree_node_delete(synapse_tree*, synapse_tree_node*);

synapse_tree_key* synapse_tree_node_get_key(synapse_tree_node* pNode)
{
	return &SYNAPSE_TREE_OPAQUE(pNode->opaque, __synapse_tree_node*)->node_kpair.key;
}

synapse_tree_value* synapse_tree_node_get_value(synapse_tree_node* pNode)
{
	return &SYNAPSE_TREE_OPAQUE(pNode->opaque, __synapse_tree_node*)->node_kpair.value; 
}

synapse_tree_node* synapse_tree_node_get_left(synapse_tree_node* pNode)
{
	return SYNAPSE_TREE_OPAQUE(pNode->opaque, __synapse_tree_node*)->node_left;
}

synapse_tree_node* synapse_tree_node_get_right(synapse_tree_node* pNode)
{
	return SYNAPSE_TREE_OPAQUE(pNode->opaque, __synapse_tree_node*)->node_right;
}

synapse_tree_node* synapse_tree_node_get_parent(synapse_tree_node* pNode)
{
	return SYNAPSE_TREE_OPAQUE(pNode->opaque, __synapse_tree_node*)->node_parent;
}