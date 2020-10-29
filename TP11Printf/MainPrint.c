/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainPrint.c
 * Author: ebatemarco
 *
 * Created on 29 de octubre de 2020, 15:57
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void mi_printf(char* string, ...);
void putchar_d (int num);
void putchar_x (unsigned int num);
void putchar_c (char letra);

/*
 * 
 */
int main(int argc, char** argv) 
{
    mi_printf ("Hola %x %d mundo", 1359, 1359);
    return (EXIT_SUCCESS);
}

void mi_printf(char* string, ...)
{
    va_list param_list;
    va_start (param_list, string); 
    
    int i = 0;
    
    while (string[i] != '\0')
    {
        if ((string[i] <= 254)&(string[i]>= 38)|(string[i] <= 36)&(string[i]>= 32))
        {
            putchar (string[i]);
        }
        else if ((string[i] == '%'))
        {
            switch (string[i+1])
            {   
                case 'd':
                    putchar_d (va_arg(param_list,int));
                    break;
                case 'x':
                    putchar_x (va_arg(param_list,unsigned int));
                    break;
                case 'c':
                    putchar_c (va_arg(param_list,char));
                    break;
                default:
                    break;
            }
            i++;
        }
        i++;
    }
    va_end (param_list);
}

void putchar_d (int num)
{
    if (num < 0)
    {
        putchar ('-');
        num = -num;
    }
    if (num == 0)
    {
        return;
    }
    else 
    {
        putchar_d (num/10);
        putchar ((num%10)+48);
    }
    return;
}

void putchar_x (unsigned int num)
{
    if (num == 0)
    {
        return;
    }
    else 
    {
        putchar_x (num/16);
        switch (num%16)
        {
            case 15:
                putchar ('F');
                break;
            case 14:
                putchar ('E');
                break;
            case 13:
                putchar ('D');
                break;
            case 12:
                putchar ('C');
                break;
            case 11:
                putchar ('B');
                break;
            case 10:
                putchar ('A');
                break;
            default:
                putchar ((num%16)+48);
                break;
        }
    }
    return;
}

void putchar_c (char letra)
{
    
}