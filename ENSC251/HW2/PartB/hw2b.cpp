/**
 * @file hw1a.cpp
 * @author Martin Benjamin
 * @Date   12/20/2018
 * @version 1.0
 * @section A program that modifies display 13.21, 13.22, and 13.23 from
 *problem solving with c++ to simulate a dmv queue.
 *
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Benjamin Martin ____      _____June 20 2018______________
//
// ____ 301347720______

#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

namespace queuesavitch

{
  struct QueueNode
   {
     int ticketNum;
     long arrivalTime;
     QueueNode *link;
   };
   typedef QueueNode* QueueNodePtr;
   class Queue
   {
   public:
     Queue();
     //Initializes the object to an empty queue.
     Queue(const Queue& aQueue);
     ~Queue();
     void add(int ticketNumP);
     //Postcondition: item has been added to the back of the queue.
     long remove();
     //Precondition: The queue is not empty.
     //Removes the first item from the queue.
     bool empty() const;
     //Returns true if the queue is empty. Returns false otherwise.
     int nextCustomer();
     //Returns the next customer ticket number in the queue.
   private:
     QueueNodePtr front; //Points to the head of a linked list.
     //Items are removed at the head
     QueueNodePtr back; //Points to the node at the other end of the
     //linked list. Items are added at this end.
   };
}

using namespace queuesavitch;

int main()
  {
    //declare variables
    long timeOut = 0.0;
    long currentWait = 0.0;
    int estimatedWait = 0;
    Queue q;
    char next = '\0';
    vector<int> vTickets; // a vector for tickets
    int i = 0;
    for (i=0;i<10000;i++)
    {
      vTickets.push_back(i+1);
    }
    vector<long> avgWait;
    for (i = 0;i<3;i++)
    {
      avgWait.push_back(0.0);
    }
    while (next != '3')
    {
      if (q.empty())
      {
        cout << "The line is empty." <<endl;
      }
      cout << "Enter '1' to simulate a customer's arrival, '2' to help the"
        << " next customer, or '3' to quit." << endl;
      cin >> next;
      if (next == '1')
      {
        //to add a customer
        cout << "Customer " << vTickets[0] << " entered the queue at time ";
        q.add(vTickets[0]);
        vTickets.erase(vTickets.begin());
      }
      else if (next == '2')
      {
        if (q.empty())
        {
          cout << "Every man must serve someone. But noone is there now."
          << endl;
        }
        else
        {
          //remove a customer
          timeOut = q.remove();
          cout << " Wait time = " << timeOut << " seconds." << endl;
          //recalculate the average wait time
          avgWait.erase(avgWait.begin());
          avgWait.push_back(timeOut);

          if(avgWait[1]==0.0 && avgWait[0] ==0.0)
          {
            currentWait = avgWait[2];
          }
          else if(avgWait[0]==0.0)
          {
            currentWait = (avgWait[1] + avgWait[2])/2.0;
          }
          else
          {
            currentWait = (avgWait[0] + avgWait[1] + avgWait[2])/3.0;
          }

          estimatedWait = static_cast<int>(currentWait);
          if (q.empty() == false)
          {
          cout << "The estimated wait time for customer " << q.nextCustomer()
            << " is " << estimatedWait << " seconds." << endl;
          }
        }
      }
      else
      {
        if (next != '3')
        {
          cout << "That is not a valid input." << endl;
        }
      }
      cin.ignore(1000,'\n');
      cin.clear();
  }

    return 0;
  }

  namespace queuesavitch
  {
    //Uses cstddef:
    Queue::Queue() : front(NULL), back(NULL)
    {
      //Intentionally empty.
    }
    Queue::Queue(const Queue&aQueue)
    {
      if (aQueue.empty( ))
      front = back = NULL;
      else
      {
        QueueNodePtr temp_ptr_old = aQueue.front;
        //temp_ptr_old moves through the nodes
        //from front to back of aQueue.
        QueueNodePtr temp_ptr_new;
        //temp_ptr_new is used to create new nodes.
        back = new QueueNode;
        back->ticketNum = temp_ptr_old->ticketNum;
        back->arrivalTime = temp_ptr_old->arrivalTime;
        back->link = NULL;
        front = back;
        //First node created and filled with data.
        //New nodes are now added AFTER this first node.
        temp_ptr_old = temp_ptr_old->link;
        //temp_ptr_old now points to second
        //node or NULL if there is no second node.
        while (temp_ptr_old != NULL)
        {
          temp_ptr_new = new QueueNode;
          back->ticketNum = temp_ptr_old->ticketNum;
          back->arrivalTime = temp_ptr_old->arrivalTime;
          temp_ptr_new->link = NULL;
          back->link = temp_ptr_new;
          back = temp_ptr_new;
          temp_ptr_old = temp_ptr_old->link;
        }
      }
    }
  Queue::~Queue( )
  {
   while (! empty( ))
   {
     QueueNodePtr discard;
     discard = front;
     front = front->link;
     if (front == NULL) //if you removed the last node
     back = NULL;

     delete discard;
    }
  }
  //Uses cstddef:
  bool Queue::empty() const
  {
    return (back == NULL); //front == NULL would also work
  }
  //Uses cstddef and ctime as well as a vector vTickets:
  void Queue::add(int ticketNumP)
  {
    if (empty())
    {
      front = new QueueNode;
      front->ticketNum = ticketNumP;
      front->arrivalTime = static_cast<long>(time(NULL));
      front->link = NULL;
      back = front;
      cout << front->arrivalTime << "." << endl;
    }

    else
    {
      QueueNodePtr temp_ptr;
      temp_ptr = new QueueNode;
      temp_ptr->ticketNum = ticketNumP;
      temp_ptr->arrivalTime = static_cast<long>(time(NULL));
      cout << temp_ptr->arrivalTime << "." << endl;
      temp_ptr->link = NULL;
      back->link = temp_ptr;
      back = temp_ptr;
    }
  }
 //Uses cstdlib and iostream:
 long Queue::remove()
  {
    if (empty())
    {
       cout << "Error: Removing an item from an empty queue.\n";
       exit(1);
    }
    long helpTime = static_cast<long>(time(NULL));
    cout << "Customer " << front->ticketNum << " is being helped at time "
      << helpTime << ".";
    long timeWaiting =  helpTime - front->arrivalTime;
    QueueNodePtr discard;
    discard = front;
    front = front->link;
    if (front == NULL) //if you removed the last node
    back = NULL;

    delete discard;

    return timeWaiting;
  }
  int Queue::nextCustomer()
  {
    int tempI = 0;
    tempI = front->ticketNum;
    return tempI;
  }
}//queuesavitch
