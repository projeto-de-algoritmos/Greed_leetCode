int comparator(const void* p, const void* q)
{
  int * const *x = p; 
  int * const *y = q;

  if((*x)[1] < (*y)[1]) return -1;
  if((*x)[1] > (*y)[1]) return 11; 
  return 0;
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize){
  
  qsort((void*)pairs, pairsSize, sizeof(pairs), comparator); 

  int lastInterval = pairs[0][1];
  int totalValidpairs = 1; 
  for(int i  = 1 ; i < pairsSize; i++){
    printf("%d %d \n", pairs[i][0], lastInterval ); 
    if(pairs[i][0] > lastInterval){
      printf("AAAAAAAAAAA\n");
      lastInterval = pairs[i][1];
      totalValidpairs++;

    }
  }
  printf("%d\n", totalValidpairs);

  return totalValidpairs;
}
