Option Explicit

Public Sub run()
    Const Earth = "World"
    Debug.Print Hello(Earth) & "!!"
End Sub

Private Function Hello(what As String) As String
    Hello = "Hello " & what
End Function
