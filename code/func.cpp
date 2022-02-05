/** 
 * Func
 * @description 函数
 * @author YiNN 
 * @creat 2022-01-30 23:41:07 
 */

#include"iostream"
#include"header/data.h"
#include"header/data-user.h"
#include"header/data-admin.h"
#include"header/display-color.h"
#include"header/display.h"
using namespace std;
 
void buyBook();
void E();
void B_(string);
void b(string);
void B(string);
void G(string);
void G_(string);
void _G__(string);
void g_(string);
void g(string);

/** 用户登陆验证 **/
User *verifyU(string n,string pass){
    User *u=NULL;
    for (auto b = v_users.begin(); b != v_users.end();b++)
    {
        u = b->veri(n, pass);
        if(u) break;
    }
    return u;
}

/** 管理员登陆验证 **/
Admin *verifyA(string id,string pass){
    Admin *u=NULL;
    for (auto b = v_admins.begin(); b != v_admins.end();b++)
    {
        u = b->veri(id, pass);
        if(u) break;
    }
    return u;
}

/** 判断是否重名，不重名返回真 **/
bool ifDiffNameU(string n){
    bool flag=1;
    for (auto b = v_users.begin(); b != v_users.end(); b++)
    {
        if(!b->ifDiffN(n)) {
            flag = 0;
            break;
        }
    }
    if(flag)
        return 1;
    else
        return 0;
}

/** 打印所有书信息 **/
void allBooksA(){
    for (auto b = v_books.begin(); b != v_books.end();b++)
        b->print_a();
}
void allBooksU(){
    for (auto b = v_books.begin(); b != v_books.end();b++)
        if(b->ifSelling()) b->print_u();
}

/** 搜索书信息 **/
void searchBookA(){
    string str;
    cin >> str;
    bool flag=0;
    for (auto b = v_books.begin(); b != v_books.end(); b++)
        if (b->searchName(str)){
            flag = 1;
            break;
        }
    if(flag){
        E();
        g_("here are the results:");
        g_("────────────────────────────────────────────────────────────────");
        g_("ID\tname\t\tprice\tdate\t\tsellerID statu");
        for (auto b = v_books.begin(); b != v_books.end();b++)
             if(b->searchName(str)) b->print_a();
        E();
        g_("────────────────────────────────────────────────────────────────");
        b("press any key to go back");
}
    else{
        B_("there's no result");
        B("press any key to go back");
    }
}


/** 管理员下架书 **/
void removeBookA(string str){
    bool flag=0;
    for (auto b = v_books.begin(); b != v_books.end(); b++)
        if(b->searchId(str)) {
            flag = 1;
            b->remove();
            B_("removal completed");
            break;
        }
        if(!flag)
            B_("this book doesn't exist.removal failed.");
}

/** 管理员打印所有订单信息 **/
void allOrdersA(){
    for (auto b = v_orders.begin(); b != v_orders.end();b++)
        b->print();
}

/** 管理员打印所有用户信息 **/
void allUsersA(){
    for (auto b = v_users.begin(); b != v_users.end();b++)
        b->print_u();
}

/** 用户的订单 **/
void ordersBoughtU(){
    bool flag = 0;
    for (auto b = v_orders.begin(); b != v_orders.end(); b++)
        if(p_User->getId()==b->getBuyer()) {
            flag = 1;
            break;
        }
    if(flag){
        E();
        G_("────────────────────────────────────────────────");
        G_("orderID\tbookID\tprice\tdate\t\tsellerID");
        for (auto b = v_orders.begin(); b != v_orders.end();b++)
            if(p_User->getId()==b->getBuyer()) cout<<"\t",b->printS();
        E();
        G_("────────────────────────────────────────────────");
    }
    else
        cout<<endl<<F_DARKGREEN<<"\t\tno order\n"<<RESET;
}
void ordersSoldU(){
    bool flag = 0;
    for (auto b = v_orders.begin(); b != v_orders.end(); b++)
        if(p_User->getId()==b->getSeller()) {
            flag = 1;
            break;
        }
    if(flag){
        E();
        G_("────────────────────────────────────────────────");
        G_("orderID\tbookID\tprice\tdate\t\tsellerID");
        for (auto b = v_orders.begin(); b != v_orders.end();b++)
            if(p_User->getId()==b->getSeller()) cout<<"\t",b->printS();
        E();
        G_("────────────────────────────────────────────────");
    }
    else
        cout<<endl<<F_DARKGREEN<<"\t\tno order\n"<<RESET;
}

