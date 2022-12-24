#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef struct listnode
{
    int key;
    listnode* next;
}ln;

int n;//链表元素个数

void build_listnode(ln** head) //尾插法建立链表
{
    ln* tail = nullptr;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        ln* n = new ln;
        n->key = x;
        n-> next = nullptr;

        if(*head == nullptr)
        {
            *head = n;
        }
        else
        {
            tail->next = n;
        }

        tail = n;
    }

}

void Swap_Key(ln* i, ln* j)
{
    int temp = i->key;
    i->key = j->key;
    j->key = temp;
}

void QuickSort(ln* less, ln* more)
{
    if(less == nullptr || less ->next == nullptr || less == more) return;

    int pivot = less->key;
    ln* i = less->next;
    ln* i_pre = less;
    ln* j = less->next;

    while(j != more->next)
    {
        if(j->key < pivot)
        {
            Swap_Key(i,j);

            i_pre = i_pre->next;
            i = i->next;
        }
        j = j->next;
    }

    Swap_Key(less, i_pre);

    QuickSort(less, i_pre);
    QuickSort(i, more);
}

void Sort(ln** head) //链表快速排序算法
{
    ln* h = *head;
    ln* t = *head;
    while(t->next != nullptr)
    {
        t =t->next;
    }

    QuickSort(h, t);
}

void print_listnode(ln* head) //链表打印函数
{
    ln* h = head;
    while(h)
    {
        if(h->next != nullptr) cout << h->key << " -> ";
        else cout << h->key; 
        h = h->next;
    }
    cout << endl;
}

int main()
{
    ln* head = nullptr;

    cin >> n;

    build_listnode(&head);

    cout << "排序前的链表为 : " ;
    print_listnode(head);

    Sort(&head);

    cout << "排序后的链表为 : " ;
    print_listnode(head);

    return 0;
}
