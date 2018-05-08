#include <iostream>
using namespace std;

class hashTable{
private:
    int size;
    int *key = new int[size];
    int *state = new int[size];
    //0-empty, 1-occupied, -1-deleted
public:
    hashTable(int s);
    void insert(int k);
    bool search(int k);
    void remove(int k);
};

int h(int key, int size){ return key%size; }

int h(int key, int size, int i){ return (h(key, size)+i)%size; }

hashTable::hashTable(int s){
    size = s;
    for(int i=0; i<s; i++){
        key[i]=NULL;
        state[i]=0;
    }
}

void hashTable::insert(int k){
    int idx;
    for(int i=0; i<size; i++){
        idx = h(k, size, i);
        if(state[idx] != 1) break;
    }
    key[idx] = k;
    state[idx] = 1;
}

bool hashTable::search(int k){
    int idx;
    for(int i=0; i<size; i++){
        idx = h(k, size, i);
        if(state[idx]==0 || key[idx]==k) break;
    }
    return key[idx] == k;
}

void hashTable::remove(int k){
    int idx;
    for(int i=0; i<size; i++){
        idx = h(k, size, i);
        if(state==0 || key[idx]==k) break;
    }
    if(key[idx]==k){
        key[idx]=NULL;
        state[idx]=-1;
    }
}

int main(){
    hashTable ht=hashTable(1000);
    ht.insert(500);
    if(ht.search(500)) cout << "znaleziono\n";
}
