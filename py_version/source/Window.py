# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Window.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patrisor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/21 22:56:42 by patrisor          #+#    #+#              #
#    Updated: 2019/08/21 22:57:23 by patrisor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import Colors

def printWin(w):
    ''' TODO: For Testing
    for r in range(len(w)):
        print(' '.join(str(n) for n in w[r]))
    '''
    ret = ''
    colors = Colors.getColors()[::-1]
    length = len(colors)
    for r in range(len(w)):
        for c in range(len(w[r])):
            if w[r][c] == 0: ret += colors[0] + '  '
            if w[r][c] == 1: ret += colors[1] + '. '
            if w[r][c] == 2: ret += colors[2] + '- '
            if w[r][c] == 3: ret += colors[3] + '~ '
            if w[r][c] == 4: ret += colors[4] + '+ '
            if w[r][c] == 5: ret += colors[5] + '* '
            if w[r][c] == 6: ret += colors[6] + '# '
            if w[r][c] == 7: ret += colors[7] + '% '
            if w[r][c] == 8: ret += colors[8] + '$ '
            if w[r][c] == 9: ret += colors[9] + '& '
        ret += '\n'
    print(ret)

def initWin(h, w): return [[0] * w for _ in range(h)]
