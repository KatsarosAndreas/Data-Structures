#include <stdio.h>
#include <stdlib.h>



typedef struct Okeanos
{
    int mhnas, mera, xronos;
    float thermokrasia, phosphate, silicate, nitrite, nitrate, salinity, oxygen;
    
}Okeanos;

int FileOpener(FILE* f);

void userInput(char s[] ,int *Value,int min ,int max);

int binarySearch(Okeanos array[], int mera,int mhnas,int xronos, int low, int high);

void printArray(Okeanos c[], int n);

void Sort(Okeanos d[],int n);

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
  printArray(OkeanosArray,count); 
  */
 /*
    for(i = 0; i<count; i++){
    	printf("%d / %d / %d \n", OkeanosArray[i].mhnas , OkeanosArray[i].mera , OkeanosArray[i].xronos);
    	
	} */
    
  

  
  int Umera,Umhnas,Uxronos;
  
    userInput("mera",&Umera,1,31);
  
    userInput("mhnas",&Umhnas,1,12);
  
    userInput("xronos",&Uxronos,2000,2019);
  
    printf("You entered :%d/%d/%d",Umera,Umhnas,Uxronos);
  
    int index,index2;
    
    Sort(OkeanosArray,count);
  
   index = binarySearch(OkeanosArray,Umera,Umhnas,Uxronos,0,count);
  
  if (index == -1)
  
    printf("\nDate not found!Try again with a valid date.");
  
  else
  
      printf("\nDate Is present with thermokrasia(integer): %d.\n",index);

    
    
    
     

 return 0; 


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




void userInput(char s[] ,int *Value,int min ,int max ){

    int TestValue;

    do{

      printf("Enter the %s :",s);

      scanf("%d",&TestValue);  

      if(TestValue<min|| TestValue>max){

          printf("Error %s must be between %d-%d",s,min,max);

          TestValue=0;

          *Value=TestValue;

          printf("\n");

      }
      else{
          printf("You entered :%d",TestValue);
          *Value=TestValue;
          printf("\n");
    
          
      }
    }while(*Value<min || *Value>max);
 
 
}

int binarySearch(Okeanos array[], int mera,int mhnas,int xronos, int low, int high) {
    
    while(low<=high) {
    int mid =low+ (high - low) / 2;

   if ((array[mid].xronos<xronos)){
        low=mid+1;
        return binarySearch(array, mera,mhnas,xronos, low, high);
 	}
    else if((array[mid].xronos>xronos)){
        high=mid-1;
        return binarySearch(array,mera,mhnas,xronos, low, high);
     }else if(array[mid].xronos==xronos){
        if(array[mid].mhnas<mhnas){
            low=mid+1;
            return binarySearch(array, mera,mhnas,xronos, low, high);
        }
        else if(array[mid].mhnas>mhnas){
            high=mid-1;
            return binarySearch(array,mera,mhnas,xronos, low, high);
        }
        else if(array[mid].mhnas==mhnas){
            if(array[mid].mera<mera){
                low=mid+1;
                return binarySearch(array, mera,mhnas,xronos, low, high);
            }
            else if(array[mid].mera>mera){
                 high=mid-1;
                return binarySearch(array,mera,mhnas,xronos, low, high);
            }
            else if((array[mid].mera == mera)){
                return array[mid].thermokrasia;
	}
        }
     }
	
    }
  return -1;
}


/* Function to print an array */
void printArray(Okeanos c[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("Date: %d/%d/%d  \n",c[i].mhnas,c[i].mera,c[i].xronos);
    printf("\n");
}


void Sort(Okeanos d[],int n){
 int i,k,j;
for(i=0; i<n; i++){
for(j=0; j<=i; j++){

if(d[j].xronos>d[i].xronos){

k=d[j].xronos;

d[j].xronos=d[i].xronos;

d[i].xronos=k;

k=d[j].mhnas;

d[j].mhnas=d[i].mhnas;

d[i].mhnas=k;

k=d[j].mera;

d[j].mera=d[i].mera;

d[i].mera=k;
}
else
{

if(d[j].xronos==d[i].xronos){

if(d[j].mhnas>d[i].mhnas){

k=d[j].xronos;

d[j].xronos=d[i].xronos;

d[i].xronos=k;

k=d[j].mhnas;

d[j].mhnas=d[i].mhnas;

d[i].mhnas=k;

k=d[j].mera;

d[j].mera=d[i].mera;

d[i].mera=k;
}

else
{
if(d[j].mhnas==d[i].mhnas)
{
    if(d[j].mera>d[i].mera)
    {
    k=d[j].xronos;
    d[j].xronos=d[i].xronos;
    d[i].xronos=k;
    k=d[j].mhnas;
    d[j].mhnas=d[i].mhnas;
    d[i].mhnas=k;
    k=d[j].mera;
    d[j].mera=d[i].mera;
    d[i].mera=k;
    }
}

}
}
}

}

}
for(i=0; i<n; i++)
{
printf("\n%d/%d/%d",d[i].mhnas,d[i].mera,d[i].xronos);
}
}
