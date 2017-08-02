#ifndef BUCKET_H_
#define BUCKET_H_

	#include <stdio.h>
	#include <stdlib.h>
	#define TAM_MAX_BUCKET 3

	typedef struct balde
	{
		int prof;
		int cont;
		int chaves[TAM_MAX_BUCKET];
		int id;
	} bucket, *ptr_bucket;

	typedef struct celula_diretorio
	{
		bucket *bucket_ref;
	} dir_cell;

	typedef struct diretorio
	{
		int profundidade;
		dir_cell *celula;
	} directory, *ptr_directory;

	extern ptr_directory an_directory;
	extern int id_index;
#endif
