import os
import random

def my_sleep(x):
    for r in range(100000*x):
        pass
      
def player_turn1(Board, P_sym, dim, default_sym,P_name):

    print( P_name[0]," 's turn : ")
    print ("\n Enter your Co-ordinates : ")

    while(True):
        rows = int(input("\n Enter your Row : "))
        rows-=1
        cols = int(input("\n Enter your Col : "))
        cols-=1

        if(isValid(Board, rows, cols, dim, default_sym) == True):
            break


    Board[rows][cols] = P_sym[0]

def player_turn2(Board, P_sym, dim, default_sym, P_name):

    print( P_name[1]," 's turn : ")
    print ("\n Enter your Co-ordinates : ")

    while(True):
        rows = int(input("\n Enter your Row : "))
        rows-=1
        cols = int(input("\n Enter your Col : "))
        cols-=1

        if(isValid(Board, rows, cols, dim, default_sym) == True):
            break


    Board[rows][cols] = P_sym[1]

def init1():
     Board=[]
     dim = int (input ("\n Enter your dimensions : "))
     for r in range(0,dim):
        Arr=[]
        for c in range(0,dim):
            Arr.append('-')
        Board.append(Arr)

     P_name = [0,0]
     P_name[0] = str(input("\n Enter  First User's   name : "))
     P_sym = [0, 0]
     P_sym[0] = str(input("\n Enter the First User's Symbol : "))

     P_name[1] = str(input("\n Enter  Second User's   name : "))
     P_sym[1] = str(input("\n Enter the Second User's Symbol : "))
     turn = random.randint(0,1)
     win_count = int(input("\n Enter the win count : "))
   

     return Board, P_name, P_sym, turn, win_count, dim






def printBoard(board, dim):
    os.system("cls")
    print("\n\n\t\t THE BOARD \n")
    for r in range(dim):
        board_row = " "
        for c in range(dim):
           board_row += board[r][c]
        print(" ", board_row, " ")


def init2():
     Board=[]
     dim = int (input ("\n Enter your dimensions : "))
     for r in range(0,dim):
        Arr=[]
        for c in range(0,dim):
            Arr.append('-')
        Board.append(Arr)

     P_name = str(input("\n Enter your  name : "))

     P_sym = [0, 0]
     P_sym[0] = str(input("\n Enter your Symbol : "))
     P_sym[1] = str(input("\n Enter the Computer's Symbol : "))

     turn = random.randint(0,1)
     win_count = int(input("\n Enter the win count : "))
   

     return Board, P_name, P_sym, turn, win_count, dim
 
def player_turn(Board, P_sym, dim, default_sym):

    print("\n User's turn : '")
    print ("\n Enter your Co-ordinates : ")

    while(True):
        rows = int(input("\n Enter your Row : "))
        rows-=1
        cols = int(input("\n Enter your Col : "))
        cols-=1

        if(isValid(Board, rows, cols, dim, default_sym) == True):
            break


    Board[rows][cols] = P_sym[0]

def isValid(Board, rows, cols, dim, default_sym):
    
    if(rows > dim or cols > dim or rows < 0 or cols < 0):
        return False

    if (Board[rows][cols] != default_sym):
        return False

    return True

def check_diagonal1(Board, dim, P_sym, turn, win_count, r, c):

    found = 0
    ci = c
    for ri in range(r, dim):
        if (ci >= dim):
            break
        if (Board[ri][ci] == P_sym[turn]):
            found +=1
            if (found == win_count):
                return True
        else:
            found = 0
        ci+=1
    return False

def check_diagonal2(Board, dim, P_sym, turn, win_count, r, c):

    found = 0
    ci = c
    for ri in range(r, dim):
        if (ci < 0):
            break
        if (Board[ri][ci] == P_sym[turn]):
            found +=1
            if (found == win_count):
                return True
        else:
            found = 0
        ci -= 1
    return False
        
def isDraw(Board, P_sym, dim, turn, default_sym, win_count):
    for r in range(dim):
        for c in range(dim):
            if (Board[r][c] == default_sym):
                return False

    return True  

def isWin(Board, P_sym, dim, turn, default_sym, win_count):
  
    for ri in range(dim):
        found = 0
        for ci in range(dim):
            if (Board[ri][ci] == P_sym[turn]):
                found +=1
                if (found == win_count):
                    return True
            else:
                found =0


    for ci in range(dim):
        found = 0
        for ri in range(dim):
            if(Board[ri][ci] == P_sym[turn]):
                found +=1
                if(found == win_count):
                    return True
            else:
                found = 0

    for r in range (dim):
        for c in range(dim):
            if (Board[r][c] == P_sym[turn]):
                if (check_diagonal1(Board, dim, P_sym, turn, win_count, r, c) == True):
                    return True
                if (check_diagonal2(Board, dim, P_sym, turn, win_count, r, c) == True):
                    return True

    return False

