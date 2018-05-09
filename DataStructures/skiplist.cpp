#include <iostream>
#include <climits>
#include <ctime>
using namespace std;

struct SLNode{
    SLNode **next;
    int val;
    int lvl;

    SLNode(int value, int level){
        val=value;
        lvl=level;
        next = new SLNode *[level];
    }
};

class SkipList{
private:
    int maxlvl;
    SLNode *head;
    SLNode *tail;
public:
    SkipList(int max){
        maxlvl=max;
        head=new SLNode(INT_MIN, max);
        tail=new SLNode(INT_MAX, max);
        for(int i=0; i<max; i++)
            head->next[i]=tail;
    }

    int getLvl(double p=0.5){
        int h=1;
        while ((double)rand()/RAND_MAX<p)
            h++;
        if(h<=maxlvl) return h;
        return maxlvl;
    }

    void printSL(){
        SLNode *it;
        for(int i=0; i<maxlvl; i++){
            it=head->next[i];
            while (it!=tail){
                cout << it->val << " ";
                it=it->next[i];
            }
            cout << endl;
        }
    }

    void insert(int key){
        int h=getLvl();
        SLNode *el=new SLNode(key, h);
        SLNode *it=head;
        for(int i=maxlvl-1; i>=0; i--){
            while(it->next[i]->val < key)
                it=it->next[i];
            if(i<h){
                el->next[i]=it->next[i];
                it->next[i]=el;
            }
        }
    }

    void remove(int key){
        SLNode *it=head;
        SLNode *tmp=NULL;
        for(int i=maxlvl-1; i>=0; i--){
            while(it->next[i]->val < key)
                it=it->next[i];
            if(it->next[i]->val==key){
                tmp=it->next[i];
                it->next[i]=tmp->next[i];
            }
        }
        if(tmp!=NULL) delete tmp;
    }

};

int main(){

}


