
#include<string>
using namespace std;
typedef std::string listelemtype;
class inord_list
{
private:
struct node;
typedef node* link;
struct node
{
    listelemtype elem;
    int elemline;
    link next;

};
link tail;

link currentpos;
link predessor;

public:
    link head ;
    inord_list();
    bool insert(const listelemtype& e,int& linenum);
    bool first(listelemtype& e , int&linenum);
    bool next(listelemtype& e , int&linenum);
    //bool exist(string& elem,int& linenum,int& linearr[5000][5000],string& arr[5000]);
};
