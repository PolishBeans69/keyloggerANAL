#!./env/bin/python
signs_arr = ["a","b","c","d","e","f","g","h","i","j",
             "k","l","m","n","o","p","q","r","s","t",
             "u","v","w","x","y","z","1","2","3","4",
             "5","6","7","8","9","0","space","enter"] #if ya wanna add shiet then do it in the same order as in the cpp file
int_arr = []
with open("zapis","r") as file:
    for line in file:
        int_arr.append(int(line.rstrip()))
if (len(int_arr)==len(signs_arr)):
    for _ in range(len(int_arr)):
        print(f'{signs_arr[_]}: {int_arr[_]}')
else: print("you fucked up")