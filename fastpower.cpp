//计算(n^m)%k
int ksm(int n,int m,int k){
    int res = 1;
    while(m){
        if(m%2){
            res=(res*n)%k;
        }
        n = n * n % k;
        m /= 2;
    }
    return res;
}
