#include<iostream>
#include <sstream>
#include<ctime>
#include <cstring>
#include <conio.h> 
#include<chrono>
#include <string> 
#include <thread>
#include <windows.h>
#include <fstream>
#include <algorithm>
using namespace std;

int subtot = 0;

// for output color//
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// Animations code //
void slide_animation(string a) {
    int i, k;
    for (k = 0; k < 70; k++) {
        for (i = 0; i < k; i++) {
            cout << " ";

        }
        cout << a;
        Sleep(50);
        system("cls");
    }
    cout << "                                ";
}

void text_animation(string a) {
    int i;
    for (i = 0; a[i] != '\0'; i++) {
        Sleep(150);
        cout << a[i];
    }
}
/////////////////////////////////////////////////////////////////

//Cart Linked List//
struct Cart {
    double Bill;
    string Item;
    int Stock;
    Cart* next;
};
Cart* head10 = NULL;

void CartinsertEnd(string item, int stock, double bill) {

    Cart* newNode = new Cart();
    newNode->Item = item;
    newNode->Stock = stock;
    newNode->Bill = bill;
    newNode->next = NULL;

    if (head10 == NULL) {
        head10 = newNode;
    }
    else {
        Cart* temp = head10;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

}
void CartDisplay() {
    Cart* temp = head10;
    int co2 = 1;
    if (head10 == NULL) {
        cout << "Cart is Empty" << endl;
        return;
    }
    SetConsoleTextAttribute(h, 7);
    cout << "\t ------------------------------------------------- " << endl;
    cout << "\t    Name               Quantity          Price     " << endl;
    cout << "\t ------------------------------------------------- " << endl;

    while (temp) {
        cout << "\t" << co2 << ") " << temp->Item << "\t\t" << temp->Stock << "\t\t" << temp->Bill << "$";
        cout << endl;
        cout << "\t ------------------------------------------------- " << endl;
        temp = temp->next;
        co2++;
    }

}
int CartTotal() {
    Cart* temp = head10;
    if (head10 == NULL) {
        return 0;
    }
    int tot = 0;
    while (temp) {
        tot += temp->Bill;
        temp = temp->next;
    }
    return tot;
}


void CusDisplay() {

    system("cls");
    SetConsoleTextAttribute(h, 9);
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||           CUSTOMER HISTORY         ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    SetConsoleTextAttribute(h, 9);
    cout << "\t\t    Name               Ph#" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    SetConsoleTextAttribute(h, 7);

    ifstream hin("CustomerDetail.txt");
    string str1;
    if (hin.is_open()) {
        while (hin.good()) {
            getline(hin, str1);
            cout << "\t\t" << str1 << endl;
        }
    }
    SetConsoleTextAttribute(h, 9);
    cout << "\nPress any key to continue . . .";
    _getche();

}
/////////////////////////////////////////////////////////////////////////
//TOTAL EARNED///
void totearn()
{

    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    system("cls");
    SetConsoleTextAttribute(h, 9);
    cout << "\t\t ------------------------------------------- " << endl;
    cout << "\t\t||                                         ||" << endl;
    cout << "\t\t||              TOTAL EARNING              ||" << endl;
    cout << "\t\t||                                         ||" << endl;
    cout << "\t\t -------------------------------------------" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t    Date            Total Earning" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t" << systemTime.wDay << "/" << systemTime.wMonth << "/" << systemTime.wYear << "\t\t" << subtot << "$" << endl;
    ifstream hin("TotalEarnDetail.txt");
    string str2;
    if (hin.is_open())
    {
        while (hin.good()) {
            getline(hin, str2);
            cout << "\t\t" << str2 << endl;
        }
    }

}
/////////////////////////////////////
void ccolor(int color) {
    // Implement the ccolor function if not already defined
}

/////////////////////////////////////////////
//TOTAL EARNING BACKUP
void backup()
{
    system("cls");
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    for (int i = 1; i <= 100; i += 10) {
        system("cls");
        ccolor(26);
        SetConsoleTextAttribute(h, 2);
        std::cout << "\n\n\n\n\n\n\n\t\t\t\t" << i << " % Backing Up DATA...\n\n\t\t";

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    ofstream tot("TotalEarnDetail.txt", ios::app);
    tot << systemTime.wDay << "/" << systemTime.wMonth << "/" << systemTime.wYear << "\t\t" << subtot << "$" << endl;
}

//Queue Linked List//
struct Queue {
    string Name;
    string Phnum;
    string Paymentmethod;
    int Ordernum;
    Queue* next;
};
Queue* front = NULL;
Queue* rear = NULL;

void Enqueue(string name, string phnum, string payment, int order) {
    Queue* newNode = new Queue();
    newNode->Name = name;
    newNode->Phnum = phnum;
    newNode->Paymentmethod = payment;
    newNode->Ordernum = order;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void Dequeue() {
    Queue* temp = front;
    if (front == NULL) {
        cout << "Queue is Empty" << endl;
        cout << "\nPress any key to continue . . .";
        _getche();

        return;
    }
    system("cls");
    SetConsoleTextAttribute(h, 13);
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||           ORDER COMPLETED          ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "\n\tCustomer Name: " << front->Name;
    cout << "\n\tCustomer Phone Number: " << front->Phnum << endl;
    cout << "\tOrder Number: ORD-" << front->Ordernum << endl;
    cout << "\tPayment Method: " << front->Paymentmethod << endl;

    cout << "\n\tORDER DEQUEUED" << endl;
    _getche();
    if (front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }
    free(temp);

}
void DisplayQueue() {
    Queue* temp = front;
    int count = 1;
    system("cls");
    SetConsoleTextAttribute(h, 13);
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||            QUEUED ORDERS           ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    SetConsoleTextAttribute(h, 7);
    while (temp != NULL) {
        cout << "Queue: " << count << endl;
        cout << "\n\tCustomer Name: " << front->Name;
        cout << "\n\tCustomer Phone Number: " << front->Phnum << endl;
        cout << "\tOrder Number: ORD-" << front->Ordernum << endl;
        SetConsoleTextAttribute(h, 13);
        cout << "===========================================================================" << endl;
        count++;
        temp = temp->next;
    }
    cout << endl;
    SetConsoleTextAttribute(h, 13);
    cout << "\nPress any key to continue . . .";
    _getche();
}
//////////////////////////////////////////////////////////////

//Stack Linked list//
struct Stack {
    int data;
    Stack* next;
};
Stack* top = NULL;

void Push(int x) {
    Stack* newNode = new Stack();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}
int Top() {
    if (top == NULL) {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    cout << systemTime.wDay << "/" << systemTime.wMonth << "/" << systemTime.wYear;
    cout << "                                               ORD-" << top->data << endl;
    return top->data;
}
void Pop() {
    if (top == NULL) {
        cout << "Stack is Empty" << endl;
        return;
    }
    Stack* temp = top;
    top = top->next;
    free(temp);
}
//////////////////////////////////////////////////////////////////////////////////

//push unique random numbers in stack/////////
void pushUniqueRandomNumbers(int count) {
    srand(time(0));
    for (int i = 0; i < count; ++i) {
        int randomNumber = 10000000 + rand() % 90000000;
        Push(randomNumber);
    }
}
////////////////////////////////////////////////////////////////////////////

//fastfood linked list//
struct FASTfood
{
    int ID;
    string Item;
    double Price;
    int Stock;
    struct FASTfood* next;
};

struct FASTfood* head = NULL;

void FSort() {
    FASTfood* temp1;
    FASTfood* temp2;
    int temp = 0;
    for (temp1 = head; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->ID > temp2->ID) {
                temp = temp1->ID;
                temp1->ID = temp2->ID;
                temp2->ID = temp;
            }
        }
    }
}
void FinsertEnd() {
    int id, stock;
    string item;
    double price;
    FASTfood* newNode = new FASTfood();

    cout << "Enter Product ID:-";
    cin >> id;
    newNode->ID = id;
    cout << "Enter Product Name:-";
    cin >> item;
    newNode->Item = item;
    cout << "Enter Price:-";
    cin >> price;
    newNode->Price = price;
    cout << "Enter Stock:-";
    cin >> stock;
    newNode->Stock = stock;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        FASTfood* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    FSort();

}
int Fsearch(int n)
{
    int count = 1;
    FASTfood* temp = head;
    while (temp) {
        if (temp->ID == n)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }
    SetConsoleTextAttribute(h, 9);
    cout << "ID Not Found." << endl;
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;
}
string Fcheck(int s) {
    int stockCheck = s;
    stringstream ss;
    ss << stockCheck;
    string stock = ss.str();

    if (s <= 0) {
        SetConsoleTextAttribute(h, 9);
        return "Out Of Stock!";
    }
    else {
        return stock;
    }
}
int Fdisplay()
{
    system("cls");
    int count = 0;
    struct FASTfood* temp = head;

    SetConsoleTextAttribute(h, 9);
    cout << "Existing products are:\n";
    cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    SetConsoleTextAttribute(h, 9);
    cout << "=================================================================|\n";

    SetConsoleTextAttribute(h, 7);
    while (temp != NULL) {
        cout << temp->ID << "\t\t" << temp->Item << "\t\t\t" << temp->Price << "$" << "\t\t\t" << Fcheck(temp->Stock) << "\n";
        temp = temp->next;
        count++;
    }
    SetConsoleTextAttribute(h, 9);
    cout << "\nTotal products in our store is : " << count << "\n\n\n";
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;

}
void FDeletefromNthPos() {
    FASTfood* temp = head;
    FASTfood* oldTemp = temp;
    int count, id;


    if (head == NULL) {
        SetConsoleTextAttribute(h, 9);
        cout << "No Products Found." << endl;
        cout << "\nPress any key to continue . . .";
        _getche();
        return;
    }

    int count1 = Fdisplay();
    SetConsoleTextAttribute(h, 9);
    cout << "\nEnter Product ID: " << endl;
    cin >> id;
    int pos = Fsearch(id);

    if (pos <= count1) {
        if (pos == 1) {
            FASTfood* temp = head;
            head = temp->next;

            free(temp);
            return;
        }

        for (int i = 1; i < pos; i++) {
            oldTemp = temp;
            temp = temp->next;

        }
        oldTemp->next = temp->next;
        free(temp);
    }
}
void Fmodify() {
    system("cls");
    SetConsoleTextAttribute(h, 9);
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||               MODIFY               ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    int id, stock;
    double price;
    string item;
    int nid; int nq;
    if (head == NULL) {
        system("cls");
        SetConsoleTextAttribute(h, 9);
        cout << "No Products Found." << endl;
        cout << "\n\nPress any key to return to Main Menu . . .";
        _getche();
    }
    else {
        int count = Fdisplay();
        cout << "\n\nEnter ID To Modify Product:\n";
        cin >> id;
        struct FASTfood* temp = head;
        int pos = 0;
        pos = Fsearch(id);
        if (pos <= count) {
            while (temp->ID != id)
            {
                temp = temp->next;
            }
            int choice = 0;
            while (choice != 5) {
                system("cls");
                SetConsoleTextAttribute(h, 9);
                cout << "\nCurrent ID : " << temp->ID << endl;
                cout << "Current Product Name : " << temp->Item << endl;
                cout << "Current Price : " << temp->Price << endl;
                cout << "Current stock : " << temp->Stock << endl;

                SetConsoleTextAttribute(h, 7);
                cout << "\n\n\t\t    1) Modify ID" << endl;
                cout << "\t\t    2) Modify Product Name" << endl;
                cout << "\t\t    3) Modify Price" << endl;
                cout << "\t\t    4) Modify Stock" << endl;
                cout << "\t\t    5) Back" << endl;

                cout << "\nEnter Your Choice: ";
                cin >> choice;

                SetConsoleTextAttribute(h, 7);
                switch (choice) {
                case 1:
                    cout << "Enter new ID:" << endl;
                    cin >> id;
                    temp->ID = id;
                    break;

                case 2:
                    cout << "Enter new Product Name:" << endl;
                    cin >> item;
                    temp->Item = item;
                    break;

                case 3:
                    cout << "Enter new Price:" << endl;
                    cin >> price;
                    temp->Price = price;
                    break;

                case 4:
                    cout << "Enter new Stock:" << endl;
                    cin >> stock;
                    temp->Stock = stock;
                    break;
                }
            }
        }
        else {
            SetConsoleTextAttribute(h, 9);
            cout << id << " Not found\n\n";
            cout << "\nPress any key to continue . . .";
            _getche();
        }
    }
}
void Fbuy() {
    system("cls");
    int count10 = Fdisplay();
    int bill = 0, price;

    if (head == NULL) {
        SetConsoleTextAttribute(h, 9);
        cout << "\nNothing is Available at the moment\n\n";
        cout << "Press any key tou continue . . .";
        _getche();
    }
    else {
        struct FASTfood* cur = head;
        int stock, id;
    A:
        SetConsoleTextAttribute(h, 9);
        cout << "Enter ID of item that you want to buy: ";
        cin >> id;
        if (id == -1) {
            system("cls");
            return;
        }
        int pos = Fsearch(id);
        if (pos <= count10)
        {
            while (cur->ID != id)
            {
                cur = cur->next;
            }
            cout << "How much do you want:";
            cin >> stock;
            if (cur->Stock < stock)
            {
                SetConsoleTextAttribute(h, 9);
                cout << "\n\n\t\t\tThe Quantity You Want Is Not Available right now . . ." << endl;
                cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
                goto A;

            }


            bill = bill + (cur->Price * stock);
            cur->Stock = cur->Stock - stock;
            CartinsertEnd(cur->Item, stock, bill);


        }
        else {

            SetConsoleTextAttribute(h, 9);
            cout << "\nID doesnt Exist\n\n";
        }

    }
}
/////////////////////////////////////////////////////////////////////////////
//Mexican cuisines linked list//
struct MEXICANfood
{
    int ID;
    string Item;
    double Price;
    int Stock;
    struct MEXICANfood* next;
};

struct MEXICANfood* head1 = NULL;

void MSort() {
    MEXICANfood* temp1;
    MEXICANfood* temp2;
    int temp = 0;
    for (temp1 = head1; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->ID > temp2->ID) {
                temp = temp1->ID;
                temp1->ID = temp2->ID;
                temp2->ID = temp;
            }
        }
    }
}
void MinsertEnd() {
    int id, stock;
    string item;
    double price;
    MEXICANfood* newNode = new MEXICANfood();

    SetConsoleTextAttribute(h, 7);
    cout << "Enter Product ID:-";
    cin >> id;
    newNode->ID = id;
    cout << "Enter Product Name:-";
    cin >> item;
    newNode->Item = item;
    cout << "Enter Price:-";
    cin >> price;
    newNode->Price = price;
    cout << "Enter Stock:-";
    cin >> stock;
    newNode->Stock = stock;
    newNode->next = NULL;

    if (head1 == NULL) {
        head1 = newNode;
    }
    else {
        MEXICANfood* temp = head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    MSort();

}
int Msearch(int n)
{
    int count = 1;
    MEXICANfood* temp = head1;
    while (temp) {
        if (temp->ID == n)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }

    SetConsoleTextAttribute(h, 9);
    cout << "ID Not Found." << endl;
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;
}
string Mcheck(int s) {
    int stockCheck = s;
    stringstream ss;
    ss << stockCheck;
    string stock = ss.str();

    if (s <= 0) {

        SetConsoleTextAttribute(h, 9);
        return "Out Of Stock!";
    }
    else {
        return stock;
    }
}
int Mdisplay()
{
    system("cls");
    int count = 0;
    struct MEXICANfood* temp = head1;
    cout << "Existing products are:\n";
    cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";

    SetConsoleTextAttribute(h, 9);
    cout << "=================================================================|\n";
    while (temp != NULL) {
        SetConsoleTextAttribute(h, 7);
        cout << temp->ID << "\t\t" << temp->Item << "\t\t\t" << temp->Price << "$" << "\t\t\t" << Mcheck(temp->Stock) << "\n";
        temp = temp->next;
        count++;
    }

    SetConsoleTextAttribute(h, 9);
    cout << "\nTotal products in our store is : " << count << "\n\n\n";
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;

}
void MDeletefromNthPos() {
    MEXICANfood* temp = head1;
    MEXICANfood* oldTemp = temp;
    int count, id;


    if (head1 == NULL) {
        SetConsoleTextAttribute(h, 9);
        cout << "No Products Found." << endl;
        cout << "\nPress any key to continue . . .";
        _getche();
        return;
    }

    int count1 = Mdisplay();
    SetConsoleTextAttribute(h, 9);
    cout << "\nEnter Product ID: " << endl;
    cin >> id;
    int pos = Msearch(id);

    if (pos <= count1) {
        if (pos == 1) {
            MEXICANfood* temp = head1;
            head1 = temp->next;

            free(temp);
            return;
        }

        for (int i = 1; i < pos; i++) {
            oldTemp = temp;
            temp = temp->next;

        }
        oldTemp->next = temp->next;
        free(temp);
    }
}
void Mmodify() {
    system("cls");
    SetConsoleTextAttribute(h, 9);
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||               MODIFY               ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    int id, stock;
    double price;
    string item;
    int nid; int nq;
    if (head1 == NULL) {
        system("cls");
        SetConsoleTextAttribute(h, 9);
        cout << "No Products Found." << endl;
        cout << "\n\nPress any key to return to Main Menu . . .";
        _getche();
    }
    else {
        int count = Mdisplay();
        cout << "\n\nEnter ID To Modify Product:\n";
        cin >> id;
        struct MEXICANfood* temp = head1;
        int pos = 0;
        pos = Msearch(id);
        if (pos <= count) {
            while (temp->ID != id)
            {
                temp = temp->next;
            }
            int choice = 0;
            while (choice != 5) {
                system("cls");
                SetConsoleTextAttribute(h, 9);
                cout << "\nCurrent ID : " << temp->ID << endl;
                cout << "Current Product Name : " << temp->Item << endl;
                cout << "Current Price : " << temp->Price << endl;
                cout << "Current stock : " << temp->Stock << endl;
                SetConsoleTextAttribute(h, 7);
                cout << "\n\n\t\t    1) Modify ID" << endl;
                cout << "\t\t    2) Modify Product Name" << endl;
                cout << "\t\t    3) Modify Price" << endl;
                cout << "\t\t    4) Modify Stock" << endl;
                cout << "\t\t    5) Back" << endl;

                cout << "\nEnter Your Choice: ";
                cin >> choice;
                SetConsoleTextAttribute(h, 7);
                switch (choice) {
                case 1:
                    cout << "Enter new ID:" << endl;
                    cin >> id;
                    temp->ID = id;
                    break;

                case 2:
                    cout << "Enter new Product Name:" << endl;
                    cin >> item;
                    temp->Item = item;
                    break;

                case 3:
                    cout << "Enter new Price:" << endl;
                    cin >> price;
                    temp->Price = price;
                    break;

                case 4:
                    cout << "Enter new Stock:" << endl;
                    cin >> stock;
                    temp->Stock = stock;
                    break;
                }
            }
        }
        else {
            SetConsoleTextAttribute(h, 9);
            cout << id << " Not found\n\n";
            cout << "\nPress any key to continue . . .";
            _getche();
        }
    }
}
void Mbuy() {
    system("cls");
    int count10 = Mdisplay();
    int bill = 0, price;

    if (head == NULL) {
        SetConsoleTextAttribute(h, 9);
        cout << "\nNothing is Available at the moment\n\n";
        cout << "Press any key tou continue . . .";
        _getche();
    }
    else {
        struct MEXICANfood* cur = head1;
        int stock, id;
    A:
        SetConsoleTextAttribute(h, 9);
        cout << "Enter ID of item that you want to buy: ";
        cin >> id;
        if (id == -1) {
            system("cls");
            return;
        }
        int pos = Msearch(id);
        if (pos <= count10)
        {
            while (cur->ID != id)
            {
                cur = cur->next;
            }
            cout << "How much do you want:";
            cin >> stock;
            if (cur->Stock < stock)
            {
                SetConsoleTextAttribute(h, 9);
                cout << "\n\n\t\t\tThe Quantity You Want Is Not Available right now . . ." << endl;
                cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
                goto A;

            }


            bill = bill + (cur->Price * stock);
            cur->Stock = cur->Stock - stock;
            CartinsertEnd(cur->Item, stock, bill);


        }
        else {
            SetConsoleTextAttribute(h, 9);
            cout << "\nID doesnt Exist\n\n";
        }

    }
}
/////////////////////////////////////////////////////////////////////////////
//Italian cuisines linked list//
struct ITALIANfood
{
    int ID;
    string Item;
    double Price;
    int Stock;
    struct ITALIANfood* next;
};

struct ITALIANfood* head2 = NULL;

void ISort() {
    ITALIANfood* temp1;
    ITALIANfood* temp2;
    int temp = 0;
    for (temp1 = head2; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->ID > temp2->ID) {
                temp = temp1->ID;
                temp1->ID = temp2->ID;
                temp2->ID = temp;
            }
        }
    }
}
void IinsertEnd() {
    int id, stock;
    string item;
    double price;
    ITALIANfood* newNode = new ITALIANfood();
    SetConsoleTextAttribute(h, 7);
    cout << "Enter Product ID:-";
    cin >> id;
    newNode->ID = id;
    cout << "Enter Product Name:-";
    cin >> item;
    newNode->Item = item;
    cout << "Enter Price:-";
    cin >> price;
    newNode->Price = price;
    cout << "Enter Stock:-";
    cin >> stock;
    newNode->Stock = stock;
    newNode->next = NULL;

    if (head2 == NULL) {
        head2 = newNode;
    }
    else {
        ITALIANfood* temp = head2;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    ISort();

}
int Isearch(int n)
{
    int count = 1;
    ITALIANfood* temp = head2;
    while (temp) {
        if (temp->ID == n)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }
    SetConsoleTextAttribute(h, 9);
    cout << "ID Not Found." << endl;
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;
}
string Icheck(int s) {
    int stockCheck = s;
    stringstream ss;
    ss << stockCheck;
    string stock = ss.str();

    if (s <= 0) {
        SetConsoleTextAttribute(h, 9);
        return "Out Of Stock!";
    }
    else {
        return stock;
    }
}
int Idisplay()
{
    system("cls");
    int count = 0;
    struct ITALIANfood* temp = head2;
    cout << "Existing products are:\n";
    cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    SetConsoleTextAttribute(h, 9);
    cout << "=================================================================|\n";
    while (temp != NULL) {
        SetConsoleTextAttribute(h, 7);
        cout << temp->ID << "\t\t" << temp->Item << "\t\t\t" << temp->Price << "$" << "\t\t\t" << Icheck(temp->Stock) << "\n";
        temp = temp->next;
        count++;
    }
    SetConsoleTextAttribute(h, 9);
    cout << "\nTotal products in our store is : " << count << "\n\n\n";
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;

}
void IDeletefromNthPos() {
    ITALIANfood* temp = head2;
    ITALIANfood* oldTemp = temp;
    int count, id;


    if (head2 == NULL) {
        SetConsoleTextAttribute(h, 9);
        cout << "No Products Found." << endl;
        cout << "\nPress any key to continue . . .";
        _getche();
        return;
    }

    int count1 = Idisplay();
    SetConsoleTextAttribute(h, 9);
    cout << "\nEnter Product ID: " << endl;
    cin >> id;
    int pos = Isearch(id);

    if (pos <= count1) {
        if (pos == 1) {
            ITALIANfood* temp = head2;
            head2 = temp->next;

            free(temp);
            return;
        }

        for (int i = 1; i < pos; i++) {
            oldTemp = temp;
            temp = temp->next;

        }
        oldTemp->next = temp->next;
        free(temp);
    }
}
void Imodify() {
    system("cls");
    SetConsoleTextAttribute(h, 9);
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||               MODIFY               ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    int id, stock;
    double price;
    string item;
    int nid; int nq;
    if (head2 == NULL) {
        system("cls");
        SetConsoleTextAttribute(h, 9);
        cout << "No Products Found." << endl;
        cout << "\n\nPress any key to return to Main Menu . . .";
        _getche();
    }
    else {
        int count = Idisplay();
        cout << "\n\nEnter ID To Modify Product:\n";
        cin >> id;
        struct ITALIANfood* temp = head2;
        int pos = 0;
        pos = Isearch(id);
        if (pos <= count) {
            while (temp->ID != id)
            {
                temp = temp->next;
            }
            int choice = 0;
            SetConsoleTextAttribute(h, 9);
            while (choice != 5) {
                system("cls");
                cout << "\nCurrent ID : " << temp->ID << endl;
                cout << "Current Product Name : " << temp->Item << endl;
                cout << "Current Price : " << temp->Price << endl;
                cout << "Current stock : " << temp->Stock << endl;
                SetConsoleTextAttribute(h, 7);
                cout << "\n\n\t\t    1) Modify ID" << endl;
                cout << "\t\t    2) Modify Product Name" << endl;
                cout << "\t\t    3) Modify Price" << endl;
                cout << "\t\t    4) Modify Stock" << endl;
                cout << "\t\t    5) Back" << endl;

                SetConsoleTextAttribute(h, 9);
                cout << "\nEnter Your Choice: ";
                cin >> choice;
                SetConsoleTextAttribute(h, 7);
                switch (choice) {
                case 1:
                    cout << "Enter new ID:" << endl;
                    cin >> id;
                    temp->ID = id;
                    break;

                case 2:
                    cout << "Enter new Product Name:" << endl;
                    cin >> item;
                    temp->Item = item;
                    break;

                case 3:
                    cout << "Enter new Price:" << endl;
                    cin >> price;
                    temp->Price = price;
                    break;

                case 4:
                    cout << "Enter new Stock:" << endl;
                    cin >> stock;
                    temp->Stock = stock;
                    break;
                }
            }
        }
        else {
            SetConsoleTextAttribute(h, 9);
            cout << id << " Not found\n\n";
            cout << "\nPress any key to continue . . .";
            _getche();
        }
    }
}
void Ibuy() {
    system("cls");
    int count10 = Idisplay();
    int bill = 0, price;

    if (head == NULL) {
        SetConsoleTextAttribute(h, 9);
        cout << "\nNothing is Available at the moment\n\n";
        cout << "Press any key tou continue . . .";
        _getche();
    }
    else {
        struct ITALIANfood* cur = head2;
        int stock, id;
    A:
        SetConsoleTextAttribute(h, 9);
        cout << "Enter ID of item that you want to buy: ";
        cin >> id;
        if (id == -1) {
            system("cls");
            return;
        }
        int pos = Isearch(id);
        if (pos <= count10)
        {
            while (cur->ID != id)
            {
                cur = cur->next;
            }
            cout << "How much do you want:";
            cin >> stock;
            if (cur->Stock < stock)
            {
                SetConsoleTextAttribute(h, 9);
                cout << "\n\n\t\t\tThe Quantity You Want Is Not Available right now . . ." << endl;
                cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
                goto A;

            }


            bill = bill + (cur->Price * stock);
            cur->Stock = cur->Stock - stock;
            CartinsertEnd(cur->Item, stock, bill);
        }
        else {
            cout << "\nID doesnt Exist\n\n";
        }

    }
}
/////////////////////////////////////////////////////////////////////////////
//BBQ linked list//
struct BBQ
{
    int ID;
    string Item;
    double Price;
    int Stock;
    struct BBQ* next;
};

struct BBQ* head3 = NULL;

void BSort() {
    BBQ* temp1;
    BBQ* temp2;
    int temp = 0;
    for (temp1 = head3; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->ID > temp2->ID) {
                temp = temp1->ID;
                temp1->ID = temp2->ID;
                temp2->ID = temp;
            }
        }
    }
}
void BinsertEnd() {
    int id, stock;
    string item;
    double price;
    BBQ* newNode = new BBQ();
    SetConsoleTextAttribute(h, 7);
    cout << "Enter Product ID:-";
    cin >> id;
    newNode->ID = id;
    cout << "Enter Product Name:-";
    cin >> item;
    newNode->Item = item;
    cout << "Enter Price:-";
    cin >> price;
    newNode->Price = price;
    cout << "Enter Stock:-";
    cin >> stock;
    newNode->Stock = stock;
    newNode->next = NULL;

    if (head3 == NULL) {
        head3 = newNode;
    }
    else {
        BBQ* temp = head3;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    BSort();

}
int Bsearch(int n)
{
    int count = 1;
    BBQ* temp = head3;
    while (temp) {
        if (temp->ID == n)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }
    SetConsoleTextAttribute(h, 9);
    cout << "ID Not Found." << endl;
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;
}
string Bcheck(int s) {
    int stockCheck = s;
    stringstream ss;
    ss << stockCheck;
    string stock = ss.str();

    if (s <= 0) {
        return "Out Of Stock!";
    }
    else {
        return stock;
    }
}
int Bdisplay()
{
    system("cls");
    int count = 0;
    struct BBQ* temp = head3;
    cout << "Existing products are:\n";
    cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    SetConsoleTextAttribute(h, 9);
    cout << "=================================================================|\n";
    while (temp != NULL) {
        SetConsoleTextAttribute(h, 7);
        cout << temp->ID << "\t\t" << temp->Item << "\t\t\t" << temp->Price << "$" << "\t\t\t" << Bcheck(temp->Stock) << "\n";
        temp = temp->next;
        count++;
    }
    SetConsoleTextAttribute(h, 9);
    cout << "\nTotal products in our store is : " << count << "\n\n\n";
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;

}
void BDeletefromNthPos() {
    BBQ* temp = head3;
    BBQ* oldTemp = temp;
    int count, id;


    if (head3 == NULL) {
        SetConsoleTextAttribute(h, 9);
        cout << "No Products Found." << endl;
        cout << "\nPress any key to continue . . .";
        _getche();
        return;
    }

    int count1 = Bdisplay();
    SetConsoleTextAttribute(h, 9);
    cout << "\nEnter Product ID: " << endl;
    cin >> id;
    int pos = Bsearch(id);

    if (pos <= count1) {
        if (pos == 1) {
            BBQ* temp = head3;
            head3 = temp->next;

            free(temp);
            return;
        }

        for (int i = 1; i < pos; i++) {
            oldTemp = temp;
            temp = temp->next;

        }
        oldTemp->next = temp->next;
        free(temp);
    }
}
void Bmodify() {
    system("cls");
    SetConsoleTextAttribute(h, 9);
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||               MODIFY               ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    int id, stock;
    double price;
    string item;
    int nid; int nq;
    if (head3 == NULL) {
        system("cls");
        SetConsoleTextAttribute(h, 9);
        cout << "No Products Found." << endl;
        cout << "\n\nPress any key to return to Main Menu . . .";
        _getche();
    }
    else {
        int count = Bdisplay();
        SetConsoleTextAttribute(h, 9);
        cout << "\n\nEnter ID To Modify Product:\n";
        cin >> id;
        struct BBQ* temp = head3;
        int pos = 0;
        pos = Bsearch(id);
        if (pos <= count) {
            while (temp->ID != id)
            {
                temp = temp->next;
            }
            int choice = 0;
            SetConsoleTextAttribute(h, 9);
            while (choice != 5) {
                system("cls");
                cout << "\nCurrent ID : " << temp->ID << endl;
                cout << "Current Product Name : " << temp->Item << endl;
                cout << "Current Price : " << temp->Price << endl;
                cout << "Current stock : " << temp->Stock << endl;

                SetConsoleTextAttribute(h, 7);
                cout << "\n\n\t\t    1) Modify ID" << endl;
                cout << "\t\t    2) Modify Product Name" << endl;
                cout << "\t\t    3) Modify Price" << endl;
                cout << "\t\t    4) Modify Stock" << endl;
                cout << "\t\t    5) Back" << endl;

                SetConsoleTextAttribute(h, 7);
                cout << "\nEnter Your Choice: ";
                cin >> choice;
                SetConsoleTextAttribute(h, 7);
                switch (choice) {
                case 1:
                    cout << "Enter new ID:" << endl;
                    cin >> id;
                    temp->ID = id;
                    break;

                case 2:
                    cout << "Enter new Product Name:" << endl;
                    cin >> item;
                    temp->Item = item;
                    break;

                case 3:
                    cout << "Enter new Price:" << endl;
                    cin >> price;
                    temp->Price = price;
                    break;

                case 4:
                    cout << "Enter new Stock:" << endl;
                    cin >> stock;
                    temp->Stock = stock;
                    break;
                }
            }
        }
        else {
            SetConsoleTextAttribute(h, 9);
            cout << id << " Not found\n\n";
            cout << "\nPress any key to continue . . .";
            _getche();
        }
    }
}
void Bbuy() {
    system("cls");
    int count10 = Bdisplay();
    int bill = 0, price;

    if (head == NULL) {
        SetConsoleTextAttribute(h, 9);
        cout << "\nNothing is Available at the moment\n\n";
        cout << "Press any key tou continue . . .";
        _getche();
    }
    else {
        struct BBQ* cur = head3;
        int stock, id;
    A:
        SetConsoleTextAttribute(h, 9);
        cout << "Enter ID of item that you want to buy: ";
        cin >> id;
        if (id == -1) {
            system("cls");
            return;
        }
        int pos = Bsearch(id);
        if (pos <= count10)
        {
            while (cur->ID != id)
            {
                cur = cur->next;
            }
            cout << "How much do you want:";
            cin >> stock;
            if (cur->Stock < stock)
            {
                SetConsoleTextAttribute(h, 9);
                cout << "\n\n\t\t\tThe Quantity You Want Is Not Available right now . . ." << endl;
                cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
                goto A;

            }


            bill = bill + (cur->Price * stock);
            cur->Stock = cur->Stock - stock;
            CartinsertEnd(cur->Item, stock, bill);


        }
        else {
            SetConsoleTextAttribute(h, 9);
            cout << "\nID doesnt Exist\n\n";
        }

    }
}
/////////////////////////////////////////////////////////////////////////////
//Brunch linked list//
struct BRUNCHFOOD
{
    int ID;
    string Item;
    double Price;
    int Stock;
    struct BRUNCHFOOD* next;
};

struct BRUNCHFOOD* head4 = NULL;

void BrSort() {
    BRUNCHFOOD* temp1;
    BRUNCHFOOD* temp2;
    int temp = 0;
    for (temp1 = head4; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->ID > temp2->ID) {
                temp = temp1->ID;
                temp1->ID = temp2->ID;
                temp2->ID = temp;
            }
        }
    }
}
void BrinsertEnd() {
    int id, stock;
    string item;
    double price;
    BRUNCHFOOD* newNode = new BRUNCHFOOD();

    cout << "Enter Product ID:-";
    cin >> id;
    newNode->ID = id;
    cout << "Enter Product Name:-";
    cin >> item;
    newNode->Item = item;
    cout << "Enter Price:-";
    cin >> price;
    newNode->Price = price;
    cout << "Enter Stock:-";
    cin >> stock;
    newNode->Stock = stock;
    newNode->next = NULL;

    if (head4 == NULL) {
        head4 = newNode;
    }
    else {
        BRUNCHFOOD* temp = head4;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    BrSort();

}
int Brsearch(int n)
{
    int count = 1;
    BRUNCHFOOD* temp = head4;
    while (temp) {
        if (temp->ID == n)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }
    cout << "ID Not Found." << endl;
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;
}
string Brcheck(int s) {
    int stockCheck = s;
    stringstream ss;
    ss << stockCheck;
    string stock = ss.str();

    if (s <= 0) {
        return "Out Of Stock!";
    }
    else {
        return stock;
    }
}
int Brdisplay()
{
    system("cls");
    int count = 0;
    struct BRUNCHFOOD* temp = head4;
    SetConsoleTextAttribute(h, 9);

    cout << "Existing products are:\n";
    cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";

    cout << "=================================================================|\n";
    while (temp != NULL) {
        SetConsoleTextAttribute(h, 7);

        cout << temp->ID << "\t\t" << temp->Item << "\t\t\t" << temp->Price << "$" << "\t\t\t" << Brcheck(temp->Stock) << "\n";
        temp = temp->next;
        count++;
    }

    SetConsoleTextAttribute(h, 9);
    cout << "\nTotal products in our store is : " << count << "\n\n\n";
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;

}
void BrDeletefromNthPos() {
    BRUNCHFOOD* temp = head4;
    BRUNCHFOOD* oldTemp = temp;
    int count, id;


    if (head4 == NULL) {
        cout << "No Products Found." << endl;
        cout << "\nPress any key to continue . . .";
        _getche();
        return;
    }

    int count1 = Brdisplay();
    cout << "\nEnter Product ID: " << endl;
    cin >> id;
    int pos = Brsearch(id);

    if (pos <= count1) {
        if (pos == 1) {
            BRUNCHFOOD* temp = head4;
            head4 = temp->next;

            free(temp);
            return;
        }

        for (int i = 1; i < pos; i++) {
            oldTemp = temp;
            temp = temp->next;

        }
        oldTemp->next = temp->next;
        free(temp);
    }
}
void Brmodify() {
    system("cls");
    SetConsoleTextAttribute(h, 13);
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||               MODIFY               ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    int id, stock;
    double price;
    string item;
    int nid; int nq;
    if (head4 == NULL) {
        system("cls");
        cout << "No Products Found." << endl;
        cout << "\n\nPress any key to return to Main Menu . . .";
        _getche();
    }
    else {
        int count = Brdisplay();
        cout << "\n\nEnter ID To Modify Product:\n";
        cin >> id;
        struct BRUNCHFOOD* temp = head4;
        int pos = 0;
        pos = Brsearch(id);
        if (pos <= count) {
            while (temp->ID != id)
            {
                temp = temp->next;
            }
            int choice = 0;
            while (choice != 5) {
                system("cls");
                cout << "\nCurrent ID : " << temp->ID << endl;
                cout << "Current Product Name : " << temp->Item << endl;
                cout << "Current Price : " << temp->Price << endl;
                cout << "Current stock : " << temp->Stock << endl;

                cout << "\n\n\t\t    1) Modify ID" << endl;
                cout << "\t\t    2) Modify Product Name" << endl;
                cout << "\t\t    3) Modify Price" << endl;
                cout << "\t\t    4) Modify Stock" << endl;
                cout << "\t\t    5) Back" << endl;

                cout << "\nEnter Your Choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << "Enter new ID:" << endl;
                    cin >> id;
                    temp->ID = id;
                    break;

                case 2:
                    cout << "Enter new Product Name:" << endl;
                    cin >> item;
                    temp->Item = item;
                    break;

                case 3:
                    cout << "Enter new Price:" << endl;
                    cin >> price;
                    temp->Price = price;
                    break;

                case 4:
                    cout << "Enter new Stock:" << endl;
                    cin >> stock;
                    temp->Stock = stock;
                    break;
                }
            }
        }
        else {
            cout << id << " Not found\n\n";
            cout << "\nPress any key to continue . . .";
            _getche();
        }
    }
}
void Brbuy() {
    system("cls");
    int count10 = Brdisplay();
    int bill = 0, price;

    if (head == NULL) {
        cout << "\nNothing is Available at the moment\n\n";
        cout << "Press any key tou continue . . .";
        _getche();
    }
    else {
        struct BRUNCHFOOD* cur = head4;
        int stock, id;
    A:
        cout << "Enter ID of item that you want to buy: ";
        cin >> id;
        if (id == -1) {
            system("cls");
            return;
        }
        int pos = Brsearch(id);
        if (pos <= count10)
        {
            while (cur->ID != id)
            {
                cur = cur->next;
            }
            cout << "How much do you want:";
            cin >> stock;
            if (cur->Stock < stock)
            {
                cout << "\n\n\t\t\tThe Quantity You Want Is Not Available right now . . ." << endl;
                cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
                goto A;

            }


            bill = bill + (cur->Price * stock);
            cur->Stock = cur->Stock - stock;
            CartinsertEnd(cur->Item, stock, bill);


        }
        else {
            cout << "\nID doesnt Exist\n\n";
        }

    }
}
/////////////////////////////////////////////////////////////////////////////
//Vegan linked list//
struct VEGANfood
{
    int ID;
    string Item;
    double Price;
    int Stock;
    struct VEGANfood* next;
};

