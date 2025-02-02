#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef int status;
#define MAXSIZE 100
#define ERROR 0
#define TRUE 1


//获取value“后缀规则”，移动距离
status GetValue(int **value,char *target){
    int i = 0,j = 0;
    char temp;
    int tarlen = strlen(target);
    (*value) = (int *)malloc(sizeof(int) *MAXSIZE);
    if(!(*value))return ERROR;

    for(i = 0; i < MAXSIZE; i++){  //初始化
        (*value)[i] = -1;    //-1代表后缀无匹配的字符
    }
    for(i = tarlen -1; i >0; i--){
        temp = target[i];

        if(i <tarlen -1) 
            (*value)[i] = (*value)[i+1];  //后一位赋值到前一位

        for(j = 0; j<i ;j++){
            if(target[j] ==temp){
                (*value)[i] = i - j;   //移动的距离
            }
        }
    }
    return TRUE;
}

//初始化字符串和搜索词
status InitData(char **source,char **target){

    char ch;
    int i =0;
    (*source) = (char *)malloc(sizeof(char) * MAXSIZE); //初始化
    (*target) = (char *)malloc(sizeof(char) * MAXSIZE); 
    if(!(*source) || !(*target))return ERROR;
    printf("请输入字符串以#结束:\n");
    while((ch=getchar())!='#'){
        (*source)[i++] = ch;
        (*source)[i] = '\0';
    }

    printf("请输入搜索词以#结束:\n");
    getchar();  //回车清除
    i = 0;

    while((ch =getchar())!='#'){
        (*target)[i++] = ch;
        (*target)[i] = '\0';
    }
    return TRUE;

}

//获取“坏字符”移动距离
int BadValue(char bad,char *target){
    int i =0;
    int badindex = -1;
    for(i = 0; i < strlen(target); i++){
        if(bad==target[i]){
            badindex = strlen(target) - 1 - i;
        }
    }
    return badindex;
}

//BM算法
status BM(char *source,char *target, int *value){

    int num = 0;
    int i = 0,j = 0, soulen = strlen(source),tarlen = strlen(target);  //初始化
    int badvalue = 0,distance = 0;
    if(soulen<tarlen){  //比较长度
        printf("字符串的长度小于搜索词的长度\n");
        return ERROR;
    }

    i = tarlen -1;j = tarlen -1; //从尾开始匹配

    while(i < soulen ){
        printf("%d\n",num );
        num++;
        if(source[i] == target[j]){  //字符匹配成功
            if(j ==0){
                printf("匹配成功\n");
                return TRUE;
            }

            i--;j--;
        }else{  //未匹配成功
            if(j == tarlen -1){  //如果尾字符未匹配成功，"坏字符规则"
                badvalue = BadValue(source[i],target);
                if(badvalue == -1)
                    badvalue = strlen(target);

                i =i+ tarlen - 1 - j + badvalue;
                j = tarlen -1;
            }else{  //有后缀,比较"坏字符规则"和"后缀规则"
                badvalue = BadValue(source[i],target);
                if(badvalue == -1)
                    badvalue = strlen(target);
                distance = badvalue > value[j-1] ? badvalue : value[j-1];
                printf("移动距离:%d\n",distance);
                j = tarlen -1;   //更新j位置
                i = i+ tarlen - 1 - j + distance;  //更新i的位置
            }
        }
    }
    printf("匹配失败....");
    return ERROR;
}

void main(){
    char *source,*target;  //source字符串，target搜索词
    int *value;  //好后缀词表

    int i = 0;
    InitData(&source,&target);  //初始化

    GetValue(&value,target); //获取后缀表

    BM(source,target,value);  //BM算法


    for(i = 0; i<strlen(target);i++){
        printf("%d\n",value[i]);
    }

    if(source && target){
        printf("%s\n",source);
        printf("%s\n",target);
    }
}