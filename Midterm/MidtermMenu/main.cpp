#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cctype>

/// PROBLEM 1 /// 
#include "Customer.h"

void problem1();

void processCust(Cust*);
void prntCust(Cust*);

std::string sInput(const std::string& ,const std::string&);
int iInput(const std::string&, const std::string&);
bool isNums(const std::string&);
/////////////////

/// PROBLEM 2 ///
#include "Employee.h"

void problem2();

void processEmp();
void calculate(Employee&);
void prntEmp(const Employee&,const std::string&, const std::string&);
void prntChck(const Employee&, const std::string&, const std::string&);

/// Personal Input Functions /// 
float fInput(const std::string&, const std::string&);

/// Whatever else needed ///
bool isNums(const std::string&);
std::string englishNums(const int&, const float&);
////////////////

/// PROBLEM 3 ///
//User Libraries
#include "Array.h"
#include "Stats.h"

void problem3();

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

// Personal functions 
float mean(int, int*);
float median(int, int*);
int *mode(int, int*, int&, int&);
///////////////////

/// PROBLEM 4 ///
void problem4();

int encrypt(const int&);
bool verify(const int&);
/////////////////

/// PROBLEM 5 ///
void problem5();

int decrypt(const int&);
/////////////////

/// PROBLEM 6 ///
void problem6();

size_t factorial(int);// size_t is the biggest possible positive integer possible

void test(char);
void test(unsigned char);
void test(short);
void test(unsigned short);
void test(float);
void test(double);
void test(int);
void test(unsigned int);
void test(long);
void test(unsigned long);
void test(long long);
void test(unsigned long long);
////////////////

/// PROBLEM 7 ///
void problem7();
/////////////////

/// PROBLEM 8 ///
#include "Primes.h"

void problem8();

Primes *factor(const int &x);
void prntPrm(Primes*);
/////////////////

void menu(){
    //Display menu
    std::cout<<std::endl<<"Choose from the following Menu"<<std::endl;
    std::cout<<"Type 1 for Customer struct example"<<std::endl;
    std::cout<<"Type 2 for Gross Pay example"<<std::endl;
    std::cout<<"Type 3 for Stats Stub example"<<std::endl;   
    std::cout<<"Type 4 for Encryption example"<<std::endl;   
    std::cout<<"Type 5 for Decryption example"<<std::endl;   
    std::cout<<"Type 6 for Byte Size Factorials example"<<std::endl;   
    std::cout<<"Type 7 for Float and Int conversions example"<<std::endl;   
    std::cout<<"Type 8 for Prime Factors example"<<std::endl<<std::endl;
}
int main(int argc, char** argv) {

    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        std::cin>>choice;
        std::cout<<std::endl;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{problem1();break;}
            case '2':{problem2();break;}
            case '3':{problem3();break;}
            case '4':{problem4();break;}
            case '5':{problem5();break;}
            case '6':{problem6();break;}
            case '7':{problem7();break;}
            case '8':{problem8();break;}
            default: std::cout<<"Exiting Menu"<<std::endl;
        }
    }while(choice>='1'&&choice<='8');
    return 0;
}

/// PROBLEM 1 ///
void problem1(){
    Cust *test = new Cust;
    processCust(test);
}
void processCust(Cust *customer){
    bool debug = false;
    if(debug){
        customer -> accntNum = 12345;
        customer -> name = "John Doe";
        customer -> address = "1234 Test St.";
        customer -> balance = 999;
        customer -> checks = 888;
        customer -> nBalance = 112;
        customer -> deposits = 1;
        customer -> overdraft = false;
    }
    
    customer -> accntNum = iInput("account number", "high");
    customer -> name = sInput("name", "high");
    customer -> address = sInput("address", "low");
    customer -> balance = iInput("starting balance", "low");
    customer -> deposits = iInput("total money deposited in the account", "low");
    customer -> checks = iInput("total money taken out of account", "low");
    
    customer -> nBalance = (customer -> balance) - (customer -> checks)
            + (customer -> deposits);
    if(customer -> nBalance < 0){
        customer -> overdraft = true;
        customer -> nBalance -= 15;
    }
    
    prntCust(customer);
}