void searchBookU(){
    string str;
    cin >> str;
    bool flag=0;
    for (auto b = v_books.begin(); b != v_books.end(); b++)
        if (b->searchName(str)&&b->ifSelling()){
            flag = 1;
            break;
        }
    if(flag){
        E();
        G_("here are the results:");
        G_("────────────────────────────────────────────────");
        G_("ID\tname\t\tprice\t\tseller");
        for (auto b = v_books.begin(); b != v_books.end();b++)
             if(b->searchName(str)&&b->ifSelling()) b->print_u();
        E();
        G_("────────────────────────────────────────────────");
    goo:
        B("enter bookID for details (or enter 0 to go back): \n");
        B("");
        string s;
        cin >> s;
        if (s.length() !=6)
            pBuyMenu();
        else
            pDetail(s);
}
    else{
        B_("there's no result");
        B("press any key to go back");
    }
}

/* 查看书详细信息 */
void detail(string str){
retry1:
    bool flag=0;
    auto b = v_books.begin();
    for (; b != v_books.end(); b++)
        if (b->searchId(str)&&b->selling()){
            flag = 1;
            p_Book = b->getBook(str);
            break;
        }
    if(flag){
        E();
        G_("───────────────────────────────────────────────");
        for (auto b = v_books.begin(); b != v_books.end();b++)
             if(b->searchId(str)&&b->selling()){
                b->printDetails();
                break;
             }
        G_("-----------------------------------------------");
        B_("1.buy this book       2.go back");
        G_("───────────────────────────────────────────────");
        B("please choose operation: ");
    }
    else{
        B("no result, please retry:");
        cin >> str;
        goto retry1;
    }
retry:
    int num;
    cin >> num;
    while(cin.fail()||(num<1||num>2)){
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
            G("are you sure to buy this book? [y/n]: ");
            char ch;
            cin >> ch;
            if(ch=='y'){
                if(p_User->getId()==b->getSeller()){
                    B("you can't buy your own book");
                    cin.get();
                    cin.get();
                    pBookMall();
                }
                buyBook();
            }
            else{
                B("enter 1 to buy, or enter 0 to go back: ");
                goto retry;
            }
            break;
        case 2:
            G("are you sure to go back? [y/n]: ");
            char c;
            cin >> c;
            if(c=='y'){
                pBuyMenu();
            }
            else{
                B("please choose operation: ");
                goto retry;
            }
            break;
    }    
}

/* buy book */
void buyBook(){
    if(p_User->getBalance()>=p_Book->getPrice()){
        Order neworder(p_Book, p_User);
        v_orders.push_back(neworder);
        p_Book->buy();
        float f = p_Book->getPrice();
        for (auto b = v_users.begin(); b != v_users.end(); b++)
            if(b->getId()==p_Book->getSeller())
                b->sell(f);
        p_User->buy(f);
        B("purchase succeed!press any key to go back");
        cin.get();
        pBuyMenu();
    }
    else{
        B_("your balance is not enough");
        B("please go to info & top-up to top-up.");
        cin.get();
        cin.get();
        pMainMenu_u();
    }
}

/* 我发布的书 */
void sellBooksU(){
    bool flag = 0;
    for (auto b = v_books.begin(); b != v_books.end();b++)
        if(p_User->getId()==b->getSeller()){
            flag = 1;
            break;
        }
    if(flag){
        E();
        G_("───────────────────────────────────────────────────────");
        G_("ID\tname\t\tprice\tdate\t\tstatu");
        for (auto b = v_books.begin(); b != v_books.end();b++)
        if(p_User->getId()==b->getSeller())
            b->print_seller();
        G_("-------------------------------------------------------");
        B_("1.revise my release         2.remove my release");
        B_("3.go back");
        G_("───────────────────────────────────────────────────────");
        B("please choose operation: ");
    }
    else
        cout<<endl<<F_DARKGREEN<<"\t\toops, no book there\n"<<RESET;
}

/** 由id_book获取指向book类对象的指针 **/
void getBook(string id){
    for (auto b = v_books.begin(); b != v_books.end();b++)
        if(id==b->getId()){
            p_Book = b->getBook(id);
            break;
        }
}