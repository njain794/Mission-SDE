#include <bits/stdc++.h>
using namespace std;

class node
{
    public: char data;
            unordered_map<char,node*>children;
            bool terminal;

            node(char d)
            {
                data = d;
                terminal = false;
            }
};

class trie
{
    private :
        node *root;
        int count;

    public:
    trie()
    {
        root = new node('\0');
        count = 0;
    }

    void insert(char *w)
    {
        node *temp = root;
        for(int i=0;w[i]!='\0';i++)
        {
            char ch = w[i];
            if(temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                node *n = new node(ch);
                temp->children[ch]=n;
                temp=n;
            }
        }
        temp->terminal = true;
    }

    bool findo(char *w)
    {
        node *temp = root;
        for(int i=0;w[i]!='\0';i++)
        {
            char ch = w[i];
            if(temp->children.count(ch)==0)
            {
                return false;
            }
            else
            {
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }
};

int main() 
{
    trie t;
    char word[][10] = {"a","not","hello","news","apple"};
    char w[10];
    cin>>w;

    for(int i=0;i<5;i++)
    {
        t.insert(word[i]);
    }

    if(t.findo(w))
    {
        cout<<"Present";
    }
    else
    {
        cout<<"Absent";
    }
}
