#include<iostream>

using namespace std;


struct QNode {
    int data;
    QNode* next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};
 
struct Queue {
    QNode *front, *rear;
    Queue() { front = rear = NULL; }
 
    void enQueue(int x)
    {
 
        // Create a new LL node
        QNode* temp = new QNode(x);
 
        // If queue is empty, then
        // new node is front and rear both
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
 
        // Add the new node at
        // the end of queue and change rear
        rear->next = temp;
        rear = temp;
    }
 
    // Function to remove
    // a key from given queue q
    void deQueue()
    {
        // If queue is empty, return NULL.
        if (isEmpty())
            return;
 
        // Store previous front and
        // move front one node ahead
        QNode* temp = front;
        front = front->next;
 
        // If front becomes NULL, then
        // change rear also as NULL
        if (front == NULL)
            rear = NULL;
 
        delete (temp);
    }

    void display(){
        if(isEmpty()){
            return;
        }

        QNode *temp=front;

        do{
            cout<<temp->data+"->";
        }while(temp->next==NULL);
        
    }

    void sum(){
         if(isEmpty()){
            return;
        }

        QNode *temp=front;
        int sum=0;

        do{
            sum+=temp->data;
        }while(temp->next==NULL);

        cout<<"\n"+sum<<endl;
    }

    void average(){
         if(isEmpty()){
            return;
        }

        QNode *temp=front;
        int sum=0;
        int count=0;

        do{
            sum+=temp->data;
            ++count;
        }while(temp->next==NULL);

        cout<<"\n"+sum/count<<endl;
    }

    bool isEmpty(){
        if(front==NULL){
            return true;
        }
        return false;
    }
};
 
// Driver code
int main()
{
 
    Queue q;
while(){
 cout<<"======================\n";
    cout<<"Menu\n";
    cout<<"======================\n";
    cout<<"Options\n";
    cout<<"1)enQueue\n";
    cout<<"2)deQueue\n";
    cout<<"3)Average\n";
    cout<<"4)Sum\n";
    cout<<"5)Display\n";
    cout<<"6)exit\n";
    cout<<"->";
    int x;
    cin>>x;
    switch (x)
    {
    case 1:
       cout<<"\ninput value.\n";
       cout<<"->";
       int v;
       cin>>v;
       q.enQueue(v);
    break;
    case 2:
    cout<<"\n input value.\n";
    cout<<"->";
    int g;
    cin>>g;
        q.deQueue();
    break;

    case 3:
        q.average();
    break;

    case 4:
        q.sum();
    break;
    case 5:
    	q.display();
    	break;
    	case 6:
    		exit(0);
    		break;
    default:
    cout<<"\nWrong input!Try again.\n";
        break;
    }	
}
   
}
// This code is contributed by rathbhupendra
