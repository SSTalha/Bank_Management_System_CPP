#include<iostream>
#include<iomanip>//here we use this for set width "setw()"
#include<Windows.h>//it includes libraries like stdlib stdio.h for inbuilt functions like sleep etc.
#include<conio.h>//for inbuilt function like getch()
#include<fstream>//file input output
#include<stdlib.h>
#include<stdio.h>
#include<string>//string character
using namespace std;
//loading bar function starts----------------------------------
void loadingbar() {
    char x = 219;//ascii value character
    cout << "\n\n\n\n";
    cout << "\t\t\tLoading...System. PLEASE WAIT! \n\n\n";
    cout << "\t";
    for (int i = 0; i < 100; i++) {
        cout << x;
        Sleep(5);// wait time for 5 secs
    }
    system("cls");//clear the screen from top
}

//----------------------------------------loading function ends
//class of main menu
class main_menu {
private:
    int transaction;
    char c;
    string name;
    long cnic;
    long Account_Number;
    int Amount_in_Bank = 0;
    int Employee_id, Branch_id, Department_id, Customer_id, Loan_id;
    char Account_type;
    string Loan_type;
    float Interest_rate;
    int Duration;
    int account_choice;
    int credit, debit, C_D_option = 0, Amount;
    string transaction_type;
    int Start_date;
    int Due_amount;
    char Employee_name[40];
    char Employee_address[60];
    int  Employee_phone;
    char Employee_Email[35];
    char Branch_name[40];
    char Branch_city[60];
    int  Branch_phone;
    char Branch_country[35];
    char Customer_name[30];
    char Customer_address[50];
    int Customer_phone;
    char Customer_Email[45];
    char Department_name[30];
    char Department_head[22];
public:
    //functions
//---------------Bank Branch------------------------
    void Bank_Branch();
    void Add_new_Branch();//Bank Branch
    void All_Branches() const;//Bank Branch
    void Branch_sequence();
    int Branch_ID() const;
    //---------------EMployee---------------
    void Add_employee();//Employee
    void Show_all_Employees() const;//Employee
    void Employee_sequence();
    int Employee_ID() const;
    //--------------------Customers--------------------------
    void New_Customer();//customer
    void All_customer() const;//customer
    int Customer_ID() const;
    void customer_sequence();
    void Transaction();
    void new_transaction();//Transaction
    void All_transaction() const;//Transaction
//----------------Department--------------
    void Add_Department();//department
    void show_departments() const;//department
    int department_id() const;
    void department_sequence();
    //------------------Loans----------------------
    void Add_new_loan();//loans
    void Show_loans() const;//loans
    void loans_sequence();
    int loan_id() const;
    //-------------Accounts-------------------
    void Create_new_Account();//Accounts
    void Existing_Accounts() const;//Accounts
    void Accounts_sequence();//Accounts
    int Account_num() const; //Accounts
    //-----------
    void dealing();
    void show_dealing();
    void dealing_sequence();
};

//========================================================================================================
int main_menu::Employee_ID() const {
    return Employee_id;
}
int main_menu::Account_num() const {
    return Account_Number;
}
int main_menu::loan_id() const {
    return Loan_id;
}
int main_menu::Customer_ID() const {
    return Customer_id;
}
int main_menu::department_id() const {
    return Department_id;
}
int main_menu::Branch_ID() const {
    return Branch_id;
}
void main_menu::dealing_sequence() {
    cout << setw(10) << Account_Number << setw(15) << Amount << setw(15) << transaction << endl;
}
void main_menu::loans_sequence() {
    cout << setw(10) << Account_Number << setw(15) << Loan_id << setw(15) << Loan_type << setw(15) << Interest_rate << setw(15) << Duration << setw(15) << Start_date << setw(15) << Due_amount << endl;
}
void main_menu::Accounts_sequence() {
    cout << setw(10) << Account_Number << setw(15) << Branch_id << setw(15) << Customer_id << setw(15) << Account_type << setw(15) << Interest_rate << endl;
}
void main_menu::Employee_sequence() {
    cout << setw(10) << Employee_id << setw(15) << Employee_name << setw(16) << Employee_phone << setw(21) << Employee_Email << setw(16) << Employee_address << setw(16) << Branch_id << setw(14) << Department_id << setw(17) << Account_Number << endl;
}
void main_menu::customer_sequence() {
    cout << setw(10) << Customer_id << setw(15) << Customer_name << setw(18) << Customer_Email << setw(17) << Customer_phone << setw(17) << Customer_address << setw(19) << Branch_id << setw(17) << Account_Number << endl;
}
void main_menu::department_sequence() {
    cout << setw(10) << Department_id << setw(15) << Department_name << setw(17) << Department_head << endl;
}
void main_menu::Branch_sequence() {
    cout << setw(10) << Branch_id << setw(15) << Branch_name << setw(15) << Branch_phone << setw(15) << Branch_city << setw(15) << Branch_country << endl;
}
//=======================================================================================================================
//-----------------------------------ACCOUNTS----------------------------------------------------------------------------
//=======================================================================================================================
void main_menu::Create_new_Account() //create accounts
{
    system("cls");
    cout << "\n Enter the account number you want to issue to the new account: ";
    cin.ignore();
    cin >> Account_Number;
    cout << "\n Enter Branch Id: ";
    cin.ignore();
    cin >> Branch_id;
    cout << "\n Enter Customer Id: ";
    cin.ignore();
    cin >> Customer_id;
    cout << "\n Enter Account Type(S for saving and C for Current): ";
    cin.ignore();
    cin >> Account_type;
    //conditional statements for current and saving accounts
    if (Account_type == 's' || Account_type == 'S') {
        cout << "\n\t\tYour Account is Saving!!";
        cout << "\n Enter Interest rate: ";
        cin.ignore();
        cin >> Interest_rate;
    }
    else if (Account_type == 'c' || Account_type == 'C') {
        cout << "Your Account is Current";
    }
    else {
        cout << "\n\t\tWrong choice Entered";
    }
    cout << "Press up/down key to return to main menu or Enter to re enter new Account";
}

