/** 
 * Main 
 * @description 程序运行主函数
 * @author YiNN 
 * @creat 2022-01-29 14:43:13 
 */

#include"header/display.h"
#include"header/file.h"

int main(){
    pullFile();
    display();
    pushFile();
    return 0;
}