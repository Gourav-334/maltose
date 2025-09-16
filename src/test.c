/* Adding header(s) for unit testing. */

#include "../include/cmd_interpreter/flag_status.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
	flag_mod.subtype = malloc(6);
	strcpy(flag_mod.subtype, "host\0");
	strcpy(flag_mod.subtype, "metal\0");
	flag_mod.status = true;

	printf("deb.subtype=%s, deb.status=%b\n", flag_deb.subtype, flag_deb.status);
	printf("dev.subtype=%s, dev.status=%b\n", flag_dev.subtype, flag_dev.status);
	printf("log.subtype=%s, log.status=%b\n", flag_log.subtype, flag_log.status);
	printf("mod.subtype=%s, mod.status=%b\n", flag_mod.subtype, flag_mod.status);
	printf("opt.subtype=%s, opt.status=%b\n", flag_opt.subtype, flag_opt.status);
	printf("nwr.subtype=%s, nwr.status=%b\n", flag_nwr.subtype, flag_nwr.status);


	return 0;
}