struct VEGANfood* head5 = NULL;

void VSort() {
    VEGANfood* temp1;
    VEGANfood* temp2;
    int temp = 0;
    for (temp1 = head5; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->ID > temp2->ID) {
                temp = temp1->ID;
                temp1->ID = temp2->ID;
                temp2->ID = temp;
            }
        }
    }
}
void VinsertEnd() {
    int id, stock;
    string item;
    double price;
    VEGANfood* newNode = new VEGANfood();

    cout << "Enter Product ID:-";
    cin >> id;
    newNode->ID = id;
    cout << "Enter Product Name:-";
    cin >> item;
    newNode->Item = item;
    cout << "Enter Price:-";
    cin >> price;
    newNode->Price = price;
    cout << "Enter Stock:-";
    cin >> stock;
    newNode->Stock = stock;
    newNode->next = NULL;

    if (head5 == NULL) {
        head5 = newNode;
    }
    else {
        VEGANfood* temp = head5;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    VSort();

}
int Vsearch(int n)
{
    int count = 1;
    VEGANfood* temp = head5;
    while (temp) {
        if (temp->ID == n)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }
    cout << "ID Not Found." << endl;
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;
}
string Vcheck(int s) {
    int stockCheck = s;
    stringstream ss;
    ss << stockCheck;
    string stock = ss.str();

    if (s <= 0) {
        return "Out Of Stock!";
    }
    else {
        return stock;
    }
}
int Vdisplay()
{
    system("cls");
    int count = 0;
    struct VEGANfood* temp = head5;
    SetConsoleTextAttribute(h, 9);
    cout << "Existing products are:\n";
    cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    cout << "=================================================================|\n";
    while (temp != NULL) {
        SetConsoleTextAttribute(h, 7);
        cout << temp->ID << "\t\t" << temp->Item << "\t\t\t" << temp->Price << "$" << "\t\t\t" << Vcheck(temp->Stock) << "\n";
        temp = temp->next;
        count++;
    }
    SetConsoleTextAttribute(h, 9);
    cout << "\nTotal products in our store is : " << count << "\n\n\n";
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;

}
void VDeletefromNthPos() {
    VEGANfood* temp = head5;
    VEGANfood* oldTemp = temp;
    int count, id;


    if (head5 == NULL) {
        cout << "No Products Found." << endl;
        cout << "\nPress any key to continue . . .";
        _getche();
        return;
    }

    int count1 = Vdisplay();
    cout << "\nEnter Product ID: " << endl;
    cin >> id;
    int pos = Vsearch(id);

    if (pos <= count1) {
        if (pos == 1) {
            VEGANfood* temp = head5;
            head5 = temp->next;

            free(temp);
            return;
        }

        for (int i = 1; i < pos; i++) {
            oldTemp = temp;
            temp = temp->next;

        }
        oldTemp->next = temp->next;
        free(temp);
    }
}
void Vmodify() {
    system("cls");
    SetConsoleTextAttribute(h, 13);
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||               MODIFY               ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    int id, stock;
    double price;
    string item;
    int nid; int nq;
    if (head5 == NULL) {
        system("cls");
        cout << "No Products Found." << endl;
        cout << "\n\nPress any key to return to Main Menu . . .";
        _getche();
    }
    else {
        int count = Vdisplay();
        cout << "\n\nEnter ID To Modify Product:\n";
        cin >> id;
        struct VEGANfood* temp = head5;
        int pos = 0;
        pos = Vsearch(id);
        if (pos <= count) {
            while (temp->ID != id)
            {
                temp = temp->next;
            }
            int choice = 0;
            while (choice != 5) {
                system("cls");
                SetConsoleTextAttribute(h, 9);
                cout << "\nCurrent ID : " << temp->ID << endl;
                cout << "Current Product Name : " << temp->Item << endl;
                cout << "Current Price : " << temp->Price << endl;
                cout << "Current stock : " << temp->Stock << endl;

                SetConsoleTextAttribute(h, 7);
                cout << "\n\n\t\t    1) Modify ID" << endl;
                cout << "\t\t    2) Modify Product Name" << endl;
                cout << "\t\t    3) Modify Price" << endl;
                cout << "\t\t    4) Modify Stock" << endl;
                cout << "\t\t    5) Back" << endl;

                SetConsoleTextAttribute(h, 9);
                cout << "\nEnter Your Choice: ";
                cin >> choice;

                SetConsoleTextAttribute(h, 9);
                switch (choice) {
                case 1:
                    cout << "Enter new ID:" << endl;
                    cin >> id;
                    temp->ID = id;
                    break;

                case 2:
                    cout << "Enter new Product Name:" << endl;
                    cin >> item;
                    temp->Item = item;
                    break;

                case 3:
                    cout << "Enter new Price:" << endl;
                    cin >> price;
                    temp->Price = price;
                    break;

                case 4:
                    cout << "Enter new Stock:" << endl;
                    cin >> stock;
                    temp->Stock = stock;
                    break;
                }
            }
        }
        else {
            SetConsoleTextAttribute(h, 9);
            cout << id << " Not found\n\n";
            cout << "\nPress any key to continue . . .";
            _getche();
        }
    }
}
void Vbuy() {
    system("cls");
    int count10 = Vdisplay();
    int bill = 0, price;

   
    if (head == NULL) {
        SetConsoleTextAttribute(h, 9);
        cout << "\nNothing is Available at the moment\n\n";
        cout << "Press any key tou continue . . .";
        _getche();
    }
    else {
        struct VEGANfood* cur = head5;
        int stock, id;
    A:
        SetConsoleTextAttribute(h, 9);
        cout << "Enter ID of item that you want to buy: ";
        cin >> id;
        if (id == -1) {
            system("cls");
            return;
        }
        int pos = Vsearch(id);
        if (pos <= count10)
        {
            while (cur->ID != id)
            {
                cur = cur->next;
            }
            SetConsoleTextAttribute(h, 9);
            cout << "How much do you want:";
            cin >> stock;
            if (cur->Stock < stock)
            {
                SetConsoleTextAttribute(h, 9);
                cout << "\n\n\t\t\tThe Quantity You Want Is Not Available right now . . ." << endl;
                cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
                goto A;

            }


            bill = bill + (cur->Price * stock);
            cur->Stock = cur->Stock - stock;
            CartinsertEnd(cur->Item, stock, bill);


        }
        else {
            SetConsoleTextAttribute(h, 9);
            cout << "\nID doesnt Exist\n\n";
        }

    }
}
/////////////////////////////////////////////////////////////////////////////
//SEAFOOD linked list//
struct SEAfood
{
    int ID;
    string Item;
    double Price;
    int Stock;
    struct SEAfood* next;
};

struct SEAfood* head6 = NULL;

void SSort() {
    SEAfood* temp1;
    SEAfood* temp2;
    int temp = 0;
    for (temp1 = head6; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->ID > temp2->ID) {
                temp = temp1->ID;
                temp1->ID = temp2->ID;
                temp2->ID = temp;
            }
        }
    }
}
void SinsertEnd() {
    int id, stock;
    string item;
    double price;
    SEAfood* newNode = new SEAfood();

    SetConsoleTextAttribute(h, 9);
    cout << "Enter Product ID:-";
    cin >> id;
    newNode->ID = id;
    cout << "Enter Product Name:-";
    cin >> item;
    newNode->Item = item;
    cout << "Enter Price:-";
    cin >> price;
    newNode->Price = price;
    cout << "Enter Stock:-";
    cin >> stock;
    newNode->Stock = stock;
    newNode->next = NULL;

    if (head6 == NULL) {
        head6 = newNode;
    }
    else {
        SEAfood* temp = head6;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    SSort();

}
int Ssearch(int n)
{
    int count = 1;
    SEAfood* temp = head6;
    while (temp) {
        if (temp->ID == n)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }
    SetConsoleTextAttribute(h, 9);
    cout << "ID Not Found." << endl;
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;
}
string Scheck(int s) {
    int stockCheck = s;
    stringstream ss;
    ss << stockCheck;
    string stock = ss.str();

    if (s <= 0) {
        SetConsoleTextAttribute(h, 9);
        return "Out Of Stock!";
    }
    else {
        return stock;
    }
}
int Sdisplay()
{
    system("cls");
    int count = 0;
    struct SEAfood* temp = head6;
    cout << "Existing products are:\n";
    cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    SetConsoleTextAttribute(h, 9);
    cout << "=================================================================|\n";
    while (temp != NULL) {
        SetConsoleTextAttribute(h, 7);
        cout << temp->ID << "\t\t" << temp->Item << "\t\t\t" << temp->Price << "$" << "\t\t\t" << Scheck(temp->Stock) << "\n";
        temp = temp->next;
        count++;
    }
    SetConsoleTextAttribute(h, 9);
    cout << "\nTotal products in our store is : " << count << "\n\n\n";
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;

}
void SDeletefromNthPos() {
    SEAfood* temp = head6;
    SEAfood* oldTemp = temp;
    int count, id;


    if (head6 == NULL) {
        SetConsoleTextAttribute(h, 9);
        cout << "No Products Found." << endl;
        cout << "\nPress any key to continue . . .";
        _getche();
        return;
    }

    int count1 = Sdisplay();
    SetConsoleTextAttribute(h, 9);
    cout << "\nEnter Product ID: " << endl;
    cin >> id;
    int pos = Ssearch(id);

    if (pos <= count1) {
        if (pos == 1) {
            SEAfood* temp = head6;
            head6 = temp->next;

            free(temp);
            return;
        }

        for (int i = 1; i < pos; i++) {
            oldTemp = temp;
            temp = temp->next;

        }
        oldTemp->next = temp->next;
        free(temp);
    }
}
void Smodify() {
    system("cls");
    SetConsoleTextAttribute(h, 9);
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||               MODIFY               ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    int id, stock;
    double price;
    string item;
    int nid; int nq;
    if (head6 == NULL) {
        system("cls");
        cout << "No Products Found." << endl;
        cout << "\n\nPress any key to return to Main Menu . . .";
        _getche();
    }
    else {
        int count = Sdisplay();

        SetConsoleTextAttribute(h, 9);
        cout << "\n\nEnter ID To Modify Product:\n";
        cin >> id;
        struct SEAfood* temp = head6;
        int pos = 0;
        pos = Ssearch(id);
        if (pos <= count) {
            while (temp->ID != id)
            {
                temp = temp->next;
            }
            int choice = 0;
            while (choice != 5) {
                system("cls");

                SetConsoleTextAttribute(h, 9);
                cout << "\nCurrent ID : " << temp->ID << endl;
                cout << "Current Product Name : " << temp->Item << endl;
                cout << "Current Price : " << temp->Price << endl;
                cout << "Current stock : " << temp->Stock << endl;

                SetConsoleTextAttribute(h, 7);
                cout << "\n\n\t\t    1) Modify ID" << endl;
                cout << "\t\t    2) Modify Product Name" << endl;
                cout << "\t\t    3) Modify Price" << endl;
                cout << "\t\t    4) Modify Stock" << endl;
                cout << "\t\t    5) Back" << endl;

                SetConsoleTextAttribute(h, 9);
                cout << "\nEnter Your Choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    SetConsoleTextAttribute(h, 9);
                    cout << "Enter new ID:" << endl;
                    cin >> id;
                    temp->ID = id;
                    break;

                case 2:
                    SetConsoleTextAttribute(h, 9);
                    cout << "Enter new Product Name:" << endl;
                    cin >> item;
                    temp->Item = item;
                    break;

                case 3:
                    SetConsoleTextAttribute(h, 9);
                    cout << "Enter new Price:" << endl;
                    cin >> price;
                    temp->Price = price;
                    break;

                case 4:
                    SetConsoleTextAttribute(h, 9);
                    cout << "Enter new Stock:" << endl;
                    cin >> stock;
                    temp->Stock = stock;
                    break;
                }
            }
        }
        else {
            cout << id << " Not found\n\n";
            cout << "\nPress any key to continue . . .";
            _getche();
        }
    }
}
void Sbuy() {
    system("cls");
    int count10 = Sdisplay();
    int bill = 0, price;

    SetConsoleTextAttribute(h, 9);
    if (head == NULL) {
        cout << "\nNothing is Available at the moment\n\n";
        cout << "Press any key tou continue . . .";
        _getche();
    }
    else {
        struct SEAfood* cur = head6;
        int stock, id;
    A:
        SetConsoleTextAttribute(h, 9);
        cout << "Enter ID of item that you want to buy: ";
        cin >> id;
        if (id == -1) {
            system("cls");
            return;
        }
        int pos = Ssearch(id);
        if (pos <= count10)
        {
            while (cur->ID != id)
            {
                cur = cur->next;
            }
            SetConsoleTextAttribute(h, 9);
            cout << "How much do you want:";
            cin >> stock;
            SetConsoleTextAttribute(h, 9);
            if (cur->Stock < stock)
            {
                cout << "\n\n\t\t\tThe Quantity You Want Is Not Available right now . . ." << endl;
                cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
                goto A;

            }


            bill = bill + (cur->Price * stock);
            cur->Stock = cur->Stock - stock;
            CartinsertEnd(cur->Item, stock, bill);


        }
        else {
            cout << "\nID doesnt Exist\n\n";
        }

    }
}
/////////////////////////////////////////////////////////////////////////////
//Dessert linked list//
struct DESSERTfood
{
    int ID;
    string Item;
    double Price;
    int Stock;
    struct DESSERTfood* next;
};

