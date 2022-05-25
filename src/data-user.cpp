/** 
 * Data-User 
 * @description 用户类
 * @author YiNN 
 * @creat 2022-01-30 00:45:46 
 */

#include"header/data-user.h"
#include"header/func-info.h"
#include"header/data.h"

/** 用户类构造函数 **/
User::User(string n,string pa,string ph,string a){
    id_user = userId();
    name = n;
    pass = pa;
    phone = ph;
    address = a;
    balance = 0;
}

/** 打印用户信息函数（admin） **/
void User::print_u(){
    cout <<"\t"<< id_user << "\t"
         << name << "\t"
         << phone << "\t"
         << address<<"\t"
         << balance <<endl;
}

/* 个人中心 */
void User::myInfo(){
    G("ID: "), cout << id_user << endl;
    G("name: "), cout << name<<endl;
    G("tele: "), cout << phone<<endl;
    G("address: "), cout << address<<endl;
    G("balance: "), cout << balance<<endl;
}


/* 充值 */
void User::topup(float b){
    balance += b;
    B("top-up succeed!");
}