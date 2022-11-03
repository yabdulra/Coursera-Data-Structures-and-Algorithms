#!/usr/bin/env python
# coding: utf-8

# In[ ]:


"""
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
"""
# create table to store any number between 0 and 10**7
contact_list = ['not found']*(10**7)

class PhoneBook:
    def __init__(self, query):
        self.type = query[0]
        self.number = int(query[1])
        if self.type == 'add':
            self.name = query[2]
    
    def add(self, number, name):
        contact_list[number] = name
    
    def delete(self, number):
        contact_list[number] = 'not found'
    
    def find(self, number):
        return contact_list[number]
        

def read_queries():
    n = int(input())
    return [PhoneBook(input().split()) for i in range(n)]

def process_queries(queries):
    result = []
    
    for query in queries:
        if query.type == 'add':
            query.add(query.number, query.name)
        elif query.type == 'del':
            query.delete(query.number)
        elif query.type == 'find':
            result.append(query.find(query.number))
        else:
            print("Invalid request")     
    return result

def write_responses(results):
    for result in results:
        print(result)

if __name__ == '__main__':
    write_responses(process_queries(read_queries()))
