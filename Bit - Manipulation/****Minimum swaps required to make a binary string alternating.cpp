int countMinSwaps(string st) 
    { 
  
        int min_swaps = 0; 
  
        // counts number of zeroes at odd  
        // and even positions 
        int odd_0 = 0, even_0 = 0; 
  
        // counts number of ones at odd  
        // and even positions 
        int odd_1 = 0, even_1 = 0; 
  
        int n = st.length(); 
        for (int i = 0; i < n; i++) { 
            if (i % 2 == 0) {  
                if (st[i] == '1')  
                    even_1++; 
                else
                    even_0++; 
            } 
            else {  
                if (st[i] == '1')  
                    odd_1++; 
                else
                    odd_0++; 
            } 
        } 
  
        // alternating string starts with 0 
        int cnt_swaps_1 = min(even_0, odd_1);  
  
        // alternating string starts with 1 
        int cnt_swaps_2 = min(even_1, odd_0);  
  
        // calculates the minimum number of swaps 
        return min(cnt_swaps_1, cnt_swaps_2); 
    } 
