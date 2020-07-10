#ifndef	STRINGS
#define	STRINGS	250

typedef struct Template_file{
	const unsigned char *body;
	const unsigned int len;
}template_file;

const extern unsigned char make[];
const extern unsigned int make_len;

const extern unsigned char main_cpp[];
const extern unsigned int main_cpp_len;

const extern unsigned char def[];
const extern unsigned int def_len;

const extern unsigned char libh[];
const extern unsigned int libh_len;

const extern unsigned char libc[];
const extern unsigned int libc_len;
#endif
