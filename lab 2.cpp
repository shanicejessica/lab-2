#include<iostream>

using namespace std;

class node //craete a class of type node
{  public :
    int data;
    node *next;
};

class link //create a class of type link
{
    node *head;  //create head node
    node *tail;  //create tail node

  public:
    link () //constructor
    {
      head = NULL;  //make head null
      tail = NULL;  //make head null
    }
       void insert_list(int data);
       void insert_at(int pos, int data);
       void delete_list();
       void delete_at(int pos);
       void display_l();
       int count_l();
};

void menu()  //menu of functions one can use
{ cout<<"\n This is the list of thing you can do using this programme."<<endl;
  cout<<" (a) create a linked list."<<endl;
  cout<<" (b) insert data in linked list."<<endl;
  cout<<" (c) insert a data at any position. "<<endl;
  cout<<" (d) delete the linked list. "<<endl;
  cout<<" (e) delete data of a specific position."<<endl;
  cout<<" (f) display the elements of linked list."<<endl;
  cout<<" (g) count the number of elements in the list."<<endl;
  cout<<" Press 'x' and hit 'enter' to exit."<<endl;
  cout<<" Choose the option what you want to do : \n -> ";
}

int main()
{ char ch;  //character type variable
  link l_l; //create an object
 //start while loop
 while (ch != 'x')  //condition : input is not x otherwise break the loop
   { menu();
     cin>> ch;
     //give different output depending on the character variable using 'if else'
     if (ch=='a') 
     {
        cout<<"\n Linked list is created."<<endl;
     }
     else if (ch=='b')
     {
         int num;
         cout<<"\n How many data do you want to add ? \n ->";
         cin>>num;
         for(int i=1;i<=num;i++)
         {   int data;
             cout<<"Data "<<i<<" = ";
             cin >> data;
             l_l.insert_list(data); //calling the insert_list(int data) function
         }
     }
     else if (ch=='c')
     {   int post, data;
         int num;
         num = l_l.count_l(); //calling the count_l() function to check the number element in the list
         cout<<"\n Enter the position where you want to insert a data : ";
         cin>>post;
         if (0 < post && post < num+1) //condition for nonempty linked list
         {
             cout<<"\n Enter the new data : ";
             cin >> data;
             l_l.insert_at(post, data); //calling the insert_at() function
         }
         else { cout<<" Invalid position. \n ";} //condition when position entered is not valid for the linked list

     }
     else if (ch=='d')
     {
         l_l.delete_list();  //calling delete_list() function
     }
     else if (ch=='e')
     {
         int post;
         int num;
         num = l_l.count_l();  //calling the count_l() function to check the number element in the list
         cout <<"\n Enter the position of data you want to delete : ";
         cin >> post;
         if (0 < post && post <= num)  //condition for nonempty linked list
         {
             l_l.delete_at(post);  //calling the delete_at() function
         }
         else {cout<<"Invalid position.";}  //condition when position entered is not valid for the linked list
     }
     else if (ch=='f')
     {
         cout<<"This are your data :"<<endl;
         l_l.display_l();  //calling the display_l() function
     }
     else if (ch=='g')
     {   int num;
         num = l_l.count_l();  //calling the count_l() funtion
         cout<<"\n There is ";
         cout<<num;
         cout<<" elements in your linked list. \n ";
     }
     else
        {
             cout<<"\n You have entered an invalid key try again.";  //when one enter a invalid character
        }

     cout <<"\n  Thank you for using this programme.";
     cout <<"\n  If you want to continue press any key and hit 'enter'.";  //run the while loop again
     cout <<"\n  If you want to exit press 'x' and hit 'enter'. \n -> ";   //break the while loop
     cin >> ch; 
   }

return 0;
}

void link :: insert_list(int data)
{
     node *temp = new node; //create a new node type object called 'temp'
     temp->data = data;   //data input is inserted in data part of temp
     if (head == NULL)   //condition for empty list
     {
         head=temp;   //make 'head' and 'temp' same
         tail=temp;   //make 'tail' and 'temp' same
         temp->next = NULL;  //points 'next' of temp to null
     }
     else    //condition for nonempty list
        {
           tail->next = temp;  //points 'next' of tail to temp
           temp->next = NULL;  //points 'next' pointer of temp to null
           tail=temp;   //make 'temp' and 'tail' same
        }
}

void link :: insert_at(int post, int dat)
{
    node *tmp =new node;  //create a new node type object called 'temp'
    node *pos;   //create a new node type pointer called 'pos'
    pos=head;   //makes the address of 'pos' and 'head' same
    tmp->data= dat;
    for (int i=2;i<post;i++)
    {
        pos=pos->next;
    }
    tmp->next = pos->next;
    pos->next = tmp;
}

void link :: delete_list()
{
    node *pos;  //create a new node type pointer called 'pos'
    pos=head;  //makes the address of 'pos' and 'head' same
    if (head == NULL)
    {
         cout<<"Nothing in the list to delete \n ";
    }
    else
    { 
        while (pos->next != tail)  //run this loop until 'next' of pos does not point to tail
        {
            pos=pos->next;  //make the next node new 'pos'
        }
        tail=pos;    //make 'tail' and 'pos' same
        pos=pos->next;   //make the next node new 'pos'
        tail->next = NULL;
        delete pos;   //delete node 'pos'
    }

}

void link :: delete_at(int post)
{ node *pos;  //create a new node type pointer called 'pos'
  pos=head;   //makes the address of 'pos' and 'head' same
  for (int i=2;i<post;i++)
  {
      pos=pos->next;
  }
  node *temp;  //create a new node type pointer called 'temp'
  temp = pos->next;
  pos->next = temp->next;
  temp->next = NULL;
  delete temp;  //delete node 'temp'
}

void link :: display_l()
{
    node *pos;  //create a new node type pointer called 'pos'
    pos=head;  //makes the address of 'pos' and 'head' same
    if (head==NULL)
    {
        cout<<"your list is empty.";
    }
    else
    {
       while (pos != NULL)
      {
         cout<<pos->data<<" -> ";  //display the elements
         pos=pos->next; //goes to next element 
      }
    }
}

int link :: count_l()
{
    node *pos;  //create a new node type pointer called 'pos'
    pos = head;  //makes the address of 'pos' and 'head' same
    int i=2;
    if (head == NULL)   //when number of element in the list is zero
    {
        return 0;
    }

    else if (pos->next == NULL) //when number of element in the list is one
    {
        return 1;
    }

    else
    {
        while (pos->next != tail)
        {
            pos = pos->next;
            i++;
        }
        return i; //return the number of element present
    }
}
