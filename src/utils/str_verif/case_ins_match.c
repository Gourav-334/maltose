/* Including required headers. */

#include "../../../include/utils/str_verif/case_ins_match.h"

#include <stdio.h>		// To provide feedback to user as per mode.
#include <string.h>		// To measure length of strings.










/* Matches two strings irrespective of casing (case-insensitive matching). */

int match_ins_case(char *str1, char *str2, bool full_match, char *mode)
{
	/* Variable declarations/definitions. */

	int str_len;
	int count = 0;
	short int type;
	bool mismatch = false;





	/* Non-linear structures declarations/definitions. */

	enum Mode{DEV, USER, DEBUG} M;





	/* Checking which mode is used for function. */

	if (!strcmp(mode,"dev")) {M = DEV;}
	else if (!strcmp(mode,"user")) {M = USER;}
	else if (!strcmp(mode,"debug")) {M = DEBUG;}
	else
	{
		printf("ERROR: Mode named \"%s\" doesn't exist!\n", mode);
		return 1;
	}










	/* Checking if length of both the string are same or not. */

	str_len = (int)strlen(str1);



	/* Providing feedback as per chosen mode. */

	if (str_len==(int)strlen(str2))
	{
		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG) {printf("OK :: len(\"%s\") = len(\"%s\") = %d\n", str1, str2, str_len);}
	}
	else
	{
		if (M==DEV) {}
		else if (M==USER) {printf("ERROR: Length of both the strings don't match!\n");}
		else if (M==DEBUG) {printf("ERROR :: len(\"%s\")!=len(\"%s\") :: len(\"%s\")=%d\n", str1, str2, str1, str_len);}

		return 1;
	}








	

	/* Checking each character in loop. */

	for (int i=0; i<str_len; i++)
	{
		/* Categorizing the character of 'str1' into something. */

		if (*(str1+i)>='a' && *(str1+i)<='z') {type = LOWERCASE;}
		else if (*(str1+i)>='A' && *(str1+i)<='Z') {type = UPPERCASE;}
		else {type = OTHER;}





		/* Providing feedback as per the programmer. */

		if (M==DEV) {}
		else if (M==USER) {}
		else if (M==DEBUG)
		{
			printf("STAT: str1[%d]=\'%c\' :: str2[%d]=\'%c\' :: type(\"%s\")=%d :: str_len=%d\n",
				i, *(str1+i), i, *(str2+i), str1, type, str_len);
		}





		/* Checking as per the category. */

		if (type==LOWERCASE)
		{
			if (*(str1+i)==*(str2+i)) {continue;}
			else if (*(str1+i)==*(str2+i)+LWR2UPR_DIFF) {continue;}
			else
			{
				count++;
				if (full_match==false) {mismatch = true; break;}
			}
		}
		else if (type==UPPERCASE)
		{
			if (*(str1+i)==*(str2+i)) {continue;}
			else if (*(str1+i)==*(str2+i)-LWR2UPR_DIFF) {continue;}
			else
			{
				count++;
				if (full_match==false) {mismatch = true; break;}
			}
		}
		else
		{
			if (*(str1+i)==*(str2+i)) {continue;}
			else
			{
				count++;
				if (full_match==false) {mismatch = true; break;}
			}
		}
	}





	/* Providing feedback as per requested mode. */

	if (M==DEV) {}
	else if (M==USER) {printf("STAT: Total %d mismatches found.\n", count);}
	else if (M==DEBUG) {printf("STAT :: count=%d\n", count);}



	/* Returning count of unmatching characters. */

	return count;
}