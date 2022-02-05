/**
 * File
 * @description 程序开始时进行数据载入
 *              程序结束后进行数据保存
 * @author YiNN
 * @creat 2022-01-30 23:39:17
 */

#include"iostream"
#include"fstream"
#include"vector"
#include"header/data.h"
#include"header/display-color.h"
using namespace std;

vector<User> v_users;
vector<Admin> v_admins;
vector<Book> v_books;
vector<Order> v_orders;
int countU = 0;
int countB = 0;
int countO = 0;

void pullUsers() {
    ifstream fin;
    fin.open("data/users.txt");
    if (!fin.is_open()) {
        cout << "Loading failed,please retry.\n";
        exit(EXIT_FAILURE);
    }
    User item;
    while (fin >> item) {
        countU++;
        v_users.push_back(item);
    }
    fin.close();
    fin.open("data/admins.txt");
    if (!fin.is_open()) {
        cout << "Loading failed,please retry.\n";
        exit(EXIT_FAILURE);
    }
    Admin it;
    while (fin >> it) v_admins.push_back(it);
    fin.close();
}
void pullBooks() {
    ifstream fin;
    fin.open("data/books.txt");
    if (!fin.is_open()) {
        cout << "Loading failed,please retry.\n";
        exit(EXIT_FAILURE);
    }
    Book item;
    while (fin >> item){
        countB++;
        v_books.push_back(item);
    } 
    fin.close();
}

void pullOrders() {
    ifstream fin;
    fin.open("data/orders.txt");
    if (!fin.is_open()) {
        cout << "Loading failed,please retry.\n";
        exit(EXIT_FAILURE);
    }
    Order item;
    while (fin >> item){
        countO++;
        v_orders.push_back(item);
    } 
    fin.close();
}

void pushUsers() {
    ofstream outfile;
    outfile.open("data/users.txt");
    if (!outfile.is_open()) {
        cout << "Save failed,your data may be lost.\n";
        exit(EXIT_FAILURE);
    }
    for (auto item : v_users) outfile << item;
    outfile.close();
    outfile.open("data/a.txt");
    if (!outfile.is_open()) {
        cout << "Save failed,your data may be lost.\n";
        exit(EXIT_FAILURE);
    }
    for (auto item : v_admins) outfile << item;
    outfile.close();
}

void pushBooks() {
    ofstream outfile;
    outfile.open("data/books.txt");
    if (!outfile.is_open()) {
        cout << "Save failed,your data may be lost.\n";
        exit(EXIT_FAILURE);
    }
    for (auto item : v_books) outfile << item;
    outfile.close();
}

void pushOrders() {
    ofstream outfile;
    outfile.open("data/orders.txt");
    if (!outfile.is_open()) {
        cout << "Save failed,your data may be lost.\n";
        exit(EXIT_FAILURE);
    }
    for (auto item : v_orders) outfile << item;
    outfile.close();
}

void pullFile() {
    cout <<"\t\tloading...\n";
    pullUsers();
    pullBooks();
    pullOrders();
}

void pushFile() {
    cout << F_GREY << "\n\t\tsaving...";
    pushUsers();
    pushBooks();
    pushOrders();
    cout << "\n\t\tsave completed.\n\t\texit iFleaBooks successfully.\n"<<RESET;
}