void prntCust(Cust *customer){
    std::cout<<customer -> name<<" account number: "<<customer -> accntNum<<std::endl;
    std::cout<<"Starting balance: $"<<customer -> balance<<std::endl;
    std::cout<<"Amount deposited: $"<<customer -> deposits<<std::endl;
    std::cout<<"Amount withdrawn: $"<<customer -> checks<<std::endl;
    std::cout<<"Over-drafted: "<<std::boolalpha<<customer -> overdraft<<std::endl;
    if(customer -> overdraft){
        std::cout<<"You have over-drafted your account and have been charged $15"
                " subsequently."<<std::endl;
    }
    std::cout<<"Account total: $"<<customer -> nBalance<<std::endl;
}

bool isNums(const std::string &input){
    int size = input.length();
    for(int i = 0; i < size; i++){
        if(!(input[i] >= '0' && input[i] <= '9')){
            return false;
        }
    }
    return true;
}
/// END PROBLEM 1 ///

/// PROBLEM 2 ///
void problem2(){
    processEmp();
}

void processEmp(){
    std::string cmpName = sInput("the name of the company", "high");
    std::string addr = sInput("the address of the company", "low");
    int size = iInput("amount of employees to process", "low");
    Employee *arr = new Employee[size];
    
    for(int i = 0; i < size; i ++){
        arr[i].name = sInput("employee name", "low");
        arr[i].hours = iInput("hours worked", "low");
        arr[i].rop = fInput("hourly pay rate", "none");
        calculate(arr[i]);
        std::cout<<std::endl;
    }
    for(int i = 0; i < size; i++){
        //prntEmp(arr[i], cmpName, addr);
        prntChck(arr[i], cmpName, addr);
    } 
}

void calculate(Employee &emp){
    float total;
    
    if(emp.hours >= 50){
        total += (30 * emp.rop);
        total += (20 * emp.rop * 2);
        total += ((emp.hours - 50) * emp.rop * 3);
    }
    else if(emp.hours >= 30){
        total += (30 * emp.rop);
        total += ((emp.hours - 30) * emp.rop * 2);
    }
    else{
        total += (emp.rop * emp.hours);
    }
    
    emp.total = total;
    emp.cents = total - emp.total;
    englishNums(emp.total, emp.cents);
}

void prntEmp(const Employee &emp, const std::string &cmpName,
        const std::string &addr){
    std::cout<<cmpName<<std::endl;
    std::cout<<addr<<std::endl;
    std::cout<<emp.name<<" has worked "<<emp.hours<<" hours at $"<<emp.rop
            <<" per hour which comes out to $"<<emp.total<<std::endl<<std::endl;
}

void prntChck(const Employee &emp, const std::string &cmpName, const std::string &addr){
    std::cout<<cmpName<<std::endl;
    std::cout<<addr<<std::endl;
    std::cout<<"Name: "<<emp.name;
    std::cout<<std::setw(15)<<std::right<<std::fixed<<std::setprecision(2);
    std::cout<<"Amount: $"<<emp.total<<"."<<(int)(emp.cents * 100)<<std::endl;
    std::cout<<"Amount: "<<englishNums(emp.total, emp.cents)<<std::endl; 
    std::cout<<"Signature Line: "<<std::endl;
}

std::string sInput(const std::string &type, const std::string &strictness){
    std::string temp = "";
    bool valid = true;
    int size;
    
    std::cin.ignore();
    std::cout<<"Please enter "<<type<<": ";
    
    do{
        valid = true;
        getline(std::cin, temp);
        size = temp.length();
        
        if(size <= 0){
            valid = false;
        }
        
        if(strictness == "high"){// For names and stuff
            for(int i = 0; i < size; i++){
                if(!(isalpha(temp[i]) || isspace(temp[i]))){
                    valid = false;
                    break;
                }
            }
            if(!valid){
                std::cout<<"Incorrect input for "<<type<<", please try again."
                        <<std::endl;
            }
        }
        
        else if(strictness == "low"){// for addresses and stuff
            for(int i = 0; i < size; i++){
                if(!(isalnum(temp[i]) || isspace(temp[i]) || ispunct(temp[i]))){
                    valid = false;
                    break;
                }
            }
            if(!valid){
                std::cout<<"Incorrect input for "<<type<<", please try again."
                        <<std::endl;
            }
        }
        
        else{
            // you fucked up   
            std::cout<<"Missing strictness, try again dummy"<<std::endl;
        }
        
    }while(!valid);
    
    return temp;
}