//---------Existing accounts fucntions in file
void main_menu::Existing_Accounts() const {
    cout << "\n";
    cout << "\tAccount Number: \t" << Account_Number << endl;
    cout << "\tBranch Id: \t" << Branch_id << endl;
    cout << "\tCustomer ID: \t" << Customer_id << endl;
    cout << "\tAccount Type: \t" << Account_type << endl;
    cout << "\tInterest Rate: \t" << Interest_rate << endl;
}
//----------Store Accounts Functions-----
void store_account() {
    main_menu s_ac;
    ofstream outfile;
    outfile.open("Accounts.dat", ios::binary | ios::app);
    s_ac.Create_new_Account();
    outfile.write(reinterpret_cast<char*>(&s_ac), sizeof(main_menu));
    outfile.close();
}
void single_account() {
    int n;
    main_menu mm;
    ifstream infile;
    infile.open("Accounts.dat", ios::binary);
    if (!infile) {
        cout << "File not found!..(Press any Key)";
        return;
    }
    cout << "\n\t\t=================================";
    cout << "\n\t\t[      Single Account Record     ";
    cout << "\n\t\t=================================";
    cout << "Enter Account Number: ";
    cin >> n;
    while (infile.read(reinterpret_cast<char*>(&mm), sizeof(main_menu))) {
        if (mm.Account_num() == n) {
            mm.Existing_Accounts();
        }
        else {
            cout << "Account Number does not exist" << endl;
        }
    }
    infile.close();
    cout << "Press Enter Key to show another record or \n\tPress up/down key to return to main menu..." << endl;
}
void display_accounts() {
    main_menu dis;
    ifstream infile;
    infile.open("Accounts.dat", ios::binary);
    if (!infile) {
        cout << "Could Not open File! Press any Key....";
        return;
    }
    cout << "\n";
    cout << setw(50) << "======================================" << endl;
    cout << setw(50) << "--       All Existing Accounts      --" << endl;
    cout << setw(50) << "======================================" << endl << endl;
    cout << "=======================================================================" << endl;
    cout << setw(15) << "ACCOUNT NUMBER" << setw(15) << "BRANCH ID" << setw(15) << "CUSTOMER ID" << setw(15) << "ACCOUNT TYPE" << setw(15) << "INTEREST RATE" << endl;
    while (infile.read(reinterpret_cast<char*>(&dis), sizeof(main_menu))) {
        dis.Accounts_sequence();
    }
    infile.close();
    cout << "Press up/down arrow key to move to main menu..";
}
void Delete_Account()
{
    int n;
    main_menu s_ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("Accounts.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Tempac.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    cout << "\n\t\t====================================";
    cout << "\n\t\t[     DELETE ACCOUNT's RECORD      ]";
    cout << "\n\t\t====================================" << endl;
    cout << "\n\tEnter Account num: ";
    cin >> n;
    while (inFile.read(reinterpret_cast<char*> (&s_ac), sizeof(main_menu)))
    {
        if (s_ac.Account_num() != n)
        {
            cout << "No Record Found" << endl;
        }
        else {
            inFile.close();
            outFile.close();
            remove("Accounts.dat");
            rename("Tempac.dat", "Accounts.dat");
        }
    }
    cout << "\n\n....... Record DELETED Successfully.....";
}
void Accounts_menu(int wr) {
    system("cls");
    int i = 0;
    cout << "\n   ==============================================" << endl;
    cout << "   [ \"----              ACCOUNTS            ---\" ]";
    cout << "\n   ==============================================" << endl;
    char account[4][30] = { "\tCREATE NEW ACCOUNT", "\tSHOW EXISTING ACCOUNTS", "\tSINGLE ACCOUNT RECORD","\tDELETE ACCOUNT" };
    while (i < 4) {
        if (wr == i + 1) {
            cout << "\n   =>" << account[i];
        }
        else {
            cout << "\n " << account[i];
        }
        i++;
    }
    cout << "\n\nUse up down keys to move the cursor and\n SELECT Enter to select";
}

void mini_Accounts() {
    char ch = ' ';
    int i = 1;
    Accounts_menu(13);

    while (1) {
        ch = _getch();
        switch (ch) {
        case 72:
            if (i != 1) {
                i--;
                Accounts_menu(i);
            }
            break;
        case 80:
            if (i != 4) {
                i++;
                Accounts_menu(i);
            }
            break;
        case 13:
            if (i == 1) {
                system("cls");
                store_account();
            }
            else if (i == 2) {
                system("cls");
                display_accounts();
            }
            else if (i == 3) {
                system("cls");
                single_account();
            }
            else if (i == 4) {
                system("cls");
                Delete_Account();
            }
            else {
                return;
                break;
            }
        }
    }
}
//=========================================================================================
//-------------------Transactions--------------------------
//=========================================================================================
class Queue
{
    int* arr;       // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue

public:
    Queue(int size = 100);     // constructor
    ~Queue();                   // destructor

    int dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

// Constructor to initialize a queue
Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
Queue::~Queue() {
    delete[] arr;
}

// Utility function to dequeue the front element
int Queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    int x = arr[front];
    cout << "Removing " << x << endl;

    front = (front + 1) % capacity;
    count--;

    return x;
}

// Utility function to add an item to the queue
void Queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << item << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// Utility function to return the front element of the queue
int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

// Utility function to return the size of the queue
int Queue::size() {
    return count;
}

// Utility function to check if the queue is empty or not
bool Queue::isEmpty() {
    return (size() == 0);
}

// Utility function to check if the queue is full or not
bool Queue::isFull() {
    return (size() == capacity);
}
void main_menu::dealing() {
    system("cls");

    cout << "Enter Account: ";
    cin >> Account_Number;
    cout << "Number of transaction: ";
    cin >> transaction;
    Queue q;
    for (int i = 0; i < transaction; i++) {
        cout << "\n\t\tWhat to do?\n\n\t\t\t1. Credit Account\n\t\t\t2. Debit Account\n";
        cout << "Enter Option: ";
        cin >> C_D_option;
        if (C_D_option == 1) {
            cout << "Enter Amount You want to DEPOSIT: ";
            cin >> Amount;
            q.enqueue(Amount);
            Amount_in_Bank = Amount + Amount_in_Bank;
            cout << "\n\t\t\t\tAMOUNT SUCCESSFULLY ADDED TO THE ACCOUNT";
        }
        else if (C_D_option == 2) {
            cout << "Enter Amount You want to DEBIT: ";
            cin >> Amount;
            q.enqueue(Amount);
            cout << "If u want cancel your transaction press c";
            cin >> c;
            if (c == 'c') {
                q.dequeue();
            }
            else if (Amount_in_Bank >= Amount) {
                Amount_in_Bank = Amount - Amount_in_Bank;
                cout << "\n\t\t\t\tAMOUNT SUCCESSFULLY DEBITED";
            }
            else
            {
                cout << "You DON'T HAVE ENOUGH CASH";
            }
        }
        else
        {
            cout << "!!!!!!!!!!!!!You have ENTERED WRONG Choice!!!!!!!!!!!!!!!";
        }
    }
}
void main_menu::show_dealing() {
    cout << "Account Number: " << Account_Number;
    cout << "Amount: " << Amount;
    cout << "Transaction Amount: " << transaction;
}
void store_transaction() {
    main_menu s_ac;
    ofstream outfile;
    outfile.open("transaction.dat", ios::binary | ios::app);
    s_ac.dealing();
    outfile.write(reinterpret_cast<char*>(&s_ac), sizeof(main_menu));
    outfile.close();
}
void show() {
    main_menu dis;
    ifstream infile;
    infile.open("transaction.dat", ios::binary);
    if (!infile) {
        cout << "Could Not open File! Press any Key....";
        return;
    }
    cout << "\n";
    cout << setw(50) << "======================================" << endl;
    cout << setw(50) << "--       All Transactions      --" << endl;
    cout << setw(50) << "======================================" << endl << endl;
    cout << "=======================================================================" << endl;
    cout << setw(15) << "ACCOUNT NUMBER" << setw(15) << "AMOUNT" << setw(25) << "TRANSACTION AMOUNT" << endl;
    while (infile.read(reinterpret_cast<char*>(&dis), sizeof(main_menu))) {
        dis.dealing_sequence();
    }
    infile.close();
    cout << "Press up/down arrow key to move to main menu..";
}
void dealing_menu(int wr) {
    system("cls");
    int i = 0;
    cout << "\n   ==============================================" << endl;
    cout << "   [ \"----              TRANSACTIONS            ---\" ]";
    cout << "\n   ==============================================" << endl;
    char deal[2][30] = { "\tDO TRANSACTION", "\tSHOW ALL TRANSACTIONS" };
    while (i < 2) {
        if (wr == i + 1) {
            cout << "\n   =>" << deal[i];
        }
        else {
            cout << "\n " << deal[i];
        }
        i++;
    }
    cout << "\n\nUse up down keys to move the cursor and\n SELECT Enter to select";
}

void mini_dealings() {
    char ch = ' ';
    int i = 1;
    dealing_menu(13);

    while (1) {
        ch = _getch();
        switch (ch) {
        case 72:
            if (i != 1) {
                i--;
                dealing_menu(i);
            }
            break;
        case 80:
            if (i != 2) {
                i++;
                dealing_menu(i);
            }
            break;
        case 13:
            if (i == 1) {
                system("cls");
                store_transaction();
            }
            else if (i == 2) {
                system("cls");
                show();
            }
            else {
                return;
                break;
            }
        }
    }
}
//======================================================================================================================
//--------------------------------------------------------EMPLOYEES-----------------------------------------------------
//======================================================================================================================
void main_menu::Add_employee()
{
    system("cls");
    cout << "\nEnter Name: ";
    cin.ignore();
    cin.get(Employee_name, 40);
    cout << "\nEnter Phone Number: ";
    cin.ignore();
    cin >> Employee_phone;
    cout << "\nEnter Email Address: ";
    cin.ignore();
    cin.get(Employee_Email, 35);
    cout << "\nEnter Home Address: ";
    cin.ignore();
    cin.get(Employee_address, 60);
    cout << "\nWhat ID you want to NEW FAMILY MEMBER: ";
    cin >> Employee_id;
    cout << "\nIn Which Branch You  want to Assign. Give Branch ID: ";
    cin >> Branch_id;
    cout << "\nWhich Department. GIVE Department ID: ";
    cin >> Department_id;
    cout << "\nAccount Number: ";
    cin >> Account_Number;
}
void main_menu::Show_all_Employees() const {
    cout << "\n";
    cout << "\tEmployee Name: \t" << Employee_name << endl;
    cout << "\tEmployee Phone: \t" << Employee_phone << endl;
    cout << "\tEmployee Email: \t" << Employee_Email << endl;
    cout << "\tEmployee Address: \t" << Employee_address << endl;
    cout << "\tEmployee ID: \t" << Employee_id << endl;
    cout << "\tBranch ID: \t" << Branch_id << endl;
    cout << "\tDepartment ID: \t" << Department_id << endl;
    cout << "\tAccount Number: \t" << Account_Number << endl;
}
void store_employee() {
    main_menu s_ac;
    ofstream outfile;
    outfile.open("Employee.dat", ios::binary | ios::app);
    s_ac.Add_employee();
    outfile.write(reinterpret_cast<char*>(&s_ac), sizeof(main_menu));
    outfile.close();
}

void single_Employee() {
    int n;
    main_menu mm;
    ifstream infile;
    infile.open("Employee.dat", ios::binary);
    if (!infile) {
        cout << "File not found!..(Press any Key)";
        return;
    }
    cout << "\n\t\t=================================";
    cout << "\n\t\t[      Single Employee Record     ";
    cout << "\n\t\t=================================";
    cout << "Enter Employee ID: ";
    cin >> n;
    while (infile.read(reinterpret_cast<char*>(&mm), sizeof(main_menu))) {
        if (mm.Employee_ID() == n) {
            mm.Show_all_Employees();
        }
        else {
            cout << "Employee does not exist" << endl;
        }
    }
    infile.close();
    cout << "Press Enter Key to show another record or \n\tPress up/down key to return to main menu..." << endl;
}
void display_Employee() {
    main_menu dis;
    ifstream infile;
    infile.open("Employee.dat", ios::binary);
    if (!infile) {
        cout << "Could Not open File! Press any Key....";
        return;
    }
    cout << "\n";
    cout << setw(50) << "======================================" << endl;
    cout << setw(50) << "--       All Existing EMPLOYEE      --" << endl;
    cout << setw(50) << "======================================" << endl << endl;
    cout << "=======================================================================" << endl;
    cout << setw(15) << "EMPLOYEE ID" << setw(15) << "EMPLOYEE NAME" << setw(19) << "EMPLOYEE PHONE NO." << setw(15) << "EMPLOYEE EMAIL" << setw(18) << "EMPLOYEE ADDRESS" << setw(13) << "BRANCH ID" << setw(15) << "DEPARTMENT ID" << setw(16) << "ACCOUNT NUMBER" << endl;
    while (infile.read(reinterpret_cast<char*>(&dis), sizeof(main_menu))) {
        dis.Employee_sequence();
    }
    infile.close();
    cout << "Press up/down arrow key to move to main menu..";
}
void Delete_Employee()
{
    int n;
    main_menu s_ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("Employee.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Tempem.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    cout << "\n\t\t====================================";
    cout << "\n\t\t[     DELETE EMPLOYEES RECORD      ]";
    cout << "\n\t\t====================================" << endl;
    cout << "\n\tEnter Employee ID: ";
    cin >> n;
    while (inFile.read(reinterpret_cast<char*> (&s_ac), sizeof(main_menu)))
    {
        if (s_ac.Employee_ID() != n)
        {
            cout << "No Record Found" << endl;
        }
        else {
            inFile.close();
            outFile.close();
            remove("Employee.dat");
            rename("Tempem.dat", "Employee.dat");
        }
    }
    cout << "\n\n....... Record DELETED Successfully.....";
}
void Employees_menu(int wr) {
    system("cls");
    int i = 0;
    cout << "\n   ==============================================" << endl;
    cout << "   [ \"----              EMPLOYEES             ---\" ]";
    cout << "\n   ==============================================" << endl;
    char employee[4][25] = { "\tADD NEW EMPLOYEE", "\tSHOW ALL EMPLOYEES", "\tSHOW SINGLE EMPLOYEE", "\tDELETE EMPLOYEE" };
    while (i < 4) {
        if (wr == i + 1) {
            cout << "\n   =>" << employee[i];
        }
        else {
            cout << "\n " << employee[i];
        }
        i++;
    }
    cout << "\n\nUse up down keys to move the cursor and\n SELECT Enter to select";
}
void mini_Employees() {
    char ch = ' ';
    int i = 1;
    Employees_menu(13);

    while (1) {
        ch = _getch();
        switch (ch) {
        case 72:
            if (i != 1) {
                i--;
                Employees_menu(i);
            }
            break;
        case 80:
            if (i != 4) {
                i++;
                Employees_menu(i);
            }
            break;
        case 13:
            if (i == 1) {
                system("cls");
                store_employee();
            }
            else if (i == 2) {
                system("cls");
                display_Employee();
            }
            else if (i == 3) {
                system("cls");
                single_Employee();
            }
            else if (i == 4) {
                system("cls");
                Delete_Employee();
            }
            else {
                return;
                break;
            }
        }
    }
}
//=====================================================================================================================
//-------------------------------------------------BANK BRANCH----------------------------------------------------------
//=====================================================================================================================
void main_menu::Add_new_Branch() //2
{
    system("cls");
    cout << "\n Enter Branch Id: ";
    cin.ignore();
    cin >> Branch_id;
    cout << "\n Enter Bank Branch Name: ";
    cin.ignore();
    cin.get(Branch_name, 40);
    cout << "\n Enter Branch City: ";
    cin.ignore();
    cin.get(Branch_city, 60);
    cout << "\n Enter Branch phone no: ";
    cin.ignore();
    cin >> Branch_phone;
    cout << "\n Enter Branch country: ";
    cin.ignore();
    cin.get(Branch_country, 35);
}
void main_menu::All_Branches() const {
    cout << "\n";
    cout << "\tBranch Name: \t" << Branch_name << endl;
    cout << "\tBranch Phone: \t" << Branch_phone << endl;
    cout << "\tBranch City: \t" << Branch_city << endl;
    cout << "\tBranch Country: \t" << Branch_country << endl;
    cout << "\tBranch ID: \t" << Branch_id << endl;
}
void store_branch() {
    main_menu s_ac;
    ofstream outfile;
    outfile.open("Branch.dat", ios::binary | ios::app);
    s_ac.Add_new_Branch();
    outfile.write(reinterpret_cast<char*>(&s_ac), sizeof(main_menu));
    outfile.close();
}

void single_Branch() {
    int n;
    main_menu mm;
    ifstream infile;
    infile.open("Branch.dat", ios::binary);
    if (!infile) {
        cout << "File not found!..(Press any Key)";
        return;
    }
    cout << "\n\t\t=================================";
    cout << "\n\t\t[      Single Branch Record     ";
    cout << "\n\t\t=================================";
    cout << "Enter Branch ID: ";
    cin >> n;
    while (infile.read(reinterpret_cast<char*>(&mm), sizeof(main_menu))) {
        if (mm.Branch_ID() == n) {
            mm.All_Branches();
        }
        else {
            cout << "Branch does not exist" << endl;
        }
    }
    infile.close();
    cout << "Press Enter Key to show another record or \n\tPress up/down key to return to main menu..." << endl;
}
void display_Branch() {
    main_menu dis;
    ifstream infile;
    infile.open("Branch.dat", ios::binary);
    if (!infile) {
        cout << "Could Not open File! Press any Key....";
        return;
    }
    cout << "\n";
    cout << setw(50) << "======================================" << endl;
    cout << setw(50) << "--       All Existing BRANCHES      --" << endl;
    cout << setw(50) << "======================================" << endl << endl;
    cout << "=======================================================================" << endl;
    cout << setw(15) << "BRANCH ID" << setw(15) << "BRANCH NAME" << setw(18) << "BRANCH PHONE NO." << setw(15) << "BRANCH CITY" << setw(16) << "BRANCH COUNTRY" << endl;
    while (infile.read(reinterpret_cast<char*>(&dis), sizeof(main_menu))) {
        dis.Branch_sequence();
    }
    infile.close();
    cout << "Press up/down arrow key to move to main menu..";
}
void Delete_Branch()
{
    int n;
    main_menu s_ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("Branch.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Tempbr.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    cout << "\n\t\t====================================";
    cout << "\n\t\t[     DELETE BRANCH      ]";
    cout << "\n\t\t====================================" << endl;
    cout << "\n\tEnter Branch ID: ";
    cin >> n;
    while (inFile.read(reinterpret_cast<char*> (&s_ac), sizeof(main_menu)))
    {
        if (s_ac.Branch_ID() != n)
        {
            cout << "No Record Found" << endl;
        }
        else {
            inFile.close();
            outFile.close();
            remove("Branch.dat");
            rename("Tempbr.dat", "Branch.dat");
        }
    }
    cout << "\n\n....... Record DELETED Successfully.....";
}
void Branch_menu(int wr) {
    system("cls");
    int i = 0;
    cout << "\n   ==============================================" << endl;
    cout << "   [ \"----              BRANCHES              ---\" ]";
    cout << "\n   ==============================================" << endl;
    char branch[4][30] = { "\tADD NEW BRANCH", "\tSHOW ALL BRANCHES", "\tSHOW SINGLE BRANCH", "\tDELETE BRANCH" };
    while (i < 4) {
        if (wr == i + 1) {
            cout << "\n   =>" << branch[i];
        }
        else {
            cout << "\n " << branch[i];
        }
        i++;
    }
    cout << "\n\nUse up down keys to move the cursor and\n SELECT Enter to select";
}
void mini_Branch() {
    char ch = ' ';
    int i = 1;
    Branch_menu(13);

    while (1) {
        ch = _getch();
        switch (ch) {
        case 72:
            if (i != 1) {
                i--;
                Branch_menu(i);
            }
            break;
        case 80:
            if (i != 4) {
                i++;
                Branch_menu(i);
            }
            break;
        case 13:
            if (i == 1) {
                system("cls");
                store_branch();
            }
            else if (i == 2) {
                system("cls");
                display_Branch();
            }
            else if (i == 3) {
                system("cls");
                single_Branch();
            }
            else if (i == 4) {
                system("cls");
                Delete_Branch();
            }
            else {
                return;
                break;
            }
        }
    }
}
//========================================================================================================
//--------------------------------------------------CUSTOMER----------------------------------------------
//========================================================================================================
void main_menu::New_Customer() //5
{

    system("cls");
    cout << "\n Enter Customer id: ";
    cin.ignore();
    cin >> Customer_id;
    cout << "\n Enter Customer_name: ";
    cin.ignore();
    cin.get(Customer_name, 30);
    cout << "\n Enter Customer Address: ";
    cin.ignore();
    cin.get(Customer_address, 50);
    cout << "\n Enter Customer phone no: ";
    cin.ignore();
    cin >> Customer_phone;
    cout << "\n Enter Customer Email: ";
    cin.ignore();
    cin.get(Customer_Email, 45);
    cout << "\n In which Branch customer has opened account. Give Branch id: ";
    cin.ignore();
    cin >> Branch_id;
    cout << "\n Enter Customer's account no: ";
    cin.ignore();
    cin >> Account_Number;
}
void main_menu::All_customer() const {
    cout << "\n";
    cout << "\tCustomer ID: \t" << Customer_id << endl;
    cout << "\tCustomer name: \t" << Customer_name << endl;
    cout << "\tEmployee Email: \t" << Customer_Email << endl;
    cout << "\tCustomer Phone: \t" << Customer_phone << endl;
    cout << "\tEmployee Address: \t" << Customer_address << endl;
    cout << "\tBranch ID: \t" << Branch_id << endl;
    cout << "\tAccount Number: \t" << Account_Number << endl;
}
void store_customer() {
    main_menu s_ac;
    ofstream outfile;
    outfile.open("Customer.dat", ios::binary | ios::app);
    s_ac.New_Customer();
    outfile.write(reinterpret_cast<char*>(&s_ac), sizeof(main_menu));
    outfile.close();
}
void single_customer() {
    int n;
    main_menu mm;
    ifstream infile;
    infile.open("Customer.dat", ios::binary);
    if (!infile) {
        cout << "File not found!..(Press any Key)";
        return;
    }
    cout << "\n\t\t=================================";
    cout << "\n\t\t[      Single Customer Record     ";
    cout << "\n\t\t=================================";
    cout << "Enter Customer ID: ";
    cin >> n;
    while (infile.read(reinterpret_cast<char*>(&mm), sizeof(main_menu))) {
        if (mm.Customer_ID() == n) {
            mm.All_customer();
        }
        else {
            cout << "Customer does not exist" << endl;
        }
    }
    infile.close();
    cout << "Press Enter Key to show another record or \n\tPress up/down key to return to main menu..." << endl;
}
void display_Customer() {
    main_menu dis;
    ifstream infile;
    infile.open("Customer.dat", ios::binary);
    if (!infile) {
        cout << "Could Not open File! Press any Key....";
        return;
    }
    cout << "\n";
    cout << setw(50) << "======================================" << endl;
    cout << setw(50) << "--       All Existing Customer      --" << endl;
    cout << setw(50) << "======================================" << endl << endl;
    cout << "=======================================================================" << endl;
    cout << setw(15) << "CUSTOMER ID" << setw(15) << "CUSTOMER NAME" << setw(17) << "CUSTOMER EMAIL" << setw(20) << "CUSTOMER PHONE NO." << setw(18) << "CUSTOMER ADDRESS" << setw(13) << "BRANCH ID" << setw(16) << "ACCOUNT NUMBER" << endl;
    while (infile.read(reinterpret_cast<char*>(&dis), sizeof(main_menu))) {
        dis.customer_sequence();
    }
    infile.close();
    cout << "Press up/down arrow key to move to main menu..";
}
void Delete_Customer()
{
    int n;
    main_menu s_ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("Customer.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Tempde.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    cout << "\n\t\t====================================";
    cout << "\n\t\t[     DELETE CUSTOMER RECORD      ]";
    cout << "\n\t\t====================================" << endl;
    cout << "\n\tEnter Customer ID: ";
    cin >> n;
    while (inFile.read(reinterpret_cast<char*> (&s_ac), sizeof(main_menu)))
    {
        if (s_ac.Customer_ID() != n)
        {
            cout << "No Record Found" << endl;
        }
        else {
            inFile.close();
            outFile.close();
            remove("Customer.dat");
            rename("Tempde.dat", "Customer.dat");
        }
    }
    cout << "\n\n....... Record DELETED Successfully.....";
}
void Customer_menu(int wr) {
    system("cls");
    int i = 0;
    cout << "\n   ==============================================" << endl;
    cout << "   [ \"----              CUSTOMERS             ---\" ]";
    cout << "\n   ==============================================" << endl;
    char customer[4][30] = { "\tADD NEW CUSTOMER", "\tSHOW ALL CUSTOMER", "\tSHOW SINGLE CUSTOMER", "\tDELETE CUSTOMER" };
    while (i < 4) {
        if (wr == i + 1) {
            cout << "\n   =>" << customer[i];
        }
        else {
            cout << "\n " << customer[i];
        }
        i++;
    }
    cout << "\n\nUse up down keys to move the cursor and\n SELECT Enter to select";
}
void mini_Customers() {
    char ch = ' ';
    int i = 1;
    Customer_menu(13);

    while (1) {
        ch = _getch();
        switch (ch) {
        case 72:
            if (i != 1) {
                i--;
                Customer_menu(i);
            }
            break;
        case 80:
            if (i != 4) {
                i++;
                Customer_menu(i);
            }
            break;
        case 13:
            if (i == 1) {
                system("cls");
                store_customer();
            }
            else if (i == 2) {
                system("cls");
                display_Customer();
            }
            else if (i == 3) {
                system("cls");
                single_customer();
            }
            else if (i == 4) {
                system("cls");
                Delete_Customer();
            }
            else {
                return;
                break;
            }
        }
    }
}
//========================================================================================================================
//-------------------------------------------------------DEPARTMENT-------------------------------------------------------
//========================================================================================================================
void main_menu::Add_Department() //7
{
    system("cls");
    cout << "\n Enter Department id: ";
    cin.ignore();
    cin >> Department_id;
    cout << "\n Enter Department name: ";
    cin.ignore();
    cin.get(Department_name, 30);
    cout << "\n Enter Department Head: ";
    cin.ignore();
    cin.get(Department_head, 22);
}
void main_menu::show_departments() const {
    cout << "\n";
    cout << "\tDepartment ID: \t" << Department_id << endl;
    cout << "\tDepartment name: \t" << Department_name << endl;
    cout << "\tDepartment Head: \t" << Department_head << endl;
}
void store_department() {
    main_menu s_ac;
    ofstream outfile;
    outfile.open("Department.dat", ios::binary | ios::app);
    s_ac.Add_Department();
    outfile.write(reinterpret_cast<char*>(&s_ac), sizeof(main_menu));
    outfile.close();
}
void display_Department() {
    main_menu dis;
    ifstream infile;
    infile.open("Department.dat", ios::binary);
    if (!infile) {
        cout << "Could Not open File! Press any Key....";
        return;
    }
    cout << "\n";
    cout << setw(50) << "======================================" << endl;
    cout << setw(50) << "--          ALL DEPARTMENTS         --" << endl;
    cout << setw(50) << "======================================" << endl << endl;
    cout << "=======================================================================" << endl;
    cout << setw(15) << "DEPARTMENT ID" << setw(18) << "DEPARTMENT NAME" << setw(17) << "DEPARTMENT HEAD" << endl;
    while (infile.read(reinterpret_cast<char*>(&dis), sizeof(main_menu))) {
        dis.department_sequence();
    }
    infile.close();
    cout << "Press up/down arrow key to move to main menu..";
}
void Department_menu(int wr) {
    system("cls");
    int i = 0;
    cout << "\n   ==============================================" << endl;
    cout << "   [ \"----             DEPARTMENTS            ---\" ]";
    cout << "\n   ==============================================" << endl;
    char department[2][30] = { "\tADD NEW DEPARTMENT", "\tSHOW ALL DEPARTMENTS" };
    while (i < 2) {
        if (wr == i + 1) {
            cout << "\n   =>" << department[i];
        }
        else {
            cout << "\n " << department[i];
        }
        i++;
    }
    cout << "\n\nUse up down keys to move the cursor and\n SELECT Enter to select";
}
void mini_Departments() {
    char ch = ' ';
    int i = 1;
    Department_menu(13);

    while (1) {
        ch = _getch();
        switch (ch) {
        case 72:
            if (i != 1) {
                i--;
                Department_menu(i);
            }
            break;
        case 80:
            if (i != 2) {
                i++;
                Department_menu(i);
            }
            break;
        case 13:
            if (i == 1) {
                system("cls");
                store_department();
            }
            else if (i == 2) {
                system("cls");
                display_Department();
            }
            else {
                return;
                break;
            }
        }
    }
}
//======================================================================================================
//-------------------------------------------------LOAN-------------------------------------------------
//======================================================================================================
void main_menu::Add_new_loan() //8
{
    system("cls");
    cout << "\n Enter Account Number: ";
    cin.ignore();
    cin >> Account_Number;
    cout << "\n Enter Load id: ";
    cin.ignore();
    cin >> Loan_id;
    cout << "\n Enter Loan Type: ";
    cin.ignore();
    cin >> Loan_type;
    cout << "\n Enter the Interest rate: ";
    cin.ignore();
    cin >> Interest_rate;
    cout << "\n Enter the Duration of loan: ";
    cin.ignore();
    cin >> Duration;
    cout << "\n Enter the Date loan is issued (DD/MM/YYYY): ";
    cin.ignore();
    cin >> Start_date;
    cout << "\n Enter the loan Due ammount: ";
    cin.ignore();
    cin >> Due_amount;
}
void main_menu::Show_loans() const {
    cout << "\n";
    cout << "\tLoan ID: \t" << Loan_id << endl;
    cout << "\tLoan Type: \t" << Loan_type << endl;
    cout << "\tInterest Rate: \t" << Interest_rate << endl;
    cout << "\tDuration: \t" << Duration << endl;
    cout << "\tStart Date: \t" << Start_date << endl;
    cout << "\tDue Amount: \t" << Due_amount << endl;
    cout << "\tAccount Number: \t" << Account_Number << endl;
}
void store_loan() {
    main_menu s_ac;
    ofstream outfile;
    outfile.open("Loan.dat", ios::binary | ios::app);
    s_ac.Add_new_loan();
    outfile.write(reinterpret_cast<char*>(&s_ac), sizeof(main_menu));
    outfile.close();
}
void single_loan() {
    int n;
    main_menu mm;
    ifstream infile;
    infile.open("Loan.dat", ios::binary);
    if (!infile) {
        cout << "File not found!..(Press any Key)";
        return;
    }
    cout << "\n\t\t=================================";
    cout << "\n\t\t[        Single Loan Record      ";
    cout << "\n\t\t=================================";
    cout << "Enter Loan ID: ";
    cin >> n;
    while (infile.read(reinterpret_cast<char*>(&mm), sizeof(main_menu))) {
        if (mm.loan_id() == n) {
            mm.Show_loans();
        }
        else {
            cout << "There is no Such type of loan" << endl;
        }
    }
    infile.close();
    cout << "Press Enter Key to show another record or \n\tPress up/down key to return to main menu..." << endl;
}
void display_loan() {
    main_menu dis;
    ifstream infile;
    infile.open("Loan.dat", ios::binary);
    if (!infile) {
        cout << "Could Not open File! Press any Key....";
        return;
    }
    cout << "\n";
    cout << setw(50) << "======================================" << endl;
    cout << setw(50) << "--              ALL LOANS           --" << endl;
    cout << setw(50) << "======================================" << endl << endl;
    cout << "=======================================================================" << endl;
    cout << setw(15) << "ACCOUNT NUMBERS" << setw(15) << "LOAN ID" << setw(15) << "LOAN TYPE" << setw(15) << "INTEREST RATE" << setw(15) << "DURATION" << setw(15) << "START DATE" << setw(15) << "DUE AMOUNT" << endl;
    while (infile.read(reinterpret_cast<char*>(&dis), sizeof(main_menu))) {
        dis.loans_sequence();
    }
    infile.close();
    cout << "Press up/down arrow key to move to main menu..";
}

void Delete_Loan()
{
    int n;
    main_menu s_ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("Loan.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Templo.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    cout << "\n\t\t====================================";
    cout << "\n\t\t[        DELETE LOAN RECORD        ]";
    cout << "\n\t\t====================================" << endl;
    cout << "\n\tEnter Loan ID: ";
    cin >> n;
    while (inFile.read(reinterpret_cast<char*> (&s_ac), sizeof(main_menu)))
    {
        if (s_ac.loan_id() != n)
        {
            cout << "No Record Found" << endl;
        }
        else {
            inFile.close();
            outFile.close();
            remove("Loan.dat");
            rename("Templo.dat", "Loan.dat");
        }
    }
    cout << "\n\n....... Record DELETED Successfully.....";
}
void Loan_menu(int wr) {
    system("cls");
    int i = 0;
    cout << "\n   ==============================================" << endl;
    cout << "   [ \"----                LOANS               ---\" ]";
    cout << "\n   ==============================================" << endl;
    char loan[4][30] = { "\tADD NEW LOAN", "\tSHOW ALL LOANS", "\tSHOW SINGLE LOAN", "\tDELETE LOAN" };
    while (i < 4) {
        if (wr == i + 1) {
            cout << "\n   =>" << loan[i];
        }
        else {
            cout << "\n " << loan[i];
        }
        i++;
    }
    cout << "\n\nUse up down keys to move the cursor and\n SELECT Enter to select";
}
void mini_Loans() {
    char ch = ' ';
    int i = 1;
    Loan_menu(13);

    while (1) {
        ch = _getch();
        switch (ch) {
        case 72:
            if (i != 1) {
                i--;
                Loan_menu(i);
            }
            break;
        case 80:
            if (i != 4) {
                i++;
                Loan_menu(i);
            }
            break;
        case 13:
            if (i == 1) {
                system("cls");
                store_loan();
            }
            else if (i == 2) {
                system("cls");
                display_loan();
            }
            else if (i == 3) {
                system("cls");
                single_loan();
            }
            else if (i == 4) {
                system("cls");
                Delete_Loan();
            }
            else {
                return;
                break;
            }
        }
    }
}

//======================================================================================================================
//--------------------------------------MAIN MENU----------------------------------------------------------------------
//====================================================================================================================
void Mainmenu(int ch) {
    system("cls");
    int i = 0;
    cout << "\n      ==============================================" << endl;
    cout << "   [ \"          WELCOME to BANK MANAGEMENT SYSTEM            \" ]";
    cout << "\n      ==============================================" << endl;
    char m[7][30] = { "\tAccount Section","\tCustomer","\tBank Branch","\tEmployee","\tTransaction","\tDepartment","\tLoan" };
    while (i < 7) {
        if (ch == i + 1) {
            cout << "\n   =>" << m[i];
        }
        else {
            cout << "\n " << m[i];
        }
        i++;
    }
    cout << "\n\n   (Use up/down aerrow keys to move cursor and\n   Enter key to select an option)";

}
void minimain() {
    char ch = ' ';
    int i = 1;
    Mainmenu(13);

    while (1) {
        ch = _getch();
        switch (ch) {
        case 72:
            if (i != 1) {
                i--;
                Mainmenu(i);
            }
            break;
        case 80:
            if (i != 7) {
                i++;
                Mainmenu(i);
            }
            break;
        case 13:
            if (i == 1) {
                system("cls");
                mini_Accounts();
            }
            else if (i == 2) {
                system("cls");
                mini_Customers();
            }
            else if (i == 3) {
                system("cls");
                mini_Branch();
            }
            else if (i == 4) {
                system("cls");
                mini_Employees();
            }
            else if (i == 5) {
                system("cls");
                mini_dealings();
            }
            else if (i == 6) {
                system("cls");
                mini_Departments();
            }
            else if (i == 7) {
                system("cls");
                mini_Loans();
            }
            else
                return;
            break;
        }
    }
}

int main()
{
    system("Color D");
    loadingbar();
    minimain();
}