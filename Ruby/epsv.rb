require 'net/ftp'

module Net
	class FTP
		def makepasv
			debugger
			if @sock.peeraddr[0] == 'AF_INET'
				host, port = parse229(sendcmd('EPSV'))
			else
				host, port = parse227(sendcmd('EPSV'))
			end
			return host, port
		end
	end
end
