# -*- coding: utf-8 -*-
"""
Created on Wed Feb 14 09:10:49 2018

@author: Richard Cann
"""

import numpy as np

table = np.loadtxt("blosum50.txt", dtype="int")

blosumIndex = np.array(['A', 'R', 'N', 'D', 'C', 'Q', 'E', 'G', 'H', 'I', 'L', 
                        'K', 'M', 'F', 'P', 'S', 'T', 'W', 'Y', 'V'], dtype='str')

def globalMatch(sequence_one, sequence_two):
    seq1 = list(sequence_one)
    seq2 = list(sequence_two)
    #insert first as zero for dyamic programming
    seq1.insert(0, ' ')
    seq2.insert(0, ' ')
    #represents the score taken from blosum at each index
    scores = np.zeros(shape=(len(seq1),len(seq2)))
    #the best path to follow from a given index
    path = np.ndarray(shape=(len(seq1),len(seq2)), dtype=object)
    #looping through matrix
    for i in range(0, scores.shape[0]):
        for j in range(0, scores.shape[1]):
            s1 = 0
            s2 = 0
            s3 = 0
            #three conditions to see what is best path
            #get diagonal and add blosum score
            if i-1 >= 0 and j-1 >= 0:
                s1 = scores[i-1][j-1] + table[np.where(blosumIndex==seq1[i])[0][0], 
                    np.where(blosumIndex==seq2[j])[0][0]]
            #get the left score and subract 8
            if i-1 >= 0:
                s2 = scores[i-1][j]-8
            #get above score and subtract 8
            if j-1 >= 0:
                s3 = scores[i][j-1]-8
            #get maximum of three scores and insert in scores matrix
            maximum = max(s1, s2, s3)
            if i > 0 and j > 0 and maximum==s1:
                scores[i][j] = s1
                path[i][j] = np.array([i-1, j-1])
            elif j==0 or (i > 0 and maximum==s2):
                scores[i][j] = s2
                path[i][j] = np.array([i-1 , j])
            else:
                scores[i][j] = s3
                path[i][j] = np.array([i , j-1])
                
    #backtrack algorithm, addidn this for termination
    path[0][0] = np.array([-1, -1])
    
    least_path = []
    list_seq1 = []
    list_seq2 = []
    i = len(seq1)-1
    j = len(seq2)-1
    #while is not top left of matrix
    while path[i][j][0] != -1 and path[i][j][1] != -1:
        point = path[i][j]
        least_path.append(point)
        #if path is diagonal then add both letters to common sequence
        if i-1 == point[0] and j-1 == point[1]:
            list_seq1.append(seq1[i])
            list_seq2.append(seq2[j])
        #if path oints at the left take out letter from one sequence else do
        #the opposite
        elif i-1 == point[0] and j == point[1]:
            list_seq1.append(seq1[i])
            list_seq2.append('-')
        else:
            list_seq1.append('-')
            list_seq2.append(seq2[j])
        i = point[0]
        j = point[1]
    
    list_seq1.reverse()
    list_seq2.reverse()
    print(''.join(list_seq1))
    print(''.join(list_seq2))
    
def localMatch(sequence_one, sequence_two):
    #same as global but insist F(i, j) > 0
    seq1 = list(sequence_one)
    seq2 = list(sequence_two)
    seq1.insert(0, ' ')
    seq2.insert(0, ' ')
    
    scores = np.zeros(shape=(len(seq1),len(seq2)))
    path = np.ndarray(shape=(len(seq1),len(seq2)), dtype=object)
    #need maxes for i and j to store highest F(i, j)
    maxi = 0
    maxj = 0
    for i in range(0, scores.shape[0]):
        for j in range(0, scores.shape[1]):
            s1 = 0
            s2 = 0
            s3 = 0
            if i-1 >= 0 and j-1 >= 0:
                s1 = scores[i-1][j-1] + table[np.where(blosumIndex==seq1[i])[0][0], 
                    np.where(blosumIndex==seq2[j])[0][0]]
            if i-1 >= 0:
                s2 = scores[i-1][j]-8
            if j-1 >= 0:
                s3 = scores[i][j-1]-8
            
            #zero added for local
            maximum = max(s1, s2, s3, 0)
            if maximum==0:
                scores[i][j] = 0
                path[i][j] = np.array([-1, -1])
            elif i > 0 and j > 0 and maximum==s1:
                scores[i][j] = s1
                path[i][j] = np.array([i-1, j-1])
            elif j==0 or (i > 0 and maximum==s2):
                scores[i][j] = s2
                path[i][j] = np.array([i-1 , j])
            else:
                scores[i][j] = s3
                path[i][j] = np.array([i , j-1])
            #added for local
            if scores[i][j] > scores[maxi][maxj]:
                maxi = i
                maxj = j
                
    
    path[0][0] = np.array([-1, -1])
    
    least_path = []
    list_seq1 = []
    list_seq2 = []
    
    i = maxi
    j = maxj
    #we start at max and work back until we reach zero
    while path[i][j][0] != -1 and path[i][j][1] != -1:
        point = path[i][j]
        least_path.append(point)
        if i-1 == point[0] and j-1 == point[1]:
            list_seq1.append(seq1[i])
            list_seq2.append(seq2[j])
        elif i-1 == point[0] and j == point[1]:
            list_seq1.append(seq1[i])
            list_seq2.append('-')
        else:
            list_seq1.append('-')
            list_seq2.append(seq2[j])
        i = point[0]
        j = point[1]
    
    list_seq1.reverse()
    list_seq2.reverse()
    print(''.join(list_seq1))
    print(''.join(list_seq2))
    
print('Global Matches:')
globalMatch('HEAGAWGHEE', 'PAWHEAE')
globalMatch('SALPQPTTPVSSFTSGSMLGRTDTALTNTYSAL', 'PSPTMEAVTSVEASTASHPHSTSSYFATTYYHLY')
print('')
print('Local Matches:')
localMatch('HEAGAWGHEE', 'PAWHEAE')
localMatch('MQNSHSGVNQLGGVFVNGRPLPDSTRQKIVELAHSGARPCDISRILQVSNGCVSKILGRY', 
           'TDDECHSGVNQLGGVFVGGRPLPDSTRQKIVELAHSGARPCDISRI')
    

