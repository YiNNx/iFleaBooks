/** 
 * Data-Order 
 * @description 订单类
 * @author YiNN 
 * @creat 2022-01-29 23:42:40 
 */


#include"header/data-order.h"
#include"header/func-info.h"

/** 订单类构造函数 **/
Order::Order(Book* pb,User* pu){
    id_order = orderId();
    id_book = pb->id_book;
    price = pb->price;
    time = date();
    id_seller = pb->id_seller;
    id_buyer = pu->id_user;
}

/** 查看订单 **/
void Order::print(){
    cout << "\t"<<id_order << "\t"
         << id_book<< "\t"
         << price << "\t"
         << time << "\t"
         << id_seller << "\t"
         << id_buyer << "\n";
}