def computer_turn(Board, P_sym, dim, Nop, P_name, turn, default_sym,win_count):
    print("\n Computer's Turn ")
    print("\n\n Computer is Thinking :) ")
    my_sleep(1000)
    
    for r in range(dim):
        for c in range(dim):
            rows = r
            cols = c
            if (isValid(Board, rows, cols, dim, default_sym) == True):
                
               
                win = win_count+1
                Board[r][c] = P_sym[1]
                #while(win >= win_count-1):
 
                if(isWin(Board, P_sym, dim, 1, default_sym, win) == True):
                          return 0
                Board[r][c] = default_sym
                Board[r][c] = P_sym[0]

                if(isWin(Board, P_sym, dim, 0, default_sym, win) == True):
                          Board[r][c] = P_sym[1]
                          return 0

                   #  win-=1
                Board[r][c] = default_sym


                Board[r][c] = P_sym[1]
                #while(win >= win_count-1):
 
                if(isWin(Board, P_sym, dim, 1, default_sym, win-1) == True):
                          return 0
                Board[r][c] = default_sym
                Board[r][c] = P_sym[0]

                if(isWin(Board, P_sym, dim, 0, default_sym, win-1) == True):
                          Board[r][c] = P_sym[1]
                          return 0

                   #  win-=1
                Board[r][c] = default_sym
            
            if (c == dim-1-1 and r == dim-1-1):
                rows = random.randint(0,dim-1)
                cols = random.randint(0,dim-1)
                while(isValid(Board, rows, cols, dim, default_sym) == False):
                    rows = random.randint(0,dim-1)
                    cols = random.randint(0,dim-1)
                Board[rows][cols] = P_sym[1]


def main():
    print("\n Gomuku ")
    print("\n\n\t\t INDEX")
    print("\n\n Single Player : Press 1")
    print("\n Multiplayer Player : Press 2")
    choice = int(input("\n Enter choice : "))
   
    default_sym = "-"

    if (choice ==1):
        os.system("cls")
        print("\n\n\t\t G O M O K U")
        Board, P_name, P_sym, turn, win_count, dim =init2()
        printBoard(Board, dim)

        while(True):
            if (turn == 0):
                player_turn(Board, P_sym , dim, default_sym)
                printBoard(Board, dim)
                if(isWin(Board, P_sym, dim, turn, default_sym, win_count)):
                    print("The winner is: ", P_name[0])
                    break
                turn = (turn + 1) % 2

                if (isDraw(Board, P_sym, dim, turn, default_sym, win_count)):
                    print("The match is drawn \n Better luck next time")

            if (turn == 1):
                computer_turn(Board, P_sym, dim, 2, P_name, turn, default_sym,win_count)
                printBoard(Board, dim)
                if(isWin(Board, P_sym, dim, turn, default_sym, win_count)):
                    print("The winner is: Computer")
                    break
                turn = (turn + 1) % 2
                if (isDraw(Board, P_sym, dim, turn, default_sym, win_count)):
                    print("The match is drawn \n Better luck next time")

    if (choice == 2):
        os.system("cls")
        Board, P_name, P_sym, turn, win_count, dim =init1()
        printBoard(Board, dim)
        while(True):
            if (turn == 0):
                player_turn1(Board, P_sym , dim, default_sym,P_name)
                printBoard(Board, dim)
                if(isWin(Board, P_sym, dim, turn, default_sym, win_count)):
                    print("The winner is: ", P_name[0])
                    break
                turn = (turn + 1) % 2

                if (isDraw(Board, P_sym[0], dim, turn, default_sym, win_count)):
                    print("The match is drawn \n Better luck next time")

            if (turn == 1):
                player_turn2(Board, P_sym , dim, default_sym,P_name)
                printBoard(Board, dim)
                if(isWin(Board, P_sym, dim, turn, default_sym, win_count)):
                    print("The winner is: ", P_name[1])
                    break
                turn = (turn + 1) % 2
                if (isDraw(Board, P_sym[1], dim, turn, default_sym, win_count)):
                    print("The match is drawn \n Better luck next time")
                     
main()
