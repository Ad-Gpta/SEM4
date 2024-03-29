# -*- coding: utf-8 -*-
"""
Created on Tue May  2 21:27:13 2023

@author: Aditi
"""

#using bfs

Q = []
board = [[1]*8]*8
pos = [0]*8
row = 0

def place():
    board = [[1]*8]*8
    pos = [0]*8
    row = 0
    Q.append([board,row, pos])
    while(Q!= []):
        [board,row, pos] = Q[0]
        Q.remove(Q[0])
        if(row == 8):
            print(pos)
        for col in range(0, 8): #for each column in a board
            new_board = board
            new_pos = pos
            if new_board[row][col] == 1:
                new_pos[row] = col
                #j = rows
                for j in range(8): #this column is invalid
                    new_board[j][col] == 0
                for k in range(1,min(row, col)+1): #diagonal elements in prev rows
                    new_board[j-k][col-k] == 0
                for k in range(max(row,col), 8):
                    new_board[k][k] == 0
                Q.append([new_board,row+1, new_pos])'
            else:
                continue

place()