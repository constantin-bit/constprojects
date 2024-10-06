#include <iostream>

using namespace std;

int main(){
    int cnt = 0, start = 0, word_cnt = 0, prev_start, prev_cnt, j;
    char strInput[1000] = {'\0'};
    char ch;
    cin.getline(strInput, 301);

    for (int i = 0; i < 301; i++){
        if (i > 0){
            if (strInput[i - 1] == '\0') break;
        }
        else{
            if ((strInput[i] == '\0') && (strInput[i - 1] == '\0')) break;
        }
        if ((strInput[i] != ' ') && (strInput[i] != '\0')){
            if (i == 0) cnt = 1;
            else{
                cnt += 1;
                if (strInput[i - 1] == ' ') start = i;
            }
        }
        else{
            if (i == 0) continue;
            else{
                int found = 1;
                for (int j = 0; j < cnt; j++){
                    if ((strInput[start + j] != strInput[start + cnt - j - 1]) || (int(strInput[start + j]) < 48) || (int(strInput[start + j]) > 57)){
                        start = 0;
                        cnt = 0; 
                        found = 0;
                        break;
                    }
                }
                if (((found == 1) && (cnt > 0)) || (strInput[i] == '\0')){
                    word_cnt += found;
                    if ((word_cnt == 1) && (found == 1)){
                        prev_cnt = cnt;
                        prev_start = start;
                    }
                    if ((word_cnt == 2) || (strInput[i] == '\0')){
                        if (word_cnt == 2) {
                            for (int j = start; j < start + cnt; j++) {
                                cout << strInput[j];
                            }    
                        }
                        else{
                            for (int j = prev_start; j < prev_start + prev_cnt; j++) cout << strInput[j];
                        }
                        break;
                    }
                    start = 0;
                    cnt = 0;
                }
            }
        }
    }
    return 0;
}