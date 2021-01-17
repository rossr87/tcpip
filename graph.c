#include "graph.h"

/*
 *  returns a pointer to the node I am attached to.
 */
static inline node_t *get_nbr_node(interface_t *interface) {
    return interface->my_node;
}

/*
 * Given a node, return an available slot among the array of
 * interfaces.
 */

static inline int get_node_intf_available_slot(node_t *node) {
   
    int i;
 
    for (i = 0; node->interfaces[i] && i < INTERFACE_SLOTS_MAX; i++) {
    }
   
    if (i == INTERFACE_SLOTS_MAX)
        return -1;
    else
        return i;

}
