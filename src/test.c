/* Adding header(s) for unit testing. */

#include "../include/linked_list/ll_struct.h"
#include "../include/linked_list/inserter.h"
#include "../include/linked_list/full_remover.h"

#include <stdio.h>



int main(int argc, char **argv)
{
	Ll_recorder my_recorder = {.total=0, .head=NULL, .tail=NULL};

	insert_node(&my_recorder, "ABC", true, "user");
	insert_node(&my_recorder, "DEF", true, "user");
	insert_node(&my_recorder, "GHI", false, "user");
	insert_node(&my_recorder, "JKL", true, "user");
	insert_node(&my_recorder, "MNO", false, "user");
	insert_node(&my_recorder, "PQR", false, "user");

	remove_all_nodes(&my_recorder, "debug");
	remove_all_nodes(&my_recorder, "debug");


	return 0;
}
