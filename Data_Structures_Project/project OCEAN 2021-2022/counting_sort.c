#include <stdio.h>
#include <stdlib.h>



typedef struct Okeanos
{
    int mhnas, mera, xronos;
    float thermokrasia, phosphate, silicate, nitrite, nitrate, salinity, oxygen;
    
}Okeanos;

int FileOpener(FILE* fp);
void printArray(Okeanos c[], int n);
void swap(int *a, int *b);
void countingSort(int array[],Okeanos c[], int size);

int main(){
    FILE *fp;
    fp = fopen("project.csv","r+");
    if (fp == NULL) {exit(1);}

    int count=FileOpener(fp);
    fp = fopen("project.csv","r+");

    Okeanos OkeanosArray[count];
    int i=0;
    int mhnas, mera, xronos;
    mhnas=mera=xronos=0;
    float thermokrasia, phosphate, silicate, nitrite, nitrate, salinity, oxygen;
    thermokrasia=phosphate=silicate=nitrite=nitrate=salinity=oxygen=0.0;
    char c;
    for (c = fgetc(fp); c != '\n' && c != EOF; c=fgetc(fp)){};
    

    while (c!=EOF) 
    {
        fscanf(fp, "%d/%d/%d, %f, %f, %f, %f, %f, %f, %f", &mhnas, &mera, &xronos, &thermokrasia, &phosphate, &silicate, &nitrite, &nitrate, &salinity, &oxygen);
        OkeanosArray[i].mhnas=mhnas;
        OkeanosArray[i].mera=mera;
        OkeanosArray[i].xronos=xronos;
        OkeanosArray[i].thermokrasia=thermokrasia;
        OkeanosArray[i].phosphate=phosphate;
        OkeanosArray[i].silicate=silicate;
        OkeanosArray[i].nitrite=nitrite;
        OkeanosArray[i].nitrate=nitrate;
        OkeanosArray[i].salinity=salinity;
        OkeanosArray[i].oxygen=oxygen;
        c=getc(fp);
        if (c == '\n') {i++;}
    }
    

  
  
   int CountingList[count];
   int j;
   
   for(j=0; j<count; j++){
     CountingList[j]=OkeanosArray[j].phosphate*100;
   }
   /*
   for(j=0; j<count; j++){
       printf("%d\n",CountingList[j]);
   }
   */
   
  //int length = sizeof(CountingList) / sizeof(CountingList[0]);
  
   countingSort(CountingList,OkeanosArray,count);
   
}
   
    
  
   



int FileOpener (FILE* fp){
int counter = 0;
char c;
for (c = fgetc(fp); c != '\n' && c != EOF; c=fgetc(fp)){};
for (c=fgetc(fp); c!=EOF; c=fgetc(fp))
{
    if (c == '\n')
    {
        counter++;
    }
}
    counter++;
    return counter;
}

  
  void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  }
  
 
  /* Function to print an array */
/* Function to print an array */
void printArray(Okeanos c[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("Date: %d/%d/%d ||phosphate: %f \n",c[i].mhnas,c[i].mera,c[i].xronos,c[i].phosphate);
    printf("\n");
}












void countingSort(int array[],Okeanos c[], int size) {
  int output[size];

  // Find the largest element of the array
  int max = array[0];
  int i;
  for ( i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // The size of count must be at least (max+1) but
  // we cannot declare it as int count(max+1) in C as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int count[size];

  // Initialize count array with all zeros.
  for ( i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
      swap(&c[count[array[i]] - 1].mera,&c[i].mera);
      swap(&c[count[array[i]] - 1].mhnas,&c[i].mhnas);
      swap(&c[count[array[i]] - 1].xronos,&c[i].xronos);
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (i = 0; i < size; i++) {
    array[i] = output[i];
  }


   for (i = 0; i < size; ++i) {
    printf("Date: %d/%d/%d ||phosphate: %d \n",c[i].mhnas,c[i].mera,c[i].xronos,array[i]);
  }
  printf("\n");
}