import os, sys
import PIL.Image as Image
import PIL.ImageDraw as Draw
import PIL.ImageFont as Font

if len(sys.argv) != 3:
    print '>> python <SCRIPT> <ARQUIVO> <SAIDA>'
    sys.exit(0)

class nodo:
    def __init__(self, key, x, y):
        self.chave = key
        self.x = x
        self.y = y
        self.esq = self.dir = None
    def __str__(self):
        return '{0}: ({1}, {2})'.format(self.x, self.y, self.y)

fentrada = sys.argv[1]
fsaida = sys.argv[2]

f = open(fentrada, 'r')
linhas = f.readlines()
w, h, raio = [int(s) for s in linhas[0].split()]
a = []
for item in linhas[1:]:
    key, x, y = [int(s) for s in item.split()]     
    a.append( nodo(key, x, y) )
f.close()

if len(a)==0:
    print 'ARVORE VAZIA'
    sys.exit()

t = a[0]
for obj in a[1:]:
    key, x, y = obj.chave, obj.x, obj.y
    u, v = None, t
    insert = True 
    while v != None:
        if key == v.chave:
            insert = False
            break
        elif key < v.chave:
            u, v = v, v.esq
        else:
            u, v = v, v.dir
    if insert:
        if key < u.chave:
            u.esq = obj
        else:
            u.dir = obj

img = Image.new('RGB', (w, h))
draw = Draw.Draw(img)
fonte = Font.load_default()

pilha = [ (w/2, 0, t) ]
while len(pilha)>0:
    x, y, n = pilha.pop()
    draw.line( (x, y, n.x, n.y) , width = 3)
    if (n.esq != None): pilha.append( (n.x, n.y, n.esq) ) 
    if (n.dir != None): pilha.append( (n.x, n.y, n.dir) )

pilha = [ (w/2, 0, t) ]
while len(pilha)>0:
    x, y, n = pilha.pop()
    rect = (n.x-raio, n.y-raio, n.x+raio, n.y+raio)
    draw.ellipse(rect, fill=(0,0,0), outline=(0,200,0) ) 
    draw.text((n.x,n.y), '{0}'.format(n.chave), font = fonte)
    if (n.esq != None): pilha.append( (n.x, n.y, n.esq) ) 
    if (n.dir != None): pilha.append( (n.x, n.y, n.dir) )

img.save(fsaida)
