#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

class PasswordManager
{
public:
    char password[20];
    void setPassword(int code);
};

class HotelReservation
{
public:
    int roomNumber;
    char checkInDate[15];
    char checkOutDate[15];
    char guestName[30];
    char mobileNumber[15];
    char cardNumber[15];
    char guestAddress[50];

    void acceptReservation();
    void displayReservation();
};

PasswordManager passwordObj;
HotelReservation reservationObj;

int checkRoomAvailability(int room);
void reserveRoom();
void roomStatus();
void editReservation();
void roomDetails();
void guestInformation();
void checkOut();
void historicalRecords();

int mainMenu();

void PasswordManager::setPassword(int code)
{
    if (code == 1234)
    {
        cout << "\nEnter new password: ";
        cin.ignore();
        cin.getline(password, 20);
        fstream writeStream;
        writeStream.open("password.txt", ios::out);
        writeStream.write((char *)this, sizeof(PasswordManager));
        writeStream.close();
    }
    else
    {
        cout << "\nCode Error";
    }
}

void HotelReservation::acceptReservation()
{
    cin.ignore();
    cout << "\n2. Enter check-in date: ";
    cin.getline(checkInDate, 15);
    cout << "\n3. Enter guest's full name: ";
    cin.getline(guestName, 30);
    cout << "\n4. Enter guest's mobile number: ";
    cin >> mobileNumber;
    cin.ignore();
    cout << "\n5. Enter Hotel Card Number: ";
    cin.getline(cardNumber, 15);
    cout << "\n6. Enter guest's address: ";
    cin.getline(guestAddress, 50);
}

void HotelReservation::displayReservation()
{
    cout << "\n1. Room number       " << roomNumber;
    cout << "\n2. Guest's Name      " << guestName;
    cout << "\n3. Mobile number     " << mobileNumber;
    cout << "\n4. Hotel Card Number " << cardNumber;
    cout << "\n5. Address           " << guestAddress;
    cout << "\n----------------------------";
}