float fInput(const std::string &type, const std::string &strictness){
    std::string temp = "";
    bool valid = true;
    bool decimal = false;
    int placeCnt = 0;
    int floatMaker = 1;
    int size;
    float result = 0;
    
    std::cin.ignore();
    std::cout<<"Please enter "<<type<<": ";
    
    do{
        valid = true;
        decimal = false;
        placeCnt = 0;
        
        getline(std::cin, temp);
        size = temp.length();
        
        if(size <= 0){
            valid = false;
        }
        
        for(int i = 0; i < size; i++){
            if(decimal)placeCnt++;
            if(temp[i] != '.' && temp[i] < '0' || temp[i] > '9'){
                valid = false;
                std::cout<<"Incorrect input for "<<type<<", please try again."
                        <<std::endl;
                break;
            }
            if(temp[i] != '.'){
                result = (result * 10) + (temp[i] - '0');
            }
            else{
                decimal = true;
            }
        }

    }while(!valid);
    
    for(int i = 0; i < placeCnt; i++){
        floatMaker *= 10;
    }
    
    return result / floatMaker;
}

std::string englishNums(const int &total, const float &cents){
    int temp = total;
    float cent = cents;
    bool teen = false;
    bool teenThsnd = false;
    std::string number;
    
    int hThsnd = 100000;
    int tThsnd = 10000;
    int thsnd = 1000;
    int hndrd = 100;
    int ten = 10;
    int one = 1;

    
    
    int nHThsnd = -1;
    int nTThsnd = -1;
    int nThsnd = -1;
    int nHndrd = -1;
    int nTen = -1;
    int nOne = -1;
    
    if(temp >= hThsnd){
        nHThsnd = temp / hThsnd;
        temp %= hThsnd;
        
        nTThsnd = temp / tThsnd;
        temp %= tThsnd;
        
        nThsnd = temp / thsnd;
        temp %= thsnd;
        
        nHndrd = temp / hndrd;
        temp %= hndrd;
        
        nTen = temp / ten;
        temp %= ten;
        
        nOne = temp;
    }
    else if(temp >= tThsnd){
        nTThsnd = temp / tThsnd;
        temp %= tThsnd;
        
        nThsnd = temp / thsnd;
        temp %= thsnd;
        
        nHndrd = temp / hndrd;
        temp %= hndrd;
        
        nTen = temp / ten;
        temp %= ten;
        
        nOne = temp;
    }
    else if(temp >= thsnd){
        nThsnd = temp / thsnd;
        temp %= thsnd;
        
        nHndrd = temp / hndrd;
        temp %= hndrd;
        
        nTen = temp / ten;
        temp %= ten;
        
        nOne = temp;
    }
    else if(temp >= hndrd){
        nHndrd = temp / hndrd;
        temp %= hndrd;
        
        nTen = temp / ten;
        temp %= ten;
        
        nOne = temp;
    }
    else if(temp >= ten){
        nTen = temp / ten;
        temp %= ten;
        
        nOne = temp;
    }
    else{
        nOne = temp;
    }
    
    switch(nHThsnd){
        case 9: number += "Nine Hundred ";break;
        case 8: number += "Eight Hundred ";break;
        case 7: number += "Seven Hundred ";break;
        case 6: number += "Six Hundred ";break;
        case 5: number += "Five Hundred ";break;
        case 4: number += "Four Hundred ";break;
        case 3: number += "Three Hundred ";break;
        case 2: number += "Two Hundred ";break;
        case 1: number += "One Hundred ";break;
    }
    
    switch(nTThsnd){
        case 9: number += "Ninety ";break;
        case 8: number += "Eighty ";break;
        case 7: number += "Seventy ";break;
        case 6: number += "Sixty ";break;
        case 5: number += "Fifty ";break;
        case 4: number += "Forty ";break;
        case 3: number += "Thirty ";break;
        case 2: number += "Twenty ";break;
        case 1: teenThsnd = true;break;
    }
    
    switch(nThsnd){
        case 9: (teenThsnd)?(number += "Nineteen Thousand "):(number += "Nine Thousand ");break;
        case 8: (teenThsnd)?(number += "Eighteen Thousand "):(number += "Eight Thousand ");break;
        case 7: (teenThsnd)?(number += "Seventeen Thousand "):(number += "Seven Thousand ");break;
        case 6: (teenThsnd)?(number += "Sixteen Thousand "):(number += "Six Thousand ");break;
        case 5: (teenThsnd)?(number += "Fifteen Thousand "):(number += "Five Thousand ");break;
        case 4: (teenThsnd)?(number += "Fourteen Thousand "):(number += "Four Thousand ");break;
        case 3: (teenThsnd)?(number += "Thirteen Thousand "):(number += "Three Thousand ");break;
        case 2: (teenThsnd)?(number += "Twelve Thousand "):(number += "Two Thousand ");break;
        case 1: (teenThsnd)?(number += "Eleven Thousand "):(number += "One Thousand ");break;
        case 0: (teenThsnd)?(number += "Ten Thousand "):(number += "Thousand ");break;
    }
    
    switch(nHndrd){
        case 9: number += "Nine Hundred ";break;
        case 8: number += "Eight Hundred ";break;
        case 7: number += "Seven Hundred ";break;
        case 6: number += "Six Hundred ";break;
        case 5: number += "Five Hundred ";break;
        case 4: number += "Four Hundred ";break;
        case 3: number += "Three Hundred ";break;
        case 2: number += "Two Hundred ";break;
        case 1: number += "One Hundred ";break;
    }
    
    switch(nTen){
        case 9: number += "Ninety ";break;
        case 8: number += "Eighty ";break;
        case 7: number += "Seventy ";break;
        case 6: number += "Sixty ";break;
        case 5: number += "Fifty ";break;
        case 4: number += "Forty ";break;
        case 3: number += "Thirty ";break;
        case 2: number += "Twenty ";break;
        case 1: teen = true;break;
    }
    
    switch(nOne){
        case 9:(teen)?(number += "Nineteen "):(number += "Nine ");break;
        case 8:(teen)?(number += "Eighteen "):(number += "Eight ");break;
        case 7:(teen)?(number += "Seventeen "):(number += "Seven ");break;
        case 6:(teen)?(number += "Sixteen "):(number += "Six ");break;
        case 5:(teen)?(number += "Fifteen "):(number += "Five ");break;
        case 4:(teen)?(number += "Fourteen "):(number += "Four ");break;
        case 3:(teen)?(number += "Thirteen "):(number += "Three ");break;
        case 2:(teen)?(number += "Twelve "):(number += "Two ");break;
        case 1:(teen)?(number += "Eleven "):(number += "One ");break;
        case 0:(teen)?(number += "Ten "):(number = number);break;// Have to put something or it throws a fit
    }
    
    number += "dollars ";
    
    cent *= 100;
    int temp2 = cent;

    
    if(temp2 == 0){
        number += "and 00/100 cents.";
    }
    else{
        
        number += " and " + std::to_string(temp2) + "/100 cents.";
    }
    
    
    return number;
}
/// END PROBLEM 2 ///

