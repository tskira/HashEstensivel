#include "hashing.h"

	int make_address(int key, int profundidade)
	{
		int retval = 0;
		int mask = 1;
		int hashval = key;
		int index;
		int lowbit = 0;

		for(index = 0; index < profundidade; index++)
		{
			retval = retval << 1;
			lowbit = hashval & mask;
			retval = retval | lowbit;
			hashval = hashval >> 1;
		}
		return retval;
	}

	int op_find(int key, ptr_bucket *balde_encontrado)
	{
		int index;
		int address;
		address = make_address(key, an_directory->profundidade);
		(*balde_encontrado) = an_directory->celula[address].bucket_ref;

		for(index = 0; index < (*balde_encontrado)->cont; index++)
		{
			if((*balde_encontrado)->chaves[index] == key) return 1;
		}
		return 0;
	}

	void abrearq(char arqnome[20]){
    	char info[15];
		FILE *arq;

		arq = fopen(arqnome, "r");
		if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
		else
		while( (fgets(info, sizeof(info), arq))!=NULL ){
			int infoint;
			infoint = atoi(info);
			if (infoint <= 999999) op_add(infoint);
			}

		fclose(arq);
	}

	void dir_inst_bucket(bucket *bk, int start, int end){
    		int i;
    		for (i = start; i <= end; i++){
        		an_directory->celula[i].bucket_ref = bk;
    		}
	}

	void bk_split(ptr_bucket balde_alvo)
	{
		ptr_bucket novo_bucket = malloc(sizeof(bucket));
		int new_start, new_end;
		int index;
		int chaves_reinserir[TAM_MAX_BUCKET];
		int size;

		novo_bucket->cont = 0;
		novo_bucket->prof = 0;
		novo_bucket->id = id_index++;
		printf("\nentrou no split");
		if(balde_alvo->prof == an_directory->profundidade)
		{
			 dir_double();
		}

		find_new_range(balde_alvo, &new_start, &new_end);
		dir_inst_bucket(novo_bucket, new_start, new_end);


		balde_alvo->prof = balde_alvo->prof + 1;
		novo_bucket->prof = balde_alvo->prof;

		//redistribuir as chaves entre bucket e novo bucket
		for(index = 0; index < balde_alvo->cont; index++)
		{
			chaves_reinserir[index] = balde_alvo->chaves[index];
		}
		size = index;
		balde_alvo->cont = 0;
		for(index = 0; index < size; index++)
		{
			op_add(chaves_reinserir[index]);
		}
	}

	void dir_double()
	{
		dir_cell *nova_celula;
		int atual_tam = pow (2, an_directory->profundidade);
		int novo_tam = 2 * atual_tam;
		int index;

		nova_celula = malloc(novo_tam * (sizeof(dir_cell)));
		for(index = 0; index < atual_tam; index++)
		{
			nova_celula[2 * index].bucket_ref = an_directory->celula[index].bucket_ref;
			nova_celula[(2 * index) + 1].bucket_ref = an_directory->celula[index].bucket_ref;
		}
		free(an_directory->celula);
		an_directory->celula = nova_celula;
		an_directory->profundidade++;
		printf("\nentrou no double");

	}

	void find_new_range(ptr_bucket bucket_alvo, int *n_start, int *n_end)
	{
		int bits_to_fill;
		int index;
		int shared_addres = make_address(bucket_alvo->chaves[0], bucket_alvo->prof);

		shared_addres = shared_addres << 1;
		shared_addres = shared_addres | 1;
		bits_to_fill = an_directory->profundidade - (bucket_alvo->prof + 1) ;
		*n_start = *n_end = shared_addres;
		for(index = 0; index < bits_to_fill; index++)
		{
			*n_start = *n_start << 1;
			*n_end = *n_end << 1;
			*n_end = *n_end | 1;
		}
		printf("\nentrou no find new range");
	}

	void bk_add_key(bucket *bk, int chave){
		printf("\nentrou em bk add value: %d", chave);
	    if (bk->cont < TAM_MAX_BUCKET)
		{
	        	bk->chaves[bk->cont] = chave;
				bk->cont++;
	    }
	    else
		{
	        bk_split(bk);
	        op_add(chave);
	    }
	}

	void print_directory()
	{
		int index;
		int index_j;
		for (index = 0; index < pow(2 , an_directory->profundidade); index++)
		{
			printf("\ndir[%2d] = bucket #%d", index, an_directory->celula[index].bucket_ref->id );
			for(index_j = 0; index_j < an_directory->celula[index].bucket_ref->cont; index_j++)
			{
				printf("\n\t %d", an_directory->celula[index].bucket_ref->chaves[index_j]);
			}
		}
		printf("\nDirectory current size = %d\n", an_directory->profundidade);
	}

	int op_add(int key)
	{
		ptr_bucket bucket_procurado;
		if(op_find(key, &bucket_procurado)) return 0;
		else bk_add_key(bucket_procurado, key);
		return 1;
	}
