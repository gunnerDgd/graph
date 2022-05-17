#include <graph/tree/tree_init.h>
#include <graph/headers/tree_define.h>
#include <graph/details/tree/tree_internal_types.h>

#include <stdlib.h>

void* __synapse_tree_default_allocator(void* pHint  , size_t pSize) { return malloc(pSize)  ; }
void  __synapse_tree_default_deleter  (void* pDelete, size_t pSize) { return free  (pDelete); }

int  __synapse_tree_default_compare_eq(void* pLhs, void* pRhs) { return SYNAPSE_TREE_REFERENCE_CAST(pLhs, int) == SYNAPSE_TREE_REFERENCE_CAST(pRhs, int); }
int  __synapse_tree_default_compare_lt(void* pLhs, void* pRhs) { return SYNAPSE_TREE_REFERENCE_CAST(pLhs, int) <  SYNAPSE_TREE_REFERENCE_CAST(pRhs, int); }
int  __synapse_tree_default_compare_gt(void* pLhs, void* pRhs) { return SYNAPSE_TREE_REFERENCE_CAST(pLhs, int) >  SYNAPSE_TREE_REFERENCE_CAST(pRhs, int); }

synapse_tree* synapse_tree_init(synapse_tree_mman* pMman, synapse_tree_manipulate* pManip)
{
	synapse_tree* ptr_init		   = malloc(sizeof(synapse_tree))  ;
				  ptr_init->opaque = malloc(sizeof(__synapse_tree));

	SYNAPSE_TREE_OPAQUE(ptr_init->opaque, __synapse_tree*)->mman.allocate 
		= (pMman) ? pMman->allocate   : __synapse_tree_default_allocator;
	SYNAPSE_TREE_OPAQUE(ptr_init->opaque, __synapse_tree*)->mman.deallocate
		= (pMman) ? pMman->deallocate : __synapse_tree_default_deleter;
	
	SYNAPSE_TREE_OPAQUE(ptr_init->opaque, __synapse_tree*)->manipulate.compare_eq
		= (pManip) ? pManip->compare_eq : __synapse_tree_default_compare_eq;
	SYNAPSE_TREE_OPAQUE(ptr_init->opaque, __synapse_tree*)->manipulate.compare_lt
		= (pManip) ? pManip->compare_lt : __synapse_tree_default_compare_lt;
	SYNAPSE_TREE_OPAQUE(ptr_init->opaque, __synapse_tree*)->manipulate.compare_gt
		= (pManip) ? pManip->compare_gt : __synapse_tree_default_compare_gt;

	return ptr_init;
}

void		  synapse_tree_destruct(synapse_tree* pTree)
{

}