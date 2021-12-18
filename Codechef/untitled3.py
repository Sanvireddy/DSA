#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Nov 21 21:54:35 2021

@author: sanvireddy
"""

for _ in range(int(input())):
    n= int(input())
    arr = list(map(int,input().strip().split()))[:n]
    res=0
    sum1=arr[0]-arr[1]
    sum2=((n-2)*arr[1]) - sum(arr)+arr[0]+arr[1]
    res+=(sum1*sum2)
    print(res)
    for i in range(2,n-1):
        sum1+=(2*arr[i-1])-arr[i]
        sum2+=((n-i)*arr[i])-((n-i)*arr[i-1])
        print(sum1*sum2)
        res+=(sum1*sum2)
    print(res)
        