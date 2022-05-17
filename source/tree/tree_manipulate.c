#include <graph/tree/tree_manipulate.h>
#include <graph/tree/tree_node.h>

#include <graph/headers/tree_define.h>
#include <graph/details/tree/tree_internal_types.h>

__synapse_tree_node*  __synapse_tree_manip_insert_point(__synapse_tree*, synapse_tree_key*)		   ;
void				  __synapse_tree_manip_adopt	   (__synapse_tree*, __synapse_tree_node*)	   ;

void				  __synapse_tree_manip_adopt_top   (__synapse_tree*, __synapse_tree_node*)	   ;
void			      __synapse_tree_manip_adopt_left  (__synapse_tree_node*, __synapse_tree_node*);
void			      __synapse_tree_manip_adopt_right (__synapse_tree_node*, __synapse_tree_node*);

void synapse_tree_manip_insert(synapse_tree* pTree, synapse_tree_key* pKey, synapse_tree_value* pValue)
{
	synapse_tree_node  * ptr_node   =   synapse_tree_node_init		   (pTree, pKey, pValue);
	__synapse_tree_node* ptr_insert = __synapse_tree_manip_insert_point(pTree, pKey);

	if (ptr_insert == SYNAPSE_TREE_ERROR) return;

	switch (SYNAPSE_TREE_OPAQUE(pTree->opaque, __synapse_tree*)
		->manipulate.compare(pKey->key_ptr, ptr_insert->node_kpair.key.key_ptr))
	{
	case -1:
		ptr_insert->node_left  = ptr_node; SYNAPSE_TREE_LOOP_BREAK
	case 1:
		ptr_insert->node_right = ptr_node; SYNAPSE_TREE_LOOP_BREAK
	}

	ptr_insert->node_parent = ptr_insert;
}
void synapse_tree_manip_delete(synapse_tree* pTree, synapse_tree_key* pKey)
{
	synapse_tree_node* ptr_node = synapse_tree_manip_get_node(pTree, pKey);
	
	if (!ptr_node)
		return;

	synapse_tree_node_delete(pTree, ptr_node);
}

synapse_tree_node* synapse_tree_manip_get_node     (synapse_tree_key*);
synapse_tree_node* synapse_tree_manip_get_leftmost (synapse_tree* pTree)
{
	return SYNAPSE_TREE_OPAQUE(pTree->opaque, __synapse_tree*)->leftmost_node;
}

synapse_tree_node* synapse_tree_manip_get_rightmost(synapse_tree* pTree)
{
	return SYNAPSE_TREE_OPAQUE(pTree->opaque, __synapse_tree*)->rightmost_node;
}

__synapse_tree_node* __synapse_tree_manip_insert_point(__synapse_tree* pTree, synapse_tree_key* pKey)
{
	synapse_tree_manipulate* ptr_manip = &pTree->manipulate;
	__synapse_tree_node	   * ptr_seek  = (pTree->node) ? pTree->node->opaque : NULL;
	
	if (!ptr_seek) return NULL;

	SYNAPSE_TREE_LOOP_BEGIN
		switch (pTree->manipulate.compare(pKey->key_ptr, ptr_seek->node_kpair.key.key_ptr))
		{
		case -1: 
			if (!ptr_seek->node_left)			  return ptr_seek;
			else ptr_seek = ptr_seek->node_left;  SYNAPSE_TREE_LOOP_BREAK
		case 0 :								  return SYNAPSE_TREE_ERROR;
		case 1 :
			if (!ptr_seek->node_right)			  return ptr_seek;
			else ptr_seek = ptr_seek->node_right; SYNAPSE_TREE_LOOP_BREAK;
		}
	SYNAPSE_TREE_LOOP_END
}

void __synapse_tree_manip_adopt(__synapse_tree* pTree, __synapse_tree_node* pNode)
{
	__synapse_tree_node* ptr_seek = pNode->node_parent;
	
	if		(!ptr_seek)					    __synapse_tree_manip_adopt_top  (pNode, pTree);
	else if (ptr_seek->node_left  == pNode) __synapse_tree_manip_adopt_left (pNode, ptr_seek);
	else if (ptr_seek->node_right == pNode) __synapse_tree_manip_adopt_right(pNode, ptr_seek);
}

void __synapse_tree_manip_adopt_left(__synapse_tree_node* pAdopt, __synapse_tree_node* pParent)
{
	pParent->node_left = pAdopt->node_left;
	__synapse_tree_node ptr_seek = pAdopt->
}

void __synapse_tree_manip_adopt_right(__synapse_tree_node* pAdopt, __synapse_tree_node* pParent)
{

}