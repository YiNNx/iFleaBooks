/** 
 * Data-Book 书类
 * @description 
 * @author YiNN 
 * @creat 2022-01-29 16:42:48 
 */

#include"header/data-book.h"
#include"header/func-info.h"
#include"header/data.h"

/** 书类 **/

/** 书类的构造函数 **/
Book::Book(string n, float p,string d){
    id_book = bookId();
    name = n;
    price = p;
    describe = d;
    time = date();
    id_seller = p_User->getId();
    name_seller = p_User->getName();
    statu = "selling";
}

/** 打印书信息函数（admin） **/
void Book::print_a(){
    cout <<"\t"<< id_book << "\t"
        << name << "\t"
        << price << "\t"
        << time << "\t"
        << id_seller << "\t"
        << statu << endl;
}

/** search **/
bool Book::searchName(string str){
    if(name.find(str)!=name.npos)
        return 1;
    else
        return 0;
}

bool Book::searchId(string str){
    if(str==id_book)
        return 1;
    else
        return 0;
}

bool Book::selling(){
    if(statu=="selling")
        return 1;
    else
        return 0;
}

/** 打印书信息函数（user） **/
void Book::print_u(){
    cout <<"\t\t"<< id_book << "\t"
         << name << "\t"
         << price << "\t\t"
         << name_seller <<endl;
}
void Book::print_seller(){
    cout <<"\t\t"<< id_book << "\t"
         << name << "\t"
         << price << "\t"
         << time << "\t"
         << statu <<endl;    
}
    
/** 更改函数 **/
void Book::edit_P(float p){
    price = p;
}
void Book::edit_N(string n){
    name = n;
}
void Book::edit_D(string d){
    describe = d;
}

/* 书的详细信息 */
void Book::printDetails(){
    G_("\t\t  book details");
    G("bookID: "), cout << id_book << "\n";
    G("name: "), cout << name <<"\n";
    G("price: "), cout << price<<"\n";
    G("describe: "), cout << describe<<"\n";
    G("sellerID: "), cout << id_seller<<"\n";
    G("seller name: "), cout << name_seller<<"\n";
    G("date: "), cout << time<<"\n";
}