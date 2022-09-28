#include <iostream>
#include <queue>
#include <vector>

/*
Please refer to week1_basic_data_structures.pdf for details about the requirements
for this problem.
*/

// define structs to store data for request and response.
struct Request {
    Request(int arrival_time, int process_time) :
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time) :
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};

// define a class for the buffer and set its size
class Buffer {
public:
    Buffer(int size) :
        size_(size),
        finish_time_()
    {}

    // check the status of the buffer (full or empty) to know whether a packet 
    // can be processed or not
    bool isFull() {
        return ((finish_time_.size() == size_) ? true : false);
    }

    bool isEmpty() {
        return finish_time_.empty();
    }

    // get the last element to access its finish time
    int LastElem() {
        return finish_time_.back();
    }
    // if a packet is processed, flush it out to make room for incoming packets
    void Flush_processed(const Request& request) {
        while (finish_time_.size() > 0) {
            if (finish_time_.front() <= request.arrival_time) finish_time_.pop();
            else break;
        }
    }

    Response Process(const Request& request) {
        Flush_processed(request);

        if (this->isFull()) return Response(true, -1); // drop packet if buffer is full

        // add packet to buffer and process it immediately if empty and return 
        // the time at which the processor will begin processing it
        if (this->isEmpty()) {
            finish_time_.push(request.arrival_time + request.process_time);
            return Response(false, request.arrival_time);
        }

        // if buffer is not full and not empty, push packet to the queue and return 
        // the time at which the processor will begin processing it
        finish_time_.push(this->LastElem() + request.process_time);

        return Response(false, this->LastElem());
    }
private:
    int size_;
    std::queue <int> finish_time_;
};

// read packet request and store them in a vector
std::vector <Request> ReadRequests() {
    std::vector <Request> requests;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}

// process requests and store responses
std::vector <Response> ProcessRequests(const std::vector <Request>& requests, Buffer* buffer) {
    std::vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

// print out the responses
void PrintResponses(const std::vector <Response>& responses) {
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}

int main() {
    int size;
    std::cin >> size;
    std::vector <Request> requests = ReadRequests();  // read requests

    Buffer buffer(size);
    std::vector <Response> responses = ProcessRequests(requests, &buffer); //process requests

    PrintResponses(responses);  // print responses
    return 0;
}
