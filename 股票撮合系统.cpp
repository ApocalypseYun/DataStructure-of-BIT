//
//  main.cpp
//  数据结构
//
//  Created by 刘冠中 on 2016/10/18.
//  Copyright © 2016年 刘冠中. All rights reserved.
//


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void input();
void cancel();

typedef struct stock
{
    short int orderid;
    short int stockid;
    double price;
    int quantity;
    char type;
    struct stock * next;
}STOCK;

typedef struct stockId
{
    int stockid;
    STOCK * sellhead;
    STOCK * buyhead;
    struct stockId * next;
}STKID;

STOCK * orderList[10005] = {NULL};
STKID *idhead;
int totalOrder = 0;

STKID * FDSTACK(int stockid){
    STKID * idProbe = idhead;
    while(idProbe->next){
        if(idProbe->next->stockid == stockid){
            return idProbe->next;
        }
        idProbe = idProbe->next;
    }
    return NULL;
}

void init(){
    idhead = (STKID*)malloc(sizeof(STKID));
    idhead->next = NULL;
    memset(orderList, 0, sizeof(orderList));
    totalOrder = 0;
    return;
}

int min(int a, int b){
    return a<b ? a : b;
}

double ava(double a, double b){
    return (a+b)/2;
}

void inquire(){
    int stockid;
    scanf("%d", &stockid);
    STKID * p = FDSTACK(stockid);
    STOCK * pPr;
    printf("buy orders:\n");
    if(p == NULL){
        printf("sell orders:\n");
        return;
    }
    for(pPr = p->buyhead;pPr->next;){
        if(orderList[pPr->next->orderid] == NULL){
            pPr->next = pPr->next->next;
            continue;
        }
        printf("orderid: %04d, stockid:%04d, price: %6.1lf, quantity: %4d, b/s: %c\n", pPr->next->orderid, pPr->next->stockid, pPr->next->price, pPr->next->quantity, pPr->next->type);
        pPr = pPr->next;
    }
    printf("sell orders:\n");
    for(pPr = p->sellhead;pPr->next;){
        if(orderList[pPr->next->orderid] == NULL){
            pPr->next = pPr->next->next;
            continue;
        }
        printf("orderid: %04d, stockid:%04d, price: %6.1lf, quantity: %4d, b/s: %c\n", pPr->next->orderid, pPr->next->stockid, pPr->next->price, pPr->next->quantity, pPr->next->type);
        pPr = pPr->next;
    }
    return;
}

int main(){
    init();
    int select = 1;
    while(scanf("%d", &select), select){
        switch(select){
            case 1:{
                input();
                break;
            }
            case 2:{
                inquire();
                break;
            }
            case 3:{
                cancel();
                break;
            }
        }
    }
    return 0;
}

void input(){
    int stockid, quantity;
    char type;
    double price;
    STKID * head;
    totalOrder++;
    scanf("%d%lf%d %c", &stockid, &price, &quantity, &type);
    printf("orderid: %04d\n", totalOrder);
    if(!(head = FDSTACK(stockid)))
    {
        STOCK * sellhead = (STOCK*)malloc(sizeof(STOCK));
        STOCK * buyhead  = (STOCK*)malloc(sizeof(STOCK));
        sellhead->next = NULL;
        buyhead->next = NULL;
        head = (STKID*)malloc(sizeof(STKID));
        head->next = idhead->next;
        head->stockid = stockid;
        head->sellhead = sellhead;
        head->buyhead = buyhead;
        idhead->next = head;
    }
    if(type == 's'){
        STOCK * sellhead = head->sellhead;
        STOCK * buyhead = head->buyhead;
        
        while(buyhead->next){
            if(buyhead->next->price < price)break;
            if(orderList[buyhead->next->orderid] == NULL)
            {
                buyhead->next = buyhead->next->next;
                continue;
            }
            int minimum = min(quantity, buyhead->next->quantity);
            double dealprice = ava(price, buyhead->next->price);
            printf("deal--price:%6.1lf  quantity:%4d  sellorder:%04d  buyorder:%04d\n", dealprice, minimum, totalOrder, buyhead->next->orderid);
            quantity -= minimum;
            buyhead->next->quantity -= minimum;
            if(buyhead->next->quantity == 0){
                orderList[buyhead->next->orderid] = NULL;
                buyhead->next = buyhead->next->next;
            }
            if(quantity == 0)
                break;
        }
        if(quantity == 0)
            return;
        while(sellhead->next && sellhead->next->price<=price){
            sellhead = sellhead->next;
        }
        STOCK * p = (STOCK*)malloc(sizeof(STOCK));
        p->stockid = stockid;
        p->orderid = totalOrder;
        p->price = price;
        p->quantity = quantity;
        p->next = sellhead->next;
        p->type = 's';
        sellhead->next = p;
        orderList[totalOrder] = p;
    }
    else{
        STOCK * sellhead = head->sellhead;
        STOCK * buyhead = head->buyhead;
        while(sellhead->next){
            if(sellhead->next->price > price)
                break;
            if(orderList[sellhead->next->orderid] == NULL){
                sellhead->next = sellhead->next->next;
                continue;
            }
            int minimum = min(quantity, sellhead->next->quantity);
            double dealprice = ava(price, sellhead->next->price);//新的委托序号， 匹配的委托序号
            printf("deal--price:%6.1lf  quantity:%4d  buyorder:%04d  sellorder:%04d\n", dealprice, minimum, totalOrder, sellhead->next->orderid);
            quantity -= minimum;
            sellhead->next->quantity -= minimum;
            if(sellhead->next->quantity == 0){
                orderList[sellhead->next->orderid] = NULL;
                sellhead->next = sellhead->next->next;
            }
            if(quantity == 0)
                break;
        }
        if(quantity == 0)
            return;
        while(buyhead->next && buyhead->next->price>=price){
            buyhead = buyhead->next;
        }
        STOCK * p = (STOCK*)malloc(sizeof(STOCK));
        p->stockid = stockid;
        p->orderid = totalOrder;
        p->price = price;
        p->quantity = quantity;
        p->next = buyhead->next;
        p->type = 'b';
        buyhead->next = p;
        orderList[totalOrder] = p;
    }
}

void cancel()
{
    int orderid;
    STOCK * p;
    scanf("%d", &orderid);
    if((p = orderList[orderid]) == NULL){
        printf("not found\n");
        return;
    }
    printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1lf, quantity: %4d, b/s: %c\n", p->orderid, p->stockid, p->price, p->quantity, p->type);
    p->quantity = 0;
    orderList[orderid] = NULL;
    return;
}
