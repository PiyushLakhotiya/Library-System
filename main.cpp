#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

class Book {
    private:
        string bookName, publisher, author;
        int id,bookCount;
    public:
        void setBookFields(ifstream& bookInputFile, vector<Book>obj);
};

void Book::setBookFields(ifstream& bookInputFile, vector<Book>obj) {
    string line;
    int count = 0;
    Book tempBook;
    while(getline(bookInputFile, line)) {
        if(count == 0) {
            tempBook.bookName = line;
            count++;
        } else if(count == 1) {
            tempBook.author = line;
            count++;
        } else if(count == 2) {
            tempBook.publisher = line;
            count++;
        } else if(count == 3) {
            tempBook.id = stoi(line);
            count++;
        } else if(count == 4) {
            tempBook.bookCount = stoi(line); 
            count++;
        }
        if(count == 5) {
            obj.push_back(tempBook);
            count = 0;
        }
    }
}

class User{
    private:
        string name,department,contactNumber,password;
        int age;
        static int id;
        vector<int> booksIssued;
    public:
        void setName(User& obj,string name);
        void setAge(User& obj,int age);
        void setDepartment(User& obj,string department);
        void setContact(User& obj,string contact);
        void setPassword(User& obj,string contact);
        void setUserID(User& obj,int id);
        void setBookIssueId(User& obj, vector<int>id);
        void getName(ofstream& userOutputFile);
        void getAge(ofstream& userOutputFile);
        void getDepartment(ofstream& userOutputFile);
        void getContact(ofstream& userOutputFile);
        void getPassword(ofstream& userOutputFile);
        void newUserDetails(ofstream& userOutputFile);
        void generateUserID(ofstream& userOutputFile);
        void getBookIssueId(ofstream& userOutputFile);
        string returnName();
        string returnPassword();
        bool booksNeedToBeDeposited();
        void removeDepositedBook(int id);
};

string User::returnName() {
    return name;
}

string User::returnPassword() {
    return password;
}
void User::getName(ofstream& userOutputFile) {
    cout << "Please Enter Your Name: ";
    getline(cin >> ws, name);
    userOutputFile << name << endl;
}

void User::getAge(ofstream& userOutputFile) {
    cout << "Please Enter Your Age: ";
    cin >> age;
    userOutputFile << age << endl;
}

void User::getDepartment(ofstream& userOutputFile) {
    cout << "Please Enter Your Department: ";
    getline(cin >> ws, department);
    userOutputFile << department << endl;
}

void User::getContact(ofstream& userOutputFile) {
    cout << "Please Enter Your Contact Number: ";
    cin >> contactNumber;
    while(contactNumber.size() != 10) {
        cout << "Invalid!! Please Enter Your Correct Mobile Number\n";
        cin >> contactNumber;
    }
    userOutputFile << contactNumber << endl;
}

void User::getPassword(ofstream& userOutputFile) {
    cout << "Last Thing!!! Set Password and try to set a strong password.";
    getline(cin >> ws, password);
    while(password.size() < 6) {
        cout << "Okk. You made a mistake. So let's try again. You have to make a password of atleast length 6\n";
        getline(cin >> ws, password);
    }
    userOutputFile << password << endl;
}

void User::generateUserID(ofstream& userOutputFile) {
    ++id;
    userOutputFile << id << endl;
}

void User::getBookIssueId(ofstream& userOutputFile) {
    userOutputFile << endl;
}

void User::newUserDetails(ofstream& userOutputFile) {
    User::getName(userOutputFile);
    User::getAge(userOutputFile);
    User::getDepartment(userOutputFile);
    User::getContact(userOutputFile);
    User::getPassword(userOutputFile);
    User::generateUserID(userOutputFile);
    User::getBookIssueId(userOutputFile);
}

void User::setName(User& obj,string name) {
    obj.name = name;
}

void User::setAge(User& obj, int age) {
    obj.age = age;
}

void User::setDepartment(User& obj, string department) {
    obj.department = department;
}

void User::setContact(User& obj, string contact) {
    obj.contactNumber = contact;
}

void User::setPassword(User& obj, string password) {
    obj.password = password;
}

void User::setUserID(User& obj, int id) {
    obj.id = id;
}

void User::setBookIssueId(User& obj, vector<int> id) {
    obj.booksIssued = id;
}

bool User::booksNeedToBeDeposited() {
    for(int i=0; i<booksIssued.size(); i++) {
        cout << booksIssued[i] << endl;
    }
    if(booksIssued.size() == 0) {
        cout << "Sorry! But we cannot see anybook that you need to deposit\n";
        return 0;
    }
    return 1;
}

void User::removeDepositedBook(int id) {
    for(auto it=booksIssued.begin(); it!=booksIssued.end(); it++) {
        if(*it == id) {
            booksIssued.erase(it);
            break;
        }
    }
}

int User::id = 0;



