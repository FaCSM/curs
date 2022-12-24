#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void remove_spaces(string &str) {
    str.erase(
            unique_copy(str.begin(), str.end(), str.begin(), [](char c1, char c2) { return c1 == ' ' && c2 == ' '; }),
            str.end());
}
void remove_symbols(string &str) {
    int symbols[10] = {33,34,45,40,41,58,59,44,46,63};
    for(int i=0;i<10;i++){
        str.erase(
                unique_copy(str.begin(), str.end(), str.begin(),
                            [&symbols, &i](char c1, char c2) { return c1 == (char) symbols[i] && c2 == (char) symbols[i]; }),
                str.end());
    }
}
void RegCheck(string &str){
    if((int)str[0]>=97 &&(int)str[0]<=122){ str[0] = char((int) str[0] - 32); }
    for(int i =1;i < str.length();i++){
        if((int)str[i-1] != 32 && (int)str[i]>= 65 && (int)str[i]<=90){
            str[i] = char((int)str[i]+32);
        }
    }
}
void ReversOut(string &str){
    int a;
    for(int i=str.length();i>=0;i--){
        if(str[i] == ' '){
            for(int k=i + 1;k<=(i+a);k++){
                cout << str[k];
            }
            a=0;
        }
        a++;
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') break;
        cout << str[i];
    }
    cout<<endl;
}
void ColumnOut(string &str){
    for(int i = 0;i<str.length();i++){
        if((int)str[i]==32) {
            cout << endl;
        }else{
            cout<<str[i];
        }
    }
    cout<<endl;
}
void finder(string &str){
    string subString = "", strRes = "not exist";
    int count = 0;
    int index =0;
    cout << "Input the substring you want to find in the string:";
    getline(cin, subString);
    cout << "Line search:" << "\n";
    string str1 = "";
    for(int i = 0; i <= str.length() - subString.length(); i++){
        str1 = "";
        for(int j = i; j < subString.length() + i; j++){
            if (str[j] == subString[j-i]){
                str1 += str[j];
            } else {
                continue;
            }
        }
        if (subString == str1){
            cout << i + 1 << " ";
            strRes = "exist";
            count += 1;
        }
    }
    cout << "SubString - " << strRes << "; There is(are) " << count << " substring(s);"<< "\n";
    cout << "Boyer-moore algorithm:" << "\n";
    strRes = "not exist"; count = 0;
    int arr[subString.length()];
    for(int i = 0; i < subString.length(); i++){
        if(i != subString.length() - 1){
            arr[i] = subString.length() - 1 - i;
        }else{
            bool flag = false;
            for (int j = i - 1; j >= 0; j--){
                if (subString[j] == subString[i]){
                    flag = true;
                    arr[i] = arr[j];
                    break;
                }
            }
            if(!flag){
                arr[i] = subString.length();
            }
        }
    }
    for(int i = subString.length() - 1; i < str.length();){
        string str1 = "";
        bool flag = true;
        if(str[i] == subString[subString.length() - 1]){
            for(int j = i; j > int(i - subString.length()); j--){
                if(str[j] == subString[subString.length() - 1 - i + j]){
                    str1 = str[j] + str1;
                }else{
                    flag = false;
                    i += subString.find(str[j]) != std::string::npos ? abs(arr[subString.find_last_of(str[j])] - int(i - j)) : subString.length() - int(i - j);
                    break;
                }
            }
            if(flag){
                strRes = "exist";
                cout << i + 1 - (subString.length() - 1) << " ";
                count += 1;
                i += arr[subString.length() - 1];
            }

        }else{
            i += subString.find(str[i]) != std::string::npos ? arr[subString.find_last_of(str[i])] : subString.length();
        }
    }
    cout << "SubString - " << strRes << "; There is(are) " << count << " substring(s);" << "\n";
}
int main4() {
    cout<<"Enter string:\n";
    string BaseString;
    getline(cin>>ws,BaseString,'\n');
    remove_spaces(BaseString);
    cout<<"Without spaces: "<< BaseString<<endl;
    remove_symbols(BaseString);
    cout<<"Without symbols: "<< BaseString<<endl;
    RegCheck(BaseString);
    cout<<"Register normalized: "<< BaseString<<endl;
    cout<<"Reversed fraze: ";
    ReversOut(BaseString);
    cout<<"Column out: \n";
    ColumnOut(BaseString);
    finder(BaseString);
    char ch;
    ch = 0;
    cout << "Press \"C\" to continue...";
    do {
        std::cin >> ch;
    } while (ch != 'c');
}