vector<int> graph[10001];
bool vis[10001];

void convertToGraph(Node *root){
    if(!root)
        return;
    if(root->left){
        int u = root->data, v = root->left->data;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    if(root->right){
        int u = root->data, v = root->right->data;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    convertToGraph(root->left);
    convertToGraph(root->right);
}

int minTime(Node* root, int target) 
{
    // Your code goes here
    if(!root)
        return 0;
    for(int i=0;i<10001;i++)
        graph[i].clear();
    memset(vis,false,sizeof(vis));
    convertToGraph(root);
    queue<int> q;
    q.push(target);
    int t = 0;
    while(!q.empty()){
        int len = q.size();
        while(len--){
            int v = q.front();
            vis[v] = true;
            q.pop();
            
            for(int u: graph[v])
                if(vis[u] == false)
                    q.push(u);
        }
        t++;
    }
    return t-1;
}
