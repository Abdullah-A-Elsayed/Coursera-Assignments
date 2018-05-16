# python3

import sys
class Vertex:
  def __init__(self, key, value, sum, left, right, parent):
    (self.key, self.sum,self.value ,self.left, self.right, self.parent) = (key, sum, value, left, right, parent)

class Splay_tree:
    def __init__(self, root=None): (self.root) = (root)
    
    def update(self,v):
      if v == None:
        return
      v.sum = v.key + (v.left.sum if v.left != None else 0) + (v.right.sum if v.right != None else 0)
      if v.left != None:
        v.left.parent = v
      if v.right != None:
        v.right.parent = v

    def smallRotation(self,v):
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
      self.update(parent)
      self.update(v)
      v.parent = grandparent
      if grandparent != None:
        if grandparent.left == parent:
          grandparent.left = v
        else: 
          grandparent.right = v

    def bigRotation(self, v):
      if v.parent.left == v and v.parent.parent.left == v.parent:
        # Zig-zig
        self.smallRotation(v.parent)
        self.smallRotation(v)
      elif v.parent.right == v and v.parent.parent.right == v.parent:
        # Zig-zig
        self.smallRotation(v.parent)
        self.smallRotation(v)    
      else: 
        # Zig-zag
        self.smallRotation(v)
        self.smallRotation(v)

    # Makes splay of the given vertex and makes
    # it the new root.
    def splay(self,v):
      if v == None:
        return None
      while v.parent != None:
        if v.parent.parent == None:
          self.smallRotation(v)
          break
        self.bigRotation(v)
      return v

    # Searches for the given key in the tree with the given root
    # and calls splay for the deepest visited node after that.
    # Returns pair of the result and the new root.
    # If found, result is a pointer to the node with the given key.
    # Otherwise, result is a pointer to the node with the smallest
    # bigger key (next value in the order).
    # If the key is bigger than all keys in the tree,
    # then result is None.
    def find(self, key): 
      v = self.root
      last = self.root
      next = None
      while v != None:
        if v.key >= key and (next == None or v.key < next.key):
          next = v    
        last = v
        if v.key == key:
          break    
        if v.key < key:
          v = v.right
        else: 
          v = v.left      
      self.root = self.splay(last)
      return next

    def split(self, tree, key):  
      result = self.find(key)  
      if result == None:    
        return (tree, None)  
      right = self.splay(result)
      left = right.left
      right.left = None
      if left != None:
        left.parent = None
      self.update(left)
      self.update(right)
      return (left, right)

      
    def merge(self, left, right):
      if left == None:
        return right
      if right == None:
        return left
      while right.left != None:
        right = right.left
      right = self.splay(right)
      right.left = left
      self.update(right)
      return right

    def insert(self,key,value):
      (left, right) = self.split(self.root, key)
      new_vertex = None
      if right == None or right.key != key:
        new_vertex = Vertex(key, value, 0, None, None, None)  
      self.root = self.merge(self.merge(left, new_vertex), right)
      
    def erase(self,x):
      # Implement erase yourself
      (left, middle) = self.split(self.root, x)#middle may contain x
      (middle, right)= self.split(middle, x+1)# right contains no x
      self.root = self.merge(left,right)

    def search(self,x):
      # Implement find yourself
      result = self.find(x)
      if(result!=None and result.key==x): return True
      return False

    def toString(node):
        if node != None:
            res = Splay_tree.toString(node.left)
            res = res + node.value
            res = res + Splay_tree.toString(node.right)
            return res
        else:
            return str()

class Rope:
    def __init__(self, s):
        self.data = Splay_tree(None)
        self.stringToTree(s,0)

    def stringToTree(self,s,k):
        s_list = list(s)
        i=0
        for letter in s_list:
            self.data.insert(int(i+k),str(letter))
            i=i+1
    def result(self):
        return Splay_tree.toString(self.data.root)
    def process(self, i, j, k):
        (left,middle) = self.data.split(self.data.root,i)
        (middle,right) = self.data.split(middle,j+1)
        self.data.root = self.data.merge(left,right)
        self.stringToTree(Splay_tree.toString(middle),k)
rope = Rope(sys.stdin.readline().strip())
q = int(sys.stdin.readline())
for _ in range(q):
    i, j, k = map(int, sys.stdin.readline().strip().split())
    rope.process(i, j, k)
    ##map distributes list to variables (dataType, List)
    ##strip('v') remove all v
    ####strip() remove all white spaces
print(rope.result())
