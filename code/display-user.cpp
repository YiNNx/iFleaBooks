/** 
 * Display-User 
 * @description 界面-用户
 * @author YiNN 
 * @creat 2022-02-01 23:00:22 
 */

#include<iostream>
#include"header/func.h"
#include"header/data.h"
#include"header/display.h"
#include"header/display-color.h"
using namespace std;

/**************** 用户 *****************/

/** 主菜单 **/
void pMainMenu_u(){
    cout << F_DARKGREEN
         << "\n\t\t┌──────────────────────────────────────────────┐"
         << "\n\t\t│    have a nice day with good books :D        │"
         << "\n\t\t│   " << RESET << "   1.book-buying     2.book-selling     " << F_DARKGREEN << "   │"
         << "\n\t\t│   " << RESET << "   3.my orders       4.info & top-up    " << F_DARKGREEN << "   │"
         << "\n\t\t│   " << RESET << "   5.log out                            " << F_DARKGREEN << "   │"
         << "\n\t\t│   ----------------------------------------   │"
         << "\n\t\t└──────────────────────────────────────────────┘"
         << "\n\n\t\tplease choose operation: "<<RESET;
    int num;
    cin >> num;
    while(cin.fail()||(num<1||num>5)){
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
            pBuyMenu();
            break;
        case 2:
            pSellMenu();
            break;
        case 3:
            E();
            pOrderMenu();
            break;
        case 4:
            pMyMenu();
            break;
        case 5:
            pLogOut_u();
            break;
    }    
}

/*#### 买书菜单 ####*/
void pBuyMenu(){
    cout << F_DARKGREEN
         << "\n\t\t┌──────────────────────────────────────────────┐"
         << "\n\t\t│   --- book-buying ------------------------   │"
         << "\n\t\t│   " << RESET << "   1.book mall       2.searching        " << F_DARKGREEN << "   │"
         << "\n\t\t│   " << RESET << "   3.my orders       4.go back          " << F_DARKGREEN << "   │"
         << "\n\t\t│   ----------------------------------------   │"
         << "\n\t\t└──────────────────────────────────────────────┘"
         << "\n\n\t\tplease choose operation: "<<RESET;
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
            pBookMall();
            break;
        case 2:
            pSearchBook();
            break;
        case 3:
            E();
            pOrdersB();
            break;
        case 4:
            pMainMenu_u();
            break;
    }    
}

/* 逛逛书库 */
void pBookMall(){
    E();
    G_("────────────────────────────────────────────────");
    G_("ID\tname\t\tprice\t\tseller");
    allBooksU();
    E();
    G_("────────────────────────────────────────────────");
goo:
    B_("enter bookID for details (or enter 0 to go back): ");
    B("");
    string s;
    cin >> s;
    if (s.length() !=6)
            pBuyMenu();
    else
        pDetail(s);
}

/* 搜索书名 */
void pSearchBook(){
    G("please choose operation keyword: ");
    searchBookU();
    getchar();
    getchar();
    pBuyMenu();
}

/* 查看书的详细信息 */
void pDetail(string s){
    detail(s);


}

/* 查看已买订单 */
void pOrdersB(){
    pOrdersBought();
    B("press any key to go back");
    getchar();
    getchar();
    E();
    pBuyMenu();
}


/*#### 卖书菜单 ####*/
void pSellMenu(){
    cout << F_DARKGREEN
         << "\n\t\t┌──────────────────────────────────────────────┐"
         << "\n\t\t│   --- book-selling -----------------------   │"
         << "\n\t\t│   " << RESET << "   1.release book    2.my releases      " << F_DARKGREEN << "   │"
         << "\n\t\t│   " << RESET << "   3.my orders       4.go back          " << F_DARKGREEN << "   │"
         << "\n\t\t│   ----------------------------------------   │"
         << "\n\t\t└──────────────────────────────────────────────┘"
         << "\n\n\t\tplease choose operation: " << RESET;
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
            pRelease();
            break;
        case 2:
            pViewRelease();
            break;
        case 3:
            pOrdersS();
            break;
        case 4:
            pMainMenu_u();
            break;
    }    
}

/* 发布闲置书 */
void pRelease(){
    E();
    B_("let's sell our old books to give them more value!");
    B("please fill in the info to release your book");
    cin.get();
    cin.get();
    string n, d;
    float p;
    G("book name:\n");
    G("price:\n");
    G("describe:  ");
    cout << UPLINE<< UPLINE;
    cin >> n;
    G("price:\n");
    G("describe:  ");
    cout << UPLINE;
    cin >> p;
    G("describe:  ");
    cin.get();
    getline(cin, d);
    Book newbook(n, p, d);
    v_books.push_back(newbook);
    B_("succeed!");
    B("press Enter to check the books you released");
    cin.get();
    pViewRelease();
}