bool startMessage() {
    bool isAccount;
    cout << "Hi! Welecome to our library and blah blah blah" << endl;
    cout << "Do you have an account\nIf Yes Please Press 1 Otherwise Please Press 0" << endl;
    cin >> isAccount;
    return isAccount;
}

bool endMessage() {
    char choice;
    cout << "Do you want to continue?[y/n]\n";
    cin >> choice;
    if(choice == 'y' || choice == 'Y') {
        return true;
    } else {
        return false;
    }
}

bool issueOrDeposit() {
    string userChoice;
    cout << "So. Do you want to Issue or Deposit book" << endl;
    cin >> userChoice;
    transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);
    if(userChoice == "issue") {
        return 1;
    } else {
        return 0;
    }
}

bool authentication(string username, string password, vector<User> &user, User &currentUser) {
    for(int i=0; i<user.size(); i++) {
        if(user[i].returnName() == username && user[i].returnPassword() == password) {
            currentUser = user[i];
            return 1;
        }
    }
    return 0;
}

void createNewAccount(ofstream& userOutputFile, User& tempUser1) {
    tempUser1.newUserDetails(userOutputFile);
}

int main() {
    ifstream bookInputFile;
    vector<Book>book;
    bookInputFile.open("Book.txt");
    
    bookInputFile.close();
    ifstream userInputFile;
    ofstream userOutputFile;
    vector<User> user;
    
    userInputFile.open("User.txt");
    string line;
    int count = 0;
    {
    User tempUser;
    while(getline(userInputFile, line)) {
        if(count == 0) {
            tempUser.setName(tempUser,line);
            count++;
        } else if(count == 1) {
            int age = stoi(line);
            tempUser.setAge(tempUser,age);
            count++;
        } else if(count == 2) {
            tempUser.setDepartment(tempUser,line);
            count++;
        } else if(count == 3) {
            tempUser.setContact(tempUser,line);
            count++;
        } else if(count == 4) {
            tempUser.setPassword(tempUser,line);
            count++;
        } else if(count == 5) {
            int id = stoi(line);
            tempUser.setUserID(tempUser,id);
            count++;
        } else if(count == 6) {
            string a = "";
            if(line == "") {
                count++;
            } else {
                line += " ";
                vector<int> id;
                for(int i=0; i<line.size(); i++) {
                    if(line[i] == ' ') {
                        id.push_back(stoi(a));
                        a = "";
                    } else {
                        a += line[i];
                    }
                }
                tempUser.setBookIssueId(tempUser, id);
                count++;
            }
        }
        if(count == 7) {
            user.push_back(tempUser);
            count = 0;
        }
    }
    }
    userInputFile.close();
    
    bool isAccount,whatUserWantToDo,bookIssueOrDeposit;
    isAccount = startMessage();
    User currentUser;
    if(isAccount == false) {
        cout << "Ok. So Let's first create your account.\n";
        User tempUser1;
        userOutputFile.open("User.txt",userOutputFile.app);
        // tempUser1.newUserDetails(userOutputFile);
        createNewAccount(userOutputFile, tempUser1);
        user.push_back(tempUser1);
        userOutputFile.close();
        currentUser = tempUser1;
        isAccount = true;
        cout << "Great Your Account Has Been Created." << endl;
        whatUserWantToDo = endMessage();
        if(whatUserWantToDo == false) {
            return 0;
        }
    } else {
        string name,password;
        cout << "Please Enter Your Account Information" << endl;
        cout << "Your Name\n";
        getline(cin >> ws, name);
        cout << "Password\n";
        getline(cin >> ws, password);
        // Check if account exist
        bool isAccountExist,newAccountCreate;
        isAccountExist = authentication(name, password, user, currentUser);
        if(isAccountExist == false) {
            cout << "Sorry! Your credentials are wrong or you don't have any account in our database" << endl;
            cout << "So. Do you want to create new account.[y/n]\n";
            char a;
            cin >> a;
            if(a == 'Y' || a == 'y') {
                userOutputFile.open("User.txt",userOutputFile.app);
                createNewAccount(userOutputFile, currentUser);
                user.push_back(currentUser);
                userOutputFile.close();
                cout << "Great Your Account Has Been Created." << endl;
            } else {
                return 0;
            }
        }
    }
    start:;
    bookIssueOrDeposit = issueOrDeposit();
    if(bookIssueOrDeposit == 0) { // Deposit
        int id;
        bool isTrue;
        cout << "Books need to be deposited are: \n";
        isTrue = currentUser.booksNeedToBeDeposited();
        if(isTrue) {
            cout << "Enter Book ID: ";
            cin >> id;
            // remove book from book  issued
            currentUser.removeDepositedBook(id);
        } else {
            bool continueOrNot;
            continueOrNot = endMessage();
            if(continueOrNot) {
                goto start;
            } else {
                return 0;
            }
        }
    }
}
