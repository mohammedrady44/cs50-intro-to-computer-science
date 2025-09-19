import basicfunc
def main():
    number = basicfunc.get_int("Number: ")
    limit = len(str(number))
    subset = str(number)
    rest= 0
    base = 0
    for i in range(limit):
        mod = number % 10
        number = number // 10
        if i % 2 == 0 :
            rest += mod
        else:
            check = 2 * mod
            if len(str(check)) != 1:
                base += (check % 10) + (check // 10)
            else:
                base += check   
    
    check_sum = base + rest
    
    if check_sum % 10 == 0:
        start = subset[0] + subset[1]        
        if limit == 15 and int(start) in [34,37]:
            print("AMEX")
        
        elif limit == 16 and int(start) in range(51,56):
            print("MASTERCARD")

        elif limit in [13,16] and int(start[0]) == 4:
            print("VISA")
        else:
            print("INVALID")             

    else:
        print("INVALID")             

main()