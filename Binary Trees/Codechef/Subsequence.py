for _ in range(int(input())):
    n=int(input())
    cnt=0
    arr = list(map(int,input().strip().split()))[:n]
    odd=[]
    even=[]
    for i in range(0,n):
        if(i%2):
            odd.append(arr[i])
        else:
            even.append(arr[i])
    even.sort()
    odd.sort()
    for i in range(0,n):
        if(i%2):
            arr[i]=odd[i/2]
        else:
            arr[i]=even[i/2]
        cnt = cnt + even[i/2]*(sum(odd[:i]))
        print(arr[i])
    
    print(cnt)
        

