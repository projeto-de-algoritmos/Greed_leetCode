#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000001
// Define a struct to represent ClassRooms in the heap.

// Define a struct to represent ClassRooms in the heap.
typedef struct {
    int classbegin;
    int classend;
} ClassRoom;


ClassRoom* heap; // Array of pointers
int size = 0;

void swap(ClassRoom *a, ClassRoom *b) {
    
    ClassRoom *temp =  malloc(sizeof(ClassRoom));
    memcpy(temp, a, sizeof(ClassRoom));
    memcpy(a, b, sizeof(ClassRoom));
    memcpy(b, temp, sizeof(ClassRoom));    
}
int comparator(const void* p, const void* q)
{   
    if(((ClassRoom*)p)->classbegin < ((ClassRoom*)q)->classbegin) return -1;
    if(((ClassRoom*)p)->classbegin > ((ClassRoom*)q)->classbegin) return 1;
    return 0;
}
void min_heapify(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < size && heap[left].classend < heap[smallest].classend) {
        smallest = left;
    }

    if (right < size && heap[right].classend < heap[smallest].classend) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        min_heapify(smallest);
    }
}

void insert(ClassRoom *ClassRoom,int pos ) {
    if (size >= MAX_SIZE) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    memcpy(&heap[size], &ClassRoom[pos], sizeof(*ClassRoom)); 
    int current = size;

    while (current > 0 && heap[current].classend < heap[(current - 1) / 2].classend) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
    
    size++;
}

ClassRoom* extract_min() {
    if (size <= 0) {
        printf("Heap is empty. Cannot extract minimum.\n");
        return NULL;
    }

    ClassRoom* min = (ClassRoom*) malloc(sizeof(ClassRoom));
    memcpy(&min[0],  &heap[0], sizeof(ClassRoom*));
    memcpy(&heap[0], &heap[size - 1], sizeof(ClassRoom*));

    size--;
    min_heapify(0);
    return min;
}



int minGroups(int** intervals, int intervalsSize, int* intervalsColSize){
    int arraySize = intervalsSize;
    size = 0; 
    ClassRoom* ClassRooms = (ClassRoom*)malloc(arraySize*sizeof(ClassRoom)); 
    heap = (ClassRoom*) malloc(MAX_SIZE*sizeof(ClassRoom)); 

    for(int i = 0 ; i < intervalsSize ; i++){
        ClassRooms[i].classbegin = intervals[i][0];
        ClassRooms[i].classend = intervals[i][1];
    }

    qsort((void*)ClassRooms, intervalsSize, sizeof(ClassRoom), comparator); 
    
    insert(ClassRooms,0);
    int groups = 1; 

    for (int i = 1; i < arraySize; i++) {
        // printf("%d [\n", heap[0].classend);

        if(ClassRooms[i].classbegin >= heap[0].classend){
            extract_min();
        }
        else{
            groups++;
        }
        insert(ClassRooms, i);
    }
    
    printf("%d\n", groups);

    return groups;
}