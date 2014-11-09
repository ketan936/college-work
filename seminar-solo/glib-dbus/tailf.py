import time
def follow(thefile):
    thefile.seek(0,2)
    while True:
        line = thefile.readline()
        if not line:
            time.sleep(0.1)
            continue
        print line

if __name__ == '__main__':
    logfile = open("secondTRy.log")
    loglines = follow(logfile)
    
        