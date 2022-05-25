/** 
 * Info 
 * @description 生成书id/用户id/订单id
 *              生成当前日期
 * @author YiNN 
 * @creat 2022-01-29 21:37:03 
 */

#include"iostream"
#include"sstream"
#include"header/data.h"
using namespace std;

/** 书id的生成函数 **/
string bookId() {
    countB++;
    string id_book = "B";
    string numStr;
    stringstream sstr;
    sstr << countB;
    numStr = sstr.str();
    for (int i = 0; i < 5 - numStr.length(); i++)
        id_book += '0';
    id_book += numStr;
    return id_book;
}

/** 用户id的生成函数 **/
string userId(){
    countU++;
    string id_user = "U";
    string numStr;
    stringstream sstr;
    sstr << countU;
    numStr = sstr.str();
    for (int i = 0; i < 5 - numStr.length(); i++)
        id_user += '0';
    id_user += numStr;
    return id_user;
}

/** 订单id的生成函数 **/
string orderId(){
    countO++;
    string id_order = "T";
    string numStr;
    stringstream sstr;
    sstr << countO;
    numStr = sstr.str();
    for (int i = 0; i < 5 - numStr.length(); i++)
        id_order += '0';
    id_order += numStr;
    return id_order;
}

/** 当前日期的生成函数 **/
string date() {
    time_t t = time(NULL);
    char date[12] = { 0 };
    strftime(date, sizeof(date) - 1, "%Y-%02m-%02d", localtime(&t));
    return date;
}