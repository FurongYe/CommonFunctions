// Returns an array of indexes of highest value.

void partition(int *x, int *pos, int begin, int end, int K){
    int i,j;
    int temp,temppos;
    if(end < begin)
        return;
    
    temp = x[begin];
    temppos = pos[begin];
    i = begin;
    j = end;
    while(i < j){
        while(i < j && x[j] < temp){
            j--;
        }
        if(i < j){
            x[i] = x[j];
            pos[i] = pos[j];
        }
        while(i < j && x[i] >= temp){
            i++;
        }
        if(i < j){
            x[j] = x[i];
            pos[j] = pos[i];
        }
    }
    x[i] = temp;
    pos[i] = temppos;
    partition(x, pos, begin, i-1, K);
    partition(x, pos, i+1, end, K);    
}


int * selectIndexofHighestValues(int *x, int length, int K){
    int * pos = (int *)malloc(sizeof(int) *length);
    int i;
    for(i = 0; i < length; ++i) pos[i] = i;
    partition(x,pos,0,length-1,K);
    return pos;
}


