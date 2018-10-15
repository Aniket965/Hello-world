class ShellSort(object):
  def sort(self, obj):
    longitud = len(arr)
    gap      = 2
    for i in range(longitud-gap):
        if arr[i] > arr[i + gap]:
            tmp   = arr[i]
            arr[i] = arr[i + gap]
            arr[i + gap] = tmp            
    return arr

     
  def __init__(self, arg=None):
    super(ShellSort, self).__init__()
    self.arg = arg