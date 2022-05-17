#pragma once

#define SYNAPSE_TREE_OPAQUE(opaque, type)			 ((type)opaque)
#define SYNAPSE_TREE_CAST(value, type)				 ((type)value)
#define SYNAPSE_TREE_REFERENCE_CAST(pointer, type) (*((type*)pointer))

#define SYNAPSE_TREE_LOOP_BEGIN while(1)\
							    {
#define SYNAPSE_TREE_LOOP_END   }
#define SYNAPSE_TREE_LOOP_BREAK    break;
#define SYNAPSE_TREE_LOOP_CONTINUE continue;
#define SYNAPSE_TREE_ERROR -1