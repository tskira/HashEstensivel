#include <stdio.h>

#include "hashing.h"

	int main()
	{
		an_directory = malloc(sizeof(directory));
		an_directory->profundidade = 0;
		an_directory->celula = malloc(sizeof(dir_cell));
		an_directory->celula->bucket_ref = malloc(sizeof(bucket));
		an_directory->celula->bucket_ref->cont = 0;
		an_directory->celula->bucket_ref->prof = 0;
		an_directory->celula->bucket_ref->id = 0;
		abrearq("chaves.txt");
		print_directory();
		return 0;
	}
