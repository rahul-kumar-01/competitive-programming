using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

Node* takeInput(){
    int num;
    cout<<"enter the data : ";
    cin>>num;
    Node * head = NULL;
    Node * tail = NULL;
    while(num!=-1){
        if(head == NULL){
            head = new Node(num);
            tail = head;
        }
        else{
            tail->next = new Node(num);
            tail = tail->next;
        }
        cin>>num;
    }
    
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int len(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        ++count;
    }
    return count;
}
