class BrowserHistory {
    //trienode *root;
public:
    unordered_map<string,string>children;
    unordered_map<string,string>parent;
    string currsite;
    BrowserHistory(string homepage) 
    {
        children.clear();
        parent.clear();
        currsite="/0";
        children[currsite]=homepage;
        parent[homepage]=currsite;
        currsite=homepage;
           //root=new trienode(homepage);
    }
    
    void visit(string url) 
    {
        children[currsite]=url;
        parent[url]=currsite;
        currsite=url;
        /*string curr=root->site;
        root->children[curr]=new trienode(url);
        root=root->children*/
    }
    
    string back(int steps) 
    {
        int cnt=0;
        while(cnt<steps)
        {
            if(parent[currsite]=="/0")
            {
                break;
            }
            string temp=parent[currsite];
            currsite=temp;
            cnt++;
        }
        return currsite;
        
    }
    
    string forward(int steps) 
    {
        int cnt=0;  
        while(cnt<steps)
        {
            if(children.find(currsite)==children.end())
            {
                break;
                //return currsite;
            }
            else
            {
                string temp=children[currsite];
                currsite=temp;
            }
            cnt++;
        }
        return currsite;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
