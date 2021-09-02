#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class trienode{
    public:
    string content;
    unordered_map<string,trienode*>children;
    trienode(string d)
    {
        content=d;
    }
}

class FileSystem {
    trienode *root;
public:
    FileSystem() {
        root=new trienode('/');
    }

    vector<string> tokenize(string path)
    {
         vector<string> ret;
        int pos = 1;
        string token;
        while (pos < path.length()) {
            if (path[pos] == '/') {
                ret.push_back(token);
                token.clear();
            } else {
                token.push_back(path[pos]);
            }
            ++pos;
        }

        if (token.length() > 0) {
            ret.push_back(token);
        }

        return ret;
    }
    
    vector<string> ls(string path) {
        trienode *curroot=root;
        vector<string>ans;
        if(path!='/')
        {
            vector<string>tokens=tokenize(path);
            string currstring;
            for(int i=0;i<tokens.size();i++)
            {
                currstring=tokens[i];
                curroot=curroot->children[currstring];
                if(i==tokens.size()-1 and curroot->content!="")
                {
                    ans.push_back(curroot->content);
                }
            }
        }
        for(auto x:curroot->children)
        {
            ans.push_back(x.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void mkdir(string path) 
    {
        trienode *curroot=root;
        vector<string>tokens=tokenize(path);
        for(int i=0;i<tokens.size();i++)
        {
            currstring=tokens[i];
            if(curroot->children.find(currstring)!=curroot->children.end())
            {
                curroot=curroot->children[currstring];
            }
            else
            {
                curroot->children[currstring]=new trienode(currstring);
                curroot=curroot->children[currstring];
            }
        }   
    }
    
    void addContentToFile(string path, string cont) {
        trienode *curroot=root;
        vector<string>tokens=tokenize(path);
        for(int i=0;i<tokens.size();i++)
        {
            currstring=tokens[i];
            if(curroot->children.find(currstring)!=curroot->children.end())
            {
                curroot=curroot->children[currstring];
            }
            else
            {
                curroot->children[currstring]=new trienode(currstring);
                curroot=curroot->children[currstring];
            }
        } 
        if(curroot->content.size()==0)
        {
            curroot->content=cont;
        }
        else{
            curroot->content+=cont;
        }
    }
    
    string readContentFromFile(string filePath) 
    {
        trienode *curroot=root;
        vector<string>tokens=tokenize(path);
        for(int i=0;i<tokens.size();i++)
        {
            currstring=tokens[i];
            if(curroot->children.find(currstring)!=curroot->children.end())
            {
                curroot=curroot->children[currstring];
            }
            else
            {
                curroot->children[currstring]=new trienode(currstring);
                curroot=curroot->children[currstring];
            }
        }   
        return curroot->content;
    }
};


int main() {
    cout<<"Hello World!";
}





