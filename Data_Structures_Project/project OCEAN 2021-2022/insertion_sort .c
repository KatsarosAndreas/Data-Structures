#include <stdio.h>
#include <stdlib.h>



typedef struct Okeanos
{
    int mhnas, mera, xronos;
    float thermokrasia, phosphate, silicate, nitrite, nitrate, salinity, oxygen;
    
}Okeanos;

int FileOpener(FILE* f);
void insertionSort(Okeanos c[], int n);
void printArray(Okeanos c[], int n);
int main(){
    FILE *f;
    f = fopen("project.csv","r+");
    if (f == NULL) {exit(1);}

    int count=FileOpener(f);
    
    f = fopen("project.csv","r+");

    Okeanos OkeanosArray[count];
    int i=0;
    int mhnas, mera, xronos;
    mhnas=mera=xronos=0;
    float thermokrasia, phosphate, silicate, nitrite, nitrate, salinity, oxygen;
    thermokrasia=phosphate=silicate=nitrite=nitrate=salinity=oxygen=0.0;
    char c;
    for (c = fgetc(f); c != '\n' && c != EOF; c=fgetc(f)){};
    

    while (c!=EOF) 
    {
        fscanf(f, "%d/%d/%d, %f, %f, %f, %f, %f, %f, %f", &mhnas, &mera, &xronos, &thermokrasia, &phosphate, &silicate, &nitrite, &nitrate, &salinity, &oxygen);
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
        c=getc(f);
        if (c == '\n') {i++;}
    }
    
    /*
    for(i = 0; i<count; i++){
    	printf("%d / %d / %d \n", OkeanosArray[i].mhnas , OkeanosArray[i].mera , OkeanosArray[i].xronos);
    	
	} */
  
  insertionSort(OkeanosArray,count);
  printArray(OkeanosArray,count); 
  
 
  
  
    
}



int FileOpener (FILE* f)
{
int counter = 0;
char c;
for (c = fgetc(f); c != '\n' && c != EOF; c=fgetc(f)){};
for (c=fgetc(f); c!=EOF; c=fgetc(f))
{
    if (c == '\n')
    {
        counter++;
    }
}
    counter++;
    return counter;
}







//INSERTION SORT
void insertionSort(Okeanos c[], int n)
{
    int i,  j;
    float key,key1,key2,key3;
    for (i = 1; i < n; i++) {
        key = c[i].thermokrasia;
        key1=c[i].mera;
        key2=c[i].mhnas;
        key3=c[i].xronos;
        j = i - 1;
 
   
        while (j >= 0 && c[j].thermokrasia > key) {
            c[j+1].thermokrasia = c[j].thermokrasia;
            c[j+1].mera = c[j].mera;
            c[j+1].mhnas = c[j].mhnas;
            c[j+1].xronos = c[j].xronos;
            j = j - 1;
        }
       c[j+1].thermokrasia = key;
        c[j+1].mera = key1;
        c[j+1].mhnas = key2;
        c[j+1].xronos = key3;
    }
}
 

//ENDS HERE

/* Function to print an array */
void printArray(Okeanos c[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("Date: %d/%d/%d ||thermokrasia: %f \n",c[i].mhnas,c[i].mera,c[i].xronos,c[i].thermokrasia);
    printf("\n");
}