/** 
 * Data 
 * @description 各类数据结构的声明
 * @author YiNN 
 * @creat 2022-02-01 16:59:37 
 */

#pragma once

#include"data-order.h"
#include"data-admin.h"

#include "vector"
using namespace std;

void E();
void B_(string);
void B(string);
void b(string);
void G(string);
void G_(string);
void _G__(string);
void g_(string);
void g(string);

/** vector声明 **/
extern vector<User> v_users;
extern vector<Admin> v_admins;
extern vector<Book> v_books;
extern vector<Order> v_orders;

/** 指向当前用户的类对象的指针 **/
extern User *p_User;
extern Admin *p_Admin;
extern Book *p_Book;

/** 数量标记 **/
extern int countU;
extern int countB;
extern int countO;
