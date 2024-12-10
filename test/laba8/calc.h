#pragma once
#include <iostream>
#include "stack.h"
#include <stdexcept>

class expression{
    private:
        std::string line;
        std::string ready_line;
        int is_correct_expression = 1;
    public:
        expression(std::string _line){
            line = _line;
        }
        void set_line(std::string new_line){
            line = new_line;
        }
        int check(){
            char num[0];
            stack numbers(num, 0);
            stack other(num, 0);
            int i = 0;
            while (line[i] != '\0'){
                if ((line[i] == '(') && (line[i + 1] == ')')){
                    i = -1;
                    break;
                }
                if (((line[i] == '-') || (line[i] == '+') || (line[i] == '*') || (line[i] == '/')) && ((line[i + 1] == '-') || (line[i + 1] == '+') || (line[i + 1] == '*') || (line[i + 1] == '/') || (line[i + 1] == ')') || (line[i + 1] == '\0'))){
                    i = -1;
                    break;
                }
                if (((line[i] == '+') || (line[i] == '*') || (line[i] == '/')) && ((line[i - 1] == '-') || (line[i - 1] == '+') || (line[i - 1] == '*') || (line[i - 1] == '/') || (line[i - 1] == '(') || (line[i - 1] == '\0'))){
                    i = -1;
                    break;
                }
                if ((line[i] < 40) || (line[i] == 44) || (line[i] == 46) || (line[i] > 57)){
                    i = -1;
                    break;
                }
                i += 1;
            }
            if (i == -1){
                std::cout << "Incorrect note" << std::endl;
                is_correct_expression = 0;
                return 0;
            }
            i = 0;
            std::string _line = 'k' + line + 'k';
            int j = 1;
            other << 'k';
            while (true){
                char test;//curr_chr
                other >> test;
                other << test;
                if (_line[j] == 'k'){
                    if (test == 'k'){
                        break;
                    }
                    if ((test == '*') || (test == '/') || (test == '+') || (test == '-')){
                        numbers << test;
                        other >> test;
                        continue;
                    }
                    if (test == '('){
                        i = -1;
                        break;
                    }
                }
                if ((_line[j] == '+') || (_line[j] == '-')){
                    if ((_line[j] == '-') && ((j == 1) || (_line[j - 1] == '('))){
                        char trash = '~';
                        other << trash;
                        j += 1;
                        continue;
                    }
                    if ((test == 'k') || (test == '(')){
                        other << _line[j];
                        j += 1;
                        continue;
                    }
                    if ((test == '*') || (test == '/') || (test == '+') || (test == '-')){
                        numbers << test;
                        other >> test;
                        continue;
                    }
                }

                if ((_line[j] == '*') || (_line[j] == '/')){
                    if ((test == 'k') || (test == '(') || (test == '+') || (test == '-')){
                        other << _line[j];
                        j += 1;
                        continue;
                    }
                    if ((test == '*') || (test == '/')){
                        numbers << test;
                        other >> test;
                        continue;
                    }
                }
                if (_line[j] == '('){
                    other << _line[j];
                    j += 1;
                    continue;
                }
                if (_line[j] == ')'){
                    if (test == 'k'){
                        i = -1;
                        break;
                    }
                    if ((test == '*') || (test == '/') || (test == '+') || (test == '-')){
                        numbers << test;
                        other >> test;
                        continue;
                    }
                    if (test == '('){
                        char trash;
                        other >> trash;
                        other >> trash;
                        other << trash;
                        if (trash == '~'){
                            other >> trash;
                            numbers << trash;
                        }
                        j += 1;
                        continue;
                    }
                    continue;
                }
                if ((_line[j] > 47) && (_line[j] < 58)){
                    numbers << _line[j];
                    j += 1;
                    if ((_line[j] < 48) || (_line[j] > 57)){
                        numbers << '#';
                        char trash;
                        other >> trash;
                        other << trash;
                        if (trash == '~'){
                            other >> trash;
                            numbers << trash;
                        }
                    }
                    continue;
                }
            }
            for(int i = 0; i < numbers.get_size(); i++){
                ready_line += numbers[i];
            }
            if (i == -1){
                std::cout << "Incorrect expression" << std::endl;
                is_correct_expression = 0;
                return 0;
            }
            //std::cout << ready_line << std::endl;
            std::cout << "Correct expression" << std::endl;
            return 1;
        }
        int calculate(){
            if (is_correct_expression == 0) return 0;
            int begin = 0, end = 0;
            int k = 0;
            double num[0];
            stack numbers(num, 0);
            while (true){
                if (ready_line[k] == '\0') break;
                if ((ready_line[k] > 47) && (ready_line[k] < 58)){
                    if ((k != 0) && ((ready_line[k - 1] < 48) || (ready_line[k - 1] > 57))){
                        begin = k;
                    }
                    k += 1;
                    continue;
                }
                if (ready_line[k] == '#'){
                    end = k;
                    std::string amount;
                    for (int i = 0; i < end - begin; i++){
                        amount += ready_line[begin + i];
                    }
                    double num = std::stoi(amount);
                    numbers << num;
                    k += 1;
                    continue;
                }
                if ((ready_line[k] == '+') || (ready_line[k] == '-') || (ready_line[k] == '*') || (ready_line[k] == '/')){
                    double number1;
                    double number2;
                    numbers >> number2;
                    numbers >> number1;
                    double number3;
                    if (ready_line[k] == '+'){
                        number3 = number1 + number2;
                    }
                    else{
                        if (ready_line[k] == '-'){
                            number3 = number1 - number2;
                        }
                        else{
                            if (ready_line[k] == '*'){
                                number3 = number1 * number2;
                            }
                            else{
                                if (number2 == 0){
                                    throw std::invalid_argument("division by zero");
                                }
                                else{
                                    number3 = number1 / number2;
                                }
                            }
                        }
                    }
                    numbers << number3;
                    //numbers.print();
                    k += 1;
                    continue;
                }
                if (ready_line[k] == '~'){
                    double number1;
                    numbers >> number1;
                    double number2 = 0 - number1;
                    numbers << number2;
                    k += 1;
                }
            }
            double result;
            numbers >> result;
            std::cout << result << std::endl;
            return result;
        }
};
