#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void counting_sort(int *array, int k_max,int lenght,int *sorted_array) {

    // create array count with size k_max+1 and fill it with 0
    int *count = malloc((k_max+1) * sizeof(int));
    for (int i = 0; i < k_max+1; i++) {
        count[i] = 0;
    }

    // count the number of times each element appears in array and store it in count
    for (int j=0; j<lenght ; j++) {
        count[array[j]]=count[array[j]]+1;
    }

    //accumulative sum of count
    for (int i =1; i<k_max+1; i++) {
            count[i]=count[i]+count[i-1];
    }
    //create sorted_array using the acumulative sum of count, but calling the elements of array
    for (int j=lenght-1; j>=0; j--) {
        sorted_array[count[array[j]]-1]=array[j]; //substract 1 because a 1 in the count array doesn't mean that there is an element before, but it is the first element
        count[array[j]]=count[array[j]]-1;
    }

    }


void enqueue(int *array,int lenght,int digitos,int *array_temp,int **queue){
        for (int j=0; j<10 ;j++){   // search the numbers from 0 to 9 in array_temp
            int r=0;
            for (int i =0; i<lenght;i++){   // search in the array_temp the numbers that match with j
                if (array_temp[i]==j){
                    queue[j][r]=array[i];
                    r++;
                }
            }
        }
    }

void dequeue(int lenght,int **queue,int *array){
    int indice_sorted_array=0;
    for (int j=0; j<10 ;j++){   // search the numbers from 0 to 9 in array_temp
        int i=0;
        while (queue[j][i]!=0){ // we will search in the queue until we find a 0, this means that there are no more elements in the queue
                array[indice_sorted_array]=queue[j][i];
                indice_sorted_array++;
            i++;
        }
        }

    }
    

void radix_sort(int *array,int k_max,int lenght,int *sorted_array){
    //find the number of digits of the max number
    int digitos=0;
    while(k_max!=0){
        k_max=k_max/10;
        digitos++;
    }

    for (int m=0;m<digitos;m++){
        //create array_temp with size lenght
        int *array_temp=malloc(sizeof(int)*lenght);
        for (int j=0; j<lenght ;j++){
            array_temp[j]=(array[j] % (int)pow(10, m + 1) -array[j] % (int)pow(10, m))/((int)pow(10, m));
        }

        //create queue matrix with size (10,length)
        int **queue=malloc(sizeof(int*)*10);
        for (int j=0; j<10 ;j++){
            queue[j]=malloc(sizeof(int)*lenght);
        }

        //fill queue with 0
        for (int j=0; j<10 ;j++){
            for (int i=0; i<lenght ;i++){
                queue[j][i]=0;
            }
        }

        //call the functions enqueue and dequeue
        enqueue(array,lenght,digitos,array_temp,queue);
        dequeue(lenght,queue,array);
        }

    //copy array  to sorted_array (this is necesary because we want to return to python 'sorted array')
    for (int i=0;i<lenght;i++){
        sorted_array[i]=array[i];
    }
    
}



int hash(int x){
    return x/3; //this hash function is not the best, but it works. It is not the best because it doesn't distribute the elements uniformly
}

//insertion sort algorithm
void insertion_sort(int **array,int lenght,int indice_bucket){
    for(int i=1;i<lenght;i++){
        int key=array[indice_bucket][i];
        int j=i-1;
        while(j>=0 && array[indice_bucket][j]>key){
            array[indice_bucket][j+1]=array[indice_bucket][j];
            j=j-1;
        }
        array[indice_bucket][j+1]=key;
        }
    }

//this function sort each bucket and copy the elements of the buckets to the sorted array
void sortedB_to_sortedA(int **sortedB,int *sortedA,int lenght){
    int indice_sortedA=0;
    for (int i=0;i<lenght;i++){
        int lenght_each_bucket=0;
        while(sortedB[i][lenght_each_bucket]!=-1){
            lenght_each_bucket++;
        }
        insertion_sort(sortedB,lenght_each_bucket,i);
        for (int j=0;j<lenght_each_bucket;j++){
            sortedA[indice_sortedA]=sortedB[i][j];
            indice_sortedA++;
        }
        
    }
}


//bucket sort algorithm
void bucket_sort(int *array,int k_max,int lenght,int *sorted_array){
    //create buckets matrix with size (k_max/3+1,length)
    int k=0;
    int num_buckets=k_max/3+1;
    int **buckets=malloc(sizeof(int*)*num_buckets);

    for (int i=0;i<num_buckets;i++){
        buckets[i]=malloc(sizeof(int)*lenght);
    }

    //fill buckets with -1 (is like a null value)
    for (int j=0; j<num_buckets ;j++){
        for (int i=0; i<lenght ;i++){
            buckets[j][i]=-1;
        }
    }

    //mapping the elements of array to buckets
    for (int i=0;i<lenght;i++){
        k=hash(array[i]);
        int indice_bucket=0;
        int stop_seach=0;       //this is to stop the while loop when we find a -1 in the bucket
        while (stop_seach==0)   //move the element to its bucket, but if the bucket is not empty, move it to the next position
        {
            if (buckets[k][indice_bucket]==-1){
                buckets[k][indice_bucket]=array[i];
                stop_seach=1;
            }
            else{
                indice_bucket++;
            }
            
        }
    }
    
    //sort each bucket and copy the elements of the buckets to the sorted array, at the end we will have the sorted array
    sortedB_to_sortedA(buckets,sorted_array,num_buckets);
}






//this main function can be used to test the algorithms, but we will call the functions from python
int main() {
    int array[] = {8124, 2, 18, 70, 8123, 9, 15, 300, 1, 12};
    int length = sizeof(array) / sizeof(array[0]);  // Obtener la longitud del array

    int * sorted_array = malloc(sizeof(int) * length);
    
    bucket_sort(array,8124,length,sorted_array);
    

    return 0;
    
}


    






    


