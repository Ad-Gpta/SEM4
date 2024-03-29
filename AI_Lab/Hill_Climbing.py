# -*- coding: utf-8 -*-
"""
Created on Wed Mar 29 07:11:58 2023

@author: Aditi
"""

#maximization
import random

def obj(x):
    return x*3
def HCS(start, step, max_itr):
    curr = start
    curr_val = obj(curr)
    for i in range(max_itr):
        adj = curr + step*random.random()
        adj_val = obj(adj)
        if curr_val<adj_val:
            curr = adj
            curr_val = adj_val
            return curr, curr_val   #returns next largest number be find
        print("no larger value found")
        return None, None

"""max_num, max_val = HCS(0,0.5,50)
if(max_num!=None):
    print("max: ",max_num," max_val: ",max_val)  """   

max_num = 0
max_val=0
for i in range(-10,10):   #calling the function multiple times to find largest in the area
    res, res1 = HCS(i,0.5,50)
    if(res>max_num):
        max_num = res
        max_val = res1

print("max: ",max_num," max_val: ",max_val)