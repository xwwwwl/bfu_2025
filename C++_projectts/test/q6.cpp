void sss(int *a,int *b){
if (a!=nullptr & b!=nullptr & a!=b){
        int p = *a;
        *a=*b;
        *b=p;
    }
}