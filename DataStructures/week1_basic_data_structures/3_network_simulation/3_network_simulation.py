#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from collections import namedtuple

"""
Please refer to week1_basic_data_structures.pdf for details about the requirements
for this problem.
"""

Request = namedtuple("Request", ["arrived_at", "time_to_process"])
Response = namedtuple("Response", ["was_dropped", "started_at"])

class Buffer:
    def __init__(self, size):
        self.size = size
        self.finished_time = []
    
    def _is_full(self):
        return True if len(self.finished_time) == self.size else False
    
    def _is_empty(self):
        return True if len(self.finished_time) == 0 else False
    
    @property
    def last_element(self):
        return self.finished_time[-1]
    
    def flush_processed(self, request):
        while self.finished_time:
            if self.finished_time[0] <= request.arrived_at:
                self.finished_time.pop(0)
            else:
                break
    
    def process(self, request):
        self.flush_processed(request)
        
        if self._is_full():
            return Response(True, -1)
        
        if self._is_empty():
            self.finished_time = [request.arrived_at + request.time_to_process]
            
            return Response(False, request.arrived_at)
        
        self.finished_time.append(self.last_element + request.time_to_process)
        
        return Response(False, self.last_element)


def process_requests(requests, buffer):
    responses = []
    for request in requests:
        responses.append(buffer.process(request))
    
    return responses

def main():
    buffer_size, n_requests = map(int, input().split())
    requests = []
    for _ in range(n_requests):
        arrived_at, time_to_process = map(int, input().split())
        requests.append(Request(arrived_at, time_to_process))
    
    buffer = Buffer(buffer_size)
    responses = process_requests(requests, buffer)
    
    for response in responses:
        print(response.started_at if not response.was_dropped else -1)
        
if __name__=="__main__":
    main()

