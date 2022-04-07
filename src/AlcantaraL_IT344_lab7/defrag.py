import string , os , time , shutil , tkMessageBox , Tkinter , win32wnet

from ctypes import windll
from win32netcon import RESOURCETYPE_DISK as DISK



def defrag():
	os.system("defrag c:")
	
if __name__ == '__main__':
	defrag()
	