/* 查看发布 */
void pViewRelease(){
    sellBooksU();
    int num;
    cin >> num;
    while(cin.fail()||(num<1||num>3)){
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
            pReviseRelease();
            break;
        case 2:
            pRemoveRelease();
            break;
        case 3:
            pSellMenu();
        }
}

/* 修改发布 */
void pReviseRelease(){
    G("please choose operation ID of the book you wanna revise: ");
retry:
    string id,r;
    float f;
    cin >> id;
    getBook(id);
    if (id ==p_Book->getSeller()){
        B_("1.revise the name");
        B_("2.revise the price");
        B_("3.revise the describe");
        G("please choose operation: ");
        int num;
        cin >> num;
        while(cin.fail()||(num<1||num>3)){
            cerr <<F_DARKGREEN
                << "\t\tsorry\n\t\twrong command,please retry: "
                <<RESET;
            cin.clear(),cin.ignore();
            cin >> num;
            cout << "\n";
        }
        switch (num)
        {
            case 1:
                G("input the new name: ");
                cin >> r;
                p_Book->edit_N(r);
                cout<<"press any key to refresh";
                getchar();
                getchar();
                E();
                pViewRelease();
                break;
            case 2:
                G("input the revised price: ");
                cin >> f;
                p_Book->edit_P(f);
                cout<<"press any key to refresh";
                getchar();
                getchar();
                E();
                pViewRelease();
                break;
            case 3:
                G("input the new describe: ");
                cin >> r;
                p_Book->edit_D(r);
                cout<<"press any key to refresh";
                getchar();
                getchar();
                E();
                pViewRelease();
                break;
        }
    }
    else{
        B("input error,please retry:");
        goto retry;
    }
}

/* 下架发布 */
void pRemoveRelease(){
    G("please choose operation ID of the book you wanna remove: ");
    string str;
    cin >> str;
    removeBookA(str);
    B("press any key to go back");
    getchar();
    getchar();
    E();
    pSellMenu();
}

/* 查看卖出订单 */
void pOrdersS(){
    pOrdersSold();
    B("press any key to go back");
    getchar();
    getchar();
    E();
    pSellMenu();
}

/*#### 订单菜单 ####*/
void pOrderMenu(){
    pOrdersBought();
    pOrdersSold();
    B("press any key to go back");
    getchar();
    getchar();
    E();
    pMainMenu_u();
}

/* 查看已买订单 */
void pOrdersBought(){
    cout << "\t\torders I bought: ";
    ordersBoughtU();
    }

/* 查看卖出订单 */
void pOrdersSold(){
    cout << "\t\torders I sold: ";
    ordersSoldU();
}

/*#### 个人中心菜单 ####*/
void pMyMenu(){
    E();
    G_("────────────────────────────────────────────────");
    G_("                 my information                 ");
    p_User->myInfo();
    G_("------------------------------------------------");
    B_("1.top-up");
    B_("2.revise my name");
    B_("3.revise my tele");
    B_("4.revise my address");
    B_("5.revise my password");
    B_("6.go back");
    E(),E(),E(),E();
    G_("────────────────────────────────────────────────");
    cout << UPLINE << UPLINE<< UPLINE << UPLINE<< UPLINE;
    G("please choose operation: ");
    int num;
    cin >> num;
    while(cin.fail()||(num<1||num>6)){
        cerr <<F_DARKGREEN
             << "\t\tsorry\n\t\twrong command,please retry: "
             <<RESET;
        cin.clear(),cin.ignore();
        cin >> num;
        cout << "\n";
        
    }
    float mon;
    string s;
    switch (num)
    {
        case 1:
            G("top-up amount: ");
            cin >> mon;
            p_User->topup(mon);
            cout<<"press any key to refresh";
            getchar();
            getchar();
            E();
            pMyMenu();
            break;
        case 2:
            G("input your new name: ");
            cin >> s;
            p_User->reviseName(s);
            cout<<"press any key to refresh";
            getchar();
            getchar();
            E();
            pMyMenu();
            break;
        case 3:
            G("input your new tele: ");
            cin >> s;
            p_User->reviseTele(s);
            cout<<"press any key to refresh";
            getchar();
            getchar();
            E();
            pMyMenu();
            break;
        case 4:
            G("input your new address: ");
            cin >> s;
            p_User->reviseAddress(s);
            cout<<"press any key to refresh";
            getchar();
            getchar();
            E();
            pMyMenu();
            break;
        case 5:
            G("input your new password: ");
            cin >> s;
            p_User->revisePass(s);
            cout<<"press any key to refresh";
            getchar();
            getchar();
            E();
            pMyMenu();
            break;
        case 6:
            pMainMenu_u();
            break;
        }
}

/*#### 退出登陆 ####*/
void pLogOut_u(){
    G("are you sure to log out? [y/n]: ");
    char ch;
    cin >> ch;
    if(ch=='y'){
        pSlogan();
        pMenu();
    }     
    else
        pMainMenu_u();
}