#include <iostream>

using namespace std; 

int is_palindrom(char *str, int cnt){
    int found = 1;
    for(int i = 0; i < cnt / 2; i++){
        if (str[i] != str[cnt - i - 1]){
            found = 0;
            break;
        }
    }
    if (found != 0){
        for (int i = 0; i < cnt; i++){
            if ((str[i] < 48) || (str[i] > 57)){
                found = 0;
                break;
            }
        }
    }
    return found;
}
int main(){
    char strInput[1000] = {'\0'};
    char word[1000] = {'\0'}, result_word[1000] = {'\0'};    
    char ch;
    int position = 0, found_cnt = 0;
    cin.getline(strInput, 301);
    for (int i = 0; i < 300; i++){
        ch = strInput[i];
        if ((ch != ' ') && (ch != '\0')) {
            word[position] = ch;
            position++;
        }
        else{
           word[position] = '\0';
           if (is_palindrom(word, position) == 1) { 
              if (found_cnt < 2)  {
                  copy(&word[0], &word[position + 1], &result_word[0]);
              } 
              else{
                  break;
              }  
              found_cnt++;                
           }
           position = 0;
        }
        if (ch == '\0') {
            break;
        }
    }
    cout  << result_word;
    return 0;
}