/// PROBLEM 3 ///
void problem3(){
    //Declare variables and fill
    int arySize=39;//Array Size
    int modNum=10; //Number to control the modes (digits 0 to 9 allowed)
    Array *array=fillAry(arySize,modNum);
    
    mrkSort(array ->data,arySize);// You forgot to sort it for us!!!
                                  // Had me confused for a good 20 minutes
    //Print the initial array
    std::cout<<"Original Array"<<std::endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
}
int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    std::cout<<std::endl;
    std::cout<<"The average of the array = "<<ary->avg<<std::endl;
    std::cout<<"The median of the array  = "<<ary->median<<std::endl;
    std::cout<<"The number of modes      = "<<
            ary->mode->size<<std::endl;
    std::cout<<"The max Frequency        = "<<
            ary->modFreq<<std::endl;
    if(ary->mode->size==0){
        std::cout<<"The mode set             = {null}"<<std::endl;
        return;
    }
    std::cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        std::cout<<ary->mode->data[i]<<",";
    }
    std::cout<<ary->mode->data[ary->mode->size-1]<<"}"<<std::endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        std::cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
//    for(int i = 0; i < 4; i++){
//        array -> data[i] = 1;
//    }
//    for(int i = 4; i < n; i++){
//        array -> data[i] = 2;
//    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    std::cout<<std::endl<<"stat function to be completed by the student"<<std::endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    
    stats->mode->size=0;
    int nModes=0;
    
    stats->mode->data=new int[nModes];
    stats->modFreq=1;
    stats -> mode -> data = mode(array -> size, array -> data,
            stats -> modFreq, stats -> mode -> size);
    stats -> median = median(array -> size, array -> data);
    stats -> avg = mean(array -> size, array -> data);
    return stats;
}

