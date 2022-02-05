/** 
 * Func-User 
 * @description 函数
 * @author YiNN 
 * @creat 2022-01-30 22:25:41 
 */

#pragma once

#include"data.h"

/** 用户登陆验证 **/
User *verifyU(string name,string pass);

/** 管理员登陆验证 **/
Admin *verifyA(string id,string pass);

/** 由id_book获取指向book类对象的指针 **/
void getBook(string id);

/** 判断是否重名，不重名返回真 **/
bool ifDiffNameU(string n);

/** 打印所有书信息 **/
void allBooksA();
void allBooksU();

/** 搜索书信息 **/
void searchBookA();
void searchBookU();

/** 管理员下架书 **/
void removeBookA(string str);

/** 管理员打印所有订单信息 **/
void allOrdersA();

/** 管理员打印所有用户信息 **/
void allUsersA();

/** 用户的订单 **/
void ordersBoughtU();
void ordersSoldU();

/* 查看书详细信息 */
void detail(string);

/* buy book */
void buyBook();

/* 我发布的书 */
void sellBooksU();