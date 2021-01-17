#include "gluethread/glthread.h"

/*
 * Forward declarations
 */

typedef struct node_ node_t;
typedef struct link_ link_t;

/*
 *
 * Interface has:
 * 	- a name
 *	- an owning node
 *	- a link.
 */

#define INTERFACE_NAME_MAXLEN 16
#define NODENAME_MAXLEN 16

/*
 * An interface is defined as a name, an owning node and a link/
 * --
 * OK, so we could have an interface that exists outside a node and unlinked. But for our purposes,
 * we don't need to do this and it would just complicate the code.
 */
typedef struct interface_ {
	char name[INTERFACE_NAME_MAXLEN];	/* My name, e.g. eth0, FastEthernet0/0 */
	struct node_ *my_node;			/* Node I am a member of */
	struct link_ *my_link;			/* Each interface has one and only one link */
} interface_t;

/*
 * A link is defined as a pair of interaces.
 */
struct link_ {
	interface_t iface_a;		/* first enddpoint interface  */
	interface_t iface_b;		/* second endpoint interface */
	unsigned int cost;		/* used by routing algorithms to calculate paths */
};

/*
 * A node is defined as follows:
 * 	- an node_id 
 * 	- a set of empty? interace slots.
 * 	- 
 */
#define INTERFACE_SLOTS_MAX 64
struct node_ {
	char			node_name[NODENAME_MAXLEN];		/* e.g. Router001 */
	struct interface	*interfaces[INTERFACE_SLOTS_MAX];	/* the set of network interfaces */
	glthread_t		graph_glue;				
};

/*
 * Overall topology
 */

#define TOPOLOGY_NAME_MAXLEN 16

typedef struct graph_ {
	char topology_name[TOPOLOGY_NAME_MAXLEN];		/* name of topology */
	glthread_t node_list;				/* list of nodes in the graph */
}

static inline node_t *get_nbr_node(interface_t *interface);
static inline int get_node_intf_available_slot(node_t *node);
