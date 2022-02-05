/** 
 * Display 
 * @description 显示界面
 * @author YiNN 
 * @creat 2022-01-29 14:41:45 
 */

#pragma once
#include"iostream"
using namespace std;

/** 主要函数 **/
int display();

/** 欢迎界面 **/
void pSlogan();
void pMenu();

/** 用户登陆界面 **/
void pLoginUser();

/** 管理员登陆界面 **/
void pLoginAdmin();

/** 注册界面 **/
void pSignup();

/** 退出程序界面 **/
void pExit();

/************** 管理员 *******************/

/** 主菜单 **/
void pMainMenu_a();

/** 查看全部书 **/
void pAllBooks_a();

/** 搜索书 **/
void pSearchBook_a();

/** 下架书 **/
void pRemoveBooks_a();

/** 查看全部订单 **/
void pAllOrders_a();

/** 查看全部用户账号 **/
void pAllUsers_a();

/** 退出登陆 **/
void pLogOut_a();

/**************** 用户 *****************/

/** 主菜单 **/
void pMainMenu_u();

/*#### 买书菜单 ####*/
void pBuyMenu();

/* 逛逛书库 */
void pBookMall();

/* 搜索书名 */
void pSearchBook();

/* 查看书的详细信息 */
void pDetail(string);


/* 查看已买订单 */
void pOrdersB();

/* 返回主界面 */

/*#### 卖书菜单 ####*/
void pSellMenu();

/* 发布闲置书 */
void pRelease();

/* 查看发布 */
void pViewRelease();

/* 修改发布 */
void pReviseRelease();

/* 下架发布 */
void pRemoveRelease();

/* 查看卖出订单 */
void pOrdersS();

/*#### 订单菜单 ####*/
void pOrderMenu();

/* 查看已买订单 */
void pOrdersBought();

/* 查看卖出订单 */
void pOrdersSold();

/*#### 个人中心菜单 ####*/
void pMyMenu();

/*#### 退出登陆 ####*/
void pLogOut_u();
