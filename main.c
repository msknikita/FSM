#include "fsm.h"
#include <stdio.h>

void foo(struct fsm_object *obj, int val, void **arg)
{
	//state -> default
	printf("val = %d, state = %s\n", val, obj->fsm_cur_state_name);
	
	//change state
	fsm_to_state(obj, "hello", 3, NULL);
}

void bar(struct fsm_object *obj, int val, void **arg)
{
	//state -> qwerty
	printf("val = %d, state = %s\n", val, obj->fsm_cur_state_name);

	fsm_to_state(obj, "default", 1, NULL);
}

void baz(struct fsm_object *obj, int val, void **arg)
{
	//state -> hello
	printf("val = %d, state = %s\n", val, obj->fsm_cur_state_name);

	fsm_to_state(obj, "qwerty", 2, NULL);
}

int main()
{
	//create fsm object
	struct fsm_object obj;

	//initialize it
	fsm_init(&obj);

	//set default function
	fsm_default(&obj, foo);

	//add more states
	fsm_add(&obj, "qwerty", bar);
	fsm_add(&obj, "hello", baz);

	//start the main fsm loop
	fsm_main(&obj);

	return 0;
}