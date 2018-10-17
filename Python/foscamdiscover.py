#!/usr/bin/env python

# Discovers FOSCAM cameras on the local network
#
# By SukkoPera <software@sukkology.net>
# October 2018

import struct
import socket
import threading
import logging

class DiscovererException (Exception):
	pass

class Discoverer (object):
	BIND_IP = ""		# All addresses
	PORT = 10000
	DEFAULT_AUTODISCOVER_INTERVAL = 5	# sec

	def __init__ (self):
		self._logger = logging.getLogger ('Discoverer')
		self._handlers = []
		self._keepGoing = False

	def registerHandler (self, h):
		if h not in self._handlers and callable (h):
			self._handlers.append (h)

	def _timerCallback (self):
		self.discover ()

		# Restart timer
		if self._autodiscoverEnabled:
			self.enableAutodiscovery (self._autodiscInterval)

	def start (self, interval = DEFAULT_AUTODISCOVER_INTERVAL):
		if not self._keepGoing:
			self._autodiscoverTimer = threading.Thread (target = self._timerCallback, args = (interval, ), name = "Discovery Thread")
			self._autodiscoverTimer.daemon = True
			self._keepGoing = True
			self._autodiscoverTimer.start ()

	def stop (self):
		self._keepGoing = False
		self._autodiscoverTimer.join ()

	def _timerCallback (self, interval):
		while self._keepGoing:
			s = self._trigger (interval)
			self._waitForReplies (s)

	def _waitForReplies (self, s):
		timedout = False
		while not timedout and self._keepGoing:
			try:
				reply, addr = s.recvfrom (1024)
				# ~ print "Got %d byte(s) from %s:%u:" % (len (reply), addr[0], addr[1])
				# ~ for i in Discoverer.hexdump (reply):
					# ~ print (i)
				try:
					data = self._decodeReply (reply)
					if data is not None:
						devid, name, ver, ip, mask, gw, dns, port, dhcpEnabled = data
						for h in self._handlers:
							h (devid, name, ver, ip, mask, gw, dns, port, dhcpEnabled)
				except DiscovererException as ex:
					self._logger.error ("Cannot parse reply from %s: %s" % (addr[0], str (ex)))
			except socket.error as ex:
				# ~ print "Socket Error: %s" % str (ex)
				timedout = True

	def _trigger (self, timeout):
		"""Sends the magic "trigger" packet, returning the socket to wait for
		replies onto."""
		s = socket.socket (socket.AF_INET, socket.SOCK_DGRAM)
		# ~ s.setsockopt (socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
		s.setsockopt (socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

		# User Datagram Protocol, Src Port: 10000, Dst Port: 10000
		s.bind ((Discoverer.BIND_IP, Discoverer.PORT))

		# Data, 27 bytes: 4d4f5f490000000000000000000000040000000400000000000001
		body = "4d4f5f490000000000000000000000040000000400000000000006".decode ("hex")

		s.sendto (body, ('<broadcast>', Discoverer.PORT))

		s.settimeout (timeout)

		return s

	def _decodeReply (self, reply):
		#print "Got %d byte(s):" % len (reply)
		#for i in Discoverer.hexdump (reply):
		#	print (i)
		header = reply[:23]
		text = reply[23:]

		# Header is little-endian
		proto, opcode, textlen = struct.unpack ("< 4s H 9x L 4x", header)

		if proto != "MO_I":
			raise DiscovererException ("Bad protocol")
		elif opcode != 1:
			# ~ raise DiscovererException ("Bad operation code")
			# Not a discover reply, ignore
			return None
		elif len (text) != textlen:
			raise DiscovererException ("Bad packet length")
		else:
			# We only know the meaning of the first 65 bytes
			if textlen > 65:
				self._logger.debug ("Reply is longer than expected, truncating")
				text = text[:65]

			# Text is big-endian (...)
			devid, name, ip, mask, gw, dns, v1, v2, v3, v4, v5, v6, v7, v8, port, dhcpEnabled = struct.unpack ("> 12s 1x 21s 4s 4s 4s 4s 4x 8B H 1B", text)

			# Do some postprocessing
			name = name.rstrip ("\0")
			# ~ mac = re.sub (r"(..)", r"\1:", devid)[:-1]
			sysVer = "%u.%u.%u.%u" % (v1, v2, v3, v4)
			appVer = "%u.%u.%u.%u" % (v5, v6, v7, v8)
			ver = "%s_%s" % (sysVer, appVer)
			ip = socket.inet_ntoa (ip)
			mask = socket.inet_ntoa (mask)
			gw = socket.inet_ntoa (gw)
			dns = socket.inet_ntoa (dns)
			dhcpEnabled = bool (dhcpEnabled)

			return devid, name, ver, ip, mask, gw, dns, port, dhcpEnabled

	@staticmethod
	def hexdump(byte_string, _len=16, base_addr=0, n=0, sep='-'):
		"""https://codereview.stackexchange.com/questions/161616/python-hexdump-generator"""
		FMT = '{}  {}  |{}|'
		not_shown = ['  ']
		leader = (base_addr + n) % _len
		next_n = n + _len - leader
		while byte_string[n:]:
			col0 = format(n + base_addr - leader, '08x')
			col1 = not_shown * leader
			col2 = ' ' * leader
			leader = 0
			for i in bytearray(byte_string[n:next_n]):
				col1 += [format(i, '02x')]
				col2 += chr(i) if 31 < i < 127 else '.'
			trailer = _len - len(col1)
			if trailer:
				col1 += not_shown * trailer
				col2 += ' ' * trailer
			col1.insert(_len // 2, sep)
			yield FMT.format(col0, ' '.join(col1), col2)
			n = next_n
			next_n += _len


if __name__ == "__main__":
	import time

	class Handler (object):
		def __init__ (self):
			self.cams = {}

		def __call__ (self, devid, name, ver, ip, mask, gw, dns, port, dhcpEnabled):
			if devid not in self.cams:
				print "Found %s (%s) at http://%s:%u" % (name, devid, ip, port)
				self.cams[devid] = (devid, name, ver, ip, mask, gw, dns, port, dhcpEnabled)

	logging.basicConfig ()
	d = Discoverer ()
	d.registerHandler (Handler ())
	d.start ()
	time.sleep (1)
	d.stop ()

