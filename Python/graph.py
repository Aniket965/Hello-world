# -*- coding: utf-8 -*-
"""
Created on Fri Oct 12 00:49:35 2018

@author: Varshika Choudhary
"""
t = int(input())
for _ in range(t):
    V,E = map(int,input().split())
    
    graph = {}
    
    for i in range(V):
        graph[i] = []
    
    for _ in range(E):
        src,dest = map(int,input().split())
        graph[src].append(dest)
        graph[dest].append(src)
    
    for v,e in graph.items():
        print("-> ".join([str(v)] + [str(x) for x in e]))