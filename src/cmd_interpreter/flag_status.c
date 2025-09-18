/* Including required headers. */

#include "../../include/cmd_interpreter/flag_status.h"

#include <stdio.h>			// Required to use NULL in subtypes.










/* Instances of each flag. */

struct Flag flag_deb = {.subtype=NULL, .status=false};
struct Flag flag_dev = {.subtype=NULL, .status=false};
struct Flag flag_log = {.subtype=NULL, .status=false};
struct Flag flag_mod = {.subtype=NULL, .status=false};
struct Flag flag_nwr = {.subtype=NULL, .status=false};
struct Flag flag_help = {.subtype=NULL, .status=false};