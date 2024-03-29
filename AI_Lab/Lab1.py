#!/usr/bin/env python
# coding: utf-8

# Q1) queue using 2 stack operations
# method: making deQueue operation costly

# In[14]:


stk1 = []
stk2 = []
def enQ():
    n = int(input("Enter new element: "))
    stk1.append(n)
def deQ():
    stk2.clear()
    for i in range(0,len(stk1)):
        stk2.append(stk1.pop())
    print("popped element: ",stk2.pop())
    for i in range(0,len(stk2)):
        stk1.append(stk2.pop())
def disp1():
    print("Stack1: ")
    for i in stk1:
        print(i)
        print()
def disp2():
    print("Stack2: ")
    for i in stk2:
        print(i)
        print()

print("Enter:\n1.Enqueue\n2.Dequeue\n3.Disp1\n4.Disp2\n5.Exit")
ch = 0
while(ch!=5):
    ch = int(input("Choice: "))
    if(ch==1):
        enQ()
    elif(ch==2):
        deQ()
    elif(ch==3):
        disp1()
    elif(ch==4):
        disp2()


# Q3)Create two list X and Y with some set of numerical values. Compute Euclidean distance for corresponding values in X and Y. Store the distance values in a separate list and sort them using Bubble sort algorithm.

# In[15]:


import math
X = [[6,7],[8,9],[10,11]]
Y = [[5,4],[3,2],[1,-1]]
dist= []
for k in range(0,len(X)):
    sum = 0
    i = X[k]
    j = Y[k]
    for l in range(len(i)):
        sum += (i[l]-j[l])**2
    dist.append(math.sqrt(sum))
print(dist)
for j in range(len(dist)):
    for i in range(len(dist)-j-1):
        if(dist[i]<dist[i+1]):
            t = dist[i]
            dist[i] = dist[i+1]
            dist[i+1] = t
print(dist)


# Q4) Implement the given binary search tree using Python and print the pre-order, in-order, and post-order tree traversal. 

# In[29]:


"""class Node:
    val = 0
    left = Node()
    right = Node()
    
def init(h,data):
    self.left= None
    self.right = None
    self.val = data

class Node:
    def __init__(self,data):
        self.left= None
        self.right = None
        self.val = data

    def insert(data,self):
        if(data<self.val):
            while(data<self.val):
                self = self.left
            if(self.left is None):
                self.left = Node(data)
            else:
                self.left.val = data
        elif(data>self.val):
            while(data>self.val):
                self= self.right
            if(self.right is None):
                self.right = Node(data)
            else:
                self.right.val = data

def inorder(root):
    if(root is None):
        return;
    inorder(root.left)
    print(root.val)
    inorder(root.right)
    
h = Node(25)
insert(h,15)
insert(h,10)
insert(h,4)
insert(h,12)"""


# In[ ]:


class Node:
   def __init__(self, data):
      self.left = None
      self.right = None
      self.data = data
# Insert Node
   def insert(self, data):
      if self.data:
         if data < self.data:
            if self.left is None:
               self.left = Node(data)
            else:
               self.left.insert(data)
         else data > self.data:
            if self.right is None:
               self.right = Node(data)
            else:
               self.right.insert(data)
      else:
         self.data = data
# Print the Tree
   def PrintTree(self):
      if self.left:
         self.left.PrintTree()
      print( self.data),
      if self.right:
         self.right.PrintTree()
# Inorder traversal
# Left -> Root -> Right
   def inorderTraversal(self, root):
      res = []
      if root:
         res = self.inorderTraversal(root.left)
         res.append(root.data)
         res = res + self.inorderTraversal(root.right)
      return res
root = Node(25)
root.insert(15)
root.insert(10)
root.insert(4)
root.insert(12)
root.insert(22)
root.insert(18)
root.insert(24)
root.insert(50)
print(root.inorderTraversal(root))

