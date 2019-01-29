from collections import defaultdict
from IPython.display import Image, display
import pydot
from graphviz import Digraph


import os
os.environ["PATH"] += os.pathsep + 'C:/Users/all_users.cclab05-11/Documents/16CS8103/release/bin'

from tkinter import *
from tkinter import messagebox
#import Tkinter
#import tkMessageBox
dot = Digraph(comment='The Round Table') 
adj=defaultdict(list)
node=set()
edges=0
nodes=0
window = Tk()
 
window.title("Graph Specifications")
 
window.geometry('900x600')
 
lbl = Label(window, text="Starting Node")
 
lbl.grid(column=0, row=0)
 
txt = Entry(window,width=30)
 
txt.grid(column=1, row=0)

lbl1 = Label(window, text="Ending Node")
 
lbl1.grid(column=0, row=1)
 
txt1 = Entry(window,width=30)
 
txt1.grid(column=1, row=1)

def clicked1():
    a=txt.get()
    b=txt1.get()
    adj[a].append(b)
    txt.delete(first=0,last=10)
    txt1.delete(first=0,last=10)
    #edges=edges+1
def clicked2():
    a=txt.get()
    b=txt1.get()
    adj[a].append(b)
    window.destroy()
    #edges=edges+1
btn1 = Button(window, text="Next", command=clicked1)
btn2 = Button(window, text="Over", command=clicked2) 
btn1.grid(column=0, row=2)
btn2.grid(column=1, row=2) 
window.mainloop()
#G = pydot.Dot(graph_type="digraph")  
    
for i in adj.keys():
    dot.node(str(i))
    
    #G.add_node(node)
 
for i in adj.keys():
    for j in adj[i]:
       # edge = pydot.Edge(i,j)
        dot.edge(str(i),str(j))
        edges=edges+1
        node.add(str(i))
        node.add(str(j))
       


for i in node:
    nodes=nodes+1
print(edges-nodes+1)


os.chdir(os.getcwd())

print(dot.source)  
dot.render('round-table.gv', view=True)       
# im = Image(G.create_png())
# display(im)


pypdfocr.pypdfocr_gs.PyGs({}).make_img_from_pdf('round-table.gv.pdf')

top = Tk()
def hello():
   messagebox.showinfo("No of Regions",str(edges-nodes+1))
def hello1():
    top.destroy()
B1 = Button(top, text = "CLick for bounded regions", command = hello)
B2=  Button(top, text = "Exit", command = hello1)
B1.pack()
B2.pack()

top.mainloop()
