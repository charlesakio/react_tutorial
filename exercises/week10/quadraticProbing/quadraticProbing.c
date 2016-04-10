#include <stdio.h>
#define N 23
#define Empty 0
#define MaxNumbers 20

int main() {
  //OPEN THE FILE
  FILE *in = fopen("numbers.txt", "r"); //r means read.

  if(in == NULL) {
    printf("cannot open the file");
    exit(1);
  }

  //Define the hash table and other variables
  int j, key, num[N + 1]; //N + 1 to match index count to human counting.
  
  for(j=1; j<=N; j++) {
    num[j] = Empty;
    int uniqueNum; //a counter for unique numbers
    
    while(fscanf(in, "%d", &key) == 1) {
    int i = 0;

    //Apply the hash function to identify the location
    //In which the number will be stored
    int location = (key%N) + 1;

    //If there is a collision,
    //Calculate a new location
    while(num[location] != Empty && num[location] != key) {
      i = i + 1;
      
      //Quadratic probing
      location = locationi + i + (i**2);
      while(location > N) {
        //If the location is out of bounds,
        //Subtract the location number with the max size
        //To go to index 0
        //Thus, making the array shift back to the beginning
         location = location - N;
      }
    }
    
    if(num[location] == Empty) {
      if(uniqueNum == MaxNumbers) {
        printf("Table is full");
        exit(1);
      }//if
      
      num[location] = key;
      uniqueNum++;
    }//if
    
    }//while
  }//for
}//main