struct DESSERTfood* head7 = NULL;

void DSort() {
    DESSERTfood* temp1;
    DESSERTfood* temp2;
    int temp = 0;
    for (temp1 = head7; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            if (temp1->ID > temp2->ID) {
                temp = temp1->ID;
                temp1->ID = temp2->ID;
                temp2->ID = temp;
            }
        }
    }
}
void DinsertEnd() {
    int id, stock;
    string item;
    double price;
    DESSERTfood* newNode = new DESSERTfood();

    SetConsoleTextAttribute(h, 9);
    cout << "Enter Product ID:-";
    cin >> id;
    newNode->ID = id;

    SetConsoleTextAttribute(h, 9);
    cout << "Enter Product Name:-";
    cin >> item;
    newNode->Item = item;

    SetConsoleTextAttribute(h, 9);
    cout << "Enter Price:-";
    cin >> price;
    newNode->Price = price;

    SetConsoleTextAttribute(h, 9);
    cout << "Enter Stock:-";
    cin >> stock;
    newNode->Stock = stock;
    newNode->next = NULL;

    if (head7 == NULL) {
        head7 = newNode;
    }
    else {
        DESSERTfood* temp = head7;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    DSort();

}
int Dsearch(int n)
{
    int count = 1;
    DESSERTfood* temp = head7;
    while (temp) {
        if (temp->ID == n)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }
    cout << "ID Not Found." << endl;
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;
}
string Dcheck(int s) {
    int stockCheck = s;
    stringstream ss;
    ss << stockCheck;
    string stock = ss.str();

    if (s <= 0) {
        return "Out Of Stock!";
    }
    else {
        return stock;
    }
}
int Ddisplay()
{
    system("cls");
    int count = 0;
    struct DESSERTfood* temp = head7;
    cout << "Existing products are:\n";
    cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    SetConsoleTextAttribute(h, 9);
    cout << "=================================================================|\n";
    while (temp != NULL) {
        SetConsoleTextAttribute(h, 7);
        cout << temp->ID << "\t\t" << temp->Item << "\t\t\t" << temp->Price << "$" << "\t\t\t" << Dcheck(temp->Stock) << "\n";
        temp = temp->next;
        count++;
    }
    SetConsoleTextAttribute(h, 9);
    cout << "\nTotal products in our store is : " << count << "\n\n\n";
    cout << "\nPress any key to continue . . .";
    _getche();
    return count;

}
void DDeletefromNthPos() {
    DESSERTfood* temp = head7;
    DESSERTfood* oldTemp = temp;
    int count, id;


    if (head7 == NULL) {
        cout << "No Products Found." << endl;
        cout << "\nPress any key to continue . . .";
        _getche();
        return;
    }

    int count1 = Ddisplay();
    SetConsoleTextAttribute(h, 9);
    cout << "\nEnter Product ID: " << endl;
    cin >> id;
    int pos = Dsearch(id);

    if (pos <= count1) {
        if (pos == 1) {
            DESSERTfood* temp = head7;
            head7 = temp->next;

            free(temp);
            return;
        }

        for (int i = 1; i < pos; i++) {
            oldTemp = temp;
            temp = temp->next;

        }
        oldTemp->next = temp->next;
        free(temp);
    }
}
void Dmodify() {
    system("cls");
    SetConsoleTextAttribute(h, 9);
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||               MODIFY               ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    int id, stock;
    double price;
    string item;
    int nid; int nq;
    if (head7 == NULL) {
        system("cls");
        cout << "No Products Found." << endl;
        cout << "\n\nPress any key to return to Main Menu . . .";
        _getche();
    }
    else {
        int count = Ddisplay();

        SetConsoleTextAttribute(h, 9);
        cout << "\n\nEnter ID To Modify Product:\n";
        cin >> id;
        struct DESSERTfood* temp = head7;
        int pos = 0;
        pos = Dsearch(id);
        if (pos <= count) {
            while (temp->ID != id)
            {
                temp = temp->next;
            }
            int choice = 0;
            while (choice != 5) {
                system("cls");
                cout << "\nCurrent ID : " << temp->ID << endl;
                cout << "Current Product Name : " << temp->Item << endl;
                cout << "Current Price : " << temp->Price << endl;
                cout << "Current stock : " << temp->Stock << endl;
                SetConsoleTextAttribute(h, 7);
                cout << "\n\n\t\t    1) Modify ID" << endl;
                cout << "\t\t    2) Modify Product Name" << endl;
                cout << "\t\t    3) Modify Price" << endl;
                cout << "\t\t    4) Modify Stock" << endl;
                cout << "\t\t    5) Back" << endl;

                cout << "\nEnter Your Choice: ";
                cin >> choice;
                SetConsoleTextAttribute(h, 13);
                switch (choice) {
                case 1:
                    cout << "Enter new ID:" << endl;
                    cin >> id;
                    temp->ID = id;
                    break;

                case 2:
                    cout << "Enter new Product Name:" << endl;
                    cin >> item;
                    temp->Item = item;
                    break;

                case 3:
                    cout << "Enter new Price:" << endl;
                    cin >> price;
                    temp->Price = price;
                    break;

                case 4:
                    cout << "Enter new Stock:" << endl;
                    cin >> stock;
                    temp->Stock = stock;
                    break;
                }
            }
        }
        else {
            cout << id << " Not found\n\n";
            cout << "\nPress any key to continue . . .";
            _getche();
        }
    }
}
void Dbuy() {
    system("cls");
    int count10 = Ddisplay();
    int bill = 0, price;

    if (head == NULL) {
        cout << "\nNothing is Available at the moment\n\n";
        cout << "Press any key tou continue . . .";
        _getche();
    }
    else {
        struct DESSERTfood* cur = head7;
        int stock, id;
    A:
        cout << "Enter ID of item that you want to buy: ";
        cin >> id;
        if (id == -1) {
            system("cls");
            return;
        }
        int pos = Dsearch(id);
        if (pos <= count10)
        {
            while (cur->ID != id)
            {
                cur = cur->next;
            }
            cout << "How much do you want:";
            cin >> stock;
            if (cur->Stock < stock)
            {
                cout << "\n\n\t\t\tThe Quantity You Want Is Not Available right now . . ." << endl;
                cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
                goto A;

            }


            bill = bill + (cur->Price * stock);
            cur->Stock = cur->Stock - stock;
            CartinsertEnd(cur->Item, stock, bill);


        }
        else {
            cout << "\nID doesnt Exist\n\n";
        }

    }
}
/////////////////////////////////////////////////////////////////////////////

//Recipt //////////////////
void Receipt(string name, string phnum, string method) {
    SetConsoleTextAttribute(h, 9);
    cout << "\n--------------------------------------------------------------------------" << endl;
    SetConsoleTextAttribute(h, 7);
    cout << "RECEIPT                                                    " << name << endl;
    int ordnumber = Top();
    Pop();
    cout << "                                                           " << phnum << endl;

    CartDisplay();
    SetConsoleTextAttribute(h, 9);
    cout << "\n--------------------------------------------------------------------------" << endl;
    SetConsoleTextAttribute(h, 7);
    int total = CartTotal();
    int subtotal = (total * 0.95);
    cout << "\t                                                    Total: " << total << "$" << endl;
    cout << "\t                                           Discount( 5% ): " << (total - (total * 0.95)) << "$" << endl;
    cout << "\t                                                 SubTotal: " << (subtotal) << "$" << endl;

    cout << "Payment Method                                             " << method << endl;

    SetConsoleTextAttribute(h, 9);
    cout << "\n--------------------------------------------------------------------------" << endl;
    SetConsoleTextAttribute(h, 7);

    subtot = subtot + subtotal;
    head10 = NULL;

    ofstream cust("CustomerDetail.txt", ios::app);
    cust << name << "\t\t" << phnum << endl;
    Enqueue(name, phnum, method, ordnumber);
    SetConsoleTextAttribute(h, 9);
    cout << "\nPress any key to continue . . .";
    _getche();

}

//Payment methodss////
void Cash() {
    system("cls");
    SetConsoleTextAttribute(h, 2);
    slide_animation("Order Placed!");
    SetConsoleTextAttribute(h, 9);
    text_animation("Order Placed!");

}
bool isNumeric(const string& str) {
    return all_of(str.begin(), str.end(), ::isdigit);
}
bool isValidCreditCard(const string& creditCardNumber, const string& cvv, const string& expirationDate) {
    // Check if the input is numeric
    if (!isNumeric(creditCardNumber) || !isNumeric(cvv) || !isNumeric(expirationDate)) {
        return false;
    }

    // Check if the credit card number is of valid length
    size_t cardLength = creditCardNumber.length();
    if (cardLength < 13 || cardLength > 19) {
        return false;
    }

    // Check if CVV is of valid length
    if (cvv.length() != 3 && cvv.length() != 4) {
        return false;
    }

    // Check if expiration date is of valid length
    if (expirationDate.length() != 4) {
        return false;
    }

    // Apply the Luhn algorithm
    int sum = 0;
    bool doubleDigit = false;

    for (int i = cardLength - 1; i >= 0; --i) {
        int digit = creditCardNumber[i] - '0';

        if (doubleDigit) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    // Check if the sum is a multiple of 10
    if (sum % 10 == 0) {
        return true;
    }
    else {
        return false;
    }
}

void creditCard() {
A:
    system("cls");
    string creditnum, cvv, expiry;
    SetConsoleTextAttribute(h, 9);
    cout << "\n\t\t    Enter Credit Card Number: ";
    cin >> creditnum;
    SetConsoleTextAttribute(h, 9);
    cout << "\n\t\t    Enter CVV: ";
    cin >> cvv;
    SetConsoleTextAttribute(h, 9);
    cout << "\n\t\t    Enter Expiry: ";
    cin >> expiry;

    if (!isValidCreditCard(creditnum, cvv, expiry)) {
        SetConsoleTextAttribute(h, 13);
        cout << "Invalid Credit Card Number. Enter Any Key To Try Again " << endl;
        int numberzz;
        cin >> numberzz;

        goto A;

    }
    system("cls");
    slide_animation("Order Placed");
    text_animation("Order Placed");

}
/////////////////////////////////////////////////////////

//Checkout Function//
void Checkout()
{
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);

    system("cls");
    SetConsoleTextAttribute(h, 9);
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||         ADDRESS & BILING           ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    SetConsoleTextAttribute(h, 9);
    cout << "\n\t\t    Enter Full Name: ";
    string fullname;
    cin.ignore();
    getline(cin, fullname);

    SetConsoleTextAttribute(h, 9);
    cout << "\n\t\t    Phone Number: ";
    string phnum;
    cin >> phnum;


    SetConsoleTextAttribute(h, 9);
    cout << "\n\t\t    Biling Method:" << endl;
    SetConsoleTextAttribute(h, 7);
    cout << "\t\t    1) Cash " << endl;
    cout << "\t\t    2) Credit Card " << endl;
    int choice4;

    SetConsoleTextAttribute(h, 9);
    cout << "\nEnter Your Choice: ";
    cin >> choice4;
    if (choice4 == 1) {
        Cash();
        Receipt(fullname, phnum, "Cash");
    }
    else {
        creditCard();
        Receipt(fullname, phnum, "Credit Card");
    }


}
//////////////////////////////////////////////////////////////

//View Cart Function//
void viewCart() {
    int choice3 = 0;
    while (choice3 != 2) {
        system("cls");
        cout << "\t\t -------------------------------------- " << endl;
        cout << "\t\t||                                    ||" << endl;
        cout << "\t\t||              MY CART               ||" << endl;
        cout << "\t\t||                                    ||" << endl;
        cout << "\t\t -------------------------------------- " << endl;
        cout << "\n\t\t\t                  ___" << endl;
        cout << "\t\t\t                 /  |" << endl;
        cout << "\t\t\t  ______________/   --" << endl;
        cout << "\t\t\t |___/__ /___/_|     " << endl;
        cout << "\t\t\t |__/___/___/__|     " << endl;
        cout << "\t\t\t |_/___/___/___|     " << endl;
        cout << "\t\t\t    _______/         " << endl;
        cout << "\t\t\t     O   O           " << endl;

        CartDisplay();

        SetConsoleTextAttribute(h, 7);
        cout << "\n\t\t    1) Checkout" << endl;
        cout << "\t\t    2) Back To Pevious Page" << endl;

        SetConsoleTextAttribute(h, 9);
        cout << "\nEnter Your Choice: ";
        cin >> choice3;

        switch (choice3) {
        case 1:
            //Checkout Function//
            Checkout();
            break;

        }
    }

}
///////////////////////////////////////////////////////////////

// Customer Function //             //food category database from last to start

void CustomerPortal() {
    int choice2 = 0;
    while (choice2 != 10) {
        system("cls");
        SetConsoleTextAttribute(h, 9);
        cout << "\t\t -------------------------------------- " << endl;
        cout << "\t\t||                                    ||" << endl;
        cout << "\t\t||         !!!! WELCOME !!!!          ||" << endl;
        cout << "\t\t||                                    ||" << endl;
        cout << "\t\t -------------------------------------- " << endl;
        SetConsoleTextAttribute(h, 7);
        cout << "\n\t\t    1) Fast Food" << endl;
        cout << "\t\t    2) Mexican Cuisines" << endl;
        cout << "\t\t    3) Italian Cuisines" << endl;
        cout << "\t\t    4) Barbequeue (BBQ)" << endl;
        cout << "\t\t    5) BreakFast / Brunch" << endl;
        cout << "\t\t    6) Vegetarian / Vegan" << endl;
        cout << "\t\t    7) SeaFood" << endl;
        cout << "\t\t    8) Deserts" << endl;
        cout << "\t\t    9) View Cart" << endl;
        cout << "\t\t    10) Back to Main Menu" << endl;

        SetConsoleTextAttribute(h, 9);
        cout << "\nEnter Your Choice: ";
        cin >> choice2;
        switch (choice2) {
        case 1:
            Fbuy();
            break;

        case 2:
            Mbuy();
            break;

        case 3:
            Ibuy();
            break;

        case 4:
            Bbuy();
            break;

        case 5:
            Brbuy();
            break;

        case 6:
            Vbuy();
            break;

        case 7:
            Sbuy();
            break;

        case 8:
            Dbuy();
            break;

        case 9:
            system("cls");
            //View Cart Function//
            viewCart();
            break;


        }

    }
}
//////////////////////////////////////////////////////////////////////

//Admin Portal//           
void AddNew() {
    int cho = 0;
    while (cho != 9) {
        system("cls");
        SetConsoleTextAttribute(h, 9);
        cout << "\t\t --------------------------------------------------------------- " << endl;
        cout << "\t\t||                                                             ||" << endl;
        cout << "\t\t||         ADD NEW PRODUCT TO THE FOLLOWING CATEGOIES          ||" << endl;
        cout << "\t\t||                                                             ||" << endl;
        cout << "\t\t --------------------------------------------------------------- " << endl;
        SetConsoleTextAttribute(h, 7);
        cout << "\n\t\t    1) Fast Food" << endl;
        cout << "\t\t    2) Mexican Cuisines" << endl;
        cout << "\t\t    3) Italian Cuisines" << endl;
        cout << "\t\t    4) Barbequeue (BBQ)" << endl;
        cout << "\t\t    5) BreakFast / Brunch" << endl;
        cout << "\t\t    6) Vegetarian / Vegan" << endl;
        cout << "\t\t    7) SeaFood" << endl;
        cout << "\t\t    8) Deserts" << endl;
        cout << "\t\t    9) Back" << endl;


        SetConsoleTextAttribute(h, 9);
        cout << "\nEnter Your Choice: ";
        cin >> cho;
        switch (cho) {
        case 1:
            FinsertEnd();
            break;

        case 2:
            MinsertEnd();
            break;

        case 3:
            IinsertEnd();
            break;

        case 4:
            BinsertEnd();
            break;

        case 5:
            BrinsertEnd();
            break;

        case 6:
            VinsertEnd();
            break;

        case 7:
            SinsertEnd();
            break;

        case 8:
            DinsertEnd();
            break;
        }
    }
}

void DelParticular() {
    int cho1 = 0;
    while (cho1 != 9) {
        system("cls");
        SetConsoleTextAttribute(h, 9);
        cout << "\t\t --------------------------------------------------------------- " << endl;
        cout << "\t\t||                                                             ||" << endl;
        cout << "\t\t||         DELETE PRODUCT FROM THE FOLLOWING CATEGOIES         ||" << endl;
        cout << "\t\t||                                                             ||" << endl;
        cout << "\t\t --------------------------------------------------------------- " << endl;
        SetConsoleTextAttribute(h, 7);
        cout << "\n\t\t    1) Fast Food" << endl;
        cout << "\t\t    2) Mexican Cuisines" << endl;
        cout << "\t\t    3) Italian Cuisines" << endl;
        cout << "\t\t    4) Barbequeue (BBQ)" << endl;
        cout << "\t\t    5) BreakFast / Brunch" << endl;
        cout << "\t\t    6) Vegetarian / Vegan" << endl;
        cout << "\t\t    7) SeaFood" << endl;
        cout << "\t\t    8) Deserts" << endl;
        cout << "\t\t    9) Back" << endl;


        SetConsoleTextAttribute(h, 9);
        cout << "\nEnter Your Choice: ";
        cin >> cho1;
        switch (cho1) {
        case 1:
            FDeletefromNthPos();
            break;

        case 2:
            MDeletefromNthPos();
            break;

        case 3:
            IDeletefromNthPos();
            break;

        case 4:
            BDeletefromNthPos();
            break;

        case 5:
            BrDeletefromNthPos();
            break;

        case 6:
            VDeletefromNthPos();
            break;

        case 7:
            SDeletefromNthPos();
            break;

        case 8:
            DDeletefromNthPos();
            break;
        }
    }
}

void Modify() {
    int cho2 = 0;
    while (cho2 != 9) {
        system("cls");
        SetConsoleTextAttribute(h, 9);
        cout << "\t\t --------------------------------------------------------------- " << endl;
        cout << "\t\t||                                                             ||" << endl;
        cout << "\t\t||         MODIFY PRODUCT FROM THE FOLLOWING CATEGOIES         ||" << endl;
        cout << "\t\t||                                                             ||" << endl;
        cout << "\t\t --------------------------------------------------------------- " << endl;
        SetConsoleTextAttribute(h, 7);
        cout << "\n\t\t    1) Fast Food" << endl;
        cout << "\t\t    2) Mexican Cuisines" << endl;
        cout << "\t\t    3) Italian Cuisines" << endl;
        cout << "\t\t    4) Barbequeue (BBQ)" << endl;
        cout << "\t\t    5) BreakFast / Brunch" << endl;
        cout << "\t\t    6) Vegetarian / Vegan" << endl;
        cout << "\t\t    7) SeaFood" << endl;
        cout << "\t\t    8) Deserts" << endl;
        cout << "\t\t    9) Back" << endl;


        SetConsoleTextAttribute(h, 9);
        cout << "\nEnter Your Choice: ";
        cin >> cho2;
        switch (cho2) {
        case 1:
            Fmodify();
            break;

        case 2:
            Mmodify();
            break;

        case 3:
            Imodify();
            break;

        case 4:
            Bmodify();
            break;

        case 5:
            Brmodify();
            break;

        case 6:
            Vmodify();
            break;

        case 7:
            Smodify();
            break;

        case 8:
            Dmodify();
            break;

        }
    }
}

void Display() {
    int cho3 = 0;
    while (cho3 != 9) {
        system("cls");
        SetConsoleTextAttribute(h, 9);
        cout << "\t\t --------------------------------------------------------------- " << endl;
        cout << "\t\t||                                                             ||" << endl;
        cout << "\t\t||        DISPLAY PRODUCT FROM THE FOLLOWING CATEGOIES         ||" << endl;
        cout << "\t\t||                                                             ||" << endl;
        cout << "\t\t --------------------------------------------------------------- " << endl;
        SetConsoleTextAttribute(h, 7);
        cout << "\n\t\t    1) Fast Food" << endl;
        cout << "\t\t    2) Mexican Cuisines" << endl;
        cout << "\t\t    3) Italian Cuisines" << endl;
        cout << "\t\t    4) Barbequeue (BBQ)" << endl;
        cout << "\t\t    5) BreakFast / Brunch" << endl;
        cout << "\t\t    6) Vegetarian / Vegan" << endl;
        cout << "\t\t    7) SeaFood" << endl;
        cout << "\t\t    8) Deserts" << endl;
        cout << "\t\t    9) Back" << endl;


        SetConsoleTextAttribute(h, 9);
        cout << "\nEnter Your Choice: ";
        cin >> cho3;
        switch (cho3) {
        case 1:
            Fdisplay();
            break;

        case 2:
            Mdisplay();
            break;

        case 3:
            Idisplay();
            break;

        case 4:
            Bdisplay();
            break;

        case 5:
            Brdisplay();
            break;

        case 6:
            Vdisplay();
            break;

        case 7:
            Sdisplay();
            break;

        case 8:
            Ddisplay();
            break;

        }
    }
}

void Admin() {
    int choice1 = 0;
    while (choice1 != 10) {
        system("cls");
        SetConsoleTextAttribute(h, 9);
        cout << "\t\t ----------------------------------------- " << endl;
        cout << "\t\t||                                       ||" << endl;
        cout << "\t\t||          ADMINISTRATOR PORTAL         ||" << endl;
        cout << "\t\t||                                       ||" << endl;
        cout << "\t\t ----------------------------------------- " << endl;
        SetConsoleTextAttribute(h, 7);
        cout << "\n\t\t    1) Add a new Product" << endl;
        cout << "\t\t    2) Delete a particular Product" << endl;
        cout << "\t\t    3) Modify Existing Product" << endl;
        cout << "\t\t    4) Display all Product" << endl;
        cout << "\t\t    5) Queued Orders" << endl;
        cout << "\t\t    6) DeQueue Order" << endl;
        cout << "\t\t    7) Customer History" << endl;
        cout << "\t\t    8) Total Earned" << endl;
        cout << "\t\t    9) Backup" << endl;
        cout << "\t\t    10) Back to Main Menu" << endl;
        SetConsoleTextAttribute(h, 9);
        cout << "\nEnter Your Choice: ";
        cin >> choice1;
        switch (choice1) {
        case 1:
            //Add Product//
            AddNew();
            break;

        case 2:
            //Delete Product//
            DelParticular();
            break;

        case 3:
            //Modify Product//
            Modify();
            break;

        case 4:
            //display products//
            Display();
            break;

        case 5:
            //Queued Orders//
            DisplayQueue();
            break;

        case 6:
            //DeQueue Orders//
            Dequeue();
            break;

        case 7:
            //Customer History//
            CusDisplay();
            break;

        case 8:
            //Total//
            totearn();
            _getche();
            break;

        case 9:
            backup();
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////

//Admin Login//
void Login() {
    SetConsoleTextAttribute(h, 9);
    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||               LOGIN                ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    SetConsoleTextAttribute(h, 9);
    cout << "\n\n\t\t  Username: ";
    string username;
    cin >> username;

    SetConsoleTextAttribute(h, 9);
    cout << "\t\t  Password: ";
    string password;
    cin >> password;

    if (username == "Admin" && password == "Admin") {
        system("cls");
        cout << "\t\t";
        SetConsoleTextAttribute(h, 2);
        text_animation("Logging In");
        Admin();
    }
    else {
        system("cls");
        cout << "\t\t";
        SetConsoleTextAttribute(h, 5);
        text_animation("Incorrect Credentials");
        cout << "\n\nPress any key to return to Main Menu . . .";
        _getche();
        system("cls");
    }
}
///////////////////////////////////////////////////////
//functions for rewriting //

void preDefined()
{
    //FAST FOOD
    FASTfood* newNode = new FASTfood();
    newNode->ID = 1;
    newNode->Item = "Burger";
    newNode->Price = 6.99;
    newNode->Stock = 30;
    newNode->next = NULL;
    head = newNode;

    FASTfood* newNode1 = new FASTfood();
    newNode1->ID = 2;
    newNode1->Item = "Pizza";
    newNode1->Price = 8.99;
    newNode1->Stock = 30;
    newNode1->next = NULL;
    FASTfood* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode1;

    FASTfood* newNode2 = new FASTfood();
    newNode2->ID = 3;
    newNode2->Item = "HotDog";
    newNode2->Price = 4.99;
    newNode2->Stock = 30;
    newNode2->next = NULL;
    FASTfood* temp1 = head;

    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = newNode2;

    FASTfood* newNode3 = new FASTfood();
    newNode3->ID = 4;
    newNode3->Item = "Fries";
    newNode3->Price = 3.99;
    newNode3->Stock = 30;
    newNode3->next = NULL;
    FASTfood* temp2 = head;

    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = newNode3;

    //MEXICAN FOOD
    MEXICANfood* newNode4 = new MEXICANfood();
    newNode4->ID = 1;
    newNode4->Item = "Tacos";
    newNode4->Price = 5.99;
    newNode4->Stock = 30;
    newNode4->next = NULL;
    head1 = newNode4;

    MEXICANfood* newNode5 = new MEXICANfood();
    newNode5->ID = 2;
    newNode5->Item = "Pozole";
    newNode5->Price = 8.99;
    newNode5->Stock = 30;
    newNode5->next = NULL;
    MEXICANfood* temp4 = head1;

    while (temp4->next != NULL) {
        temp4 = temp4->next;
    }
    temp4->next = newNode5;

    MEXICANfood* newNode6 = new MEXICANfood();
    newNode6->ID = 3;
    newNode6->Item = "Qdoba";
    newNode6->Price = 4.99;
    newNode6->Stock = 30;
    newNode6->next = NULL;

    MEXICANfood* temp5 = head1;
    while (temp5->next != NULL) {
        temp5 = temp5->next;
    }
    temp5->next = newNode6;

    MEXICANfood* newNode7 = new MEXICANfood();
    newNode7->ID = 4;
    newNode7->Item = "Burrito";
    newNode7->Price = 3.99;
    newNode7->Stock = 30;
    newNode7->next = NULL;
    MEXICANfood* temp6 = head1;

    while (temp6->next != NULL) {
        temp6 = temp6->next;
    }
    temp6->next = newNode7;

    //ITALIAN FOOD
    ITALIANfood* newNode8 = new ITALIANfood();
    newNode8->ID = 1;
    newNode8->Item = "Alfredo Pizza";
    newNode8->Price = 14.99;
    newNode8->Stock = 30;
    newNode8->next = NULL;
    head2 = newNode8;

    ITALIANfood* newNode9 = new ITALIANfood();
    newNode9->ID = 2;
    newNode9->Item = "Domino Pizza";
    newNode9->Price = 9.99;
    newNode9->Stock = 30;
    newNode9->next = NULL;
    ITALIANfood* temp7 = head2;

    while (temp7->next != NULL) {
        temp7 = temp7->next;
    }
    temp7->next = newNode9;

    ITALIANfood* newNode10 = new ITALIANfood();
    newNode10->ID = 3;
    newNode10->Item = "Saucy Pasta";
    newNode10->Price = 19.99;
    newNode10->Stock = 30;
    newNode10->next = NULL;

    ITALIANfood* temp8 = head2;
    while (temp8->next != NULL) {
        temp8 = temp8->next;
    }
    temp8->next = newNode10;

    ITALIANfood* newNode11 = new ITALIANfood();
    newNode11->ID = 4;
    newNode11->Item = "Pizza Balls ";
    newNode11->Price = 7.99;
    newNode11->Stock = 30;
    newNode11->next = NULL;
    ITALIANfood* temp9 = head2;

    while (temp9->next != NULL) {
        temp9 = temp9->next;
    }
    temp9->next = newNode11;

    //BBQ FOOD
    BBQ* newNode12 = new BBQ();
    newNode12->ID = 1;
    newNode12->Item = "Grilled Chicken";
    newNode12->Price = 7.99;
    newNode12->Stock = 30;
    newNode12->next = NULL;
    head3 = newNode12;

    BBQ* newNode13 = new BBQ();
    newNode13->ID = 2;
    newNode13->Item = "Chicken Tikka";
    newNode13->Price = 9.99;
    newNode13->Stock = 30;
    newNode13->next = NULL;
    BBQ* temp10 = head3;

    while (temp10->next != NULL) {
        temp10 = temp10->next;
    }
    temp10->next = newNode13;

    BBQ* newNode14 = new BBQ();
    newNode14->ID = 3;
    newNode14->Item = "Grilled Mutton";
    newNode14->Price = 19.99;
    newNode14->Stock = 30;
    newNode14->next = NULL;

    BBQ* temp11 = head3;
    while (temp11->next != NULL) {
        temp11 = temp11->next;
    }
    temp11->next = newNode14;

    BBQ* newNode15 = new BBQ();
    newNode15->ID = 4;
    newNode15->Item = "B.B.Q Bites ";
    newNode15->Price = 3.99;
    newNode15->Stock = 30;
    newNode15->next = NULL;
    BBQ* temp12 = head3;

    while (temp12->next != NULL) {
        temp12 = temp12->next;
    }
    temp12->next = newNode15;

    //BRUNCH FOOD
    BRUNCHFOOD* newNode16 = new BRUNCHFOOD();
    newNode16->ID = 1;
    newNode16->Item = "Omelete";
    newNode16->Price = 6.99;
    newNode16->Stock = 30;
    newNode16->next = NULL;
    head4 = newNode16;

    BRUNCHFOOD* newNode17 = new BRUNCHFOOD();
    newNode17->ID = 2;
    newNode17->Item = "Toast";
    newNode17->Price = 2.99;
    newNode17->Stock = 30;
    newNode17->next = NULL;
    BRUNCHFOOD* temp13 = head4;

    while (temp13->next != NULL) {
        temp13 = temp13->next;
    }
    temp13->next = newNode17;

    BRUNCHFOOD* newNode18 = new BRUNCHFOOD();
    newNode18->ID = 3;
    newNode18->Item = "Tea";
    newNode18->Price = 8.99;
    newNode18->Stock = 30;
    newNode18->next = NULL;

    BRUNCHFOOD* temp14 = head4;
    while (temp14->next != NULL) {
        temp14 = temp14->next;
    }
    temp14->next = newNode18;

    BRUNCHFOOD* newNode19 = new BRUNCHFOOD();
    newNode19->ID = 4;
    newNode19->Item = "Coffee";
    newNode19->Price = 11.99;
    newNode19->Stock = 30;
    newNode19->next = NULL;
    BRUNCHFOOD* temp15 = head4;

    while (temp15->next != NULL) {
        temp15 = temp15->next;
    }
    temp15->next = newNode19;

    //VEGAN FOOD
    VEGANfood* newNode20 = new VEGANfood();
    newNode20->ID = 1;
    newNode20->Item = "VeggieBurger";
    newNode20->Price = 6.99;
    newNode20->Stock = 30;
    newNode20->next = NULL;
    head5 = newNode20;

    VEGANfood* newNode21 = new VEGANfood();
    newNode21->ID = 2;
    newNode21->Item = "VeggiePizza";
    newNode21->Price = 14.99;
    newNode21->Stock = 30;
    newNode21->next = NULL;
    VEGANfood* temp16 = head5;

    while (temp16->next != NULL) {
        temp16 = temp16->next;
    }
    temp16->next = newNode21;

    VEGANfood* newNode22 = new VEGANfood();
    newNode22->ID = 3;
    newNode22->Item = "VeggiePasta";
    newNode22->Price = 8.99;
    newNode22->Stock = 30;
    newNode22->next = NULL;
    VEGANfood* temp17 = head5;

    while (temp17->next != NULL) {
        temp17 = temp17->next;
    }
    temp17->next = newNode22;

    VEGANfood* newNode23 = new VEGANfood();
    newNode23->ID = 4;
    newNode23->Item = "FruitSmoothie";
    newNode23->Price = 19.99;
    newNode23->Stock = 30;
    newNode23->next = NULL;
    VEGANfood* temp18 = head5;

    while (temp18->next != NULL) {
        temp18 = temp18->next;
    }
    temp18->next = newNode23;

    //SEA FOOD
    SEAfood* newNode24 = new SEAfood();
    newNode24->ID = 1;
    newNode24->Item = "GrilledFish";
    newNode24->Price = 14.99;
    newNode24->Stock = 30;
    newNode24->next = NULL;
    head6 = newNode24;

    SEAfood* newNode25 = new SEAfood();
    newNode25->ID = 2;
    newNode25->Item = "CrabCurry";
    newNode25->Price = 24.99;
    newNode25->Stock = 30;
    newNode25->next = NULL;
    SEAfood* temp19 = head6;

    while (temp19->next != NULL) {
        temp19 = temp19->next;
    }
    temp19->next = newNode25;

    SEAfood* newNode26 = new SEAfood();
    newNode26->ID = 3;
    newNode26->Item = "GrillShrimps";
    newNode26->Price = 17.99;
    newNode26->Stock = 30;
    newNode26->next = NULL;
    SEAfood* temp20 = head6;

    while (temp20->next != NULL) {
        temp20 = temp20->next;
    }
    temp20->next = newNode26;

    SEAfood* newNode27 = new SEAfood();
    newNode27->ID = 4;
    newNode27->Item = "SushiSalad";
    newNode27->Price = 19.99;
    newNode27->Stock = 30;
    newNode27->next = NULL;
    SEAfood* temp21 = head6;

    while (temp21->next != NULL) {
        temp21 = temp21->next;
    }
    temp21->next = newNode27;


    //DESSERT FOOD
    DESSERTfood* newNode28 = new DESSERTfood();
    newNode28->ID = 1;
    newNode28->Item = "MoltenLava";
    newNode28->Price = 29.99;
    newNode28->Stock = 30;
    newNode28->next = NULL;
    head7 = newNode28;

    DESSERTfood* newNode29 = new DESSERTfood();
    newNode29->ID = 2;
    newNode29->Item = "VanilaCrunch";
    newNode29->Price = 14.99;
    newNode29->Stock = 30;
    newNode29->next = NULL;
    DESSERTfood* temp22 = head7;

    while (temp22->next != NULL) {
        temp22 = temp22->next;
    }
    temp22->next = newNode29;

    DESSERTfood* newNode30 = new DESSERTfood();
    newNode30->ID = 3;
    newNode30->Item = "SparkIce";
    newNode30->Price = 16.99;
    newNode30->Stock = 30;
    newNode30->next = NULL;
    DESSERTfood* temp23 = head7;

    while (temp23->next != NULL) {
        temp23 = temp23->next;
    }
    temp23->next = newNode30;

    DESSERTfood* newNode31 = new DESSERTfood();
    newNode31->ID = 4;
    newNode31->Item = "OrangeSplash";
    newNode31->Price = 19.99;
    newNode31->Stock = 30;
    newNode31->next = NULL;
    DESSERTfood* temp24 = head7;

    while (temp24->next != NULL) {
        temp24 = temp24->next;
    }
    temp24->next = newNode31;

}

int main() {
    preDefined();
    //Project Intro Screen Code//
    SetConsoleTextAttribute(h, 6);


    cout << "\t\t -------------------------------------- " << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t||       FOOD DRIVE THRU SYSTEM       ||" << endl;
    cout << "\t\t||                                    ||" << endl;
    cout << "\t\t -------------------------------------- " << endl;
    SetConsoleTextAttribute(h, 8);
    cout << "\n\n\t\t  >>>>>>>>>>>> PROJECT BY <<<<<<<<<<<<" << endl;
    SetConsoleTextAttribute(h, 9);
    cout << "\n\t\t    Mirza Areeb Baig (2022F-BCS-014)" << endl;
    cout << "\t\t    Ali Talal (2022F-BCS-003)" << endl;
    cout << "\t\t    Mustafa Ilyas Azhar (2022F-BCS-267)" << endl;
    SetConsoleTextAttribute(h, 14);
    cout << "\n\t\t      Faculty: Miss Tahera Yawer" << endl;
    SetConsoleTextAttribute(h, 12);
    cout << "\n\t\t   Subject: Data Structures & Algorithms\n\n" << endl;
    SetConsoleTextAttribute(h, 7);
    cout << "Press any key to continue . . .";
    _getche();

    //file handling of categories//
    pushUniqueRandomNumbers(500);
    //Main Menu Screen Code//
    A:
    int choice = 0;
    
    while (choice != 3) {
        system("cls");
        SetConsoleTextAttribute(h, 9);
        cout << "\t\t -------------------------------------- " << endl;
        cout << "\t\t||                                    ||" << endl;
        cout << "\t\t||             MAIN MENU              ||" << endl;
        cout << "\t\t||                                    ||" << endl;
        cout << "\t\t -------------------------------------- " << endl;
        SetConsoleTextAttribute(h, 7);
        cout << "\n\t\t    1) Customer" << endl;
        cout << "\t\t    2) Admin" << endl;
        cout << "\t\t    3) Exit\n" << endl;

        SetConsoleTextAttribute(h, 9);
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            //customer function//
            CustomerPortal();
            break;

        case 2:
            system("cls");
            //admin function//
            Login();
            break;

        case 3:
            system("cls");
            SetConsoleTextAttribute(h, 9);

    cout << "\n\n\t\t  Username: ";
    string username1;
    cin >> username1;

    SetConsoleTextAttribute(h, 9);
    cout << "\t\t  Password: ";
    string password1;
    cin >> password1;

    if (username1 == "Admin" && password1 == "Admin") {
        system("cls");
        cout << "\t\t";
        SetConsoleTextAttribute(h, 2);
        text_animation("Exiting...");
    }
    else {
        system("cls");
        cout << "\t\t";
        SetConsoleTextAttribute(h, 5);
        text_animation("Incorrect Credentials");
        cout << "\n\nPress any key to return to Main Menu . . .";
        _getche();
        system("cls");
        goto A;
    }
            
        }
    }
    return 0;
}
