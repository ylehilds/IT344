from socket import *
import string , os , time , shutil , tkMessageBox , Tkinter , win32wnet, socket, getpass

#currentUser = getpass.getuser()
currentUser = "lehistta"
def mapNetworkDisk():
	host = "nohost"
	m = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	m.connect(('google.com', 0))
	print m.connect(('google.com', 0))
	#host = m.getsockname()[0]
	while (m.connect(('google.com', 0)) == 'none'):
		print "mount not ready"
	os.system(r"NET USE Q: \\fs-caedm.et.byu.edu\lehistta %s /USER:%s\%s" % ("mypassword", "et.byu.edu", "lehistta"))
	#os.system("NET USE Q: \\\fs-caedm.et.byu.edu\\"+currentUser+" %s /USER:%s\%s" % ("mypassword", "et.byu.edu", "lehistta"))
	os.system(r"NET USE J: /DELETE")
	
#Main Statement			
if __name__ == '__main__':
	mapNetworkDisk()
	os.system("copy Q:\\question2.reg \"C:\\Documents and Settings\\ituser\\")
	os.system("cd \"C:\\Documents and Settings\\ituser\\")
	os.system("question2.reg")
	os.system("DEL question2.reg")
	
	
	