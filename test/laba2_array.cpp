#include <iostream>

using namespace std;

int main(){
    int quan, num;
    cin >> quan;
    cout << endl;
    double arr[quan], sum;
    for (int i = 0; i < quan; i++) cin >> arr[i];
    cout << endl;
    int p;
    cin >> p;
    num = 0;
    for (int i = 0; i < quan; i++){
        if (arr[i] < p) num = num + 1;
    }
    cout << num << endl;
    num = -1;
    for (int i = quan - 1; i > -1; i--){
        if (arr[i] < 0){
            num = i;
            break;
        }
    }
    sum = 0;
    for (int i = num + 1; i < quan; i++){
        if (arr[i] < 0){
            sum = sum + int(arr[i] - 1);
        }
        else{
            sum = sum + int(arr[i]);
        }
    }
    cout << sum << endl;
    sum = 0;
    num = 0;
    /*for (int i = 0; i < quan; i++){
        if (arr[i] < p){
            sum = arr[i];
            for (int j = i - 1; j > num - 1; j--){
                arr[j + 1] = arr[j];
            }
            arr[num] = sum;
            if (arr[i] < p) num = i + 1;
            else num = i;
        }
    }*/
    while (true){
        for (int i = 0; i < quan - 1; i++){
            if ((arr[i] >= p) && (arr[i + 1] < p)){
                sum = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = sum;
                num = num + 1;
            }
        }
        if (num == 0) break; // destroy
        num = 0;
    }
    for (int i = 0; i < quan; i++) cout << arr[i] << ' ';
    return 0;
}