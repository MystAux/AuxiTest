#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void newline(int numOfLines){
    for (int i = 1; i <= numOfLines; i++){
        cout<<endl;
    }
}
void border() {
    for (int i = 1; i <= 100; i++){
        cout<<"-";
    }
    cout<<endl;
}
void Dblborder() {
    for (int i = 1; i <= 100; i++){
        cout<<"=";
    }
    cout<<endl;
}
void margin(){
    cout<<"             ";
}
void tmargin(){
    cout<<"                      ";
}
void Theme () {
    string color[3] = {"red", "green", "blue"};
    border();
    margin();
    for (int i = 0; i <= 2; i++){
        margin();
        int a = i + 1;
        cout<<"("<<a<<")"<<color[i];
    }
    cout<<endl;
    border();
    newline(2);
}
void print(string text){
    margin();
    cout<<text;

}
void println(string text){
    margin();
    cout<<text<<endl;
    
}

void center(string text){
    int length = text.length();

    int numOfSpace = (100 - length) / 2;
    for (int space = 1; space <= numOfSpace; space++){
        cout<<" ";
    }
    cout<<text<<endl;
}

void heading(string htext){
    Dblborder();
    center(htext);
    Dblborder();
}
void loginSign(){
    println("...       ...      ...    .........   ...   ...");
    println("...      .....    .....   .........   ....  ...");
    println("...      .. ..    .. ..      ...      ..... ...");
    println("...      .. ..    ..         ...      .........");
    println("...      .. ..    .....      ...      .........");
    println("......   .....    .. ..   .........   ...  ....");
    println("......    ...      ...    .........   ...   ...");
}
void choose() {
    margin();
    cout<<"<";
    for (int i; i <= 10; i++){
        cout<<"-";
    }
    cout<<"Enter the number of your choice";
    for (int i; i <= 10; i++){
        cout<<"-";
    }
    cout<<">"<<endl;

}
void login (){
    border();
    print("[ (1)Log in ]");
    margin();
    println("[ (2)Sign in ]");
    border();
}
void tableBorder(){
    tmargin();
    for (int i = 1; i <= 51; i++){
        cout<<"-";
    }
    cout<<endl;
}
void tableHeader (){
    string num = "No.";
    string part = "Parts";
    string model = "Model";
    string price = "Price";

    int spaceN = (5 - num.length()) / 2;
    int spaceP = (12 - part.length()) / 2;
    int spaceM = (20 - model.length()) / 2;
    int spacePr = (7 - price.length()) / 2;

    newline(2);
    tableBorder();
    tmargin();
    cout<<"| ";
    for (int space = 1; space <= spaceN; space++)
    {
        cout<<" ";
    }
    cout<<num;
    for (int space = 1; space <= spaceN; space++)
    {
        cout<<" ";
    }
    cout<<"| ";
    for (int space = 1; space <= spaceP; space++)
    {
        cout<<" ";
    }
    cout<<part;
    for (int space = 1; space <= spaceP; space++)
    {
        cout<<" ";
    }
    cout<<"| ";
    for (int space = 1; space <= spaceM; space++)
    {
        cout<<" ";
    }
    cout<<model;
    for (int space = 1; space <= spaceM; space++)
    {
        cout<<" ";
    }
    cout<<"| ";
    for (int space = 1; space <= spacePr; space++)
    {
        cout<<" ";
    }
    cout<<price;
    for (int space = 1; space <= spacePr; space++)
    {
        cout<<" ";
    }
    cout<<"| "<<endl;
}
void table (int num, string part, string model, int price) {
	int to_string;
    int spaceN = (5 - to_string(num).length()) / 2;
    int spaceP = (12 - part.length()) / 2;
    int spaceM = (20 - model.length()) / 2;
    int spacePr = (7 - to_string(price).length()) / 2;

    tableBorder();
    tmargin();
    cout<<"| ";
    for (int space = 1; space <= spaceN; space++)
    {
        cout<<" ";
    }
    cout<<num;
    for (int space = 1; space <= spaceN; space++)
    {
        cout<<" ";
    }
    cout<<"| ";
    for (int space = 1; space <= spaceP; space++)
    {
        cout<<" ";
    }
    cout<<part;
    for (int space = 1; space <= spaceP; space++)
    {
        cout<<" ";
    }
    cout<<"|";
    for (int space = 1; space <= spaceM; space++)
    {
        cout<<" ";
    }
    cout<<model;
    for (int space = 1; space <= spaceM; space++)
    {
        cout<<" ";
    }
    cout<<"| ";
    for (int space = 1; space <= spacePr; space++)
    {
        cout<<" ";
    }
    cout<<price;
    for (int space = 1; space <= spacePr; space++)
    {
        cout<<" ";
    }
    cout<<"| "<<endl;
}

void choice(){
    string chs = "<------Enter the number------>";

    int space = (100 - chs.length()) / 2;

    for (int i = 1; i <= space; i++){
        cout<<" ";
    }
    cout<<chs<<endl;
}

int main()
{
    //USER
    string registeredUN[3] = {};
    int registeredPass[3] = {};
    int userNum = 0;
    int id = 0;
    int userActive;

    //LOGIN
    bool complete = false;

    string username;
    int password;
    int loginChoice;

    do {
        print("Enter your username: ");
        cin>>username;
        print("Enter your password[4 Digits]: ");
        cin>>password;

        login();
        choice();
        print(">>>");
        cin>>loginChoice;
        
        if (loginChoice == 2)
        {
            if (to_string(password).length() == 4) 
            {
                for (int i = 0; i <= 2; i++){
                    if (username == registeredUN[id])
                    {
                        if (password != registeredPass[id])
                        {
                            registeredUN[id] = username;
                            registeredUN[id] = username;
                            id++;
                            border();
                            center("---Account registered! Please proceed to log in---");
                            border();
                            cout<<endl;
                        }
                            else
                            {
                                border();
                                center("---Account already registered! Please proceed to log in---");
                                border();
                            }
                    }
                        else
                        {
                            if (password != registeredPass[id])
                            {
                                registeredUN[id] = username;
                                registeredUN[id] = username;
                                id++;
                                border();
                                center("---Account registered! Please proceed to log in---");
                                border();
                                cout<<endl;
                            }
                                else
                                {
                                    border();
                                    center("---Password is already taken please try another one---");
                                    border();
                                }
                        }
                }
            }             
                else 
                {
                    border();
                    center("---Please enter the required password---");
                    border();
                    cout<<endl;
                }
        }
        else if (loginChoice == 1)
        {
            for (int i = 0; i <= 2; i++){
                if (username == registeredUN[i] && password == registeredPass[i])
                {
                    complete = true;

                    return complete;
                }
                else
                {
                    border();
                    center("---Account doesn't match---");
                    border();
                    cout<<endl;
                }
            }
        }

    } while (complete != true);
    heading("Welcome to CompEx Guide");

    
}