float mean(int size, int *arr){
    int sum = 0;
    float mean = 0.0f;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    
    mean = (float)(sum) / size;
    
    return mean;
}

float median(int size, int *arr){
    float medn = 0.0f;
    if(size % 2 == 0){
        medn = arr[(size / 2)] + arr[((size / 2) - 1)];
        medn /= 2.0f;
    }
    else{
        medn = arr[size / 2];
    }

    return medn;
}

int *mode(int size, int *arr, int &frequency, int &numModes){// MUST BE SORTED TO WORK PROPERLY
    int *modes;
    int freq = 1;
    int nModes = 0;
    
    int cFreq = 1;
    for(int i = 1; i < size; i++){
        if(arr[i] == arr[i - 1]){
            cFreq++;
            if(cFreq == freq){
                nModes++;
            }
            if(cFreq > freq){
                freq = cFreq;
                nModes = 1;
            }
        }
        else cFreq = 1;
    }
    
    // num of modes - max frequency - the modes themselves
    int count = 0;
    //size2 = 2 + nModes;
    modes = new int[nModes];
    for(int i = 0; i < nModes; i++){modes[i] = -1;}
//    modes[count] = nModes;count++;
//    modes[count] = freq;count++;
    
    int temp = 1;
    for(int i = 1; i < size; i++){
        if(arr[i] == arr[i - 1]){
            temp++;
            if(temp == freq){
                modes[count] = arr[i];
                count++;
            }
        }
        else temp = 1;
    }
    //prntArr(modes, size2);
    
    frequency = freq;
    numModes = nModes;
    return modes;
}
/// END PROBLEM 3 ///

/// PROBLEM 4 ///
void problem4(){
    int temp = iInput("number to encrypt", "medium");
    if(verify(temp)){
        std::cout<<encrypt(temp)<<std::endl;
    }
    else{
        std::cout<<"Invalid key!! "<<temp<<" is not base 8"<<std::endl;
    }
}

int encrypt(const int &secret){
    int temp = secret;
    int first = 0;
    int second = 0;
    int third = 0;
    int fourth = 0;
    
    first = temp / 1000;
    temp %= 1000;
    
    second = temp / 100;
    temp %= 100;
    
    third = temp / 10;
    temp %= 10;
    
    fourth = temp;
    
    first = (first + 5) % 8;
    std::cout<<first<<std::endl;
    second = (second + 5) % 8;
    std::cout<<second<<std::endl;
    third = (third + 5) % 8;
    std::cout<<third<<std::endl;
    fourth = (fourth + 5) % 8;
    std::cout<<fourth<<std::endl;
    
    int swap;
    swap = first;
    first = third;
    third = swap;
    
    swap = second;
    second = fourth;
    fourth = swap;
    
    temp = (first * 1000) + (second * 100) + (third * 10) + fourth;
    return temp;
}

bool verify(const int &input){
    int temp = input;
    int nThsnd = 0;
    int nHndrd = 0;
    int nTen = 0;
    int nOne = 0;
    
    nThsnd = temp / 1000;
    if(nThsnd > 7)return false;
    temp %= 1000;
    
    nHndrd = temp / 100;
    if(nHndrd > 7)return false;
    temp %= 100;
    
    nTen = temp / 10;
    if(nTen > 7)return false;
    temp %= 10;
    
    nOne = temp;
    if(nOne > 7)return false;
    
    return true;
}

