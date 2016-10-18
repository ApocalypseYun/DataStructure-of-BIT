//
//  main.cpp
//  数据结构
//
//  Created by 刘冠中 on 2016/10/18.
//  Copyright © 2016年 刘冠中. All rights reserved.
//

#include <cstdio>
#include <cstring>

typedef struct Polyn{
    int n,m;
    Polyn *next;
};

Polyn *temp;

void CreatPloyn(Polyn *p,int T){
    
    p->n=0;
    p->m=0;
    p->next=NULL;
    while(T--){
        
        Polyn *q = new Polyn;
        scanf("%d%d",&q->n,&q->m);
        p->next=q;
        q->next=NULL;
        p=q;
    }
}

void AddPolyn(Polyn *P1,Polyn *P2){
    
    P1=P1->next;
    while(P1!=NULL){
        if(P2->next!=NULL) {
            
            if(P1->m<P2->next->m)
            {
                temp=P1;
                P1=P1->next;
                temp->next=P2->next;
                P2->next=temp;
                P2=P2->next;
            }
            else if(P1->m==P2->next->m){
            
                P2->next->n+=P1->n;
                if(P2->next->n==0){
                
                    if(P2->next->next!=NULL)
                        P2->next=P2->next->next;
                    else
                        P2->next=NULL;
                }
                P1=P1->next;
            }
            else {
                
                P2=P2->next;
            }
        }
        else{
            
            P2->next=P1;
            P1=P1->next;
            P2=P2->next;
        }
    }
}

void PrintPolyn(Polyn *P) {
    
    if(P->next==NULL){
        
        printf("<0,0>\n");
        return ;
    }
    P=P->next;
    printf("<%d,%d>",P->n,P->m);
    P=P->next;
    while(P!=NULL){
        
        printf(",<%d,%d>",P->n,P->m);
        P=P->next;
    }
    printf("\n");
}

int main() {
    
    Polyn *Pa = new Polyn;
    Polyn *Pb = new Polyn;
    Polyn *Pc = new Polyn;
    int Judge,T;
    scanf("%d",&Judge);
    if(Judge==0)
        return 0;
    
    scanf("%d",&T);
    CreatPloyn(Pa, T);
    scanf("%d",&T);
    CreatPloyn(Pb, T);
    scanf("%d",&T);
    CreatPloyn(Pc, T);
    
    PrintPolyn(Pa);
    PrintPolyn(Pb);
    PrintPolyn(Pc);
    
    AddPolyn(Pa, Pb);
    PrintPolyn(Pb);
    
    AddPolyn(Pb, Pc);
    PrintPolyn(Pc);
    return 0;
}
