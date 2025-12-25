#include <stdio.h>
#include <stdlib.h>



typedef struct Okeanos
{
    int mhnas, mera, xronos;
    float  thermokrasia, phosphate, silicate, nitrite, nitrate, salinity,  oxygen;
    
}Okeanos;


int FileOpener(FILE* f);

void swap(int* a, int* b);
int partition (Okeanos c[], int low, int high);
void quickSort(Okeanos c[], int low, int high);
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
    float  thermokrasia, phosphate, silicate, nitrite, nitrate, salinity,  oxygen;
     thermokrasia=phosphate=silicate=nitrite=nitrate=salinity= oxygen=0.0;
    char c;
    for (c = fgetc(f); c != '\n' && c != EOF; c=fgetc(f)){};
    

    while (c!=EOF) 
    {
        fscanf(f, "%d/%d/%d, %f, %f, %f, %f, %f, %f, %f", &mhnas, &mera, &xronos, & thermokrasia, &phosphate, &silicate, &nitrite, &nitrate, &salinity, & oxygen);
        OkeanosArray[i].mhnas=mhnas;
        OkeanosArray[i].mera=mera;
        OkeanosArray[i].xronos=xronos;
        OkeanosArray[i]. thermokrasia= thermokrasia;
        OkeanosArray[i].phosphate=phosphate;
        OkeanosArray[i].silicate=silicate;
        OkeanosArray[i].nitrite=nitrite;
        OkeanosArray[i].nitrate=nitrate;
        OkeanosArray[i].salinity=salinity;
        OkeanosArray[i]. oxygen= oxygen;
        c=getc(f);
        if (c == '\n') {i++;}
    }
    
    /*
    for(i = 0; i<count; i++){
    	printf("%d / %d / %d \n", OkeanosArray[i].mhnas , OkeanosArray[i].mera , OkeanosArray[i].xronos);
    	
	} */

  quickSort(OkeanosArray,0,count);
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




//QUICK SORT 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition (Okeanos c[], int low, int high)
{
    float pivot = c[high]. thermokrasia; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 	int j;
    for ( j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (c[j]. thermokrasia < pivot)
        {
            i++; // increment index of smaller element
            swap(&c[i]. thermokrasia, &c[j]. thermokrasia);
            swap(&c[i].mera,&c[j].mera);
            swap(&c[i].mhnas,&c[j].mhnas);
            swap(&c[i].xronos,&c[j].xronos);
        }
    }
    swap(&c[i+1]. thermokrasia, &c[high]. thermokrasia);
    swap(&c[i+1].mera,&c[high].mera);
    swap(&c[i+1].mhnas,&c[high].mhnas);
    swap(&c[i+1].xronos,&c[high].xronos);
    return (i + 1);
}
 

void quickSort(Okeanos c[], int low, int high)
{
    if (low < high)
    {
      int pi = partition(c, low, high);
 
        
        quickSort(c, low, pi - 1);
        quickSort(c, pi + 1, high);
    }
}



/* Function to print an array */
void printArray(Okeanos c[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("Date: %d/%d/%d || thermokrasia: %f \n",c[i].mhnas,c[i].mera,c[i].xronos,c[i]. thermokrasia);
    printf("\n");
}