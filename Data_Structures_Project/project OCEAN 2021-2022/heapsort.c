#include <stdio.h>
#include <stdlib.h>



typedef struct Okeanos
{
    int mhnas, mera, xronos;
    float thermokrasia, phosphate, silicate, nitrite, nitrate, salinity, oxygen;
    
}Okeanos;

int FileCounter(FILE* fp);
void heapify(Okeanos c[], int n, int i);
void heapSort(Okeanos c[], int n);
void printArray(Okeanos c[], int n);
void swap(int *a, int *b);
void countingSort(int array[],Okeanos c[], int size);

int main(){
    FILE *fp;
    fp = fopen("project.csv","r+");
    if (fp == NULL) {exit(1);}

    int count=FileCounter(fp);
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
    
    heapSort(OkeanosArray,count);
    printArray(OkeanosArray,count);
    
   
}
   
    
  
   



int FileCounter (FILE* fp){
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
  
  void heapify(Okeanos c[], int n, int i) {
    int max = i; //Initialize max as root
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
  
    //If left child is greater than root
    if (leftChild < n && c[leftChild].phosphate > c[max].phosphate)
      max = leftChild;
  
    //If right child is greater than max
    if (rightChild < n && c[rightChild].phosphate > c[max].phosphate)
      max = rightChild;
  
    //If max is not root
    if (max != i) {
      swap(&c[i].phosphate, &c[max].phosphate);
      swap(&c[i].mera,&c[max].mera);
      swap(&c[i].mhnas,&c[max].mhnas);
      swap(&c[i].xronos,&c[max].xronos);
      //heapify the affected sub-tree recursively
      heapify(c, n, max);
    }
  }

  //Main function to perform heap sort
  void heapSort(Okeanos c[], int n) {
    //Rearrange array (building heap)
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
      heapify(c, n, i);
 
    //Extract elements from heap one by one
    int j;
    for (j = n - 1; j >= 0; j--) {
      swap(&c[0].phosphate, &c[j].phosphate); //Current root moved to the end
      swap(&c[0].mera,&c[j].mera);
      swap(&c[0].mhnas,&c[j].mhnas);
      swap(&c[0].xronos,&c[j].xronos);
  
      heapify(c, j , 0); //calling max heapify on the heap reduced
    }
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