#include <stdio.h>
#include <string.h>
#define ROWS 50
#define COLUMNS 50

void sortArray(char [][COLUMNS]);
void inputKey(char* str, FILE* fp);
void printArray(char [][COLUMNS], int);
int countOccurrence(char [], char [][COLUMNS], int);

int main() {

    FILE *fp;

    fp = fopen("input1.txt", "r");

    char array1[ROWS][COLUMNS];

    int file1_len=0;
    int file2_len=0;

    char str[COLUMNS];

    if(fp){
        while(!feof(fp)){
            inputKey(str, fp);
            strcpy(array1[file1_len], str);
            file1_len++;
        }
    }

    printf("-input1.txt: \n");
    printArray(array1, file1_len);

    fclose(fp);

    FILE *fp2;
    fp2 = fopen("input2.txt", "r");

    char array2[ROWS][COLUMNS];

    // stores input 2 in 2d array
    if(fp2){
        while(!feof(fp2)){
            inputKey(str, fp2);
            strcpy(array2[file2_len], str);
            file2_len++;
        }
    }
    printf(" \n\n");
    printf("-intput2.txt:  \n");

    // print array before sorting:
    printArray(array2, file2_len);

    // sort array
    int j, k;
    char current[COLUMNS];

    for( k=0; k<file2_len; k++){
        j = k-1;
        strcpy(current, array2[k]);

        while(j >= 0 && strcmp(current, array2[j]) < 0){
            strcpy(array2[j+1], array2[j]);
            j--;
        }
        strcpy(array2[j+1], current);
    }

    //sortArray(array2);
    printf("After sorting:\n");
    // print array after sorting
    printArray(array2, file2_len);

    fclose(fp2);

    printf("Occurrences of sentences in array1 in array2:\n");

    for(int i=0; i<file1_len; i++){
        printf("%s : %d\n", array1[i], countOccurrence(array1[i], array2, file2_len));
    }

    return 0;

}

void sortArray(char list[][COLUMNS]){
    int i;
    char current[COLUMNS];

    for(int k=0; k < ROWS; k++){

        i = k-1;
        strcpy(current, list[k]);

        while( i >= 0 && strcmp(current, list[i]) < 0){

            strcpy(list[i+1], list[i]);
            i--;
        }

        strcpy(list[i+1], current);
    }
}

void inputKey(char* str, FILE* fp){

    fgets(str,COLUMNS,fp);

    while(*str != '\n')
        str++;
    *str = '\0';
}

void printArray(char array[][COLUMNS], int limit){
    printf("\n");
    for(int i = 0; i < limit; i++){
        printf("%s\n", array[i]);
    }
    printf("\n\n");

}


int countOccurrence(char str[], char arr[][COLUMNS], int len){
    int count = 0;

    for(int i=0; i<len; i++){
        if(strcmp(arr[i], str) == 0){
            count++;
        }
    }

    return count;
}