int iInput(const std::string &type, const std::string &strictness){
    std::string temp = "";
    bool valid = true;
    int size;
    int result = 0;
    
    std::cin.ignore();
    std::cout<<"Please enter the "<<type<<": ";
    
    do{
        valid = true;
        getline(std::cin, temp);
        size = temp.length();
        
        if(size <= 0){
            valid = false;
        }
        
        if(strictness == "high"){
            if(size != 5){
                valid = false;
                std::cout<<"Incorrect input for the "<<type<<
                        ", please try again."<<std::endl;
            }
        }
        else if(strictness == "medium"){
            if(size != 4){
                valid = false;
                std::cout<<"Incorrect input for the "<<type<<
                        ", please try again."<<std::endl;
            }
        }
        
        result = 0;
        for(int i = 0; i < size; i++){
            if(isdigit(temp[i])){
                result = (result * 10) + (temp[i] - '0');
            }
            else{
                std::cout<<"Incorrect input for the "<<type<<
                        ", please try again."<<std::endl;
                valid = false;
                break;
            }
        }
    }while(!valid);
    return result;
}
/// END PROBLEM 4 ///

/// PROBLEM 5 ///
void problem5(){
    int temp = iInput("number to decrypt", "none");
    if(verify(temp)){
        std::cout<<decrypt(temp)<<std::endl;
    }
}

int decrypt(const int &challenge){
    int temp = challenge;
    int first = 0;
    int second = 0;
    int third = 0;
    int fourth = 0;
    
    first = temp / 1000;
    temp %= 1000;
    
    second = temp / 100;
    temp %= 100;
    
    third = temp / 10;
    temp %= 10;
    
    fourth = temp;
    
    if(first == 0){
        first = 3;
    }
    else{
        first -= 5;
        if(first < 0){
            first += 8;
        }
    }
    std::cout<<first<<std::endl;
    if(second == 0){
        second = 3;
    }
    else{
        second -= 5;
        if(second < 0){
            second += 8;
        }
    }
    std::cout<<second<<std::endl;
    if(third == 0){
        third = 3;
    }
    else{
        third -= 5;
        if(third < 0){
            third += 8;
        }
    }
    std::cout<<third<<std::endl;
    if(fourth == 0){
        fourth = 3;
    }
    else{
        fourth -= 5;
        if(fourth < 0){
            fourth += 8;
        }
    }
    std::cout<<fourth<<std::endl;
    
    int swap;
    swap = first;
    first = third;
    third = swap;
    
    swap = second;
    second = fourth;
    fourth = swap;
    
    temp = (first * 1000) + (second * 100) + (third * 10) + fourth;
    return temp;
}
/// END PROBLEM 5 ///

/// PROBLEM 6 ///
void problem6(){
        char a;
    unsigned char b;
    
    short c;
    unsigned short d;
    
    float e;
    
    double f;
    
    int g;
    unsigned int h;
    
    long i;
    unsigned long j;
    
    
    test(a);
    test(b);
    test(c);
    test(d);
    test(e);
    test(f);
    test(g);
    test(h);
    test(i);
    test(j);
}

size_t factorial(int x){
    size_t temp = 1;
    int temp2 = x;
    
    for(int i = 0; i < x; i++){
        temp *= temp2;
        temp2--;
    }
    
    return temp;
}

