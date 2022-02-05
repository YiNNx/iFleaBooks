/** 
 * Data-User 
 * @description 用户类
 * @author YiNN 
 * @creat 2022-01-30 00:45:06 
 */

#pragma once
#include"iostream"
#include"fstream"
using namespace std;
void B(string);

/** 用户类 **/
class User{

    string id_user;
    string name;
    string pass;
    string phone;
    string address;
    float balance;

public:
    friend class Order;

    friend ifstream& operator>>(ifstream& x,User &y){
        x >> y.id_user 
          >> y.name
          >> y.pass
          >> y.phone
          >> y.address
          >> y.balance;
        return x;
    }

    friend ofstream& operator<<(ofstream& x,User &y){
        x << y.id_user << "\t"
          << y.name << "\t"
          << y.pass << "\t"
          << y.phone << "\t"
          << y.address << "\t"
          << y.balance << endl;
        return x;
    }

    User()
    {
    }

    User(string n,string pa,string ph,string a);
    //注册，用户名-密码-手机号-收货地址 初始化书对象
    //修改信息

    User* getUser(string id_u){
        if(id_u==id_user)
            return this;
        else
            return NULL;
    }

    string getId(){
        return id_user;
    }
    string getName(){
        return name;
    }
    float getBalance(){
        return balance;
    }

    /** 判断是否重名，不重名返回真 **/
    bool ifDiffN(string n){
        if(name!=n)
            return true;
        else
            return false;
    }

    /** 登录时匹配账户密码 **/
    User* veri(string n,string p){
        if(n==name&&p==pass)
            return this;
        else
            return NULL;
    }

    /* 管理员打印用户信息 */ 
    void print_u();

    /* 个人中心 */
    void myInfo();

    /* 充值 */
    void topup(float);

    /* 修改个人信息 */
    void reviseName(string s){
        name = s;
        B("name revision succeed!");
    }
    void reviseTele(string s){
        phone = s;
        B("tele revision succeed!");
    }
    void reviseAddress(string s){
        address = s;
        B("address revision succeed!");
    }
    void revisePass(string s){
        pass = s;
        B("password revision succeed!");
    }

    /* buy&sell book */
    void buy(float f){
        balance -= f;
    }
    void sell(float f){
        balance += f;
    }
};
