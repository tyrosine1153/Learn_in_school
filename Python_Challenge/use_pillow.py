from PIL import Image

img = Image.open(r"oxygen.png")

lst = [img.getpixel((x, img.height / 2)) for x in range(img.width)]

chars = [chr(r) for r, g, b, a in lst[::7] if r == g == b]
chars = ''.join(chars)
print(chars)
