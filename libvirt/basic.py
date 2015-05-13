import libvirt
import sys

conn = libvirt.openReadOnly("xen:///system")
if conn == None:
    print 'Failed to open connection to the hypervisor'
    sys.exit(1)

try:
    dom0 = conn.lookupByName("fep1")
except:
    print 'Failed to find the main domain'
    sys.exit(1)

print "Domain 0: id %d running %s" % (dom0.ID(), dom0.OSType())
print dom0.info()