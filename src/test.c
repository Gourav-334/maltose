/* Adding header(s) for unit testing. */

#include "../include/utils/str_verif/case_ins_match.h"

#include <stdio.h>



int main(int argc, char **argv)
{
	match_ins_case("string", "string", true, "debug");
	match_ins_case("STRING", "STRING", true, "debug");
	match_ins_case("stRIng", "stRIng", true, "debug");
	match_ins_case("StRiNg", "StRiNg", true, "debug");
	match_ins_case("STriNG", "stRIng", true, "debug");
	match_ins_case("string", "overflow", true, "debug");
	match_ins_case("string", "overly", true, "debug");
	match_ins_case("STRONG", "STRAIGHT", true, "debug");
	match_ins_case("&**()", "&**()", true, "debug");
	match_ins_case("&**()", "()**&", true, "debug");
	match_ins_case("string", "&**()", true, "debug");


	return 0;
}
