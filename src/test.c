/* Adding header(s) for unit testing. */

#include "../include/utils/str_verif/ill_char_scan.h"

#include <stdio.h>
#include <string.h>



int main()
{
	char *str = "8h3d$9042F#biub78&G";
	
	scan_ill_chars(str, strlen(str), "!@#$%^&*()", "user");


	return 0;
}
