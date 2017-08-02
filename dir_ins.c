void dir_ins_bucket(balde *bk, int start, int end){
    int i;
    for (i = start; i < end; i++){
        directory->celula[i].bucket_ref = bk;
    }
}