int checkRoomAvailability(int room)
{
    int flag = 1;
    fstream readStream;
    readStream.open("reservations.txt", ios::in);
    readStream.seekg(0, ios::end);
    int totalRecords = readStream.tellg() / sizeof(reservationObj);
    readStream.seekg(0, ios::beg);

    for (int i = 1; i <= totalRecords; i++)
    {
        readStream.read((char *)&reservationObj, sizeof(reservationObj));
        if (room == reservationObj.roomNumber)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

void reserveRoom()
{
    int roomNumber, checkAvailability;
    cout << "\n1. Enter room number: ";
    cin >> roomNumber;
    checkAvailability = checkRoomAvailability(roomNumber);

    if (checkAvailability == 0)
    {
        cout << "\n   ROOM ALREADY BOOKED";
    }
    else
    {
        reservationObj.roomNumber = roomNumber;
        reservationObj.acceptReservation();
        passwordObj.setPassword(1234);
        fstream writeStream;
        writeStream.open("reservations.txt", ios::app);
        writeStream.write((char *)&reservationObj, sizeof(reservationObj));
        writeStream.close();


        cout << "\n   Room reservation successful!";
    }
}

void roomStatus()
{
    fstream readStream;
    readStream.open("reservations.txt", ios::in);
    readStream.seekg(0, ios::end);
    int totalRecords = readStream.tellg() / sizeof(reservationObj);
    readStream.seekg(0, ios::beg);

    for (int i = 1; i <= totalRecords; i++)
    {
        readStream.read((char *)&reservationObj, sizeof(reservationObj));
        cout << "\n   Room number       " << reservationObj.roomNumber;
        cout << "\n   Guest's Name      " << reservationObj.guestName;
        cout << "\n   Mobile number     " << reservationObj.mobileNumber;
        cout << "\n----------------------------";
    }
    readStream.close();
}

void editReservation()
{
    int roomNumber;
    cout << "\n   Enter room number: ";
    cin >> roomNumber;
    fstream writeStream, readStream;
    readStream.open("reservations.txt", ios::in);
    writeStream.open("temp.txt", ios::out);
    readStream.seekg(0, ios::end);
    int totalRecords = readStream.tellg() / sizeof(reservationObj);
    readStream.seekg(0, ios::beg);

    for (int i = 1; i <= totalRecords; i++)
    {
        readStream.read((char *)&reservationObj, sizeof(reservationObj));
        if (reservationObj.roomNumber == roomNumber)
        {
            passwordObj.setPassword(1234);
            cout << "\n   Enter new room Number: ";
            cin >> roomNumber;
            reservationObj.roomNumber = roomNumber;
            reservationObj.acceptReservation();
            writeStream.write((char *)&reservationObj, sizeof(reservationObj));
        }
        else
        {
            writeStream.write((char *)&reservationObj, sizeof(reservationObj));
        }
    }
    readStream.close();
    writeStream.close();
    remove("reservations.txt");
    rename("temp.txt", "reservations.txt");


    cout << "\n   Reservation edited successfully!";
}

void roomDetails()
{
    int roomNumber;
    cout << "\n   Enter room number: ";
    cin >> roomNumber;
    fstream readStream;
    readStream.open("reservations.txt", ios::in);
    readStream.seekg(0, ios::end);
    int totalRecords = readStream.tellg() / sizeof(reservationObj);
    readStream.seekg(0, ios::beg);

    bool roomFound = false;

    for (int i = 1; i <= totalRecords; i++)
    {
        readStream.read((char *)&reservationObj, sizeof(reservationObj));
        if (roomNumber == reservationObj.roomNumber)
        {
            roomFound = true;
            reservationObj.displayReservation();
            break;
        }
    }

    if (!roomFound)
    {
        cout << "\n   Sorry, room is empty.";
    }
    readStream.close();
}

void guestInformation()
{
    char guestName[30];
    cin.ignore();
    cout << "\n   Enter guest's name: ";
    cin.getline(guestName, 30);
    fstream readStream;
    readStream.open("reservations.txt", ios::in);
    readStream.seekg(0, ios::end);
    int totalRecords = readStream.tellg() / sizeof(reservationObj);
    readStream.seekg(0, ios::beg);

    bool guestFound = false;

    for (int i = 1; i <= totalRecords; i++)
    {
        readStream.read((char *)&reservationObj, sizeof(reservationObj));
        if (stricmp(reservationObj.guestName, guestName) == 0)
        {
            guestFound = true;
            reservationObj.displayReservation();
            break;
        }
    }

    if (!guestFound)
    {
        cout << "\n   Sorry, guest details not found";
    }
    readStream.close();
}

void checkOut()
{
    int roomNumber;
    cout << "\n   Enter room number: ";
    cin >> roomNumber;
    fstream readStream, writeStream, newWriteStream;
    readStream.open("reservations.txt", ios::in);
    writeStream.open("temp.txt", ios::app);
    newWriteStream.open("previous_records.txt", ios::app);
    readStream.seekg(0, ios::end);
    int totalRecords = readStream.tellg() / sizeof(reservationObj);
    readStream.seekg(0, ios::beg);

    for (int i = 1; i <= totalRecords; i++)
    {
        readStream.read((char *)&reservationObj, sizeof(reservationObj));
        if (reservationObj.roomNumber == roomNumber)
        {
            cin.ignore();
            cout << "\n   Enter checkout date: ";
            cin.getline(reservationObj.checkOutDate, 15);
            newWriteStream.write((char *)&reservationObj, sizeof(reservationObj));
        }
        else
        {
            writeStream.write((char *)&reservationObj, sizeof(reservationObj));
        }
    }
    readStream.close();
    writeStream.close();
    remove("reservations.txt");
    rename("temp.txt", "reservations.txt");

    // Display confirmation message
    cout << "\n   Check-out successful!";
}

void historicalRecords()
{
    fstream readStream;
    readStream.open("previous_records.txt", ios::in);
    readStream.seekg(0, ios::end);
    int totalRecords = readStream.tellg() / sizeof(reservationObj);
    readStream.seekg(0, ios::beg);

    for (int i = 1; i <= totalRecords; i++)
    {
        readStream.read((char *)&reservationObj, sizeof(reservationObj));
        reservationObj.displayReservation();
        cout << "\n   Checkout date: " << reservationObj.checkOutDate;
    }
    readStream.close();
}

int main()
{
    int choice = 1, option;
    while (choice != 0)
    {
        cout << "\nWelcome to Kings Land Hotel \n ";
        cout << "\n------------Main Menu---------\n";
        cout << "_____________________________________ ";
        cout << "\n1. Reserve a room";
        cout << "\n2. Check room occupancy";
        cout << "\n3. Room details";
        cout << "\n4. Guest information";
        cout << "\n5. Modify guest data";
        cout << "\n6. Check out of room";
        cout << "\n7. Historical records";
        cout << "\n8. Exit ";
        cout << "\n\______________________________________";
        cout << "\nChoose your option: ";

        cin >> option;
        switch (option)
        {
        case 1:
        {
            reserveRoom();
            break;
        }
        case 2:
        {
            roomStatus();
            break;
        }
        case 3:
        {
            roomDetails();
            break;
        }
        case 4:
        {
            guestInformation();
            break;
        }
        case 5:
        {
            editReservation();
            break;
        }
        case 6:
        {
            checkOut();
            break;
        }
        case 7:
        {
            historicalRecords();
            break;
        }
        case 8:
        {
            choice = 0;
            break;
        }
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        system("cls");
    }
    cout << "\n  THANK YOU!";
    return 0;
}
