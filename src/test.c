/* Adding header(s) for unit testing. */

#include "../include/lexer/x86/code_cleanser.h"
#include "../include/lexer/x86/token_store.h"
#include "../include/file_loader.h"
#include "../include/data_structs/linked_list/ll_struct.h"
#include "../include/data_structs/linked_list/displayer.h"
#include "../include/parser/x86/patt_fsm_main.h"

#include <stdio.h>



int main(int argc, char **argv)
{
	if (load_file("../test.asm", "dev")==true)
	{
		cleanse_code(fstream, "debug");
		display_nodes(&token);
		cleanse_code(fstream, "dev");
		patt_fsm_main(token, categ, sub_categ, type, 0, "debug");
	}


return 0;
}