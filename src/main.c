#include <stdio.h>
#include <string.h>
#include "../def/def.h"
#include "../lib/col.h"
#include "../lib/lib.h"
#include "../lib/template_strings.h"

int main(int argc, char const *argv[]) {
	//FILE * fp_make, fp_main, fp_libc, fp_libh, fp_defs;

	if(argc < 2){
		printf(ACR "Error:" ACS
		" se requiere por lo menos un argumento\n" );
		return -1;
	}

	else{
		if(1 == validar_input(argv)){
			generar_archivos(argv[1]);
		}
		else{
			return -1;
		}
	}

	return 0;
}
