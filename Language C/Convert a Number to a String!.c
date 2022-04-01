#include <stdlib.h>

char* number_to_string(int number) {
    
    int counter = 0,
        temp = number;
    
    
    if (number < 0) temp *= -1;
    
    // находим кол-во разрядов числа
    // find the number of digit of the number
    while (temp != 0) { counter ++; temp /= 10; }
    
    // выделяем память под строку
    // allocate memory for the line
    char *result = (char *)calloc(counter + 2, sizeof(char));
    result[counter + 2] = '\0';
    
  
    // проверяем положение числа на оси 
    // check the position of the number on the axis
    if (number < 0) { result[0] = '-'; number *= -1; }
    if (number == 0) { result[0] = '0'; return result; }
    
    // проверка знака, который уже поставили
    // checking the sign that has already been installed
    if (result[0] == '-')
    {
        for (int i = counter; i > 0; i --)
        {
            result[i] = (number % 10) + '0';
            number /= 10;
        }
    }
    
    else
    {
        for (int i = counter - 1; i > -1; i --)
        {
            result[i] = (number % 10) + '0';
            number /= 10;
        }
    }
  
  return result;
}
