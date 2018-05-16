# python3

import sys
class Vertex:
  def __init__(self, char, size, left, right, parent):
    (self.char, self.size, self.left, self.right, self.parent) = (char, size, left, right, parent)

class Splay_tree:
    def __init__(self, root=None): (self.root) = (root)
    
    def update(v):
      if v == None:
        return
      v.size = 1 + (v.left.size if v.left != None else 0) + (v.right.size if v.right != None else 0)
      if v.left != None:
        v.left.parent = v
      if v.right != None:
        v.right.parent = v

    def smallRotation(v):
      parent = v.parent
      if parent == None:
        return
      grandparent = v.parent.parent
      if parent.left == v:
        m = v.right
        v.right = parent
        parent.left = m
      else:
        m = v.left
        v.left = parent
        parent.right = m
      Splay_tree.update(parent)
      Splay_tree.update(v)
      v.parent = grandparent
      if grandparent != None:
        if grandparent.left == parent:
          grandparent.left = v
        else: 
          grandparent.right = v

    def bigRotation(v):
      if v.parent.left == v and v.parent.parent.left == v.parent:
        # Zig-zig
        Splay_tree.smallRotation(v.parent)
        Splay_tree.smallRotation(v)
      elif v.parent.right == v and v.parent.parent.right == v.parent:
        # Zig-zig
        Splay_tree.smallRotation(v.parent)
        Splay_tree.smallRotation(v)    
      else: 
        # Zig-zag
        Splay_tree.smallRotation(v)
        Splay_tree.smallRotation(v)

    # Makes splay of the given vertex and makes
    # it the new root.
    def splay(v):
      if v == None:
        return None
      while v.parent != None:
        if v.parent.parent == None:
          Splay_tree.smallRotation(v)
          break
        Splay_tree.bigRotation(v)
      return v

    # Searches for the given key in the tree with the given root
    # and calls splay for the deepest visited node after that.
    # Returns pair of the result and the new root.
    # If found, result is a pointer to the node with the given key.
    # Otherwise, result is a pointer to the node with the smallest
    # bigger key (next value in the order).
    # If the key is bigger than all keys in the tree,
    # then result is None.
    def find( tree, index):
      size = index + 1
      if(tree == None or size>tree.size): return (tree,None) #out of range
      while 1:
        l_s = (tree.left.size if tree.left!=None else 0)
        if(size == l_s + 1): 
            Splay_tree.splay(tree)
            return (tree,tree)
        if(size < l_s+1): tree = tree.left
        elif (size > l_s+1): (tree,size)=(tree.right, size-l_s-1)

    def split(tree, key):  
      (tree, result) = Splay_tree.find(tree, key) 
      if result == None:  
        #print(Splay_tree.toString(tree),(tree.size if tree !=None else 0), key)
        return (tree, None)
      right = Splay_tree.splay(result)
      left = right.left
      right.left = None
      if left != None:
        left.parent = None
      Splay_tree.update(left)
      Splay_tree.update(right)
      return (left, right)

      
    def merge(left, right):
      if left == None:
        return right
      if right == None:
        return left
      while right.left != None:
        right = right.left
      right = Splay_tree.splay(right)
      right.left = left
      Splay_tree.update(right)
      return right

    def insert(self,key,value):#(pos, char)
      (left, right) = Splay_tree.split(self.root, key)
      new_vertex = Vertex(value, 1, None, None, None)  
      self.root = Splay_tree.merge(Splay_tree.merge(left, new_vertex), right)

    def toString(node):
        if node == None: return str()
        res = str()
        stack = list()
        while node != None or len(stack) !=0 :
            if(node != None):
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                res = res + node.char
                node = node.right
        return res
class Rope:
    def __init__(self, s):
        self.data = Splay_tree(None)
        self.stringToTree(s)

    def stringToTree(self,s):
        s_list = list(s)
        i=0
        for letter in s_list:
            self.data.insert(i,str(letter))
            i=i+1
    def result(self):
        return Splay_tree.toString(self.data.root)

    def process(self, i, j, k):
        (left,middle) = Splay_tree.split(self.data.root,i)
        (middle,right) = Splay_tree.split(middle,j-i+1)
        # new string without sub[i..j]
        self.data.root = Splay_tree.merge(left,right)
        # adding sub in position k, note: k belongs to most right
        (left, right) = Splay_tree.split(self.data.root,k)
        self.data.root = Splay_tree.merge(Splay_tree.merge(left,middle),right)

rope = Rope(sys.stdin.readline().strip())
q = int(sys.stdin.readline())
for _ in range(q):
    i, j, k = map(int, sys.stdin.readline().strip().split())
    rope.process(i, j, k)
    # map distributes list to variables (dataType, List)
    # strip('v') remove all v
    ####strip() remove all white spaces
print(rope.result())
