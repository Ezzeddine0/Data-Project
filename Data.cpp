#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class tree_node
{
public:

    string name, gender;
    int age, percent, student_id;

    tree_node* left, * right;

    tree_node()
    {
        left = right = NULL;
        student_id = percent = age = 0;
    }
};
class node
{
public:

    string name, gender;
    int age, percent, student_id;
    node* next;
    node()
    {
        student_id = percent = age = 0;
        next = NULL;
    }
};
class Stack :public node
{
    node* top;
public:

    Stack()
    {
        top = NULL;
    }
    void push(Stack s)
    {
        node* temp = new node;

        temp->student_id = s.student_id;
        temp->name = s.name;
        temp->age = s.age;
        temp->gender = s.gender;
        temp->percent = s.percent;

        temp->next = top;
        top = temp;

    }
    void display_stack()
    {
        node* temp;
        if (top == NULL)
        {
            cout << "\nStack Underflow\n";
            return;
        }
        else
        {
            temp = top;

            while (temp != NULL)
            {

                printf("\n\tThe Student ID is : ");
                cout << temp->student_id << "\n\n";
                printf("\tThe Student name is : ");
                cout << temp->name << "\n\n";
                printf("\tThe Student age is : ");
                cout << temp->age << "\n\n";
                printf("\tThe Student gender is : ");
                cout << temp->gender << "\n\n";
                printf("\tThe Student Percent is : ");
                cout << temp->percent << "\n\n";
                cout << "\n____________________________________________________\n";
                temp = temp->next;
            }
        }
    }
    void pop()
    {
        node* temp;
        while (top != NULL)
        {
            temp = top;
            top = top->next;
            free(temp);
        }
    }
}z;
class BST :public tree_node
{
    tree_node* root;

public:

    BST()
    {
        root = NULL;
    }

    tree_node* add_to_tree(tree_node* temp, BST B)
    {
        if (temp == NULL)
        {
            temp = new tree_node;

            temp->student_id = B.student_id;
            temp->name = B.name;
            temp->age = B.age;
            temp->percent = B.percent;
            temp->gender = B.gender;

            //left and right are NULL already
        }
        else
        {
            if (B.percent < temp->percent)
            {
                temp->left = add_to_tree(temp->left, B);
            }
            else
            {
                temp->right = add_to_tree(temp->right, B);
            }
        }

        return temp;
    }
    void add_to_tree(BST B)
    {
        root = add_to_tree(root, B);
    }

    void Inorder(tree_node* temp) // left->root -> right 
    {
        if (temp == NULL)
        {
            return;
        }

        Inorder(temp->left);

        z.name = temp->name;
        z.age = temp->age;
        z.student_id = temp->student_id;
        z.percent = temp->percent;
        z.gender = temp->gender;

        z.push(z);

        Inorder(temp->right);
    }
    void Inorder()
    {
        Inorder(root);
    }

}TREE;
class Queue : public node
{
    node* front;
    node* rear;

public:

