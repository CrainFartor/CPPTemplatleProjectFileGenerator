#include <stdio.h>
#include <string.h>
#include "col.h"
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../lib/template_strings.h"
//----------------------------------------Validacion----------------------------------------
int	is_valid(char c){
	if(	((c >= '0') && (c <= '9')) ||
			((c >= 'a') && (c <= 'z')) ||
			((c >= 'A') && (c <= 'Z')) ||
			(c == '-') || (c == '_')  ){
			return 1;
		}
		else{
			return 0;
		}
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
int validar_input(char const *argv[]){
	int i = 0;

	for(i=0;i<strlen(argv[1]);i++){
		if(	1 == is_valid(*(*(argv+1)+i))	){
			//printf("char: %c valido\n", *(*(argv+1)+i) );
		}
		else{
			printf(ACR "Error:" ACS
			" el nombre es invalido el caracter: "
			ACG "%c" ACS
			" no se permite para nombres de proyecto\n", *(*(argv+1)+i) );
			return -2;
		}
	}

	return 1;
}
//----------------------------------------Validacion----------------------------------------
//------------------------------------------------------------------------------------------
//---------------------------------Generadores Individuales---------------------------------
int generar_make(char *arg, template_file *file){
	FILE *f = NULL;
	char buffer[200] = {0};

	snprintf(buffer, 200, "./%s", arg);

	mkdir(buffer, S_IRWXU);

	snprintf(buffer, 200, "%s/makefile", arg);

	f = fopen(buffer,"w");

	fwrite(file->body, sizeof(char), file->len, f);

	fclose(f);

	return 0;
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
int generar_main(char *arg, template_file *file){
	FILE *f = NULL;
	char buffer[200] = {0};

	snprintf(buffer, 200, "./%s/src", arg);

	mkdir(buffer, S_IRWXU);

	snprintf(buffer, 200, "%s/src/main.cpp", arg);

	f = fopen(buffer,"w");

	fwrite(file->body, sizeof(char), file->len, f);

	fclose(f);

	return 0;
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
int generar_libc(char *arg, template_file *file){
	FILE *f = NULL;
	char buffer[200] = {0};

	snprintf(buffer, 200, "./%s/lib", arg);

	mkdir(buffer, S_IRWXU);

	snprintf(buffer, 200, "%s/lib/lib.cpp", arg);

	f = fopen(buffer,"w");

	fwrite(file->body, sizeof(char), file->len, f);

	fclose(f);

	return 0;
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
int generar_libh(char *arg, template_file *file){
	FILE *f = NULL;
	char buffer[200] = {0};

	snprintf(buffer, 200, "./%s/lib", arg);

	mkdir(buffer, S_IRWXU);

	snprintf(buffer, 200, "%s/lib/lib.h", arg);

	f = fopen(buffer,"w");

	fwrite(file->body, sizeof(char), file->len, f);

	fclose(f);

	return 0;
}
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
int generar_defs(char *arg, template_file *file){
	FILE *f = NULL;
	char buffer[200] = {0};

	snprintf(buffer, 200, "./%s/def", arg);

	mkdir(buffer, S_IRWXU);

	snprintf(buffer, 200, "%s/def/def.h", arg);

	f = fopen(buffer,"w");

	fwrite(file->body, sizeof(char), file->len, f);

	fclose(f);

	return 0;
}
//---------------------------------Generadores Individuales---------------------------------
//------------------------------------------------------------------------------------------
//----------------------------------------Generador-----------------------------------------
int generar_archivos(char *proyecto){
	int i=0;
	int (*generador[6])(char *arg, template_file *file) = {
		generar_make,
		generar_main,
		generar_libc,
		generar_libh,
		generar_defs,
		NULL
	};

	template_file tp_make = { make, make_len };
	template_file tp_main_cpp = { main_cpp, main_cpp_len };
	template_file tp_def = { def, def_len };
	template_file tp_libh = { libh, libh_len };
	template_file tp_libc = { libc, libc_len };

	template_file files_array[6] = {
		tp_make,
		tp_main_cpp,
		tp_libc,
		tp_libh,
		tp_def,
		NULL
	};

	for(i=0; generador[i]!=NULL ; i++){
		generador[i](proyecto, &files_array[i]);
	}
	return 0;
}
//----------------------------------------Generador-----------------------------------------
