// given this org chart and people's music choices
// John (Rock)
// --+ May (Classical)
// ----+ Dawn (Rock)
// ------+ Duke (Jazz)
// ----+ Shawn (Classical)
// ------+ Cooper (Jazz)
// --------+ Jasmine (Rock)
// --+ Sheldon (Jazz)

// now write how you want to store this info and also implement a function that woud take a person's name and genre of music and give the members of the said music community below them.
// Lets say f(May, Rock) -> [Dawn, Jasmine] (Both of them are under May and like Rock Music)

#include <bits/stdc++.h>
using namespace std;
struct Person
{
    string name;
    string genre;
    vector<Person *> subordinates;
    Person(string name, string genre) : name(name), genre(genre), subordinates({}) {}
};
class Solution
{
public:
    vector<Person *> findCommunity(Person *ceo, string name, string genre)
    {
        queue<Person *> q;
        q.push(ceo);

        while (!q.empty() && q.front()->name != name)
        {
            Person *ancestor = q.front();
            q.pop();
            for (Person *p : ancestor->subordinates)
            {
                q.push(p);
            }
        }
        Person *lca = q.front();
        while (!q.empty())
        {
            q.pop();
        }
        q.push(lca);
        vector<Person *> res;
        while (!q.empty())
        {
            Person *anscestor = q.front();
            q.pop();
            if (anscestor->genre == genre)
            {
                res.push_back(anscestor);
            }
            for (Person *p : anscestor->subordinates)
            {
                q.push(p);
            }
        }
        return res;
    }
};
int main()
{
    Person *p = new Person("John", "Rock");
    p->subordinates = {new Person("May", "Classical"), new Person("Sheldon", "Jazz")};
    p->subordinates[0]->subordinates = {new Person("Dawn", "Rock"), new Person("Shawn", "Classical")};
    p->subordinates[0]->subordinates[0]->subordinates = {new Person("Duke", "Jazz")};
    p->subordinates[0]->subordinates[1]->subordinates = {new Person("Cooper", "Jazz")};
    p->subordinates[0]->subordinates[1]->subordinates[0]->subordinates = {new Person("Jasmine", "Rock")};
    Solution obj;
    vector<Person *> community = obj.findCommunity(p, "May", "Rock");
    for (Person *p : community)
    {
        cout << p->name << ", ";
    }
    cout << endl;
    return 0;
}