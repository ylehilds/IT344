import string , os , time , shutil , tkMessageBox , Tkinter , win32wnet, getpass

from ctypes import windll
from win32netcon import RESOURCETYPE_DISK as DISK

currentUser = getpass.getuser()
def get_drives():
    drives = []
    bitmask = windll.kernel32.GetLogicalDrives()
    for letter in string.uppercase:
        if bitmask & 1:
            drives.append(letter)
        bitmask >>= 1

    return drives

def backUp():
	drives = get_drives()
	for disk in drives:
		if(disk=='C'):
			os.system ("robocopy \"C:\\Documents and Settings\\"+currentUser+"\\My Documents\" C:\\copyOfHome /S /LOG+:log.txt")
			os.system ("robocopy \"C:\\Documents and Settings\\"+currentUser+"\\Favorites\" C:\\copyOfHome /S /LOG+:log.txt")
			os.system ("robocopy \"C:\\Documents and Settings\\"+currentUser+"\\Desktop\" C:\\copyOfHome /S /LOG+:log.txt")
			break
		elif (disk == 'F'):
			os.system ("robocopy \"C:\\Documents and Settings\\"+currentUser+"\\My Documents\" F:\\copyOfHome /S /LOG+:log.txt")
			os.system ("robocopy \"C:\\Documents and Settings\\"+currentUser+"\\Favorites\" F:\\copyOfHome /S /LOG+:log.txt")
			os.system ("robocopy \"C:\\Documents and Settings\\"+currentUser+"\\Desktop\" F:\\copyOfHome /S /LOG+:log.txt")
			break
		else:
			window = Tkinter.Tk()
			window.wm_withdraw()
			tkMessageBox.showinfo(title="Can't back it up!!!", message="No available drive is available for back up home directory! make sure drives are connected, then run it again in console window type: CD Desktop and then type: python python_section3.py")

			
if __name__ == '__main__':
	backUp()
	