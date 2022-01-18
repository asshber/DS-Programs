#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node* next;
    Node(char d)
    {
        data = d;
        next = NULL;
    }
    void insertnode(char d)
    {
        Node* newnode = new Node(d);
        Node* i;
        for (i = this; i->next!= NULL; i=i->next);
        i->next = newnode;
        newnode->next = NULL;
    }
};
int main()
{
    int x;
    cout << "Enter the length of the word: ";
    cin >> x;
    cout << "Enter the word: ";
    char d;
    cin >> d;
    Node* head = new Node(d);

    
    for (int i = 1; i < x; i++)
    {
        cin >> d;
        head->insertnode(d);
    }
    int count=0;
    int temp = 0;;
    bool flag = 0;
    Node* j;
    bool flag2 = 0;

    for (auto i = head; i != NULL; i = i->next)
    {
        count++;
        temp = 0;
        for (j = head; temp < (x - count);  j=j->next)
        {
            temp++;
        }
        if (i->data != j->data)
        {
            flag = 1;
        }
        if (flag == 1||flag2==1)
            break;

        
    }
    if (!flag)
    {
        cout << "The Entered String is Palindrome.";
        exit(0);
    }
    else
    {
        cout << "The Entered string is not palindrome";
    }


}
