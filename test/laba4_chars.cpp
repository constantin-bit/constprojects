#include <iostream>
#include <ctime>

using namespace std;

char* strncat(char* strDest, const char* strSource, size_t count){
    char* end;
    end = strDest;
    do{
        end += 1;
    }while(*end != '\0');
    for (int i = 0; i < count; i++){
        if (strSource[i] == '\0'){
            count = i;
            break;
        }
        *(end + i) = strSource[i];
    }
    *(end + count) = '\0';
    return strDest;
}
int main(){
    int qtyDest, qtySource;
    size_t additive;
    cin >> qtyDest >> qtySource >> additive;
    char Dest[qtyDest + 1], Source[qtySource + 1];
    for (int i = 0; i < qtyDest; i++) cin >> Dest[i];
    Dest[qtyDest] = '\0';
    for (int i = 0; i < qtySource; i++) cin >> Source[i];
    Source[qtySource] = '\0';
    cout << endl << strncat(Dest, Source, additive);
    return 0;
}