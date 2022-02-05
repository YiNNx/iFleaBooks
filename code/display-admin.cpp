/** 
 * Display-Admin 
 * @description 显示界面-管理员
 * @author YiNN 
 * @creat 2022-02-01 22:58:24 
 */

#include<iostream>
#include"header/func.h"
#include"header/data.h"
#include"header/display.h"
#include"header/display-color.h"
using namespace std;

/************** 管理员 *******************/

/** 主菜单 **/
void pMainMenu_a(){
    cout << F_DARKGREEN
         << "\n\t\t┌──────────────────────────────────────────────┐"
         << "\n\t\t│   ---- manage users,books and orders -----   │"
         << "\n\t\t│   " << RESET << "  1.view all books   2.search book      " << F_DARKGREEN << "   │"
         << "\n\t\t│   " << RESET << "  3.remove book      4.view all orders  " << F_DARKGREEN << "   │"
         << "\n\t\t│   " << RESET << "  5.view all users   6.log out          " << F_DARKGREEN << "   │"
         << "\n\t\t│   ----------------------------------------   │"
         << "\n\t\t└──────────────────────────────────────────────┘"
         <<"\n\n\t\tplease choose operation: "<<RESET;
    int num;
    cin >> num;
    while(cin.fail()||(num<1||num>6)){
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
            pAllBooks_a();
            break;
        case 2:
            pSearchBook_a();
            break;
        case 3:
            pRemoveBooks_a();
            break;
        case 4:
            pAllOrders_a();
            break;
        case 5:
            pAllUsers_a();
            break;
        case 6:
            pLogOut_a();
            break;
    }    
}

/** 查看全部书 **/
void pAllBooks_a(){
    E();
    g_("────────────────────────────────────────────────────────────────");
    g_("ID\tname\t\tprice\tdate\t\tsellerID statu");
    allBooksA();
    E();
    g_("────────────────────────────────────────────────────────────────");
    b("press any key to go back");
    getchar();
    getchar();
    E();
    pMainMenu_a();
}

/** 搜索书 **/
void pSearchBook_a(){
    G("please choose operation keyword: ");
    searchBookA();
    getchar();
    getchar();
    pMainMenu_a();
}

/** 下架书 **/
void pRemoveBooks_a(){
    G("please choose operation ID of the book you wanna remove: ");
    string str;
    cin >> str;
    removeBookA(str);
    B("press any key to go back");
    getchar();
    getchar();
    E();
    pMainMenu_a();
}

/** 查看全部订单 **/
void pAllOrders_a(){
    g_("────────────────────────────────────────────────────────────────");
    g_("orderID\tbookID\tprice\tdate\t\tbuyerID\tsellerID");
    allOrdersA();
    E();
    g_("────────────────────────────────────────────────────────────────");
    b("press any key to go back");
    getchar();
    getchar();
    E();
    pMainMenu_a();
}

/** 查看全部用户账号 **/
void pAllUsers_a(){
    g_("────────────────────────────────────────────────────────────────");
    g_("userID\tname\ttelephone\taddress\t\tbalance");
    allUsersA();
    E();
    g_("────────────────────────────────────────────────────────────────");
    b("press any key to go back");
    getchar();
    getchar();
    E();
    pMainMenu_a();
}

/** 退出登陆 **/
void pLogOut_a(){
    G("are you sure to log out? [y/n]: ");
    char ch;
    cin >> ch;
    if(ch=='y'){
        pSlogan();
        pMenu();
    }     
    else
        pMainMenu_a();
}
