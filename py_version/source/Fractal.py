# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Fractal.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patrisor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/21 23:00:27 by patrisor          #+#    #+#              #
#    Updated: 2019/08/21 23:12:56 by patrisor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def getColorCode():
    return [i for i in range(10)]

'''
So, start by scanning every point in that rectangular area. Each point represents a Complex number (x + yi). Iterate that complex number:
[new value] = [old-value]^2 + [original-value] while keeping track of two things:

1.) the number of iterations

2.) the distance of [new-value] from the origin.

If you reach the Maximum number of iterations, you're done. If the distance from the origin is greater than 2, you're done.
When done, color the original pixel depending on the number of iterations you've done. Then move on to the next pixel.
'''
def mandelbrot(g, h, w, m):
    for r in range(h):
        for c in range(w):
            c_re = (c - (w / 2.0)) * (4.0 / w)
            c_im = (r - (h / 2.0)) * (4.0 / w)
            rsquare = isquare = zsquare = x = y = i = 0
            while (((rsquare + isquare) <= 4) and (i < m)):
                x = rsquare - isquare + c_re
                y = zsquare - rsquare - isquare + c_im
                rsquare = x * x
                isquare = y * y
                zsquare = (x + y) * (x + y)
                i += 1
            colorCode = getColorCode()
            color = (colorCode[i] if i < m else colorCode[0])
            g[r][c] = color
