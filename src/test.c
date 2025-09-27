/* Adding header(s) for unit testing. */

#include "../include/lexer/x86/token_recog.h"
#include "../include/lexer/x86/token_store.h"
#include "../include/data_structs/linked_list/full_remover.h"

#include <stdio.h>



int main(int argc, char **argv)
{
	printf("section: %b, ", token_recog("section")); printf("%s(%p)\n", type.tail->data, type.tail);
	printf("rodata: %b, ", token_recog("rodata")); printf("%s(%p)\n", type.tail->data, type.tail);
	printf(".rodata: %b, ", token_recog(".rodata")); printf("%s(%p)\n", type.tail->data, type.tail);
	printf("log: %b, ", token_recog("log")); printf("%s(%p)\n", type.tail->data, type.tail);
	printf("rigid: %b, ", token_recog("rigid")); printf("%s(%p)\n", type.tail->data, type.tail);
	printf("byte: %b, ", token_recog("byte")); printf("%s(%p)\n", type.tail->data, type.tail);
	printf("word: %b, ", token_recog("word")); printf("%s(%p)\n", type.tail->data, type.tail);
	printf("RAX: %b, ", token_recog("RAX")); printf("%s(%p)\n", type.tail->data, type.tail);
	printf("Ebx: %b, ", token_recog("Ebx")); printf("%s(%p)\n", type.tail->data, type.tail);
	printf("SeCtIoN: %b, ", token_recog("section")); printf("%s(%p)\n", type.tail->data, type.tail);
	printf("0xdeadBEEF: %b, ", token_recog("0xdeadBEEF")); printf("%s(%p)\n", type.tail->data, type.tail);
	printf("010101000b: %b, ", token_recog("010101000b")); printf("%s(%p)\n", type.tail->data, type.tail);
	printf("\"A string!\": %b, ", token_recog("\"A string!\"")); printf("%s(%p)\n", type.tail->data, type.tail);
	printf("\': %b, ", token_recog("\'")); printf("%s(%p)\n", type.tail->data, type.tail);


	return 0;
}
