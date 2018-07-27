/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Cory
 *
 * Created on June 18, 2018, 6:04 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    int seven77 = 'A';
    
    cout<<char(seven77 + 7)<<char(seven77 + '$')<<char(seven77 + '+')<<char(seven77 + '+')
            <<char(seven77 + '.')<<char(seven77 - '!')<<char(seven77 + '6')<<char(seven77 + '.')
            <<char(seven77 + '1')<<char(seven77 + '+')<<char(seven77 + '#')
            <<char(seven77 - ' ')<<endl;
    return 0;
}

