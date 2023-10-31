int comparator(const void* p, const void* q)
{
  int * const *x = p; 
  int * const *y = q;

  if((*x)[1] < (*y)[1]) return -1;
  if((*x)[1] > (*y)[1]) return 11; 
  return 0;
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
  
  qsort((void*)intervals, intervalsSize, sizeof(intervals), comparator); 

  int lastInterval = intervals[0][1];
  int totalValidIntervals = 0; 
  for(int i  = 1 ; i < intervalsSize; i++){
    if(intervals[i][0] >= lastInterval){
      lastInterval = intervals[i][1];
    }
    else{
      totalValidIntervals++;
    }

  }
  printf("%d\n", totalValidIntervals);

  return totalValidIntervals;
}

