#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>



typedef struct Data
{
    long int x;
    float temp, phos, silic, nitrite, nitrate, sal, oxyg;
}Data;


void RemoveChar(char* str, char c);
void xSwap(char* str);
void Printday(Data* day, int measure);
void ReadFile(Data* Oceanday);
void userInput(long int *Value,long int min ,long int max );
float interpolation(Data array[],int data, int low, int high);

int main()
{
    FILE* fp = fopen("project.csv", "r");
    int rows = -1;
    if (!fp){printf("Can't open file\n");}
    else
    {
        char buffer[1024];
        int r=0;
        while (fgets(buffer,1024, fp)){
            rows++;
            if (rows == 1){continue;}
            char* value = strtok(buffer, ", ");
            while (value) 
            {value = strtok(NULL, ", ");}
        }
    }
    fclose(fp);
    Data DataArray[rows];
    ReadFile(DataArray);
    //Printday(DataArray, rows);

    long int input;
    userInput(&input,20000101,20191231);
    float result=interpolation(DataArray,input,0,rows-1);
    if(result ==-1){
    	printf("Date does not exist.Try again with a valid date.");
	}
	else{
		printf("Temp for the current date is: %.2f",result);
	}
    	
   

}

void userInput(long int *Value,long int min ,long int max ){
    long int TestValue;
    do{
      printf("Please select a desired x in YYYYMMDD format:\n");
    scanf("%ld",&TestValue);
      if(TestValue<min|| TestValue>max){
          printf("Error x must be between %ld-%ld",min,max);
          TestValue=0;
          *Value=TestValue;
          printf("\n");

      }
      else{
          printf("You entered :%ld",TestValue);
          *Value=TestValue;
          printf("\n");
    
          
      }
    }while(*Value<min || *Value>max);
 
 
}

void ReadFile(Data* DataArray)
{
    FILE* fp = fopen("project.csv", "r");
    if (!fp){printf("Can't open file\n");}
    else
    {
        char buffer[1024];
        int row = 0;
        int column = 0;
        int r=-1;
        while (fgets(buffer,1024, fp)){
            column = 0;
            row++;
            r++;
            if (row == 1)
            {
                r--;
                continue;
            }
                
            char* value = strtok(buffer, ", ");
            while (value) {
                if (column == 0)
                {
                    RemoveChar(value, '/');
                    xSwap(value);
                    DataArray[r].x = atol(value);
                }
                if (column == 1){DataArray[r].temp = atof(value);}
                if (column == 2){DataArray[r].phos = atof(value);}
                if (column == 3){DataArray[r].silic = atof(value);}
                if (column == 4){DataArray[r].nitrite = atof(value);}
                if (column == 5){DataArray[r].nitrate = atof(value);}
                if (column == 6){DataArray[r].sal = atof(value);}
                if (column == 7){DataArray[r].oxyg = atof(value);}
                value = strtok(NULL, ", ");
                column++;
            }
        }
        fclose(fp);
    }
}




void Printday(Data* day, int measure)
{
    int i;
    for(i=0;i<measure;i++)
    {
        printf("%ld, %.2f\n", day[i].x, day[i].temp);
    }
    printf("\n");
    return;
}

void RemoveChar(char* s, char c)
{
    int i, j;
    int len = strlen(s);
    for(i=0; i<len; i++)
    {
        if(s[i] == c)
        {
            for(j=i; j<len; j++){s[j] = s[j+1];}
            len--;
            i--;
        }
    }
}

void xSwap(char* str){
    char temp;
    int n;

    n = strlen(str);
    int i;
    for ( i=0; i<4; i++){
        temp = str[i];
        str[i] = str[n-(4-i)];
        str[n-(4-i)] = temp;
    }
}



float interpolation(Data array[],int data, int low, int high)
{
    int pos;
    
    if (low <= high && data >= array[low].x && data <= array[high].x) {
        
        pos = low + (((double)(high - low) / (array[high].x - array[low].x))* (data - array[low].x));
 		
    if ((array[pos].x<data)){
        low= pos+1;
        return interpolation(array,data, low, high);
 	}
    else if((array[pos].x>data)){
        high=pos-1;
        return interpolation(array,data, low, high);
     }else if(array[ pos].x==data){
       
                return array[pos].temp;
	}
}
	     
    return -1;

 
}
