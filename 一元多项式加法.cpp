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
    Polyn *next,*pre;
};

Polyn *temp;

void CreatPloyn(Polyn *p,int T){
    
    scanf("%d%d",&p->n,&p->m);
    T--;
    p->pre = NULL;
    while(T--) {
        
        Polyn *q = new Polyn;
        scanf("%d%d",&q->n,&q->m);
        q->next = NULL;
        q->pre = p;
        p->next = q;
        p = q;
    }
}

void AddPolyn(Polyn *P1,Polyn *P2){
    
    while(P1!=NULL&&P2!=NULL) {
        if(P1->m>=P2->m) {
            
            if(P2->next==NULL) {
                
                if(P1->m==P2->m) {
                    
                    P2->n+=P1->n;
                    if (P2->n==0) {
                        
                        if(P2->next!=NULL)
                            P2->next->pre=P2->pre;
                        if(P2->pre!=NULL)
                            P2->pre->next=P2->next;
                    }
                    P1=P1->next;
                    continue;
                }
                else {
                    
                    if(P1->next!=NULL) {
                        P1=P1->next;
                        P1->pre->next=P2->next;
                        P2->next=P1->pre;
                        P1->pre->pre=P2;
                    }
                    else {
                        
                        P2->next=P1;
                        P1->pre=P2;
                        P2=P2->next;
                    }
                }
            }
            if(P1->m==P2->m) {
                P2->n+=P1->n;
                if (P2->n==0) {
                    
                    if(P2->next!=NULL)
                        P2->next->pre=P2->pre;
                    if(P2->pre!=NULL)
                        P2->pre->next=P2->next;
                }
                P1=P1->next;
                P2=P2->next;
                continue;
            }
            if(P2->next->m<P1->m) {
                
                P1=P1->next;
                P1->pre->next=P2->next;
                P2->next=P1->pre;
                P1->pre->pre=P2;
            }
            else if (P2->next->m==P1->m) {
                
                P2->next->n+=P1->n;
                if (P2->next->n==0) {
                    
                    if(P2->next->next!=NULL)
                        P2->next->next->pre=P2->next->pre;
                    if(P2->next->pre!=NULL)
                        P2->next->pre->next=P2->next->next;
                }
                P1=P1->next;
            }
            else {
                
                P2=P2->next;
            }
        }
        else {
            
            P1->pre=P2->pre;
            if(P2->pre!=NULL) {
                
                P2->pre->next=P1;
            }
            P2->pre=P1;
            if(P1->next!=NULL) {
                
                P1=P1->next;
                P1->pre->next=P2;
            }
            else {
                
                P1->next=P2;
                P1=NULL;
            }
        }
    }
}

void PrintPolyn(Polyn *P) {
    
    int count=0;
    if(P->n!=0) {
        printf("<%d,%d>",P->n,P->m);
        count++;
    }
    P=P->next;
    if(P==NULL)
        return;
    while(P->next!=NULL) {
        
        if(P->n!=0) {
            printf(",<%d,%d>",P->n,P->m);
            count++;
        }
        P=P->next;
    }
    if(count!=0)
        printf(",<%d,%d>\n",P->n,P->m);
    else
        printf("<0,0>\n");
}

Polyn *findhead(Polyn *p) {
    
    while(p->pre!=NULL) {
        
        p=p->pre;
    }
    return p;
}

void free(Polyn *p) {
    
    temp=p;
    p=p->next;
    delete temp;
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
    Pb=findhead(Pb);
    PrintPolyn(Pb);
    
    AddPolyn(Pb, Pc);
    Pc=findhead(Pc);
    PrintPolyn(Pc);
    
    free(Pc);
    
    return 0;
}
