#include<iostream>
#define endl "\n"
#define ll long long
using namespace std;
ll totalNumberOfUser = -1;
class User{
    private:
        string name,department,contactNumber;
        int age;
        static int id;
    public:
        void getName();
        void getAge();
        void getDepartment();
        void getContact();
        void newUserDetails();
        void generateUserID();
};
int User::id = 0;

void User::getName() {
    cout << "Please Enter Your Name: ";
    getline(cin >> ws, name);
}

void User::getAge() {
    cout << "Please Enter Your Age: ";
    cin >> age;
}

void User::getDepartment() {
    cout << "Please Enter Your Department: ";
    getline(cin >> ws, department);
}

void User::getContact() {
    cout << "Please Enter Your Contact Number: ";
    cin >> contactNumber;
    while(contactNumber.size() != 10) {
        cout << "Invalid!! Please Enter Your Correct Mobile Number\n";
        cin >> contactNumber;
    }
}

void User::generateUserID() {
    ++id;
}

void User::newUserDetails() {
    User::getName();
    User::getAge();
    User::getDepartment();
    User::getContact();
    User::id++;
}

int main() {
    User user[100];
    cout << "Hi! Welecome to our library and blah blah blah" << endl;
    cout << "Do you have an account\nIf Yes Please Press 1 Otherwise Please Press 0" << endl;
    bool isAccount;
    cin >> isAccount;
    if(isAccount == false) {
        cout << "Ok. So Let's first create your account.\n";
        user[++totalNumberOfUser].newUserDetails();
        cout << "Great Your Account Has Been Created." << endl;
    }
}