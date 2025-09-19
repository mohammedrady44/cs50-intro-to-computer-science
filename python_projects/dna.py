import csv
import sys
def main(): 
    data = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        names = reader.fieldnames
        for i in reader:
            data.append(i)
    my_instance = open(sys.argv[2])
    text =  my_instance.read()
    indentify(text,data,names)       

def indentify(patterns,data,names):
    size = len(patterns)
    mydiction = {}
    length = len(names)
    for f in range(1,length): #intialize(patteren : 0)
        mydiction[names[f]] = 0
    
    for di in mydiction:
        current_size = len(di)
        fail = False
        start, end, subset, final = 0,0,0,0
        while True:        
            if fail == False:
                start = end
                end += current_size   
            
            if end > size:
                break
 
            if patterns[start:end] == di:  #matching 
                fail = False
                subset += 1
            
            else: #no matching
                fail = True
                start += 1
                end += 1
                final = max(final,subset)
                subset = 0
        
        final = max(final,subset)        
        mydiction[di] = final
       
    length_actual = length - 1
    for row in data:
        count = 0
        for key in mydiction:
            if int(row[key]) != mydiction[key]:
                break
            count += 1
        if count == length_actual:
            sys.exit(row["name"])
    print("No match")
            

main()