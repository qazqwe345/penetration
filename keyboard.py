import win32api
import win32con
import win32gui
import time

hWnd = win32gui.FindWindow('IEFrame', None)
win32gui.SetForegroundWindow(hWnd)

win32api.keybd_event(win32con.VK_F5, 0, 0, 0)
time.sleep(1)
win32api.keybd_event(win32con.VK_F5, 0, 0, 0)
time.sleep(1)
win32api.keybd_event(win32con.VK_F5, 0, 0, 0)


hWnd = win32gui.FindWindow('Chrome_WidgetWin_1', None)
win32gui.SetForegroundWindow(hWnd)
parent = win32gui.GetParent(hWnd)
print (win32gui.GetWindowText(parent))

x = 0
y = 0
win32gui.ClientToScreen(hWnd,(x,y))
win32api.SetCursorPos((x+36, y+395))

win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0)
time.sleep(1)
win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0)

time.sleep(1)

win32api.keybd_event(0x52, 0, 0, 0)

#hWnd = win32gui.FindWindow('Notepad', None)
