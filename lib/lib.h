#ifndef	LIBRERIAS
#define	LIBRERIAS	255

#include "../lib/template_strings.h"

int	is_valid(char c);
int validar_input(char const *argv[]);

int generar_archivos(char *proyecto);

int generar_make(char *arg, template_file *file);
int generar_main(char *arg, template_file *file);
int generar_libc(char *arg, template_file *file);
int generar_libh(char *arg, template_file *file);
int generar_defs(char *arg, template_file *file);

#endif
