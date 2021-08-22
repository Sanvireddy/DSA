#include <iostream>
#include <list>
using namespace std;

//bidirection list
//efficient insertion and deletion

void display(list<int> &lst)
{
    list<int>::iterator iter;
    for (iter = lst.begin(); iter != lst.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

int main()
{
    list<int> list1;    //List of zero length
    list<int> list2(5); //empty list of size 7
    //there are elements in it but there are no values for it
    list1.push_back(5);
    list1.push_back(50);
    list1.push_back(15);
    list1.push_back(15);
    list1.push_back(59);
    list1.push_back(8);
    /*
    list<int>::iterator iter;
    iter = list1.begin();
    cout << *iter << " ";
    iter++;
    cout << *iter << " ";
    iter++;
    cout << *iter << " ";
    iter++;
    cout << *iter << " ";
    */
    //display(list1);

    list<int>::iterator it;
    it = list2.begin();
    *it = 45;
    it++;
    *it = 5;
    it++;
    *it = 4;
    it++;
    *it = 415;
    it++;
    *it = 15;

    //display(list2);

    //Removing elements from a list
    list1.pop_back();
    //display(list1);
    list1.pop_front();
    //display(list1);

    //can delete element from anywhere in list
    //it deletes all occurences of 15
    list1.remove(15);
    list1.push_back(15);
    //display(list1);
    //sorting elements of list

    //list2.sort();
    display(list2);

    list1.merge(list2);
    cout << "List1 After merging: ";
    display(list1);
    cout << "List2 after merging: ";
    display(list2);

    list1.reverse();
    cout << "AFTER REVERSING LIST1: ";
    display(list1);
    return 0;
}