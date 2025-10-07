/* Including required headers. */

#include "../../../include/lexer/x86/fsm_state_handler.h"
#include "../../../include/lexer/x86/token_store.h"
#include "../../../include/data_structs/linked_list/ll_struct.h"
#include "../../../include/data_structs/linked_list/inserter.h"

#include <stdio.h>		// For printing feedbacks to terminal.
#include <string.h>		// For detecting chosen feedback mode.










/* Command interpreter's FSM state handler. */

bool handle_token_fsm_state(signed short int *state, char *str, char *mode)
{
	/* Variables declarations/definitions. */

	bool func_ret = true;





	/* Non-linear structures declarations/definitions. */

	enum Mode{DEV, USER, DEBUG} M;





	/* Checking which mode is used for function. */

	if (!strcmp(mode,"dev")) {M = DEV;}
	else if (!strcmp(mode,"user")) {M = USER;}
	else if (!strcmp(mode,"debug")) {M = DEBUG;}
	else
	{
		printf("ERROR: Mode named \"%s\" doesn't exist!\n", mode);
		return false;
	}










	/* Providing feedback as per mode. */

	if (M==DEV) {}
	else if (M==USER) {}
	else if (M==DEBUG) {printf("STAT :: state=%hd :: token=\"%s\"\n", *state, str);}





	/* Handling non-trap states. */

	if (*state>=0)
	{
		if (*state==0)
		{
			printf("ERROR: Token passed can't be empty!\n");
			func_ret = false;
		}



		else if (*state==1)
		{
			printf("ERROR: Sign without a value!\n");
			func_ret = false;
		}



		else if (*state>=2 && *state<=3)
		{
			insert_node(&token, str, true, "dev");
			insert_node(&categ, "literal", true, "dev");
			insert_node(&sub_categ, "numeric", true, "dev");
			insert_node(&type, "decimal", true, "dev");

			func_ret = true;
		}



		else if (*state==4)
		{
			insert_node(&token, str, true, "dev");
			insert_node(&categ, "literal", true, "dev");
			insert_node(&sub_categ, "numeric", true, "dev");
			insert_node(&type, "binary", true, "dev");

			func_ret = true;
		}


		else if (*state==5)
		{
			insert_node(&token, str, true, "dev");
			insert_node(&categ, "literal", true, "dev");
			insert_node(&sub_categ, "numeric", true, "dev");
			insert_node(&type, "decimal", true, "dev");

			func_ret = true;
		}



		else if (*state==6)
		{
			insert_node(&token, str, true, "dev");
			insert_node(&categ, "literal", true, "dev");
			insert_node(&sub_categ, "numeric", true, "dev");
			insert_node(&type, "octal", true, "dev");

			func_ret = true;
		}



		else if (*state==7)
		{
			insert_node(&token, str, true, "dev");
			insert_node(&categ, "literal", true, "dev");
			insert_node(&sub_categ, "numeric", true, "dev");
			insert_node(&type, "decimal", true, "dev");

			func_ret = true;
		}



		else if (*state==8)
		{
			printf("ERROR: Float without fraction part passed!\n");
			func_ret = false;
		}



		else if (*state==9)
		{
			insert_node(&token, str, true, "dev");
			insert_node(&categ, "literal", true, "dev");
			insert_node(&sub_categ, "numeric", true, "dev");
			insert_node(&type, "float", true, "dev");

			func_ret = true;
		}



		else if (*state==10)
		{
			printf("ERROR: Incomplete hex value!\n");
			func_ret = false;
		}



		else if (*state==11)
		{
			insert_node(&token, str, true, "dev");
			insert_node(&categ, "literal", true, "dev");
			insert_node(&sub_categ, "numeric", true, "dev");
			insert_node(&type, "hex", true, "dev");

			func_ret = true;
		}



		else if (*state==12)
		{
			printf("ERROR: Incomplete hex value!\n");
			func_ret = false;
		}



		else if (*state==13)
		{
			insert_node(&token, str, true, "dev");
			insert_node(&categ, "literal", true, "dev");
			insert_node(&sub_categ, "numeric", true, "dev");
			insert_node(&type, "hex", true, "dev");

			func_ret = true;
		}



		else if (*state==14)
		{
			insert_node(&token, str, true, "dev");
			insert_node(&categ, "others", true, "dev");
			insert_node(&sub_categ, "names", true, "dev");
			insert_node(&type, "identifier", true, "dev");

			func_ret = true;
		}



		else if (*state>=15 && *state<=16)
		{
			printf("ERROR: Open inverted comma for character, never closed!\n");
			func_ret = false;
		}



		else if (*state==17)
		{
			insert_node(&token, str, true, "dev");
			insert_node(&categ, "literal", true, "dev");
			insert_node(&sub_categ, "ascii", true, "dev");
			insert_node(&type, "char", true, "dev");

			func_ret = true;
		}



		else if (*state==18)
		{
			printf("ERROR: Open inverted comma for character, never closed!\n");
			func_ret = false;
		}



		else if (*state>=19 && *state<=20)
		{
			printf("ERROR: Open inverted comma for string, never closed!\n");
			func_ret = false;
		}



		else if (*state==21)
		{
			insert_node(&token, str, true, "dev");
			insert_node(&categ, "literal", true, "dev");
			insert_node(&sub_categ, "ascii", true, "dev");
			insert_node(&type, "string", true, "dev");

			func_ret = true;
		}
	}





	/* Handling dump states. */

	else if (*state<0)
	{
		/* Confirmed error in passed string. */

		func_ret = false;



		/* Providing feedback as per state. */

		switch(*state)
		{
			case -3: printf("ERROR: Unwanted character in possibly binary value %s!\n", str); break;
			case -4: printf("ERROR: Unwanted character in possibly binary value %s!\n", str); break;
			case -5: printf("ERROR: Unwanted character in possibly octal value %s!\n", str); break;
			case -6: printf("ERROR: Unwanted character in possibly octal value %s!\n", str); break;
			case -7: printf("ERROR: Unwanted character in possibly decimal value %s!\n", str); break;
			case -8: printf("ERROR: Unwanted character in possibly float value %s!\n", str); break;
			case -9: printf("ERROR: Unwanted character in possibly float value %s!\n", str); break;
			case -10: printf("ERROR: Unwanted character in possibly hex value %s!\n", str); break;
			case -11: printf("ERROR: Unwanted character in possibly hex value %s!\n", str); break;
			case -13: printf("ERROR: Unwanted character in possibly hex value %s!\n", str); break;
			case -16: printf("ERROR: Multiple bytes written for a character \'%s\'!\n", str); break;
			case -17: printf("ERROR: Characters written after closing of inverted comma %s!\n", str); break;
			case -18: printf("ERROR: Unknown escape character passed %s!\n", str); break;
			case -21: printf("ERROR: Characters written after closing of double inverted comma %s!\n", str); break;
		}
	}





	/* Reverting state back to initial. */

	*state = 0;


	/* Returning boolean as per execution. */

	return func_ret;
}