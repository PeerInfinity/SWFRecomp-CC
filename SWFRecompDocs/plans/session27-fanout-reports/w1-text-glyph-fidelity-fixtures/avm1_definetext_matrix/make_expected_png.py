from PIL import Image, ImageDraw
im=Image.new('RGB',(200,150),'white'); d=ImageDraw.Draw(im)
for x0,y0,x1,y1 in [(20,15,50,50),(70,15,100,50),(130,25,165,40),(130,50,165,65),(15,85,30,120),(40,85,55,120)]:
    d.rectangle([x0,y0,x1-1,y1-1],fill='black')
im.save('output.expected.png')
