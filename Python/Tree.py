import operator

class TreeNode:
	def __init__(self,value):
		self.val=value
		self.parent=None
		self.right=None
		self.left=None

	def getLeft(self):
		return self.left

	def getRight(self):
		return self.right

	def getRootVal(self):
		return self.val


class Parsetree:
	def __init__(self):
		self.root=TreeNode('')

	def insert(self,exp):
		tree=self.root
		curr=tree
		#print(curr,'\n\n')
		for i in exp:
			if i == '(':
				temp=TreeNode('')
				curr.left=temp
				temp.parent=curr
				curr=temp
			#print(curr.left)
			#print(i)
			if i=='+' or i=='-':
				curr.val=i
				temp=TreeNode('')
				curr.right=temp
				temp.parent=curr
				curr=temp
			if i=='*' or i=='/':
				curr.val=i
				temp=TreeNode('')
				curr.right=temp
				temp.parent=curr
				curr=temp

			if i==')':
				curr=curr.parent

			if i.isdigit():
				curr.val=i
				curr=curr.parent


#-------------------* and / is treated as metacharacter add a \

def printPrefix(trav):
	if trav:
		print(trav.val,end=" ")
	
	if trav.left!=None:
		printPrefix(trav.left)
	if trav.right!=None:
		printPrefix(trav.right)


def printPostFix(trav):
	if trav:
		printPostFix(trav.left)

		printPostFix(trav.right)

		print(trav.val,end=" ")
		#evaluate(trav.val)


def evaluate(trav):
	opers = {'+':operator.add, '-':operator.sub, '*':operator.mul, '/':operator.truediv}
	leftC=trav.getLeft()
	rightC=trav.getRight()
	if leftC.isdigit():
		leftC=int(leftC)
	if rightC.isdigit():
		rightC=int(rightC)

	if leftC and rightC:
		fn = opers[trav.getRootVal()]
		return fn(evaluate(leftC),evaluate(rightC))
	else:
		return trav.getRootVal()


def postordereval(tree): 
	opers = {'+':operator.add, '-':operator.sub, '*':operator.mul, '/':operator.truediv} 
	res1 = None 
	res2 = None 
	if tree: 
		res1 = postordereval(tree.getLeft()) 
		res2 = postordereval(tree.getRight()) 
		if res1 and res2: 
			return opers[tree.getRootVal()](int(res1),int(res2))
		else: 
			return tree.getRootVal()



def main():
	pt=Parsetree()
	inp=input('Enter the paranthesised string: ')
	pt.insert(inp)
	printPrefix(pt.root)
	print()
	printPostFix(pt.root)
	print()
	#print(pt.root.left.right.val)
	#evaluate(pt.root)
	print(postordereval(pt.root))

if __name__ == '__main__':
	main()