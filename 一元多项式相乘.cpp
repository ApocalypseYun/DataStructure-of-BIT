//
//  main.cpp
//  数据结构
//
//  Created by 刘冠中 on 2016/10/18.
//  Copyright © 2016年 刘冠中. All rights reserved.
//

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int    coef, exp;
    struct node  *next;
} NODE;

void multiplication( NODE *, NODE * , NODE * );
void input( NODE * );
void output( NODE * );

void input( NODE * head )
{   int flag = 0, sign = 0, sum = 0, x = 0;
    char c;
    
    NODE * p = head;
    
    while ( (c=getchar()) !='\n' )
    {
        if ( c == '<' )
        {    sum = 0;
            sign = 1;
            flag = 1;
        }
        else if ( c =='-' )
            sign = -1;
        else if( c >='0'&& c <='9' )
        {    sum = sum*10 + c - '0';
        }
        else if ( c == ',' )
        {    if ( flag == 1 )
        {    x = sign * sum;
            sum = 0;
            flag = 2;
            sign = 1;
        }
        }
        else if ( c == '>' )
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );
            p->next->coef = x;
            p->next->exp  = sign * sum;
            p = p->next;
            p->next = NULL;
            flag = 0;
        }
    }
}

void output( NODE * head )
{
    while ( head->next != NULL )
    {   head = head->next;
        printf("<%d,%d>,", head->coef, head->exp );
    }
    printf("\n");
}

int main()
{   NODE * head1, * head2, * head3;
    
    head1 = ( NODE * ) malloc( sizeof(NODE) );
    input( head1 );
    
    head2 = ( NODE * ) malloc( sizeof(NODE) );
    input( head2 );
    
    head3 = ( NODE * ) malloc( sizeof(NODE) );
    head3->next = NULL;
    multiplication( head1, head2, head3 );
    
    output( head3 );
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void multiplication( NODE *head1, NODE *head2, NODE *head3 ){
    
    NODE *temp = new NODE;
    NODE *q = head1->next;
    while(q!=NULL){
        
        NODE *p = head2->next;
        NODE *r = head3;
        while(p!=NULL){
            
            temp->coef=p->coef*q->coef;
            temp->exp=p->exp+q->exp;
            while(1){
                if(r->next==NULL){
                
                    r->next=new NODE;
                    r=r->next;
                    r->coef=temp->coef;
                    r->exp=temp->exp;
                    r->next=NULL;
                    break;
                }
                else if(r->next->exp==temp->exp){
                
                    r->next->coef+=temp->coef;
                    break;
                }
                else if(r->next->exp>temp->exp){
                
                    temp->next=r->next;
                    r->next=temp;
                    temp=new NODE;
                    break;
                }
                else{
                
                    r=r->next;
                }
            }
            p=p->next;
        }
        q=q->next;
    }
    temp=head3;
    while(temp->next!=NULL){
        
        if(temp->next->coef==0){
            temp->next=temp->next->next;
            continue;
        }
        temp=temp->next;
    }
    if(head3->next==NULL){
        head3->next=new NODE;
        head3->next->coef=0;
        head3->next->exp=0;
        head3->next->next=NULL;
    }
}
