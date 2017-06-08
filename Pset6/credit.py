#   credit.py
#   Aamel Unia
#   aameluni@buffalo.edu
#   Implements a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.

def main():
    
    while True:
        print("Number: ",end="")
        number = input()
        if number.isdigit() and int(number)>0:
            break
    
    productsum = 0;
    othersum = 0;
    
    for i in range(len(number)-1,0,-2):
        temp = int(number[i-1])*2
        if temp>9:
           productsum = productsum + int(str(temp)[0]) + int(str(temp)[1])
        else:
            productsum+=temp
        othersum+=int(number[i]);
    
    if len(number)%2!=0:
        othersum+=int(number[0])
    
    finalsum = productsum + othersum

    if finalsum%10!=0:
        print("INVALID")
    elif len(number)==15 and number[0]=="3" and (number[1]=="4" or number[1]=="7"):
        print("AMEX")
    elif len(number)==13 and number[0]=="4":
        print("VISA")
    elif len(number)==16 and number[0]=="4":
        print("VISA")
    elif len(number)==16 and number[0]=="5" and (number[1]=="1" or number[1]=="2" or number[1]=="3" or number[1]=="4" or number[1]=="5"):
        print("MASTERCARD")
    else:
        print("INVALID")


if __name__=="__main__":
    main()