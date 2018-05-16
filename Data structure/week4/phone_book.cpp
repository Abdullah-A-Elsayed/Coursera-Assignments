#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

struct Query { //for both name and query
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        cout << result[i] << "\n";
}

int hash_int(int n){//using m=1000, p = 10000019, a=3, b=7
    return ((3*n+7)%10000019)%1000;
}
vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    list<Query> contacts[1000];//list based addressing
    for (size_t i = 0; i < queries.size(); ++i){
        int hash = hash_int(queries[i].number);
        bool exist = false;
        list<Query>::iterator it;
        for(it =contacts[hash].begin();it!=contacts[hash].end();it++){
            if(it->number == queries[i].number){
                exist = true;
                break;
            }
        }
        if (queries[i].type == "add") {
            if(!exist){
                Query n;
                n.name = queries[i].name;
                n.number = queries[i].number;
                contacts[hash].push_back(n);
            }
            else  it->name = queries[i].name;
        } else if (queries[i].type == "del") {
            if(exist) contacts[hash].erase(it);
        } else { //find
            if(exist) result.push_back(it->name);
            else result.push_back("not found");
        }
    }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
