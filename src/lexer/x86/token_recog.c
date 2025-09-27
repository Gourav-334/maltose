/* Including required headers. */

#include "../../../include/utils/str_verif/case_ins_match.h"
#include "../../../include/data_structs/linked_list/inserter.h"
#include "../../../include/lexer/x86/token_store.h"
#include "../../../include/lexer/x86/token_fsm_main.h"










/* Recognizes token & stores related information. */

bool token_recog(char *str)
{
	/* Singular/unit tokens. */

	if (!match_ins_case(str, "section", false, "dev")) {insert_node(&token, "section", true, "dev"); insert_node(&categ, "directive", true, "dev"); insert_node(&sub_categ, "block", true, "dev"); insert_node(&type, "section", true, "dev"); return true;}
	else if (!match_ins_case(str, "(", false, "dev")) {insert_node(&token, "(", true, "dev"); insert_node(&categ, "bracket", true, "dev"); insert_node(&sub_categ, "round", true, "dev"); insert_node(&type, "opening", true, "dev"); return true;}
	else if (!match_ins_case(str, ".", false, "dev")) {insert_node(&token, ".", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "numeric", true, "dev"); insert_node(&type, "period", true, "dev"); return true;}
	else if (!match_ins_case(str, ")", false, "dev")) {insert_node(&token, ")", true, "dev"); insert_node(&categ, "bracket", true, "dev"); insert_node(&sub_categ, "round", true, "dev"); insert_node(&type, "closing", true, "dev"); return true;}
	else if (!match_ins_case(str, "{", false, "dev")) {insert_node(&token, "{", true, "dev"); insert_node(&categ, "bracket", true, "dev"); insert_node(&sub_categ, "curly", true, "dev"); insert_node(&type, "opening", true, "dev"); return true;}
	else if (!match_ins_case(str, "}", false, "dev")) {insert_node(&token, "}", true, "dev"); insert_node(&categ, "bracket", true, "dev"); insert_node(&sub_categ, "curly", true, "dev"); insert_node(&type, "closing", true, "dev"); return true;}
	else if (!match_ins_case(str, "\n", false, "dev")) {insert_node(&token, "\n", true, "dev"); insert_node(&categ, "terminator", true, "dev"); insert_node(&sub_categ, "escape", true, "dev"); insert_node(&type, "endline", true, "dev"); return true;}
	else if (!match_ins_case(str, "\t", false, "dev")) {insert_node(&token, "\t", true, "dev"); insert_node(&categ, "skipper", true, "dev"); insert_node(&sub_categ, "escape", true, "dev"); insert_node(&type, "tabspace", true, "dev"); return true;}
	else if (!match_ins_case(str, "ascii", false, "dev")) {insert_node(&token, "ascii", true, "dev"); insert_node(&categ, "data", true, "dev"); insert_node(&sub_categ, "ascii", true, "dev"); insert_node(&type, "unterminated", true, "dev"); return true;}
	else if (!match_ins_case(str, "string", false, "dev")) {insert_node(&token, "string", true, "dev"); insert_node(&categ, "data", true, "dev"); insert_node(&sub_categ, "ascii", true, "dev"); insert_node(&type, "terminated", true, "dev"); return true;}
	else if (!match_ins_case(str, "byte", false, "dev")) {insert_node(&token, "byte", true, "dev"); insert_node(&categ, "data", true, "dev"); insert_node(&sub_categ, "integer", true, "dev"); insert_node(&type, "byte", true, "dev"); return true;}
	else if (!match_ins_case(str, "word", false, "dev")) {insert_node(&token, "word", true, "dev"); insert_node(&categ, "data", true, "dev"); insert_node(&sub_categ, "integer", true, "dev"); insert_node(&type, "word", true, "dev"); return true;}
	else if (!match_ins_case(str, "long", false, "dev")) {insert_node(&token, "long", true, "dev"); insert_node(&categ, "data", true, "dev"); insert_node(&sub_categ, "integer", true, "dev"); insert_node(&type, "long", true, "dev"); return true;}
	else if (!match_ins_case(str, "quad", false, "dev")) {insert_node(&token, "quad", true, "dev"); insert_node(&categ, "data", true, "dev"); insert_node(&sub_categ, "integer", true, "dev"); insert_node(&type, "quad", true, "dev"); return true;}
	else if (!match_ins_case(str, "float", false, "dev")) {insert_node(&token, "float", true, "dev"); insert_node(&categ, "data", true, "dev"); insert_node(&sub_categ, "fraction", true, "dev"); insert_node(&type, "float", true, "dev"); return true;}
	else if (!match_ins_case(str, "double", false, "dev")) {insert_node(&token, "double", true, "dev"); insert_node(&categ, "data", true, "dev"); insert_node(&sub_categ, "fraction", true, "dev"); insert_node(&type, "double", true, "dev"); return true;}
	else if (!match_ins_case(str, "longdouble", false, "dev")) {insert_node(&token, "longdouble", true, "dev"); insert_node(&categ, "data", true, "dev"); insert_node(&sub_categ, "fraction", true, "dev"); insert_node(&type, "longdouble", true, "dev"); return true;}
	else if (!match_ins_case(str, "=", false, "dev")) {insert_node(&token, "=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "arithmetic", true, "dev"); insert_node(&type, "assigning", true, "dev"); return true;}
	else if (!match_ins_case(str, ",", false, "dev")) {insert_node(&token, ",", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "separator", true, "dev"); insert_node(&type, "comma", true, "dev"); return true;}
	else if (!match_ins_case(str, "[", false, "dev")) {insert_node(&token, "[", true, "dev"); insert_node(&categ, "bracket", true, "dev"); insert_node(&sub_categ, "square", true, "dev"); insert_node(&type, "opening", true, "dev"); return true;}
	else if (!match_ins_case(str, "]", false, "dev")) {insert_node(&token, "]", true, "dev"); insert_node(&categ, "bracket", true, "dev"); insert_node(&sub_categ, "square", true, "dev"); insert_node(&type, "closing", true, "dev"); return true;}
	else if (!match_ins_case(str, "global", false, "dev")) {insert_node(&token, "global", true, "dev"); insert_node(&categ, "property", true, "dev"); insert_node(&sub_categ, "scope", true, "dev"); insert_node(&type, "global", true, "dev"); return true;}
	else if (!match_ins_case(str, "extern", false, "dev")) {insert_node(&token, "extern", true, "dev"); insert_node(&categ, "property", true, "dev"); insert_node(&sub_categ, "scope", true, "dev"); insert_node(&type, "extern", true, "dev"); return true;}
	else if (!match_ins_case(str, "local", false, "dev")) {insert_node(&token, "local", true, "dev"); insert_node(&categ, "property", true, "dev"); insert_node(&sub_categ, "scope", true, "dev"); insert_node(&type, "local", true, "dev"); return true;}
	else if (!match_ins_case(str, "weak", false, "dev")) {insert_node(&token, "weak", true, "dev"); insert_node(&categ, "property", true, "dev"); insert_node(&sub_categ, "scope", true, "dev"); insert_node(&type, "weak", true, "dev"); return true;}
	else if (!match_ins_case(str, "hidden", false, "dev")) {insert_node(&token, "hidden", true, "dev"); insert_node(&categ, "property", true, "dev"); insert_node(&sub_categ, "scope", true, "dev"); insert_node(&type, "hidden", true, "dev"); return true;}
	else if (!match_ins_case(str, "protected", false, "dev")) {insert_node(&token, "protected", true, "dev"); insert_node(&categ, "property", true, "dev"); insert_node(&sub_categ, "scope", true, "dev"); insert_node(&type, "protected", true, "dev"); return true;}
	else if (!match_ins_case(str, "rigid", false, "dev")) {insert_node(&token, "rigid", true, "dev"); insert_node(&categ, "property", true, "dev"); insert_node(&sub_categ, "flexibility", true, "dev"); insert_node(&type, "rigid", true, "dev"); return true;}
	else if (!match_ins_case(str, "flexible", false, "dev")) {insert_node(&token, "flexible", true, "dev"); insert_node(&categ, "property", true, "dev"); insert_node(&sub_categ, "flexibility", true, "dev"); insert_node(&type, "flexible", true, "dev"); return true;}
	else if (!match_ins_case(str, "+=", false, "dev")) {insert_node(&token, "+=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "arithmetic", true, "dev"); insert_node(&type, "addition", true, "dev"); return true;}
	else if (!match_ins_case(str, "-=", false, "dev")) {insert_node(&token, "-=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "arithmetic", true, "dev"); insert_node(&type, "subtraction", true, "dev"); return true;}
	else if (!match_ins_case(str, "*=", false, "dev")) {insert_node(&token, "*=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "arithmetic", true, "dev"); insert_node(&type, "multiplication", true, "dev"); return true;}
	else if (!match_ins_case(str, "/=", false, "dev")) {insert_node(&token, "/=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "arithmetic", true, "dev"); insert_node(&type, "division", true, "dev"); return true;}
	else if (!match_ins_case(str, "&=", false, "dev")) {insert_node(&token, "&=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "logical", true, "dev"); insert_node(&type, "and", true, "dev"); return true;}
	else if (!match_ins_case(str, "|=", false, "dev")) {insert_node(&token, "|=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "logical", true, "dev"); insert_node(&type, "or", true, "dev"); return true;}
	else if (!match_ins_case(str, "~=", false, "dev")) {insert_node(&token, "~=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "logical", true, "dev"); insert_node(&type, "not", true, "dev"); return true;}
	else if (!match_ins_case(str, "^=", false, "dev")) {insert_node(&token, "^=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "logical", true, "dev"); insert_node(&type, "xor", true, "dev"); return true;}
	else if (!match_ins_case(str, "<<", false, "dev")) {insert_node(&token, "<<", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "bitwise", true, "dev"); insert_node(&type, "left", true, "dev"); return true;}
	else if (!match_ins_case(str, ">>", false, "dev")) {insert_node(&token, ">>", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "bitwise", true, "dev"); insert_node(&type, "right", true, "dev"); return true;}
	else if (!match_ins_case(str, "@", false, "dev")) {insert_node(&token, "@", true, "dev"); insert_node(&categ, "referral", true, "dev"); insert_node(&sub_categ, "address", true, "dev"); insert_node(&type, "pointer", true, "dev"); return true;}
	else if (!match_ins_case(str, "++", false, "dev")) {insert_node(&token, "++", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "special", true, "dev"); insert_node(&type, "increment", true, "dev"); return true;}
	else if (!match_ins_case(str, "--", false, "dev")) {insert_node(&token, "--", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "special", true, "dev"); insert_node(&type, "decrement", true, "dev"); return true;}
	else if (!match_ins_case(str, "~", false, "dev")) {insert_node(&token, "~", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "special", true, "dev"); insert_node(&type, "negation", true, "dev"); return true;}
	else if (!match_ins_case(str, "?=", false, "dev")) {insert_node(&token, "?=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "special", true, "dev"); insert_node(&type, "comparison", true, "dev"); return true;}
	else if (!match_ins_case(str, "<->", false, "dev")) {insert_node(&token, "<->", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "special", true, "dev"); insert_node(&type, "swap", true, "dev"); return true;}
	else if (!match_ins_case(str, "none", false, "dev")) {insert_node(&token, "none", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "special", true, "dev"); insert_node(&type, "nothing", true, "dev"); return true;}
	else if (!match_ins_case(str, "|", false, "dev")) {insert_node(&token, "|", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "special", true, "dev"); insert_node(&type, "absolution", true, "dev"); return true;}
	else if (!match_ins_case(str, "call", false, "dev")) {insert_node(&token, "call", true, "dev"); insert_node(&categ, "command", true, "dev"); insert_node(&sub_categ, "function", true, "dev"); insert_node(&type, "call", true, "dev"); return true;}
	else if (!match_ins_case(str, "return", false, "dev")) {insert_node(&token, "return", true, "dev"); insert_node(&categ, "command", true, "dev"); insert_node(&sub_categ, "function", true, "dev"); insert_node(&type, "return", true, "dev"); return true;}
	else if (!match_ins_case(str, "==", false, "dev")) {insert_node(&token, "==", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "comparison", true, "dev"); insert_node(&type, "equal", true, "dev"); return true;}
	else if (!match_ins_case(str, "!=", false, "dev")) {insert_node(&token, "!=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "comparison", true, "dev"); insert_node(&type, "inequal", true, "dev"); return true;}
	else if (!match_ins_case(str, "!", false, "dev")) {insert_node(&token, "!", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "comparison", true, "dev"); insert_node(&type, "not", true, "dev"); return true;}
	else if (!match_ins_case(str, "<", false, "dev")) {insert_node(&token, "<", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "comparison", true, "dev"); insert_node(&type, "lt", true, "dev"); return true;}
	else if (!match_ins_case(str, "!<", false, "dev")) {insert_node(&token, "!<", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "comparison", true, "dev"); insert_node(&type, "nlt", true, "dev"); return true;}
	else if (!match_ins_case(str, "<=", false, "dev")) {insert_node(&token, "<=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "comparison", true, "dev"); insert_node(&type, "le", true, "dev"); return true;}
	else if (!match_ins_case(str, "!<=", false, "dev")) {insert_node(&token, "!<=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "comparison", true, "dev"); insert_node(&type, "nle", true, "dev"); return true;}
	else if (!match_ins_case(str, ">", false, "dev")) {insert_node(&token, ">", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "comparison", true, "dev"); insert_node(&type, "gt", true, "dev"); return true;}
	else if (!match_ins_case(str, "!>", false, "dev")) {insert_node(&token, "!>", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "comparison", true, "dev"); insert_node(&type, "ngt", true, "dev"); return true;}
	else if (!match_ins_case(str, ">=", false, "dev")) {insert_node(&token, ">=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "comparison", true, "dev"); insert_node(&type, "gt", true, "dev"); return true;}
	else if (!match_ins_case(str, "!>=", false, "dev")) {insert_node(&token, "!>=", true, "dev"); insert_node(&categ, "operator", true, "dev"); insert_node(&sub_categ, "comparison", true, "dev"); insert_node(&type, "nge", true, "dev"); return true;}
	else if (!match_ins_case(str, "push", false, "dev")) {insert_node(&token, "push", true, "dev"); insert_node(&categ, "command", true, "dev"); insert_node(&sub_categ, "stack", true, "dev"); insert_node(&type, "push", true, "dev"); return true;}
	else if (!match_ins_case(str, "pop", false, "dev")) {insert_node(&token, "pop", true, "dev"); insert_node(&categ, "command", true, "dev"); insert_node(&sub_categ, "stack", true, "dev"); insert_node(&type, "pop", true, "dev"); return true;}
	else if (!match_ins_case(str, "store", false, "dev")) {insert_node(&token, "store", true, "dev"); insert_node(&categ, "command", true, "dev"); insert_node(&sub_categ, "stack", true, "dev"); insert_node(&type, "retrieve", true, "dev"); return true;}
	else if (!match_ins_case(str, "enable", false, "dev")) {insert_node(&token, "enable", true, "dev"); insert_node(&categ, "command", true, "dev"); insert_node(&sub_categ, "hardware", true, "dev"); insert_node(&type, "enable", true, "dev"); return true;}
	else if (!match_ins_case(str, "disable", false, "dev")) {insert_node(&token, "disable", true, "dev"); insert_node(&categ, "command", true, "dev"); insert_node(&sub_categ, "hardware", true, "dev"); insert_node(&type, "disable", true, "dev"); return true;}
	else if (!match_ins_case(str, "input", false, "dev")) {insert_node(&token, "input", true, "dev"); insert_node(&categ, "command", true, "dev"); insert_node(&sub_categ, "hardware", true, "dev"); insert_node(&type, "input", true, "dev"); return true;}
	else if (!match_ins_case(str, "output", false, "dev")) {insert_node(&token, "output", true, "dev"); insert_node(&categ, "command", true, "dev"); insert_node(&sub_categ, "hardware", true, "dev"); insert_node(&type, "output", true, "dev"); return true;}
	else if (!match_ins_case(str, "mode", false, "dev")) {insert_node(&token, "mode", true, "dev"); insert_node(&categ, "command", true, "dev"); insert_node(&sub_categ, "switch", true, "dev"); insert_node(&type, "mode", true, "dev"); return true;}
	else if (!match_ins_case(str, "halt", false, "dev")) {insert_node(&token, "halt", true, "dev"); insert_node(&categ, "command", true, "dev"); insert_node(&sub_categ, "hardware", true, "dev"); insert_node(&type, "halt", true, "dev"); return true;}
	else if (!match_ins_case(str, "interrupt", false, "dev")) {insert_node(&token, "interrupt", true, "dev"); insert_node(&categ, "command", true, "dev"); insert_node(&sub_categ, "hardware", true, "dev"); insert_node(&type, "interrupt", true, "dev"); return true;}
	else if (!match_ins_case(str, "syscall", false, "dev")) {insert_node(&token, "syscall", true, "dev"); insert_node(&categ, "command", true, "dev"); insert_node(&sub_categ, "hardware", true, "dev"); insert_node(&type, "syscall", true, "dev"); return true;}
	else if (!match_ins_case(str, "st", false, "dev")) {insert_node(&token, "st", true, "dev"); insert_node(&categ, "referrence", true, "dev"); insert_node(&sub_categ, "stack", true, "dev"); insert_node(&type, "x87", true, "dev"); return true;}





	/* Hardware units tokens. */

	else if (!match_ins_case(str, "ah", false, "dev")) {insert_node(&token, "ah", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8h-bit", true, "dev"); insert_node(&type, "accumulator", true, "dev"); return true;}
	else if (!match_ins_case(str, "al", false, "dev")) {insert_node(&token, "al", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8l-bit", true, "dev"); insert_node(&type, "accumulator", true, "dev"); return true;}
	else if (!match_ins_case(str, "ax", false, "dev")) {insert_node(&token, "ax", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "accumulator", true, "dev"); return true;}
	else if (!match_ins_case(str, "bh", false, "dev")) {insert_node(&token, "bh", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8h-bit", true, "dev"); insert_node(&type, "base", true, "dev"); return true;}
	else if (!match_ins_case(str, "bl", false, "dev")) {insert_node(&token, "bl", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8l-bit", true, "dev"); insert_node(&type, "base", true, "dev"); return true;}
	else if (!match_ins_case(str, "bp", false, "dev")) {insert_node(&token, "bp", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "base_ptr", true, "dev"); return true;}
	else if (!match_ins_case(str, "bpl", false, "dev")) {insert_node(&token, "bpl", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8l-bit", true, "dev"); insert_node(&type, "base_ptr", true, "dev"); return true;}
	else if (!match_ins_case(str, "bx", false, "dev")) {insert_node(&token, "bx", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "base", true, "dev"); return true;}
	else if (!match_ins_case(str, "ch", false, "dev")) {insert_node(&token, "ch", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8h-bit", true, "dev"); insert_node(&type, "counter", true, "dev"); return true;}
	else if (!match_ins_case(str, "cl", false, "dev")) {insert_node(&token, "cl", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8l-bit", true, "dev"); insert_node(&type, "counter", true, "dev"); return true;}
	else if (!match_ins_case(str, "cx", false, "dev")) {insert_node(&token, "cx", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "counter", true, "dev"); return true;}
	else if (!match_ins_case(str, "dh", false, "dev")) {insert_node(&token, "dh", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8h-bit", true, "dev"); insert_node(&type, "data_io", true, "dev"); return true;}
	else if (!match_ins_case(str, "di", false, "dev")) {insert_node(&token, "di", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "destination", true, "dev"); return true;}
	else if (!match_ins_case(str, "dil", false, "dev")) {insert_node(&token, "dil", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8l-bit", true, "dev"); insert_node(&type, "destination", true, "dev"); return true;}
	else if (!match_ins_case(str, "dl", false, "dev")) {insert_node(&token, "dl", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8l-bit", true, "dev"); insert_node(&type, "data_io", true, "dev"); return true;}
	else if (!match_ins_case(str, "dx", false, "dev")) {insert_node(&token, "dx", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "data_io", true, "dev"); return true;}
	else if (!match_ins_case(str, "eax", false, "dev")) {insert_node(&token, "eax", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "32-bit", true, "dev"); insert_node(&type, "accumulator", true, "dev"); return true;}
	else if (!match_ins_case(str, "ebp", false, "dev")) {insert_node(&token, "ebp", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "32-bit", true, "dev"); insert_node(&type, "base_ptr", true, "dev"); return true;}
	else if (!match_ins_case(str, "ebx", false, "dev")) {insert_node(&token, "ebx", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "32-bit", true, "dev"); insert_node(&type, "base", true, "dev"); return true;}
	else if (!match_ins_case(str, "ecx", false, "dev")) {insert_node(&token, "ecx", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "32-bit", true, "dev"); insert_node(&type, "counter", true, "dev"); return true;}
	else if (!match_ins_case(str, "edi", false, "dev")) {insert_node(&token, "edi", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "32-bit", true, "dev"); insert_node(&type, "destination", true, "dev"); return true;}
	else if (!match_ins_case(str, "edx", false, "dev")) {insert_node(&token, "edx", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "32-bit", true, "dev"); insert_node(&type, "data_io", true, "dev"); return true;}
	else if (!match_ins_case(str, "eflag", false, "dev")) {insert_node(&token, "eflag", true, "dev"); insert_node(&categ, "flag", true, "dev"); insert_node(&sub_categ, "32-bit", true, "dev"); insert_node(&type, "flag", true, "dev"); return true;}
	else if (!match_ins_case(str, "esi", false, "dev")) {insert_node(&token, "esi", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "32-bit", true, "dev"); insert_node(&type, "source", true, "dev"); return true;}
	else if (!match_ins_case(str, "esp", false, "dev")) {insert_node(&token, "esp", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "32-bit", true, "dev"); insert_node(&type, "stack_ptr", true, "dev"); return true;}
	else if (!match_ins_case(str, "fpflag", false, "dev")) {insert_node(&token, "fpflag", true, "dev"); insert_node(&categ, "flag", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "fpflag", true, "dev"); return true;}
	else if (!match_ins_case(str, "gdt", false, "dev")) {insert_node(&token, "gdt", true, "dev"); insert_node(&categ, "special", true, "dev"); insert_node(&sub_categ, "limiter", true, "dev"); insert_node(&type, "gdt", true, "dev"); return true;}
	else if (!match_ins_case(str, "idt", false, "dev")) {insert_node(&token, "idt", true, "dev"); insert_node(&categ, "special", true, "dev"); insert_node(&sub_categ, "limiter", true, "dev"); insert_node(&type, "idt", true, "dev"); return true;}
	else if (!match_ins_case(str, "r10", false, "dev")) {insert_node(&token, "r10", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "r10", true, "dev"); return true;}
	else if (!match_ins_case(str, "r10b", false, "dev")) {insert_node(&token, "r10b", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8-bit", true, "dev"); insert_node(&type, "r10", true, "dev"); return true;}
	else if (!match_ins_case(str, "r10w", false, "dev")) {insert_node(&token, "r10w", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "r10", true, "dev"); return true;}
	else if (!match_ins_case(str, "r11", false, "dev")) {insert_node(&token, "r11", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "r11", true, "dev"); return true;}
	else if (!match_ins_case(str, "r11b", false, "dev")) {insert_node(&token, "r11b", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8-bit", true, "dev"); insert_node(&type, "r11", true, "dev"); return true;}
	else if (!match_ins_case(str, "r11w", false, "dev")) {insert_node(&token, "r11w", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "r11", true, "dev"); return true;}
	else if (!match_ins_case(str, "r12", false, "dev")) {insert_node(&token, "r12", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "r12", true, "dev"); return true;}
	else if (!match_ins_case(str, "r12b", false, "dev")) {insert_node(&token, "r12b", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8-bit", true, "dev"); insert_node(&type, "r12", true, "dev"); return true;}
	else if (!match_ins_case(str, "r12w", false, "dev")) {insert_node(&token, "r12w", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "r12", true, "dev"); return true;}
	else if (!match_ins_case(str, "r13", false, "dev")) {insert_node(&token, "r13", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "r13", true, "dev"); return true;}
	else if (!match_ins_case(str, "r13b", false, "dev")) {insert_node(&token, "r13b", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8-bit", true, "dev"); insert_node(&type, "r13", true, "dev"); return true;}
	else if (!match_ins_case(str, "r13w", false, "dev")) {insert_node(&token, "r13w", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "r13", true, "dev"); return true;}
	else if (!match_ins_case(str, "r14", false, "dev")) {insert_node(&token, "r14", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "r14", true, "dev"); return true;}
	else if (!match_ins_case(str, "r14b", false, "dev")) {insert_node(&token, "r14b", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8-bit", true, "dev"); insert_node(&type, "r14", true, "dev"); return true;}
	else if (!match_ins_case(str, "r14w", false, "dev")) {insert_node(&token, "r14w", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "r14", true, "dev"); return true;}
	else if (!match_ins_case(str, "r15", false, "dev")) {insert_node(&token, "r15", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "r15", true, "dev"); return true;}
	else if (!match_ins_case(str, "r15b", false, "dev")) {insert_node(&token, "r15b", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8-bit", true, "dev"); insert_node(&type, "r15", true, "dev"); return true;}
	else if (!match_ins_case(str, "r15w", false, "dev")) {insert_node(&token, "r15w", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "r15", true, "dev"); return true;}
	else if (!match_ins_case(str, "r8", false, "dev")) {insert_node(&token, "r8", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "r8", true, "dev"); return true;}
	else if (!match_ins_case(str, "r8b", false, "dev")) {insert_node(&token, "r8b", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8-bit", true, "dev"); insert_node(&type, "r8", true, "dev"); return true;}
	else if (!match_ins_case(str, "r8w", false, "dev")) {insert_node(&token, "r8w", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "r8", true, "dev"); return true;}
	else if (!match_ins_case(str, "r9", false, "dev")) {insert_node(&token, "r9", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "r9", true, "dev"); return true;}
	else if (!match_ins_case(str, "r9b", false, "dev")) {insert_node(&token, "r9b", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8-bit", true, "dev"); insert_node(&type, "r9", true, "dev"); return true;}
	else if (!match_ins_case(str, "r9w", false, "dev")) {insert_node(&token, "r9w", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "r9", true, "dev"); return true;}
	else if (!match_ins_case(str, "rax", false, "dev")) {insert_node(&token, "rax", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "accumulator", true, "dev"); return true;}
	else if (!match_ins_case(str, "rbp", false, "dev")) {insert_node(&token, "rbp", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "base_ptr", true, "dev"); return true;}
	else if (!match_ins_case(str, "rbx", false, "dev")) {insert_node(&token, "rbx", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "base", true, "dev"); return true;}
	else if (!match_ins_case(str, "rcx", false, "dev")) {insert_node(&token, "rcx", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "counter", true, "dev"); return true;}
	else if (!match_ins_case(str, "rdi", false, "dev")) {insert_node(&token, "rdi", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "destination", true, "dev"); return true;}
	else if (!match_ins_case(str, "rdx", false, "dev")) {insert_node(&token, "rdx", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "data_io", true, "dev"); return true;}
	else if (!match_ins_case(str, "rflag", false, "dev")) {insert_node(&token, "rflag", true, "dev"); insert_node(&categ, "flag", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "flag", true, "dev"); return true;}
	else if (!match_ins_case(str, "rsi", false, "dev")) {insert_node(&token, "rsi", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "source", true, "dev"); return true;}
	else if (!match_ins_case(str, "rsp", false, "dev")) {insert_node(&token, "rsp", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "64-bit", true, "dev"); insert_node(&type, "stack_ptr", true, "dev"); return true;}
	else if (!match_ins_case(str, "si", false, "dev")) {insert_node(&token, "si", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "source", true, "dev"); return true;}
	else if (!match_ins_case(str, "sil", false, "dev")) {insert_node(&token, "sil", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "8l-bit", true, "dev"); insert_node(&type, "source", true, "dev"); return true;}
	else if (!match_ins_case(str, "sp", false, "dev")) {insert_node(&token, "sp", true, "dev"); insert_node(&categ, "gpr", true, "dev"); insert_node(&sub_categ, "16-bit", true, "dev"); insert_node(&type, "stack_ptr", true, "dev"); return true;}





	/* Period tokens (followed by '.'). */

	else if (!match_ins_case(str, ".bss", false, "dev")) {insert_node(&token, ".bss", true, "dev"); insert_node(&categ, "host", true, "dev"); insert_node(&sub_categ, "section", true, "dev"); insert_node(&type, "bss", true, "dev"); return true;}
	else if (!match_ins_case(str, ".data", false, "dev")) {insert_node(&token, ".data", true, "dev"); insert_node(&categ, "host", true, "dev"); insert_node(&sub_categ, "section", true, "dev"); insert_node(&type, "data", true, "dev"); return true;}
	else if (!match_ins_case(str, ".n", false, "dev")) {insert_node(&token, ".n", true, "dev"); insert_node(&categ, "both", true, "dev"); insert_node(&sub_categ, "copy", true, "dev"); insert_node(&type, "non-waiting", true, "dev"); return true;}
	else if (!match_ins_case(str, ".rodata", false, "dev")) {insert_node(&token, ".rodata", true, "dev"); insert_node(&categ, "host", true, "dev"); insert_node(&sub_categ, "section", true, "dev"); insert_node(&type, "r", true, "dev"); return true;}
	else if (!match_ins_case(str, ".text", false, "dev")) {insert_node(&token, ".text", true, "dev"); insert_node(&categ, "host", true, "dev"); insert_node(&sub_categ, "section", true, "dev"); insert_node(&type, "text", true, "dev"); return true;}
	else if (!match_ins_case(str, ".sack", false, "dev")) {insert_node(&token, ".sack", true, "dev"); insert_node(&categ, "host", true, "dev"); insert_node(&sub_categ, "section", true, "dev"); insert_node(&type, "stack", true, "dev"); return true;}
	else if (!match_ins_case(str, ".w", false, "dev")) {insert_node(&token, ".w", true, "dev"); insert_node(&categ, "host", true, "dev"); insert_node(&sub_categ, "copy", true, "dev"); insert_node(&type, "waiting", true, "dev"); return true;}





	/* For identifiers & numerical literals. */

	else {token_fsm_main(str, 0, "dev"); return true;}





	/* Returning the right type. */

	return false;
}