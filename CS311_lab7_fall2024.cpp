#include <iostream>
#include <stdexcept>
using namespace std;

class AccountLocked : public exception{
    public:
        const char* what() const noexcept override{ return "Your account is locked! Contact the admin."; };
};

void login(){
    throw AccountLocked();
}

string reverseString(string str){

   int i = 0;
   int j = str.length() - 1;

   while(i < j){
        swap(str[i], str[j]);
        i++;
        j--;
   }

    return str;
}

string reverse_string_rec(const string& str){
   if(str.length() <= 1){
        return str;
   }
   else{
        return reverse_string_rec(str.substr(1, str.length() - 1)) + str[0];
   }
}

int main()
{
    cout << endl << "Testing Account login exception..." << endl;

    try{
        login();
    }
    catch (const AccountLocked& excpt){
        cout << excpt.what() << endl;
    }

    cout << endl <<  "Testing reversing a string..." << endl;

    std::cout << "Reverse of 'ABCD': " << reverseString("ABCD") << std::endl;
    std::cout << "Reverse of 'Hello': " << reverseString("Hello") << std::endl;
    std::cout << "Reverse of 'Bye': " << reverseString("Bye") << std::endl;

    cout << endl <<  "Testing reversing a string recursively..." << endl;
    std::cout << "Reverse of 'ABCD': " << reverse_string_rec("ABCD") << std::endl;
    std::cout << "Reverse of 'Hello': " << reverse_string_rec("Hello") << std::endl;
    std::cout << "Reverse of 'Bye': " << reverse_string_rec("Bye") << std::endl;

    return 0;
}