import basicfunc
def main():
    while True:
        height = basicfunc.get_int("Height: ")
        if height >= 1 and height <= 8:
            break   
    
    space = height - 1
    for i in range(height):
        print(" " * space,end = "")
        space -= 1
        print("#" * (i + 1))

main()