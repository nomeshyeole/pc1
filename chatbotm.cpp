#include <iostream>
#include <string>

using namespace std;

class chatbot
{
    public:
      void welcome();
      string getCustomerName();
      void menu();
      void order(string name, int price, string product);
      void choice(string name);
};

void chatbot::welcome() {
    cout << "------------------------------------" << endl;
    cout << " Welcome to Food Shop, I am Pratik " << endl;
    cout << "------------------------------------" << endl;
}

string chatbot::getCustomerName() {
    string name;
    cout << "Can I know your good name: ";
    cin >> name;  
    cout << "Hey " << name << "! Good to see you here!!!" << endl;
    cout << "You are at the right place. I will help you book your dish and drinks." << endl;
    return name;
}

void chatbot::menu() {
    cout << "\nHere is your menu with their prices" << endl;
    cout << "1. Pizza - RS.200" << endl;
    cout << "2. Mango Juice - RS.70" << endl;
    cout << "3. Apple Juice - RS.80\n" << endl;
}

void chatbot:: order(string name, int price,  string product) 
{
    cout << "\nThank you for choosing " << product << endl;
    cout << "Please give us some more information about you!!!!\n" << endl;
    
   
    string mob,address;
    cout << "Enter your mobile number: ";
    cin >> mob;
    cout << "Enter your address of delivery: ";
   // cin.ignore();
    cin >> address;
   // getline(cin, address);

    cout << "Choose mode of payment(1 or 2):\n1. Online\n2. Cash on delivery" << endl;
    int pay;
    cin >> pay;
    string paymode="";
    if(pay==1)
        paymode=" Online";
    else
        paymode="Cash on delivery"; 

   

    cout << "\nPlease confirm by pressing 1, else 0 to cancel: ";
    int confirmation;
    cin >> confirmation;

    if (confirmation == 1) {
        cout << "\n----------------------------------" << endl;
        cout << "Your order is booked successfully" << endl;
        cout << "----------------------------------" << endl;
        cout << "Customer Name: " << name << endl;
        cout << "Product name: " << product << endl;
        cout << "Price of product: " << price << endl;
        cout << "Mode of payment: " << paymode << endl;
        cout << "Delivery Address: " << address << endl;
        cout << "\nThank you for your interest!!! Have a nice day!!!" << endl;
    } else {
        cout << "\n**Thank you for visiting!!!! Have a nice day!!!" << endl;
    }
}

void chatbot::choice(string name) {
    chatbot c1;
    cout << "Please select product which you wish: " << endl;
    string product;
    cin >> product; 
    cout<<"\nYour product is"<<product;
   // getline(cin, product); 

    int price = 0;

    if (product == "Pizza" || product == "pizza") {
        price = 200;
        c1.order(name, price, product);
    } else if (product == "MangoJuice" || product == "mangojuice" ) {
        price = 70;
        c1.order(name, price, product);
    } else if (product == "AppleJuice" || product == "applejuice") {
        price = 80;
        c1.order(name, price, product);
    } else {
        cout << "You have not selected any product....Thank you for visiting!!!! Have a nice day!!!!" << endl;
    }
}

int main()
 {
    chatbot c2;
    c2.welcome();
    string customerName =c2. getCustomerName();
    c2.menu();
    c2.choice(customerName);
    return 0;
}