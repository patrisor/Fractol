# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patrisor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/21 21:03:37 by patrisor          #+#    #+#              #
#    Updated: 2019/09/24 00:50:24 by patrisor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
sys.path.append('source')
import Window,Fractals,Getch

def die(reason):
    print(reason)
    return -1

def print_instructions():
    return """W : MOVEY++\nS : MOVEY--\nD : MOVEX--\nA : MOVEX++\n
o : CX--\np : CX++\n[ : CY--\n] : CY++\n- : ZOOM OUT\n= : ZOOM IN\n"""

def process_input(prompt, frac):
    print(prompt)
    inp = Getch.getch()
    if inp == 'w': frac.moveY += 0.1
    elif inp == 's': frac.moveY -= 0.1
    elif inp == 'd': frac.moveX -= 0.1
    elif inp == 'a': frac.moveX += 0.1
    elif inp == 'o': frac.cX -= 0.1
    elif inp == 'p': frac.cX += 0.1
    elif inp == '[': frac.cY -= 0.1
    elif inp == ']': frac.cY += 0.1
    elif inp == '-': frac.zoom *= 0.99
    elif inp == '=': frac.zoom *= 1.01

def main():
    if len(sys.argv) != 5: return(die("usage: python3 main.py [FRACTAL] [WIN_HEIGHT] [WIN_WIDTH] [MAX_ITERATIONS]"))
    if sys.argv[1].isnumeric() or not sys.argv[2].isnumeric() or not sys.argv[3].isnumeric() or not sys.argv[4].isnumeric(): return(die("Invalid input"))
    if int(sys.argv[4]) > 10: return(die("Exceeded Max Iterations"))
    MAX_ITERATIONS = int(sys.argv[4])
    WIN_HEIGHT = int(sys.argv[2])
    WIN_WIDTH = int(sys.argv[3])
    # How many colors / Symbols are available in palette
    grid = Window.initWin(WIN_HEIGHT, WIN_WIDTH)
    if sys.argv[1] == "mandelbrot":
        Fractals.mandelbrot(grid, WIN_HEIGHT, WIN_WIDTH, MAX_ITERATIONS)
        Window.printWin(grid)
    if sys.argv[1] == "julia":
        julia = Fractals.Fractal()
        while True:
            process_input(print_instructions(), julia)
            Fractals.julia(grid, WIN_HEIGHT, WIN_WIDTH, MAX_ITERATIONS, julia)
            Window.printWin(grid)

if __name__ == "__main__":
    main()
