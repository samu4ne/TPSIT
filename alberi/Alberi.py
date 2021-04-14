class Nodo:
    def __init__(self,val):
        self.left = None
        self.right = None
        self.val = val
    
    def insert(self,val):
        if self.val != None :
            if val < self.val :
                if self.left is None :
                    self.left = Nodo(val)
                else :
                    self.left.insert(val)
            elif val > self.val :
                if self.right is None :
                    self.right = Nodo(val)
                else:
                    self.right.insert(val)
            else:
                self.val = val
        else:
            self.val = val 
    
    def printroot(self):
        if self.left:
            self.left.printroot()
        
        print(self.val)

        if self.right:
            self.right.printroot()
    
    def orderTraversal(self, root):
        res = []

        if root:
            res = self.orderTraversal(root.left)
            res.append(root.val)
            res = res + self.orderTraversal(root.right)
        
        return res

    def preOrderTraversal(self, root):
        res = []

        if root:
            res.append(root.val)
            res = res + self.preOrderTraversal(root.left)
            res = res + self.preOrderTraversal(root.right)
        
        return res

    def postOrderTraversal(self, root):
        res = []

        if root:
            res = self.postOrderTraversal(root.left)
            res = res + self.postOrderTraversal(root.right)
            res.append(root.val)
        
        return res

    def sum(self):
        sum = 0
        lista = self.orderTraversal(self)

        for numero in lista: 
            sum = sum + numero

        return sum

    def pari(self):
        lista = self.orderTraversal(self)
        listaPari = []

        for k in range(len(lista)):
            if lista[k] % 2 == 0:
                listaPari.append(lista[k])

        return listaPari

root = Nodo(27)

root.insert(27)
root.insert(14)
root.insert(10)
root.insert(39)
root.insert(35)
root.insert(31)
root.insert(47)

print(root.sum())
print(root.pari())