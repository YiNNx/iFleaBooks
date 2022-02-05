/** 
 * Data-Book 
 * @description 书类&书的vector数组
 * @author YiNN 
 * @creat 2022-01-29 16:39:59 
 */

#pragma once
#include"fstream"
#include"iostream"
using namespace std;

/** 书类 **/
class Book{

    string id_book;
    string name;
    float price;
    string describe;
    string time;
    string id_seller;
    string name_seller;
    string statu;

public:

    Book(){}

    /* 构造函数，书名-价格-详情 初始化书对象 */
    Book(string n, float p,string d);
    
    friend class Order;

    friend ifstream& operator>> (ifstream& x,Book &y){
        x >> y.id_book 
          >> y.name
          >> y.price
          >> y.describe
          >> y.id_seller
          >> y.name_seller
          >> y.time
          >> y.statu;
        return x;
    }

    friend ofstream& operator<< (ofstream& x,Book &y){
        x << y.id_book << "\t"
          << y.name << "\t"
          << y.price << "\t"
          << y.describe << "\t"
          << y.id_seller << "\t"
          << y.name_seller << "\t"
          << y.time << "\t"
          << y.statu << endl;
        return x;
    }

    Book* getBook(string id_b){
        if(id_b==id_book||id_b==id_seller)
            return this;
        else
            return NULL;
    }

    string getSeller(){
        return id_seller;
    }

    string getId(){
        return id_book;
    }

    float getPrice(){
        return price;
    }

    /* 管理员打印书信息：id-名称-价格-上架时间-卖家id-状态 */
    void print_a();

    /* search */
    bool searchName(string);
    bool searchId(string);
    bool selling();

    /* 下架书，状态改为removed */
    void remove(){
        statu = "removed";
    } 

    /* 书被买入，状态改为sold */
    void buy(){
        statu = "sold";
    } 

    /* 买家打印书信息（仅selling）：id-名称-价格-上架时间-卖家id */
    void print_u();
    void print_seller();

    /* 卖家更改价格 */
    void edit_P(float p);

    /* 卖家更改描述 */
    void edit_D(string d);
    void edit_N(string n);

    /* 判断书是否selling */
    bool ifSelling(){
        if(statu=="selling")
            return 1;
        else
            return 0;
    }

    /* 书的详细信息 */
    void printDetails();
};
