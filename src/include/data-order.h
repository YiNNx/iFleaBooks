/** 
 * Data-Order 
 * @description 订单类
 * @author YiNN 
 * @creat 2022-01-29 23:41:35 
 */

#pragma once
#include"iostream"
#include"fstream"
#include"data-book.h"
#include"data-user.h"
using namespace std;

/** 订单类 **/
class Order{

    string id_order;
    string id_book;
    float price;
    string time;
    string id_seller;
    string id_buyer;

public:
    Order(){
    }

    Order(Book* pb,User* pu);
    //构造函数，书id 初始化对象

    friend ifstream& operator>>(ifstream& x,Order &y){
        x >> y.id_order 
          >> y.id_book
          >> y.price
          >> y.time
          >> y.id_seller
          >> y.id_buyer;
        return x;
    }

    friend ofstream& operator<<(ofstream& x,Order &y){
        x << y.id_order << "\t"
          << y.id_book << "\t"
          << y.price << "\t"
          << y.time << "\t"
          << y.id_seller << "\t"
          << y.id_buyer << endl;
        return x;
    }

    Order* getOrder(string id_o){
        if(id_o==id_order)
            return this;
        else
            return NULL;
    }

    string getBuyer(){
        return id_buyer;
    }

    string getSeller(){
        return id_seller;
    }

    void print();
    //查看订单：订单id-商品id-价格-交易时间-卖家id-买家id

    void printS(){
        cout << "\t"<<id_order << "\t"
         << id_book<< "\t"
         << price << "\t"
         << time << "\t"
         << id_buyer << "\n";
    }
};

/** 由id_order获取指向order类对象的指针 **/
Order *v_GetOrder(string id);