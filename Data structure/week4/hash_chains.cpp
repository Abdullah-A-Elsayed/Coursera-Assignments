#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

struct Query { //for both name and query
    string type, name;
    int number;
    Query(){
        name = "";
        number = -1;
    }
};
int card;
vector<Query> read_queries() {
    int m,n;
    cin >> m;
    card = m;
    cin>>n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "check")
            cin >> queries[i].number;
        else
           cin >> queries[i].name;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        cout << result[i] << "\n";
}

int hash_str(string s){//let x = 263, p 1000000007
    long long hash=0;
    for(int i=s.length()-1; i>-1; i--)
        hash = ((hash*263)+int(s[i]))%1000000007;
    hash%= card;
    return hash;
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<list<string>> words(card);//list based addressing
    for (size_t i = 0; i < queries.size(); ++i){
        int hash = (queries[i].type=="check")? queries[i].number :  hash_str(queries[i].name);
        bool exist = false;
        list<string>::iterator it;
        for(it =words[hash].begin();it!=words[hash].end();it++){
            if(*it == queries[i].name){
                exist = true;
                break;
            }
        }
        if (queries[i].type == "add") {
            if(!exist){
                words[hash].push_back(queries[i].name);
            }
            else  *it = queries[i].name;
        } else if (queries[i].type == "del") {
            if(exist) words[hash].erase(it);
        } else if (queries[i].type == "find"){ //find
            if(exist) result.push_back("yes");
            else result.push_back("no");
        }
        else{
            string o="";
            if(!words[hash].empty()){
                --it;
                while(it != words[hash].begin()){
                    o+=(*it+" ");
                    --it;
                }
                o+=*it;//first record
            }
            result.push_back(o);
        }
    }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
