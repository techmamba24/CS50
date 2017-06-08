#   mario.py
#   Aamel Unia
#   aameluni@buffalo.edu
#   Simple program that prints out a double half-pyramid of a specified height in which hashes represent blocks, similar to the 
#   double half-pyramid found toward the end of World 1-1 in Nintendo’s Super Mario Brothers.
#   The half-pyramid’s height which is entered by the user must be a non-negative integer no greater than 23.
 
def main():
    
    while True:
        print("Height: ",end="")
        height = int(input())
        if height>0 and height<=23:
            break
    
    spaces = height-1
    
    for i in range(height):
        for x in range(spaces,0,-1):
           print(" ",end="")
        for z in range(i+1,0,-1):
            print("#",end="")
        print("  ",end="")
        for k in range(i+1,0,-1):
            print("#",end="")
        for y in range(spaces):
            print(" ",end="")
        print()
        spaces -= 1
        


if __name__ == "__main__":
    main()
    