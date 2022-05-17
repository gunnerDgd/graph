#include <graph/tree/tree_node.h>

#include <stdint.h>
#include <stdlib.h>

#define SYNAPSE_TREE_OPAQUE(opaque, type) ((type)opaque)

void		   __synapse_tree_key_default_destructor  (synapse_tree_key  * pKey)   { free(pKey); }
void		   __synapse_tree_value_default_destructor(synapse_tree_value* pValue) { free(pValue->value_ptr); free(pValue); }
typedef struct __synapse_tree_key_pair
{ 
	synapse_tree_key  * key  ;
	synapse_tree_value* value;
} __synapse_tree_key_pair;

typedef struct __synapse_tree_node
{
	__synapse_tree_key_pair     node_kpair;
	struct __synapse_tree_node* node_left ,
							  * node_right;
}   __synapse_tree_node;

synapse_tree_node* synapse_tree_node_init(synapse_tree_key* pKey, synapse_tree_value* pValue)
{
	synapse_tree_node* pNode		 = malloc(sizeof(synapse_tree_node))  ;
					   pNode->opaque = malloc(sizeof(__synapse_tree_node));
	
	SYNAPSE_TREE_OPAQUE(pNode->opaque, __synapse_tree_node*)->node_kpair.key   = pKey  ;
	SYNAPSE_TREE_OPAQUE(pNode->opaque, __synapse_tree_node*)->node_kpair.value = pValue;

	if (!pKey  ->key_destruct)   pKey  ->key_destruct   = &__synapse_tree_key_default_destructor  ;
	if (!pValue->value_destruct) pValue->value_destruct = &__synapse_tree_value_default_destructor;

	return pNode;
}

void			   synapse_tree_node_destruct(synapse_tree_node*);
int				   synapse_tree_node_compare (synapse_tree_node* pLhs, synapse_tree_node* pRhs)
{
	return SYNAPSE_TREE_OPAQUE(pLhs->opaque, __synapse_tree_node*)->node_kpair.key->key_compare(pRhs->opaque);
}