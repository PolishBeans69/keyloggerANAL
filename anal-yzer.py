#!./env/bin/python
signs_arr = ["a","b","c","d","e","f","g","h","i","j",
             "k","l","m","n","o","p","q","r","s","t",
             "u","v","w","x","y","z","1","2","3","4",
             "5","6","7","8","9","0","space","enter","shift"] #if ya wanna add shiet then do it in the same order as in the cpp file
int_arr = []
with open("zapis","r") as file:
    for line in file:
        int_arr.append(int(line.rstrip()))
if (len(int_arr)==len(signs_arr)):
    dict_shit = dict(zip(signs_arr,int_arr))
    dict_shit_sorted = dict(sorted(dict_shit.items(), key=lambda item: item[1], reverse=True))
    for key,value in dict_shit_sorted.items():
        print(key,":",value) 
    suma = 0
    for i in int_arr:
        suma += int(i)
    print(f'total: {suma}')
else: print("you fucked up")
