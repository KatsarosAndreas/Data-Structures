#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


/* Για το παρακάτω ερώτημα αλλάζουμε την δομή μας σε name: Data.Αυτό το κάνουμε διοτι πλεον επεξεργαζόμαστε,διαβάζουμε  και χρησιμοποιούμε την ημερομηνία(Year/Month/Date) 
ως ενα στοιχείο(με όνομα x) το οποίο παιρνει την μορφή YYYYMMDD.Eπίσης επεξεργαζόμαστε κατάλληλα όλες τις συναρτήσεις και τα ορίσματά μας , βασισμένα στιε παρακάτω αλλαγες
για αυτό το ερώτημα. */

typedef struct Data
{
    long int x;
    float thermokrasia, phosphate, silicate, nitrite, nitrate, salinity, oxygen;
}Data;


void RemoveChar(char* str, char c);
void xSwap(char* str);
void Printday(Data* day, int measure);
void ReadFile(Data* Oceanday);
void userInput(long int *Value,long int min ,long int max );
float bis(Data d[], long int x,int right,int left);
float LinearSearch(Data* arr, int left, int right, long int date);

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
    float result=bis(DataArray,input,rows-1,0);
    if(result !=-1){
    	printf("thermokrasia for the current date is: %.2f",result);
	}
	else{
		printf("Date does not exist.Try again with a valid date.");
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


/*Για την υλοποίηση του παρακάτω ερωτήματος, χρησιμοποιούμε τις συναρτήσεις Readfile xSwap και RemoveChar.Mέσω αυτών αλλάζουμε τον τρόπο με τον οποίο διαβάζετε το αρχειο
και πλεον περνάμε την ημερομηνία ως ένα στοιχείο(το ονομαζουμε x στην δομή μας) και αποθηκεύουμε εκεί την ημερομηνία με σκοπό την ορθή διαχείρηση της στην συνάρτηση bis*/
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
                if (column == 1){DataArray[r].thermokrasia = atof(value);}
                if (column == 2){DataArray[r].phosphate = atof(value);}
                if (column == 3){DataArray[r].silicate = atof(value);}
                if (column == 4){DataArray[r].nitrite = atof(value);}
                if (column == 5){DataArray[r].nitrate = atof(value);}
                if (column == 6){DataArray[r].salinity = atof(value);}
                if (column == 7){DataArray[r].oxygen = atof(value);}
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
        printf("%ld, %.2f\n", day[i].x, day[i].thermokrasia);
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
    char thermokrasia;
    int n;

    n = strlen(str);
    int i;
    for ( i=0; i<4; i++){
        thermokrasia = str[i];
        str[i] = str[n-(4-i)];
        str[n-(4-i)] = thermokrasia;
    }
}



float bis(Data d[], long int x,int right,int left){
    int measure=right-left;
    int next;
    int i;
    next=(int) measure * (x-d[left].x)/(d[right].x-d[left].x) + 1;
    while(x!=d[next].x && left<right){
        i=0;
        measure=right-left;
        if(measure <= 3){return LinearSearch(d, left, right, x);}
        if(x >= d[next].x)
        {
            while(x > d[next + i * ((int) sqrt(measure))-1].x){i++;}
            right = next + (int) (i * sqrt(measure));
            left = next + (int) ((i-1) * sqrt(measure));
        }
        else if(x < d[next].x)
        {
            while(x < d[next - i * ((int)sqrt(measure))+1].x){i++;}
            right = next - (int)((i-1) * sqrt(measure));
            left = next - (int)(i * sqrt(measure));
        }
        next = (int) (left + ((right - left + 1) * (x - d[left].x)/(d[right].x - d[left].x))) - 1;
    }
    if(x == d[next].x){
        return d[next].thermokrasia;}
    else{
    	
        return -1;
    }
}
float LinearSearch(Data* arr, int left, int right, long int date)
{
	int i = left, found = 0;
	while (!found && i < right){
		if (arr[i].x == date){
		return arr[i].thermokrasia;
		}
		++i;
	}
	return -1;
}
