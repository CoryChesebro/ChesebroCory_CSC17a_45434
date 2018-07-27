/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   globals.h
 * Author: Cory
 *
 * Created on June 23, 2018, 5:07 PM
 */

#ifndef GLOBALS_H
#define GLOBALS_H 1

/*
 * Extern tells the compiler that the variable exists but that it is defined
 * somewhere else, so what we do is declare the variables in main due to the 
 * fact that GLOBAS_DECL is defined in main and then when the header file is 
 * called in another file, since GLOBALS_DECL is not defined there, the header 
 * file defines all the global variables giving them their value. 
 * 
 * This is my first time messing with header files so if you have any comment 
 * on how I could do this better please leave me a comment :) 
 * 
 */

#ifndef GLOBALS_DECL
#   define _DECL extern
#   define _INIT(x) 
#else 
#   define _DECL
#   define _INIT(x) = x
#endif

_DECL float GL_pi _INIT(3.141592f);
_DECL float GL_e _INIT(2.718281f);
_DECL float GL_gravF _INIT(32.2f);
_DECL float GL_gravM _INIT(9.81f);

#endif /* GLOBALS_H */