void test(char a){
    size_t maxSize = (pow(2, (sizeof(a) * 8)) / 2) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for char is "<<last<<" "<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(unsigned char a){
    size_t maxSize = pow(2, sizeof(a) * 8);
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for unsigned char is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(short a){
    size_t maxSize = (pow(2, sizeof(a) * 8) / 2) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for short is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(unsigned short a){
    size_t maxSize = pow(2, sizeof(a) * 8);
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for unsigned short is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(float a){
    size_t maxSize = (pow(2, sizeof(a) * 8) / 2) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for float is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(double a){
    size_t maxSize = (pow(2, sizeof(a) * 8) / 2) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for double is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(int a){
    size_t maxSize = (pow(2, sizeof(a) * 8) / 2) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for int is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(unsigned int a){
    size_t maxSize = pow(2, sizeof(a) * 8) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for unsigned int is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(long a){
    size_t maxSize = (pow(2, sizeof(a) * 8) / 2) - 1;
    size_t last = 0;
    for(int i = 0; i < 1000000; i++){
        if(factorial(i) > maxSize){
            std::cout<<"Greatest factorial for long is "<<last<<std::endl;
            break;
        }
        else{
            last = i;
        }
    }
}

void test(unsigned long a){
    size_t maxSize = pow(2, sizeof(a) * 8) - 1;
    size_t last = 0;
    size_t last2 = 0;
    size_t temp = 0;
    
    for(int i = 0; i < 1000000; i++){
        temp = factorial(i);
        if(temp > maxSize){
            std::cout<<"Greatest factorial for unsigned long long is "<<last<<std::endl;
            break;
        }
        else{
            if(temp < last2){// to catch overflows
                std::cout<<"Greatest factorial for unsigned long long is "<<last<<std::endl;
                break;
            }
            last2 = temp;
            last = i;
        }
    }
}
/// END PROBLEM 6 ///

/// PROBLEM 7 ///
void problem7(){
        std::cout<<"2.875 base 10 = "<<std::endl;
    std::cout<<"0000 0010.1110 0000 base 2"<<std::endl;
    std::cout<<"2.7 base 8"<<std::endl;
    std::cout<<"2.E base 16"<<std::endl;
    std::cout<<"Float representation in hex = 5C000002"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"0.1796875 base 10 = "<<std::endl;
    std::cout<<"0000 0000.0010 1110 base 2"<<std::endl;
    std::cout<<"0.134 base 8"<<std::endl;
    std::cout<<"0.2E base 16"<<std::endl;
    std::cout<<"Float representation in hex = 5C0000FE"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"-2.875 base 10 = "<<std::endl;
    std::cout<<"1111 1101.0010 0000 base 2"<<std::endl;
    std::cout<<"-2.7 base 8"<<std::endl;
    std::cout<<"-2.E base 16"<<std::endl;
    std::cout<<"Float representation in hex = E9000004"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"-0.1796875 base 10 = "<<std::endl;
    std::cout<<"1111 1111.1101 0010 base 2"<<std::endl;
    std::cout<<"-0.134 base 8"<<std::endl;
    std::cout<<"-0.2E base 16"<<std::endl;
    std::cout<<"Float representation in hex = E9000000"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"Hex 59999901 = Decimal 1.06...(repeating 6)"<<std::endl;
    std::cout<<"Hex 59999902 = Decimal 2.12...(repeating 12)"<<std::endl;
    std::cout<<"Hex A66667FE = Decimal -2.666...(repeating 6)"<<std::endl;
}
/// END PROBLEM 7///

/// PROBLEM 8 ///
void problem8(){
    int x = iInput("the number you would like to factor", "low");
    
    Primes *temp;
    temp = factor(x);
    prntPrm(temp);
}

Primes *factor(const int &x){
    int temp = x;
    int size = std::sqrt(x);
    int size2 = 25;
    int count = 0;
    
    int primes[size2] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
        53, 59, 61, 67, 71, 73, 79, 83, 89, 97};// Size 25
    
    Primes *set1 = new Primes;
    set1 -> primes = new Prime[x];// Just to be safe
    
    for(int i = 0; i < size2; i++){
        while(temp % primes[i] == 0){
            if(set1 -> primes[count].power == 0){
                set1 -> primes[count].power++;
                set1 -> primes[count].prime = primes[i];
            }
            else{
                set1 -> primes[count].power++;
            }
            temp /= primes[i];
            if(temp < 2){break;}
        }
        if(set1 -> primes[count].power != 0){
            count++;
        }
        //std::cout<<count<<std::endl;
    }
    if(temp > 2 && count != 0){
        set1 -> primes[count].power++;
        set1 -> primes[count].prime = temp;
        count++;
    }
    else if(temp > 100){
        set1 -> nPrimes = -1;
    }
//    if(temp >= 2){
//        set1 -> primes[count].power = 1;
//        set1 -> primes[count].prime = temp;
//        count++;
//    }
    set1 -> nPrimes = count;
    return set1;
}

void prntPrm(Primes *primes){
    int size = primes -> nPrimes;
    
    if(size > 0){
        for(int i = 0; i < size; i++){
            std::cout<<static_cast<int>(primes -> primes[i].prime)<<"^"
                <<static_cast<int>(primes -> primes[i].power);
            if(i != size - 1){
                std::cout<<", ";
            }
        }
    }
    else{
        std::cout<<"This number is prime"<<std::endl;
    }
}
/// END PROBLEM 8 ///