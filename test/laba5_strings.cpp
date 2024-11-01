#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("..\\files_for_labs\\for_laba5.txt");
    ofstream fout("..\\files_for_labs\\from_laba5.txt");
    string line;
    int line_number = 0, j = 0, count = 0;
    while (getline(fin, line)){
        int i = 0;
        while (i < line.length()){
            if ((line[i] == ' ') || (line[i] == '\t')) line.replace (i, 1, "");
            else i += 1;
        }
        if (line.length() == 0){
            count += 1;
        }
        else{
            if (count != 0){
                fout << count << ' ' << j + 1 << endl;
            } 
            j = line_number;
            count = 0;
        }
        line_number += 1;
    }
    fin.close();
    fout.close();
    return 0;
}
