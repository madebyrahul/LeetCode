class MyCircularDeque {
    int* arr;
    int size,front,back;
public:
    MyCircularDeque(int k) {
        size = k;
        arr = new int[size];
        front = back = -1;
    }
    
    bool insertFront(int value) {
         if(isEmpty()){
            front = back = 0;
            arr[front] = value;
            return true;
         }else{
            if(isFull()){
                return false;
            }else{
                front = (front-1+size)%size ;
                arr[front] = value;
                return true;
            }
         }
    }
    
    bool insertLast(int value) {
         if(isEmpty()){
            front = back = 0;
            arr[back] = value;
            return true;
         }else{
            if(isFull()){
                return false;
            }else{
                back = (back+1)%size ;
                arr[back] = value;
                return true;
            }
         }
    }
    
    bool deleteFront() {
         if(isEmpty()){
            return false;
         }else{
            if(front == back){
                front = back = -1;
                return true;
            }else{
                front = (front+1)%size ;
                return true;
            }
         }
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }else{
            if(front == back){
                front = back = -1;
            }else{
                back = (back-1+size)%size ;
            }
            return true;
        }
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }else{
            return arr[front];
        }
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }else{
            return arr[back];
        }
    }
    
    bool isEmpty() {
        return (front == -1) ? true : false;
    }
    
    bool isFull() {
        return ( (back+1)%size == front ) ? true : false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */