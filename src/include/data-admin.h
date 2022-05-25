/** 
 * Data-Admin
 * @description 管理员类
 * @author YiNN 
 * @creat 2022-01-29 15:09:59 
 */

#pragma once
#include"iostream"
#include"fstream"
using namespace std;

/** 管理员类 **/
class Admin{
    string id;
    string pass;
public:

    friend ifstream& operator>> (ifstream& x,Admin &y){
        x >> y.id
          >> y.pass;
        return x;
    }

    friend ofstream& operator<< (ofstream& x,Admin &y){
        x << y.id << "\t"
          << y.pass << endl;
        return x;
    }

    Admin* veri(string n,string p){
        if(n==id&&p==pass)
            return this;
        else
            return NULL;
    }
    
};
