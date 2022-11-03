#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using std::string;
using std::vector;
using std::cin;
/*
In this task your goal is to implement a simple phone book manager. It should be able to process
the following types of user’s queries:
    1. add number name. It means that the user adds a person with name name and phone number
    number to the phone book. If there exists a user with such number already, then your manager
    has to overwrite the corresponding name.
    2. del number. It means that the manager should erase a person with number number from the
    phone book. If there is no such person, then it should just ignore the query.
    3. find number. It means that the user looks for a person with phone number number. The manager
    should reply with the appropriate name, or with string “not found" (without quotes) if there is
    no such person in the book.
*/

// create table to sotre any number between 0 and 10**7
vector<string> contacts(pow(10, 7), "not found");

// define phonebook and its member functions
struct PhoneBook {
    void add(int number, string name) {
        contacts[number] = name;
    }
    void del(int number) {
        contacts[number] = "not found";
    }
    string find(int number) const { return contacts[number]; }
};

struct Query {
    string type, name;
    int number;
};

// read and store quesries
vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i != n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (auto r : result) std::cout << r << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result; // store results for 'find' query
  
    PhoneBook pb;
    for (auto query : queries) {
        if (query.type == "add") pb.add(query.number, query.name);
        else if (query.type == "del") pb.del(query.number);
        else if (query.type == "find") result.push_back(pb.find(query.number));
        else std::cout << "Invalid request" << "\n";
    }

    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
