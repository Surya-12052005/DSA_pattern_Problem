/*int x=5, x=00000101

if left shift ->x multiply by 2
if right shift ->x divide by 2*/

int setBit(int x, int n){
    int m=1<<n;
    return x|m;

}


int resetBit(int x, int n){
    int m=1<<n;
    return x&(~m);
    
    
}

int flipBit(int x, int n){
    int m=1<<n;
    return x^m;
    
}

int getBit(int x, int n){
    int m=1<<n;
    if(x&m==0)
    return 0;
    else
    return 1;
    
}

/*find the number of set bits in binary representation of a number*/