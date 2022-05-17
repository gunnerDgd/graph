#include <graph/tree/tree_mman.h>
#include <graph/headers/tree_define.h>

synapse_tree_mman* synapse_tree_mman_retrieve(synapse_tree* pTree)
{
	return SYNAPSE_TREE_OPAQUE(pTree->opaque, synapse_tree_mman*);
}

void synapse_tree_mman_set_allocator(synapse_tree* pTree, void* (*pAlloc)(void*, size_t))
{
	SYNAPSE_TREE_OPAQUE(pTree->opaque, synapse_tree_mman*)->allocate   = pAlloc;
}

void synapse_tree_mman_set_deallocator(synapse_tree* pTree, void(*pDealloc)(void*, size_t))
{
	SYNAPSE_TREE_OPAQUE(pTree->opaque, synapse_tree_mman*)->deallocate = pDealloc;
}

void* synapse_tree_mman_allocate(synapse_tree* pTree, void* pHint, size_t pSize)
{
	SYNAPSE_TREE_OPAQUE(pTree->opaque, synapse_tree_mman*)->allocate(pHint, pSize);
}

void  synapse_tree_mman_deallocate(synapse_tree* pTree, void* pHint, size_t pSize)
{
	SYNAPSE_TREE_OPAQUE(pTree->opaque, synapse_tree_mman*)->deallocate(pHint, pSize);
}