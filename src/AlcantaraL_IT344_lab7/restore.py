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




def restore():
	drives = get_drives()
	for disk in drives:
		if(disk=='C'):
			os.system ("robocopy C:\\copyOfHome \"C:\\Documents and Settings\\"+currentUser+"\\copyHomeDirectory\" /S /LOG+:log.txt")
			break;
		elif (disk == 'J'):
			os.system ("robocopy J:\\copyOfHome \"C:\\Documents and Settings\\"+currentUser+"\\copyHomeDirectory\" /S /LOG+:log.txt")
			break
		else:
			window = Tkinter.Tk()
			window.wm_withdraw()
			tkMessageBox.showinfo(title="Can't restore it up!!!", message="No available drive is available for restore home directory! make sure drives are connected, then run it again in console window type: CD Desktop and then type: python python_section3.py")
	
	
if __name__ == '__main__':
	restore()
