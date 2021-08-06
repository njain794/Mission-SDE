class Solution {
public:
	// pair to store the length of pattern at current node depending on the direction
    map<pair<TreeNode*,bool>,int>mp;
	
    int helper(TreeNode* root,bool isRight,int length){
        if(!root)
            return length-1; // -1 to remove the extra step taken to reach NULL node
			
        if(mp.find({root,isRight})!=mp.end()) //check memo
            return mp[{root,isRight}];
			
			/*   now we have two choices
			*    either continue the pattern or start pattern from the begining  
			*    or start a new pattern with length 1
			*    memoize and return max of both*/
			
        if(isRight)
            mp[{root,isRight}]= max(helper(root->left,false,length+1),helper(root->right,true,1)); 
        else
            mp[{root,isRight}]= max(helper(root->right,true,length+1),helper(root->left,false,1));
        return mp[{root,isRight}];
    }
	
    int longestZigZag(TreeNode* root) {
        return max(helper(root->right,true,1),helper(root->left,false,1));
    }
};
