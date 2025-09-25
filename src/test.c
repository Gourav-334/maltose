/* Adding header(s) for unit testing. */

#include "../include/linked_list/ll_struct.h"
#include "../include/linked_list/inserter.h"

#include <stdio.h>



int main(int argc, char **argv)
{
	Ll_recorder my_recorder = {.total=0, .head=NULL, .tail=NULL};

	insert(&my_recorder, "is", true, "debug");
	insert(&my_recorder, "the", true, "debug");
	insert(&my_recorder, "Who", false, "debug");
	insert(&my_recorder, "Gigachad", true, "debug");


	return 0;
}
