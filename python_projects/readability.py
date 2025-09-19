def main():
    text = input("Text: ")
    let_num = letters(text)
    sen_num = sentences(text)
    wor_num = words(text)
    l = (let_num / wor_num) * 100
    s = (sen_num / wor_num) * 100
    index = 0.0588 * l - 0.296 * s - 15.8
    final = round(index)
    if final < 1:
        print("Before Grade 1")
    
    elif final >= 16:
        print("Grade 16+")

    else:
        print(f"Grade {final}")        


def letters(text):
    count = 0
    for letter in text:
        if letter.isalpha() == True:
            count += 1
    return count

def words(text):
    count = 0
    for letter in text:
        if letter == " ":
            count +=1
    return count + 1        

def sentences(text):
    count = 0
    for letter in text:
        if letter in [".","?","!"]:
            count +=1
    return count

main()
