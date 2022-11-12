def Dynamic_Knapsack (wt, val, W, n):
    t = [[-1 for i in range (W+1)] for j in range(n+1)]
    
    for i in range(n+1):
        for j in range(W+1):
            if(i==0 or j==0):
                t[i][j]=0
            elif(wt[i-1] <= j):
                t[i][j] = max(val[i-1]+ t[i-1][j-wt[i-1]], t[i-1][j])
            else:
                t[i][j] = t[i-1][j]
    return t[n][W]
    
def Greedy_Knapsack(wt, val, W, n):
    ratio=[val[i]/wt[i] for i in range(n)]
#Selection sort on the ratio list to sort the wt, val and ratio list in descending oreder
    for i in range(n):
        max_ind = i
        for j in range (i+1 , n):
            if ratio[max_ind] < ratio[j]:
                max_ind = j
            
            ratio[i],ratio[max_ind] = ratio[max_ind], ratio[i]
            wt[i],wt[max_ind] = wt[max_ind],wt[i]
            val[i],val[max_ind]=val[max_ind],val[i]
    profit = 0
    i=0
    while(W>0 and i<n):
        if (wt[i]<W) :
            profit = val[i] + profit
            W=W-wt[i]
            i+=1
        else:
            i+=1
    return profit
def printknapSack(W, wt, val, n):
    K = [[0 for w in range(W + 1)]
         for i in range(n + 1)]

    # Build table K[][] in bottom
    # up manner
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i - 1] <= w:
                K[i][w] = max(val[i - 1]
                              + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w])
            else:
                K[i][w] = K[i - 1][w]

    # stores the result of Knapsack
    res = K[n][W]
    print(res)

    w = W
    #print("the elements are")
    for i in range(n, 0, -1):
        if res <= 0:
            break
        # either the result comes from the
        # top (K[i-1][w]) or from (val[i-1]
        # + K[i-1] [w-wt[i-1]]) as in Knapsack
        # table. If it comes from the latter
        # one/ it means the item is included.
        if res == K[i - 1][w]:
            continue
        else:

            # This item is included.
            #print(wt[i - 1])

            # Since this weight is included
            # its value is deducted
            res = res - val[i - 1]
            w = w - wt[i - 1]


# Driver code
val = [55,10,47,5,4,50,8,61,85,87]
wt = [95,4,60,32,23,72,80,62,65,46]
W = 269
n = 10

print ("Value obtained by SubSet Sum Paradism algorithm is: ")
printknapSack(W, wt, val, n)
print ("Value obtained by Dyanamic algorithm is: ")
print (Dynamic_Knapsack(wt,val,W,n))
print ("Value obtained by Greedy algorithm is: ")
print (Greedy_Knapsack(wt,val,W,n))
