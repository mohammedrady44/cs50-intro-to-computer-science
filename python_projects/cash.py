import basicfunc
def main():
    while True:
        change_owed = basicfunc.get_float("Change: ")#make sure that user don't enter negative num
        if change_owed > 0:
            break
    
    change_owed = change_owed * 100 #from dollar to cents
    mini_num  = 0
    index = 0
    coins = [25,10,5,1]
    while change_owed > 0:
        if change_owed >= coins[index]:
            change_owed -= coins[index]
            mini_num +=1
        else:
            index +=1
    
    print(mini_num)            


main()