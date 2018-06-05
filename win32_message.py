import win32api
import win32con
import win32gui

def OnClose():
    hWnd = win32gui.FindWindow("Notepad", None) #win32gui.FindWindow(classname, windowname)
    if (hWnd==0):
        win32gui.MessageBox(None, "沒有找到筆記本" ,"錯誤" ,0) #MessageBox(parent, text , caption , flags )
        return
    win32gui.SendMessage(hWnd, win32con.WM_CLOSE)


def OnExec():
    win32api.WinExec("notepad.exe", win32con.SW_SHOW)


def OnEditWnd():
    hWnd = win32gui.FindWindow(None, "新文字文件.txt - 記事本")
    if (hWnd==0):
        win32gui.MessageBox(None,"沒有找到筆記本","錯誤", 0)
        return

    win32gui.SendMessage(hWnd, win32con.WM_SETTEXT, 0, "消息測試123ㄏㄏ")


def OnGetWnd():
    hWnd = win32gui.FindWindow("Notepad", None)
    if (hWnd == 0):
        win32gui.MessageBox(None,"沒有找到筆記本","錯誤", 0)
        return
    pCaptionText = [0]*win32con.MAXBYTE
    s = "我"*win32con.MAXBYTE
    win32gui.SendMessage(hWnd, win32con.WM_GETTEXT , win32con.MAXBYTE, s)
    win32gui.MessageBox(None, s, "接收消息", 0)
    print (win32gui.GetWindowText(win32gui.FindWindowEx(hWnd,None,"Edit",None)))
