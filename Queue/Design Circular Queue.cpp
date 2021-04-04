class MyCircularQueue {
public:
    int cs,ms;
    int f,r;
    int *arr;
    MyCircularQueue(int k) 
    {
        arr=new int[k];
        cs=0;
        ms=k;
        f=0;
        r=k-1;
    }
    
    bool enQueue(int value) 
    {
        if(!isFull())
        {
            r=(r+1)%ms;
            arr[r]=value;
            cs++;
            return true;
        }
        return false;
    }
    
    bool deQueue() 
    {
        if(!isEmpty())
        {
            f=(f+1)%ms;
            cs--;
            return true;
        }
        return false;
    }
    
    int Front() 
    {
        if(!isEmpty())
        {
           return arr[f];
        }
        return -1;
    }
    
    int Rear() 
    {
        if(!isEmpty())
        {
           return arr[r]; 
        }
        return -1;
    }
    
    bool isEmpty() 
    {
        return (cs==0);   
    }
    
    bool isFull() 
    {
        return (cs==ms);   
    }
};
