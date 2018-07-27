/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order
int sToI(std::string input);// Input validation 


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}


int  read(char arr[][COLMAX],int &x){
    int temp = 0;
    for(int i = 0; i < x;  i++){
        cin>>arr[i];
        cin.ignore();
        if(strlen(arr[i]) > temp){
            temp = strlen(arr[i]);
        }
    }
    return temp;
}

void sort(char arr [][COLMAX],int row, int col, const char replace[], const char with[]){// Selection sort
    int minIndx = 0;
    char minVal[COLMAX], temp[COLMAX];
    for(int i = 0; i < row; i++){
        minIndx = i;
        strcpy(minVal,arr[i]);
        for(int j = i + 1; j < row; j++){
            cout<<strcmp(arr[j], minVal, replace, with)<<" "<<arr[j]<<" "<<minVal<<endl;
            if(strcmp(arr[j], minVal, replace, with) < 0){
                strcpy(minVal,arr[j]);
                minIndx = j;
            }
        }
        strcpy(temp, arr[minIndx]);
        strcpy(arr[minIndx],arr[i]);
        strcpy(arr[i],temp);
    } 
}

void print(const char arr[][COLMAX],int x,int y){
    for(int i = 0; i < x; i++){
        cout<<arr[i]<<endl;
    }
}

int strcmp(char a[],char b[],const char replace[],const char with[]){
    int result = 0;
    char temp[strlen(a)], temp2[strlen(b)];
    strcpy(temp, a);
    strcpy(temp2, b);
    
    for(int i = 0; i < strlen(a); i++){
        for(int j = 0; j < strlen(a); j++){
            if(temp[i] == replace[j]){
                temp[i] = with[j];
            }
            
            if(temp2[i] == replace[j]){
                temp2[i] = with[j];
            }
        }
    }
    for(int i = 0; i < strlen(a); i++){
        if(temp[i] > temp2[i]){
            result = 1;
            break;
        }
        else if(temp[i] < temp2[i]){
            result = -1;
            break;
        }
    }
    cout<<a<<" "<<temp<<" "<<b<<" "<<temp2<<endl;
    return result;
}

int sToI(std::string input){// Input validation 
    int temp = 0;
    for(int i = 0; i < input.length(); i++){
        if(input[i] >= '0' && input[i] <= '9'){
            temp = (temp * 10) + (input[i] - '0');
        }
        else{
            std::cout<<"INVALID INPUT - "<<input<<" - is not an integer."<<
                    std::endl<<"Try again please.";
            exit(EXIT_FAILURE);
        }
    }
    return temp;
}