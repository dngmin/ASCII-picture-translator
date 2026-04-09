import cv2
from tkinter import filedialog
import math


img_path = filedialog.askopenfilename()
wanted_max_width_pixel_size = 200

img = cv2.imread(img_path,cv2.IMREAD_GRAYSCALE)
h, w = img.shape
divide_scale = w//wanted_max_width_pixel_size + 1 if w > wanted_max_width_pixel_size > 1 else 1

ac = "@%#*+=-:. "
# ac = r"""$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,"^`'. """

can_cutting = True
color_scale_threshold = 256/len(ac)

for i in range(0,h,divide_scale*2):
    row = ""
    for j in range(0,w,divide_scale):
        color_scale = img[i, j]
        ascii_index = math.floor(color_scale/color_scale_threshold)
        row += ac[ascii_index]
    if can_cutting:
        if row == ac[0]*len(row) or row == ac[-1]*len(row) :
            pass
        else:
            can_cutting = False
            print(row)
    else:
        print(row)