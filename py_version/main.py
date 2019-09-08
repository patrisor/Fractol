# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patrisor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/21 21:03:37 by patrisor          #+#    #+#              #
#    Updated: 2019/09/08 07:08:01 by patrisor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
sys.path.append('source')
import Window,Fractal

def die(reason):
    print(reason)
    return -1

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
        Fractal.mandelbrot(grid, WIN_HEIGHT, WIN_WIDTH, MAX_ITERATIONS)
        Window.printWin(grid)
    if sys.argv[1] == "julia":
        while True:
            inp = input("CX,CY,MOVEX,MOVEY,ZOOM\n")
            Fractal.julia(grid, WIN_HEIGHT, WIN_WIDTH, MAX_ITERATIONS, inp)
            Window.printWin(grid)

if __name__ == "__main__":
    main()
