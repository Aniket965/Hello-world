import ctypes

class DynamicArray(object): 
  def __init__(self): 
    self.count = 0
    self.capacity = 1
    self.A = self.make_array(self.capacity)
    
  def __len__(self): 
    return self.count
  
  def __getItem__(self,k): 
    if not 0 <= k < self.count: 
      return IndexError('K is out of bounds!')
    return self.A[k]
  
  def append(self, element): 
    if self.count == self.capacity: 
      self._resize(2*self.capacity) 
    self.A[self.count] = element
    self.count += 1
  
  def _resize(self,new_cap): 
    B = self.make_array(new_cap) 
    for k in range(self.count): 
      B[k] = self.A[k]
    self.A = B
    self.capcity = new_cap
  
  def make_array(self, new_cap): 
    return (new_cap * ctypes.py_object)(
