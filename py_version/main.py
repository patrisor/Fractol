# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patrisor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/21 21:03:37 by patrisor          #+#    #+#              #
#    Updated: 2019/08/26 00:03:21 by patrisor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
sys.path.append('source')
import Window,Fractal

def die(reason):
    print(reason)
    return -1

def main():
    if len(sys.argv) != 4: return(die("usage: python3 main.py [WIN_HEIGHT] [WIN_WIDTH] [MAX_ITERATIONS]"))
    if not sys.argv[1].isnumeric() or not sys.argv[2].isnumeric() or not sys.argv[3].isnumeric(): 
        return(die("Invalid input"))
    if int(sys.argv[3]) > 10: return(die("Exceeded Max Iterations"))
    MAX_ITERATIONS = int(sys.argv[3])
    WIN_HEIGHT = int(sys.argv[1])
    WIN_WIDTH = int(sys.argv[2])
    # How many colors / Symbols are available in palette
    grid = Window.initWin(WIN_HEIGHT, WIN_WIDTH)
    Fractal.mandelbrot(grid, WIN_HEIGHT, WIN_WIDTH, MAX_ITERATIONS)
    Window.printWin(grid)

if __name__ == "__main__":
    main()
