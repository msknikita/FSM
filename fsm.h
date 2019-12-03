struct fsm_object;

/* Stores information regarding state */
struct fsm_state {
	char *name; //name of the state
	void(*function)(struct fsm_object*, int, void**); //function pointer for the state
	struct fsm_state *next; //pointer to the next state
};

/* Stores information regarding state machine */
struct fsm_object {
	struct fsm_state *fsm_base; //pointer to the linked list of fsm_state structures
	struct fsm_state *fsm_cur_state; //pointer to current FSM state 
	char *fsm_cur_state_name;  //name of current FSM state
	int fsm_arg_num; //number of argument passed to the next state 
	void **fsm_arg_value; //values of arguments passed to the next state
};

int fsm_init(struct fsm_object *obj);
int fsm_main(struct fsm_object *obj);
int fsm_next_state(struct fsm_object *obj);
int fsm_add(struct fsm_object *obj, char *state, void(*fun)(struct fsm_object *, int, void **));
int fsm_default(struct fsm_object *obj, void(*fun)(struct fsm_object *, int, void **));
int fsm_remove(struct fsm_object *obj, char *state);
int fsm_to_state(struct fsm_object *obj, char *state, int num, void** arg);
void fsm_terminate(struct fsm_object *obj);
