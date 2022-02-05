/** 
 * Display 
 * @description 显示界面
 * @author YiNN 
 * @creat 2022-01-29 14:42:45 
 */

#include<iostream>
#include"header/func.h"
#include"header/data.h"
#include"header/display.h"
#include"header/display-color.h"
using namespace std;

/** 指向当前用户的类对象的指针 **/
User *p_User=NULL;
Book *p_Book = NULL;
Admin *p_Admin = NULL;

/**自定义输入函数**/
void B(string str){
    cout << "\a\t\t" << str ;
}
void b(string str){
    cout << "\a\t" << str ;
}
void B_(string str){
    cout << "\a\t\t" << str << "\n";
}
void G(string str){
    cout << F_DARKGREEN
         << "\t\t" << str
         << RESET;
}
void G_(string str){
    cout << F_DARKGREEN
         << "\t\t" << str << "\n"
         << RESET;
}
void g_(string str){
    cout << F_DARKGREEN
         << "\t" << str << "\n"
         << RESET;
}
void g(string str){
    cout << F_DARKGREEN
         << "\t" << str 
         << RESET;
}
void _G__(string str){
    cout << F_DARKGREEN
         << "\n\t\t" << str << "\n\n"
         << RESET;
}
void GY(string str){
    cout << F_GREY
         << "\t\t" << str
         << RESET;
}
void E(){
    cout << endl;
}

/** 主要函数 **/
int display(){
    pSlogan();
    pMenu();
    return 0;
}

/** 欢迎界面 **/
void pSlogan(){
    cout << "\a"
         << "\n\t\twelcome to" << F_DARKGREEN << " iFleaBooks" << RESET
         << "\n\t\tnow start your second-hand books sale journey!"
         << endl
         << F_DARKGREEN
         << "\n\t\t         ──────────────────────────────"
         << "\n\t\t          ╦╔═╗╦  ╔═╗╔═╗┌┐ ┌─┐┌─┐┬┌─┌─┐"
         << "\n\t\t          ║╠╣ ║  ║╣ ╠═╣├┴┐│ ││ │├┴┐└─┐"
         << "\n\t\t          ╩╚  ╩═╝╚═╝╩ ╩└─┘└─┘└─┘┴ ┴└─┘"
         << "\n\t\t         ──────────────────────────────"
         << endl
         << RESET;
}

void pMenu(){
    cout << "\n\t\t------------- 1.log in as a user -------------- "
         << "\n\t\t------------- 2.log in as an admin ------------ "
         << "\n\t\t------------- 3.start an account -------------- "
         << "\n\t\t------------- 4.exit -------------------------- "
         << F_DARKGREEN
         << "\n\n\t\tplease choose operation: "
         << RESET;
    int num;
    cin >> num;
    while(cin.fail()||(num<1||num>4)){
        cerr <<F_DARKGREEN
             << "\t\tsorry\n\t\twrong command,please retry: "
             <<RESET;
        cin.clear();
        cin.ignore();
        cin >> num;
        cout << "\n";
    }
    switch (num)
    {
        case 1:
            B_("welcome!");
            pLoginUser();
            break;
        case 2:
            pLoginAdmin();
            break;
        case 3:
            pSignup();
            break;
        case 4:
            pExit();
            break;
    }    
}


/** 用户登陆界面 **/
void pLoginUser(){
    bool flag=0;
    do{
        string inName,inPass;
        G("username: \n");
        G("password: ");
        cout << UPLINE;
        cin >> inName;
        G("password: ");
        cin >> inPass;
        p_User = verifyU(inName, inPass);
        if (p_User)
        {
            flag = 1;
            B_("log-in succeed!");
        }
        else{
            B_("wrong password,please retry.");
        }
    } while (!flag);
    if(flag)
        pMainMenu_u();
}

/** 管理员登陆界面 **/
void pLoginAdmin(){
    bool flag=0;
    do{
        string inName,inPass;
        G("adminID: \n");
        G("password: ");
        cout << UPLINE;
        cin >> inName;
        G("password: ");
        cin >> inPass;
        p_Admin = verifyA(inName, inPass);
        if (p_Admin)
        {
            flag = 1;
            B_("log-in succeed!");
        }
        else{
            B_("wrong password,please retry.");
        }
    } while (!flag);
    if(flag)
        pMainMenu_a();
}

/** 注册界面 **/
void pSignup(){
    string inName,inPass,inPh,inA;
    bool flag=0;
    B("please fill in the info to create an account.");
    cin.get();
    cin.get();
    cout << endl;
    do
    {
        G("your username:\n");
        G("set password:\n");
        G("your phone number:\n");
        G("your address:      ");
        cout << UPLINE<< UPLINE<< UPLINE;
        cin >> inName;
        G("set password:\n");
        G("your phone number:\n");
        G("your address:      ");
        cout << UPLINE<< UPLINE;
        cin >> inPass;
        G("your phone number:\n");
        G("your address:      ");
        cout << UPLINE;
        cin >> inPh;
        G("your address:      ");
        cin >> inA;
        if(ifDiffNameU(inName)){
            User newUser(inName, inPass, inPh, inA);
            v_users.push_back(newUser);
            cout << endl;
            B_("account creating comleted.");
            B_("now you can use your new account to log in!");
            cout << endl;
            pLoginUser();
            flag = 1;
        }
        else
            B_("duplicate name,please change one.");
    } while (!flag);
}

/** 退出程序界面 **/
void pExit(){
    G("are you sure to exit? [y/n]: ");
    char ch;
    cin >> ch;
    if(ch=='y')
        ;
    else
        pMenu();
}
