#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>





#define PAGE_SIZE 0x1000

/* ELF constants */

#define EI_NIDENT 16
#define PT_LOAD   1
#define ET_EXEC   2
#define EM_X86_64 62
#define EV_CURRENT 1

#define PF_X 0x1
#define PF_W 0x2
#define PF_R 0x4





/* Machine instructions for: write(1, msg, 14); exit(0); */

uint8_t code[] = {
  0xb8, 0x01, 0x00, 0x00, 0x00,               // mov $1, %eax
  0xbf, 0x01, 0x00, 0x00, 0x00,               // mov $1, %edi
  0x48, 0x8d, 0x35, 0x0e, 0x00, 0x00, 0x00,   // lea 0xe + %rip, %rsi
  0xba, 0x0e, 0x00, 0x00, 0x00,               // mov $14, %edx
  0x0f, 0x05,                                 // syscall
  0xb8, 0x3c, 0x00, 0x00, 0x00,               // mov $60, %eax
  0x31, 0xff,                                 // xor %edi, %edi
  0x0f, 0x05,                                 // syscall
  'H','e','l','l','o',',',' ',                // # The message
  'w','o','r','l','d','\n', 0
};



/* ELF Header struct */

struct __attribute__((packed)) Elf64_Ehdr {
  uint8_t  e_ident[EI_NIDENT];
  uint16_t e_type;
  uint16_t e_machine;
  uint32_t e_version;
  uint64_t e_entry;
  uint64_t e_phoff;
  uint64_t e_shoff;
  uint32_t e_flags;
  uint16_t e_ehsize;
  uint16_t e_phentsize;
  uint16_t e_phnum;
  uint16_t e_shentsize;
  uint16_t e_shnum;
  uint16_t e_shstrndx;
};



/* Program Header struct */

struct __attribute__((packed)) Elf64_Phdr {
  uint32_t p_type;
  uint32_t p_flags;
  uint64_t p_offset;
  uint64_t p_vaddr;
  uint64_t p_paddr;
  uint64_t p_filesz;
  uint64_t p_memsz;
  uint64_t p_align;
};





int main()
{
  FILE *fp = fopen("out/hello", "wb");
  if (!fp) {perror("fopen"); return 1;}



  struct Elf64_Ehdr ehdr = {0};
  

  /* memcpy(ehdr.e_ident, "\x7f""ELF", 4); */

  ehdr.e_ident[0] = 0x7f;
  ehdr.e_ident[1] = 'E';
  ehdr.e_ident[2] = 'L';
  ehdr.e_ident[3] = 'F';
  ehdr.e_ident[4] = 2;        // 64-bit
  ehdr.e_ident[5] = 1;        // Little endian
  ehdr.e_ident[6] = 1;        // ELF version
  ehdr.e_type = ET_EXEC;
  ehdr.e_machine = EM_X86_64;
  ehdr.e_version = EV_CURRENT;
  ehdr.e_entry = 0x400078;
  ehdr.e_phoff = sizeof(ehdr);
  ehdr.e_ehsize = sizeof(ehdr);
  ehdr.e_phentsize = sizeof(struct Elf64_Phdr);
  ehdr.e_phnum = 1;



  /* ELF program header */

  struct Elf64_Phdr phdr = {
    .p_type = PT_LOAD,
    .p_flags = PF_R | PF_W | PF_X;  // PF_X | PF_R
    .p_offset = 0,
    .p_vaddr = 0x400000,
    .p_paddr = 0x400000,
    .p_filesz = sizeof(ehdr) + sizeof(phdr) + sizeof(code),
    .p_memsz = sizeof(ehdr) + sizeof(phdr) + sizeof(code),
    .p_align = PAGE_SIZE
  };



  fwrite(&ehdr, sizeof(ehdr), 1, fp);
  fwrite(&phdr, sizeof(phdr), 1, fp);
  fwrite(code, sizeof(code), 1, fp);

  //write(1, "Hello, world\n", 14);


  fclose(fp);
  printf("ELF binary 'hello' generated in out/\n");


  return 0;
}
