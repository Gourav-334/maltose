/* Including required headers. */

#include "../../../include/common_store.h"
#include "../../../include/lexer/x86/fsm_state_handler.h"
#include "../../../include/lexer/x86/token_store.h"
#include "../../../include/data_structs/linked_list/ll_struct.h"
#include "../../../include/data_structs/linked_list/inserter.h"
#include "../../../include/file_loader.h"
#include "../../../include/manuals/audit_msng.h"

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
			msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Token passed can't be empty!\0", "user");
			func_ret = false;
		}



		else if (*state==1)
		{
			msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Sign without a value!\0", "user");
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
			msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Float without fraction part passed!\0", "user");
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
			msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Incomplete hex value!\0", "user");
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
			insert_node(&token, str, true, "dev");
			insert_node(&categ, "others", true, "dev");
			insert_node(&sub_categ, "names", true, "dev");
			insert_node(&type, "identifier", true, "dev");

			func_ret = true;
		}



		else if (*state==13)
		{
			// VACANT STATE
		}



		else if (*state==14)
		{
			//msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Unknown character encountered!\0", "user");
			func_ret = false;
		}



		else if (*state>=15 && *state<=16)
		{
			// VACANT STATE
		}



		else if (*state==17)
		{
			// VACANT STATE
		}



		else if (*state==18)
		{
			// VACANT STATE
		}



		else if (*state>=19 && *state<=20)
		{
			// VACANT STATE
		}



		else if (*state==21)
		{
			// VACANT STATE
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
			case -3: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Unwanted character in possibly binary value!\0", "user"); break;
			case -4: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Unwanted character in possibly binary value!\0", "user"); break;
			case -5: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Unwanted character in possibly octal value!\0", "user"); break;
			case -6: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Unwanted character in possibly octal value!\0", "user"); break;
			case -7: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Unwanted character in possibly decimal value!\0", "user"); break;
			case -8: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Unwanted character in possibly float value!\0", "user"); break;
			case -9: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Unwanted character in possibly float value!\0", "user"); break;
			case -10: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Unwanted character in possibly hex value!\0", "user"); break;
			case -11: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Unwanted character in possibly hex value!\0", "user"); break;
			case -12: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Unwanted character encountered in identifier!\0", "user"); break;
			case -16: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Multiple bytes written for a character!\0", "user"); break;
			case -17: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Characters written after closing of inverted comma!\0", "user"); break;
			case -18: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Unknown escape character passed!\0", "user"); break;
			case -21: msg_audit_res(fstream, src_filename, point, row, column, "ERROR\0", "Lexical\0", "Characters written after closing of double inverted comma!\0", "user"); break;
		}
	}





	/* Reverting state back to initial. */

	*state = 0;
	point_shift = 0;


	/* Returning boolean as per execution. */

	return func_ret;
}