    Queue()
    {
        front = rear = NULL;
    }
    void Display(node* display)
    {
        cout << "\t\t\t____________________________________________________\n";
        cout << "\n\t\t\t                   The student data                 ";
        cout << "\n\t\t\t____________________________________________________\n\n\n";

        printf("  The Student ID is : ");
        cout << display->student_id << "\n\n";

        printf("  The Student name is : ");
        cout << display->name << "\n\n";

        printf("  The Student age is : ");
        cout << display->age << "\n\n";

        printf("  The Student gender is : ");
        cout << display->gender << "\n\n";

        printf("  The Student Percent is : ");
        cout << display->percent << "\n\n\n\n";

    }
    void Display()
    {
        node* temp = front;
        if (front == NULL)
        {
            printf("There is no Students\n\n\n\n");
            return;
        }
        else
        {
            cout << "\t\t\t\t**************************************************";
            cout << "\n\t\t\t\t                      History                  ";
            cout << "\n\t\t\t\t**************************************************\n\n\n";
            while (temp != NULL)
            {
                Display(temp);
                printf("\n");
                temp = temp->next;
            }
        }
    }
    void Enqueue()
    {
        string var_name = {}, var_gender = {};
        int var_age = 0,var_percent=0;

        printf("\n\tEnter name of the Student: ");
        cin >> var_name;
        printf("\n\tEnter age of the Student: ");
        cin >> var_age;
        printf("\n\tEnter Gender of the Student: ");
        cin >> var_gender;
        printf("\n\tEnter the percent of the Student: ");
        cin >> var_percent;

        if (var_percent < 50)
        {

            printf("\n\n\tTHE STUDENT MUST REACH OUR MIN. \n\n\n ");
            return;
        }
        else
        {
            if (front == NULL)
            {
                rear = new node;

                rear->student_id = TREE.student_id = rand() % 1000;
                rear->name = TREE.name = var_name;
                rear->gender = TREE.gender = var_gender;
                rear->age = TREE.age = var_age;
                rear->percent = TREE.percent = var_percent;

                front = rear;

                TREE.add_to_tree(TREE);
                system("cls");
                Display(rear);
            }
            else
            {
                node* temp = new node;

                temp->student_id = TREE.student_id = rand() % 1000;
                temp->name = TREE.name = var_name;
                temp->gender = TREE.gender = var_gender;
                temp->age = TREE.age = var_age;
                temp->percent = TREE.percent = var_percent;

                temp->next = NULL;
                rear->next = temp;
                rear = temp;

                TREE.add_to_tree(TREE);
                system("cls");
                Display(temp);

            }
        }
    }
    void SearchQ()
    {
        int x;
        system("cls");
        cout << "\t\t\t____________________________________________________\n";
        cout << "\n\t\t\t                   The student data                 ";
        cout << "\n\t\t\t____________________________________________________\n\n\n";
        printf("Please Enter Id of the studnet : ");
        cin >> x;
        node* temp = front;
        if (temp==NULL)
        {
            printf("There  is no students\n");
            return;
        }
        else
        {
            system("cls");
            while (temp!=NULL)
            {
                if (x == temp->student_id)
                {
                    Display(temp);
                }
                temp = temp->next;
            }
        }
    }
    void show_candidates() 
    {

        system("cls");
        cout << "\t\t\t____________________________________________________\n";
        cout << "\n\t\t\t                   STUDENT DATA                 ";
        cout << "\n\t\t\t____________________________________________________\n\n";
        z.pop();
        TREE.Inorder();
        z.display_stack();

    }
    /* void Dequeue()
 {
     temp = front;
     if (front == NULL)
     {
         printf("Queue is underflow\n");
         return;
     }
     else
     {
         if (temp->next != NULL)
         {
             printf("\nThis new registerd student is : \n\n");
             Display(front);
             front = front->next;
             free(temp);
         }
         else
         {
             printf("\nThis new registerd student is : \n\n");

             Display(front);
             front = rear = NULL;
         }
     }
 }  */

}q;
void RUN()
{
    system("Color 70");
main_menu:
    system("cls");
    cout << "\n\n\t\t\t\t*********************************************";
    cout << "\n\t\t\t\t                  MAIN MENU                  ";
    cout << "\n\t\t\t\t*********************************************\n\n";
    cout << "\n\n\t1.Register for a Student";
    cout << "\n\n\t2.Show Candidates ";
    cout << "\n\n\t3.Search ";
    cout << "\n\n\t4.History";
    cout << "\n\n\t5.Exit ";
    cout << "\n\n\n\tEnter your Choice -> ";

    int ch;
    cin >> ch;

    switch (ch)
    {
    case 1:
        system("cls");

        printf("\n\n   Please Enter the Student Details : \n");
        printf("   ________________________________ \n\n");
        q.Enqueue();
        system("pause");
        goto main_menu;

    case 2:
    sec_menu:
        q.show_candidates();
        system("pause");
        system("cls");
        goto main_menu;

    case 3:

        q.SearchQ();
        system("pause");
        goto main_menu;

    case 4:
        system("cls");
        q.Display();
        system("pause");
        goto main_menu;
    case 5:
        exit(1);
        break;
    default:
        printf("Please Choose a valid option\n");
        system("pause");
        goto main_menu;
    }

}
int main()
{
    RUN();
}
