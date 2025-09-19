def get_int(text):
    while True:
        try:
            return int(input(text))
        except ValueError:
            pass

def get_float(text):
    while True:
        try:
            return float(input(text))
        except ValueError:
            pass

def my_replace(text,old,new):
    size = len(old)
    start,end = 0,size
    size_2 = len(text)
    final = ""
    while(end <= size_2):          
        if text[start:end] == old:
            final += new 
            start = end
            end += size
        else:
            final += text[start]
            start += 1
            end += 1

    if size != size_2:
        final += text[start:size_2]
    return final    

def my_strip(text):
    size = len(text)
    for i in range(size): #trailing
        if text[i] != " ":
            break
    
    for j in range(size - 1, -1,-1): #leading
        if text[j] != " ":
            break
    return  text[i:j+1]   

        